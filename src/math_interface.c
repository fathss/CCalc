#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_interface.h"
#include "mathematics.h"
#include "base_utils.h"
#include "error_handling.h"

void mathInterface()
{
    double result, num1, num2;
    char input1[64], input2[64];
    char op;
    while (1)
    {
        printf("Enter numbers and operation (num1) (operator) (num2): ");
        scanf("%s %c %s", &input1, &op, &input2);

        if (validBase(input1, 10) && validBase(input2, 10))
        {
            num1 = strtod(input1, NULL);
            num2 = strtod(input2, NULL);
        }
        else
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", errorMessage);
            continue;
        }
        switch (op)
        {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            if (num2 == 0)
            {
                error(DIVISION_BY_ZERO);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }
            result = divide(num1, num2);
            break;
        default:
            error(INVALID_OPERATOR);
            printf("Invalid input: %s\n\n", errorMessage);
            continue;
        }

        printf("Result: %g\n\n", result);
        break;
    }
}