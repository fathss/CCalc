#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversion.h"
#include "base_utils.h"
#include "error_handling.h"

void conversion()
{
    double dec;
    while (1)
    {
        char input[64];
        int choice;
        char decimal[32], binary[32], octal[32], hexadecimal[32];
        puts("\nBASE CONVERSION");
        puts("----------------");
        puts("1. Decimal");
        puts("2. Binary");
        puts("3. Octal");
        puts("4. Hexadecimal");
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

        if (choice == 5)
        {
            break;
        }

        if (choice == 1)
        {
            printf("Enter decimal : ");
            scanf("%s", decimal);

            if (!validBase(decimal, 10))
            {
                error(INVALID_DECIMAL);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }

            dec = strtod(decimal, NULL);
            printf("Binary        : ");
            decimalToBase(dec, 2);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
            continue;
        }
        else if (choice == 2)
        {
            printf("Enter binary  : ");
            scanf("%s", binary);

            if (!validBase(binary, 2))
            {
                error(INVALID_BINARY);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }

            dec = baseToDecimal(binary, 2);
            printf("Decimal       : %g", dec);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
            continue;
        }
        else if (choice == 3)
        {
            printf("Enter octal : ");
            scanf("%s", octal);

            if (!validBase(octal, 8))
            {
                error(INVALID_OCTAL);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }

            dec = baseToDecimal(octal, 8);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimalToBase(dec, 2);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
            continue;
        }
        else if (choice == 4)
        {
            printf("Enter Hexadecimal : ");
            scanf("%s", hexadecimal);

            if (!validBase(hexadecimal, 16))
            {
                error(INVALID_HEX);
                printf("Invalid input: %s\n\n", errorMessage);
                continue;
            }

            dec = baseToDecimal(hexadecimal, 16);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimalToBase(dec, 2);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            puts("\n");
            continue;
        }
        break;
    }
}