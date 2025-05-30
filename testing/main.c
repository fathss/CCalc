#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_STR 100

typedef char *itemType;
typedef struct node Tree;
typedef struct
{
    Tree *data[MAX_STACK];
    int count;
} Stack;

struct node
{
    itemType data;
    Tree *kiri;
    Tree *kanan;
};

// Stack functions
void init(Stack *s) { s->count = 0; }

void push(Stack *s, Tree *node)
{
    s->data[s->count++] = node;
}

Tree *pop(Stack *s)
{
    return s->data[--s->count];
}

int empty(Stack *s)
{
    return s->count == 0;
}

Tree *peek(Stack *s)
{
    return s->data[s->count - 1];
}

// Operator utilities
int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Tree creation
Tree *createNode(const char *str)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = strdup(str);
    node->kiri = NULL;
    node->kanan = NULL;
    return node;
}

// Traversals
void preorder(Tree *root)
{
    if (root)
    {
        printf("%s ", root->data);
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void inorder(Tree *root)
{
    if (root)
    {
        inorder(root->kiri);
        printf("%s ", root->data);
        inorder(root->kanan);
    }
}

void postorder(Tree *root)
{
    if (root)
    {
        postorder(root->kiri);
        postorder(root->kanan);
        printf("%s ", root->data);
    }
}

// Build expression tree from infix
Tree *buildTreeFromInfix(const char *infix)
{
    Stack operators, operands;
    init(&operators);
    init(&operands);

    int i = 0, len = strlen(infix);
    char token[30];

    while (i < len)
    {
        if (isspace(infix[i]))
        {
            i++;
            continue;
        }

        if (isdigit(infix[i]) || infix[i] == '.')
        {
            int j = 0;
            while (i < len && (isdigit(infix[i]) || infix[i] == '.'))
                token[j++] = infix[i++];
            token[j] = '\0';
            push(&operands, createNode(token));
        }

        else if (infix[i] == '(')
        {
            char tmp[2] = {infix[i++], '\0'};
            push(&operators, createNode(tmp));
        }

        else if (infix[i] == ')')
        {
            while (!empty(&operators) && strcmp(peek(&operators)->data, "(") != 0)
            {
                Tree *op = pop(&operators);
                Tree *right = pop(&operands);
                Tree *left = pop(&operands);
                op->kiri = left;
                op->kanan = right;
                push(&operands, op);
            }
            if (!empty(&operators))
                pop(&operators); // Pop "("
            i++;
        }

        else if (isOperator(infix[i]))
        {
            char op[2] = {infix[i++], '\0'};

            while (!empty(&operators) &&
                   precedence(peek(&operators)->data[0]) >= precedence(op[0]) &&
                   strcmp(peek(&operators)->data, "(") != 0)
            {
                Tree *topOp = pop(&operators);
                Tree *right = pop(&operands);
                Tree *left = pop(&operands);
                topOp->kiri = left;
                topOp->kanan = right;
                push(&operands, topOp);
            }

            push(&operators, createNode(op));
        }
    }

    while (!empty(&operators))
    {
        Tree *op = pop(&operators);
        Tree *right = pop(&operands);
        Tree *left = pop(&operands);
        op->kiri = left;
        op->kanan = right;
        push(&operands, op);
    }

    return pop(&operands); // Final root
}

// Evaluation
double applyOperator(char op, double a, double b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0.0;
}

double evaluate(Tree *root)
{
    if (!isOperator(root->data[0]) || (strlen(root->data) > 1)) // catch multi-digit decimals
        return strtod(root->data, NULL);
    double left = evaluate(root->kiri);
    double right = evaluate(root->kanan);
    return applyOperator(root->data[0], left, right);
}

// Main
int main()
{
    char expr[MAX_STR];
    printf("Enter infix expression (with spaces between numbers/operators, e.g., 12 + 3 * ( 4 - 2) ): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    Tree *root = buildTreeFromInfix(expr);

    printf("\nPreorder (Prefix): ");
    preorder(root);
    printf("\nInorder  (Infix):  ");
    inorder(root);
    printf("\nPostorder(Postfix): ");
    postorder(root);

    double result = evaluate(root);
    printf("\n\nResult: %.2lf\n", result); // Show 2 decimal places

    return 0;
}
