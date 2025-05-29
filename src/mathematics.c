#include <stdio.h>
#include "mathematics.h"

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        printf("Invalid input: division by zero, try again\n\n");
        return -1;
    }
    return a / b;
}