#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_STRING 1024

typedef struct
{
    int data[MAX_STACK];
    int count;
} IntStack;

typedef struct
{
    char data[MAX_STACK][32];
    int count;
} TokenStack;

void initIntStack(IntStack *s) { s->count = 0; }
void pushInt(IntStack *s, int val) { s->data[s->count++] = val; }
int popInt(IntStack *s) { return s->data[--s->count]; }
int isEmptyInt(IntStack *s) { return s->count == 0; }

void initTokenStack(TokenStack *s) { s->count = 0; }
void pushToken(TokenStack *s, const char *tok) { strcpy(s->data[s->count++], tok); }
char *popToken(TokenStack *s) { return s->data[--s->count]; }
char *peekToken(TokenStack *s) { return s->data[s->count - 1]; }
int isEmptyToken(TokenStack *s) { return s->count == 0; }

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int isOperator(const char *tok)
{
    return strlen(tok) == 1 && strchr("+-*/", tok[0]);
}

void infixToPostfix(const char *infix, TokenStack *postfix)
{
    TokenStack opStack;
    initTokenStack(&opStack);

    char token[32];
    int i = 0, n = strlen(infix);
    while (i < n)
    {
        if (isspace(infix[i]))
        {
            i++;
            continue;
        }

        // Parse number (including negative)
        if (isdigit(infix[i]) || (infix[i] == '-' && (i == 0 || infix[i - 1] == '(' || isspace(infix[i - 1])) && isdigit(infix[i + 1])))
        {
            int j = 0;
            if (infix[i] == '-')
                token[j++] = infix[i++];
            while (i < n && isdigit(infix[i]))
                token[j++] = infix[i++];
            token[j] = '\0';
            pushToken(postfix, token);
            continue;
        }

        // Parse operator or parenthesis
        if (strchr("+-*/()", infix[i]))
        {
            token[0] = infix[i];
            token[1] = '\0';
            if (token[0] == '(')
            {
                pushToken(&opStack, token);
            }
            else if (token[0] == ')')
            {
                while (!isEmptyToken(&opStack) && peekToken(&opStack)[0] != '(')
                {
                    pushToken(postfix, popToken(&opStack));
                }
                if (!isEmptyToken(&opStack))
                    popToken(&opStack); // pop '('
            }
            else
            {
                while (!isEmptyToken(&opStack) && precedence(peekToken(&opStack)[0]) >= precedence(token[0]))
                {
                    pushToken(postfix, popToken(&opStack));
                }
                pushToken(&opStack, token);
            }
            i++;
            continue;
        }
        // Invalid character
        i++;
    }
    while (!isEmptyToken(&opStack))
    {
        pushToken(postfix, popToken(&opStack));
    }
}

int evalPostfix(TokenStack *postfix)
{
    IntStack valStack;
    initIntStack(&valStack);
    for (int i = 0; i < postfix->count; i++)
    {
        char *tok = postfix->data[i];
        if (isOperator(tok))
        {
            int b = popInt(&valStack);
            int a = popInt(&valStack);
            switch (tok[0])
            {
            case '+':
                pushInt(&valStack, a + b);
                break;
            case '-':
                pushInt(&valStack, a - b);
                break;
            case '*':
                pushInt(&valStack, a * b);
                break;
            case '/':
                pushInt(&valStack, a / b);
                break;
            }
        }
        else
        {
            pushInt(&valStack, atoi(tok));
        }
    }
    return popInt(&valStack);
}

void showPostfix(TokenStack *postfix)
{
    for (int i = 0; i < postfix->count; i++)
    {
        printf("%s ", postfix->data[i]);
    }
    printf("\n");
}

int main()
{
    char input[MAX_STRING];
    TokenStack postfix;
    initTokenStack(&postfix);

    printf("Enter infix expression (space optional, e.g. -5+12*(3-2)): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    infixToPostfix(input, &postfix);

    printf("Postfix expression: ");
    showPostfix(&postfix);

    printf("Evaluating postfix expression...\n");
    printf("Result: %d\n", evalPostfix(&postfix));
    return 0;
}