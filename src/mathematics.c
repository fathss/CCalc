#include <stdio.h>
#include "mathematics.h"
#include "error_handling.h"

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
        error(DIVISION_BY_ZERO);
        printf("Invalid input: %s\n\n", error_message);
        return -1;
    }
    return a / b;
}