#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100
#define MAX_STRING 1024

typedef struct
{
    char data[MAX_STACK];
    int count;
} Stack;

void initStack(Stack *s);
void push(Stack *s, char c);
void pop(Stack *s);
int isEmpty(Stack *s);

Stack stack;

int main()
{
    char input[MAX_STRING];

    initStack(&stack);

    printf(">>>> ");

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    return 0;
}

void initStack(Stack *s)
{
    s->count = 0;
}

void push(Stack *s, char c)
{
    s->data[s->count++] = c;
}

void pop(Stack *s)
{
    s->count--;
}

int isEmpty(Stack *s)
{
    return s->count == 0;
}