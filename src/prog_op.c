#include <stdio.h>
#include "mathematics.h"
#include "prog_op.h"
#include "base_utils.h"
#include "error_handling.h"

double prog_op(int choice, int operation)
{
    if (choice == 1)
    {
        if (operation == 1)
            return binary(add);
        else if (operation == 2)
            return binary(subtract);
        else if (operation == 3)
            return binary(multiply);
        else if (operation == 4)
            return binary(divide);
    }
    else if (choice == 2)
    {
        if (operation == 1)
            return octal(add);
        else if (operation == 2)
            return octal(subtract);
        else if (operation == 3)
            return octal(multiply);
        else if (operation == 4)
            return octal(divide);
    }
    else if (choice == 3)
    {
        if (operation == 1)
            return hexadecimal(add);
        else if (operation == 2)
            return hexadecimal(subtract);
        else if (operation == 3)
            return hexadecimal(multiply);
        else if (operation == 4)
            return hexadecimal(divide);
    }
    else if (choice == 4)
    {
        if (operation == 1)
            return different_types(add);
        else if (operation == 2)
            return different_types(subtract);
        else if (operation == 3)
            return different_types(multiply);
        else if (operation == 4)
            return different_types(divide);
    }
}

double binary(double (*operation)(double, double))
{
    char binary1[32], binary2[32];

    while (1)
    {
        printf("\nEnter binary 1: ");
        scanf("%s", binary1);
        getchar();

        if (!valid_base(binary1, 2))
        {
            error(INVALID_BINARY);
            printf("Invalid input: %s\n", error_message);
            continue;
        }

        printf("Enter binary 2: ");
        scanf("%s", binary2);
        getchar();

        if (!valid_base(binary2, 2))
        {
            error(INVALID_BINARY);
            printf("Invalid input: %s\n", error_message);
            continue;
        }
        break;
    }

    double dec1 = base_to_decimal(binary1, 2);
    double dec2 = base_to_decimal(binary2, 2);

    return operation(dec1, dec2);
}

double octal(double (*operation)(double, double))
{
    char octal1[32], octal2[32];

    while (1)
    {
        printf("\nEnter octal 1: ");
        scanf("%s", octal1);
        getchar();

        if (!valid_base(octal1, 8))
        {
            error(INVALID_OCTAL);
            printf("Invalid input: %s\n", error_message);
            continue;
        }

        printf("Enter octal 2: ");
        scanf("%s", octal2);
        getchar();

        if (!valid_base(octal2, 8))
        {
            error(INVALID_OCTAL);
            printf("Invalid input: %s\n", error_message);
            continue;
        }
        break;
    }

    double dec1 = base_to_decimal(octal1, 8);
    double dec2 = base_to_decimal(octal2, 8);

    return operation(dec1, dec2);
}

double hexadecimal(double (*operation)(double, double))
{
    char hex1[32], hex2[32];

    while (1)
    {
        printf("\nEnter hex 1: ");
        scanf("%s", hex1);
        getchar();

        if (!valid_base(hex1, 16))
        {
            error(INVALID_HEX);
            printf("Invalid input: %s\n", error_message);
            continue;
        }

        printf("Enter hex 2: ");
        scanf("%s", hex2);
        getchar();

        if (!valid_base(hex2, 16))
        {
            error(INVALID_HEX);
            printf("Invalid input: %s\n", error_message);
            continue;
        }
        break;
    }

    double dec1 = base_to_decimal(hex1, 16);
    double dec2 = base_to_decimal(hex2, 16);

    return operation(dec1, dec2);
}

double different_types(double (*operation)(double, double))
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
            puts("Binary Prefix      : 0b || 0B");
            puts("Octal Prefix       : 0");
            puts("Hexadecimal Prefix : 0x || 0X");
            puts("Decimal Prefix     : No prefix");
            retryMenu = 0;
        }

        printf("\nEnter input 1: ");
        scanf("%s", input);
        getchar();

        dec1 = base_check(input);
        if (dec1 < 0)
        {
            printf("Invalid input: %s\n", error_message);
            retryMenu++;
            continue;
        }

        printf("Enter input 2: ");
        scanf("%s", input);
        getchar();

        dec2 = base_check(input);
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