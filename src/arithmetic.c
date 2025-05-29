#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arithmetic.h"
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

void progInterface()
{
    double result;
    int choiceRepeat = 1;
    int choice;
    char input[64];

    while (1)
    {
        if (choiceRepeat)
        {
            puts("\n1. Binary");
            puts("2. Octal");
            puts("3. Hexadecimal");
            puts("4. Different types");
            puts("5. Back");
            printf(">>>> ");
            scanf("%s", input);

            if (!validBase(input, 10))
            {
                error(INVALID_NUMBER);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }
            choice = atoi(input);

            if (choice < 1 || choice > 5)
            {
                error(INPUT_OUT_OF_RANGE);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }
            choiceRepeat = 0;
        }

        if (choice == 5)
        {
            break;
        }

        int operation;
        puts("1. Addition");
        puts("2. Subtraction");
        puts("3. Multiplication");
        puts("4. Division");
        puts("5. Back");
        printf(">>>> ");
        scanf("%s", input);

        if (!validBase(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", errorMessage);
            continue;
        }

        operation = atoi(input);

        if (operation < 1 || operation > 5)
        {
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", errorMessage);
            continue;
        }

        if (operation == 5)
        {
            choiceRepeat = 1;
            continue;
        }

        switch (choice)
        {
        case 1:
            switch (operation)
            {
            case 1:
                result = binary(add);
                break;
            case 2:
                result = binary(subtract);
                break;
            case 3:
                result = binary(multiply);
                break;
            case 4:
                result = binary(divide);
                break;
            }
            break;
        case 2:
            switch (operation)
            {
            case 1:
                result = octal(add);
                break;
            case 2:
                result = octal(subtract);
                break;
            case 3:
                result = octal(multiply);
                break;
            case 4:
                result = octal(divide);
                break;
            }
            break;

        case 3:
            switch (operation)
            {
            case 1:
                result = hexadecimal(add);
                break;
            case 2:
                result = hexadecimal(subtract);
                break;
            case 3:
                result = hexadecimal(multiply);
                break;
            case 4:
                result = hexadecimal(divide);
                break;
            }
            break;

        case 4:
            switch (operation)
            {
            case 1:
                result = differentTypes(add);
                break;
            case 2:
                result = differentTypes(subtract);
                break;
            case 3:
                result = differentTypes(multiply);
                break;
            case 4:
                result = differentTypes(divide);
                break;
            }
            break;
        }

        if (result < 0)
            continue;
        printf("\nBinary       : ");
        decimalToBase(result, 2);
        printf("\nDecimal      : %g", result);
        printf("\nOctal        : ");
        decimalToBase(result, 8);
        printf("\nHexadecimal  : ");
        decimalToBase(result, 16);
        printf("\n");
        choiceRepeat = 1;
    }
}

void arithmetic()
{
    char input[64];
    int choice;

    while (1)
    {
        puts("\nA R I T H M E T I C");
        puts("-------------------");
        puts("1. Mathematics");
        puts("2. Programming");
        puts("3. Back");
        printf(">>>> ");
        scanf("%s", input);

        if (!validBase(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input : %s\n", errorMessage);
            continue;
        }
        choice = atoi(input);

        if (choice == 1)
        {
            mathInterface();
        }
        else if (choice == 2)
        {
            progInterface();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n", errorMessage);
        }
    }
}