#include <stdio.h>
#include <stdlib.h>
#include "conversion_utils.h"
#include "base_utils.h"
#include "error_handling.h"

void handle_decimal_input()
{
    char decimal[32];
    double dec;
    printf("Enter decimal : ");
    scanf("%s", decimal);
    getchar();

    if (!valid_base(decimal, 10))
    {
        error(INVALID_DECIMAL);
        printf("Invalid input: %s\n\n", error_message);
        return;
    }

    dec = strtod(decimal, NULL);
    printf("Binary        : ");
    decimal_to_base(dec, 2);
    printf("\nOctal         : ");
    decimal_to_base(dec, 8);
    printf("\nHexadecimal   : ");
    decimal_to_base(dec, 16);
    puts("\n");
}

void handle_binary_input()
{
    char binary[32];
    double dec;
    printf("Enter binary  : ");
    scanf("%s", binary);
    getchar();

    if (!valid_base(binary, 2))
    {
        error(INVALID_BINARY);
        printf("Invalid input: %s\n\n", error_message);
        return;
    }
    dec = base_to_decimal(binary, 2);
    printf("Decimal       : %g", dec);
    printf("\nOctal         : ");
    decimal_to_base(dec, 8);
    printf("\nHexadecimal   : ");
    decimal_to_base(dec, 16);
    puts("\n");
}

void handle_octal_input()
{
    char octal[32];
    double dec;
    printf("Enter octal : ");
    scanf("%s", octal);
    getchar();

    if (!valid_base(octal, 8))
    {
        error(INVALID_OCTAL);
        printf("Invalid input: %s\n\n", error_message);
        return;
    }

    dec = base_to_decimal(octal, 8);
    printf("Decimal       : %g", dec);
    printf("\nBinary        : ");
    decimal_to_base(dec, 2);
    printf("\nHexadecimal   : ");
    decimal_to_base(dec, 16);
    puts("\n");
}

void handle_hexadecimal_input()
{
    char hexadecimal[32];
    double dec;
    printf("Enter Hexadecimal : ");
    scanf("%s", hexadecimal);
    getchar();

    if (!valid_base(hexadecimal, 16))
    {
        error(INVALID_HEX);
        printf("Invalid input: %s\n\n", error_message);
        return;
    }

    dec = base_to_decimal(hexadecimal, 16);
    printf("Decimal       : %g", dec);
    printf("\nBinary        : ");
    decimal_to_base(dec, 2);
    printf("\nOctal         : ");
    decimal_to_base(dec, 8);
    puts("\n");
}