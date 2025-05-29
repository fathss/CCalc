#include <stdio.h>
#include <stdlib.h>
#include "prog_interface.h"
#include "mathematics.h"
#include "base_utils.h"
#include "error_handling.h"

double binary(double (*operation)(double, double))
{
    char binary1[32], binary2[32];

    while (1)
    {
        printf("\nEnter binary 1: ");
        scanf("%s", binary1);

        if (!validBase(binary1, 2))
        {
            error(INVALID_BINARY);
            printf("Invalid input: %s\n", errorMessage);
            continue;
        }

        printf("Enter binary 2: ");
        scanf("%s", binary2);

        if (!validBase(binary2, 2))
        {
            error(INVALID_BINARY);
            printf("Invalid input: %s\n", errorMessage);
            continue;
        }
        break;
    }

    double dec1 = baseToDecimal(binary1, 2);
    double dec2 = baseToDecimal(binary2, 2);

    return operation(dec1, dec2);
}

double octal(double (*operation)(double, double))
{
    char octal1[32], octal2[32];

    while (1)
    {
        printf("\nEnter octal 1: ");
        scanf("%s", octal1);

        if (!validBase(octal1, 8))
        {
            error(INVALID_OCTAL);
            printf("Invalid input: %s\n", errorMessage);
            continue;
        }

        printf("Enter octal 2: ");
        scanf("%s", octal2);

        if (!validBase(octal2, 8))
        {
            error(INVALID_OCTAL);
            printf("Invalid input: %s\n", errorMessage);
            continue;
        }
        break;
    }

    double dec1 = baseToDecimal(octal1, 8);
    double dec2 = baseToDecimal(octal2, 8);

    return operation(dec1, dec2);
}

double hexadecimal(double (*operation)(double, double))
{
    char hex1[32], hex2[32];

    while (1)
    {
        printf("\nEnter hex 1: ");
        scanf("%s", hex1);

        if (!validBase(hex1, 16))
        {
            error(INVALID_HEX);
            printf("Invalid input: %s\n", errorMessage);
            continue;
        }

        printf("Enter hex 2: ");
        scanf("%s", hex2);

        if (!validBase(hex2, 16))
        {
            error(INVALID_HEX);
            printf("Invalid input: %s\n", errorMessage);
            continue;
        }
        break;
    }

    double dec1 = baseToDecimal(hex1, 16);
    double dec2 = baseToDecimal(hex2, 16);

    return operation(dec1, dec2);
}

double differentTypes(double (*operation)(double, double))
{
    char input[32], errorMsg[32];
    double dec1, dec2;
    int retryMenu = 5;

    puts("\nCAUTION!");

    while (1)
    {
        if (retryMenu == 5)
        {
            puts("\nFOLLOW THE RULES BELOW!");
            puts("Binary Prefix   : 0b || 0B");
            puts("Octal Prefix    : 0");
            puts("Hexadecimal Prefix : 0x || 0X");
            puts("Decimal Prefix  : No prefix");
            retryMenu = 0;
        }

        printf("\nEnter input 1: ");
        scanf("%s", input);

        dec1 = baseCheck(input);
        if (dec1 < 0)
        {
            printf("Invalid input: %s\n", errorMessage);
            retryMenu++;
            continue;
        }

        printf("Enter input 2: ");
        scanf("%s", input);

        dec2 = baseCheck(input);
        if (dec2 < 0)
        {
            printf("Invalid input: %s\n");
            retryMenu++;
            continue;
        }
        break;
    }

    return operation(dec1, dec2);
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
