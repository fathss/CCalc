#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "base_utils.h"
#include "error_handling.h"

// Checking the base of the input from prefix and converting it to decimal
double base_check(char *input)
{
    // Binary type check
    if (strncmp(input, "0b", 2) == 0 || strncmp(input, "0B", 2) == 0)
    {
        input += 2;
        if (!valid_base(input, 2))
        {
            error(INVALID_BINARY);
            return -1;
        }
        return base_to_decimal(input, 2);
    }
    // Hex type check
    else if (strncmp(input, "0x", 2) == 0 || strncmp(input, "0X", 2) == 0)
    {
        input += 2;
        if (!valid_base(input, 16))
        {
            error(INVALID_HEX);
            return -1;
        }
        return base_to_decimal(input, 16);
    }
    // Octal type check
    else if (input[0] == '0')
    {
        input++;
        if (!valid_base(input, 8))
        {
            error(INVALID_OCTAL);
            return -1;
        }
        return base_to_decimal(input, 8);
    }
    // Decimal type check
    else if (input[0] >= '0' && input[0] <= '9')
    {
        if (!valid_base(input, 10))
        {
            error(INVALID_DECIMAL);
            return -1;
        };
        return strtod(input, NULL);
    }
    // Prefix error
    else
    {
        error(INVALID_PREFIX);
        return -1;
    }
}

// Check if the input is valid for the specified base
int valid_base(char *input, int base)
{
    switch (base)
    {
    case 2:
        for (char *i = input; *i != '\0'; i++)
        {
            if (isdigit(*i) && *i >= '0' && *i <= '1' || *i == '.')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        break;

    case 8:
        for (char *i = input; *i != '\0'; i++)
        {
            if (isdigit(*i) && *i >= '0' && *i <= '7' || *i == '.')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        break;

    case 10:
        for (char *i = input; *i != '\0'; i++)
        {
            if (isdigit(*i) || *i == '.')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        break;

    case 16:
        for (char *i = input; *i != '\0'; i++)
        {
            if (*i >= '0' && *i <= '9' || *i >= 'A' && *i <= 'F' || *i == '.')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        break;
    }
    return 1;
}

double binary(double (*operation)(double, double))
{
    char binary1[32], binary2[32];

    while (1)
    {
        printf("\nEnter binary 1: ");
        scanf("%s", binary1);

        if (!valid_base(binary1, 2))
        {
            error(INVALID_BINARY);
            printf("Invalid input: %s\n", error_message);
            continue;
        }

        printf("Enter binary 2: ");
        scanf("%s", binary2);

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

        if (!valid_base(octal1, 8))
        {
            error(INVALID_OCTAL);
            printf("Invalid input: %s\n", error_message);
            continue;
        }

        printf("Enter octal 2: ");
        scanf("%s", octal2);

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

        if (!valid_base(hex1, 16))
        {
            error(INVALID_HEX);
            printf("Invalid input: %s\n", error_message);
            continue;
        }

        printf("Enter hex 2: ");
        scanf("%s", hex2);

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

        dec1 = base_check(input);
        if (dec1 < 0)
        {
            printf("Invalid input: %s\n", error_message);
            retryMenu++;
            continue;
        }

        printf("Enter input 2: ");
        scanf("%s", input);

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

// Convert other base to decimal. Returns decimal value
double base_to_decimal(char *input, int base)
{
    double dec = 0.0, fraction = 0.0;
    char *dot = strstr(input, ".");

    if (!dot)
    {
        dot = input + strlen(input);
    }

    // Integer part
    int index = dot - input - 1;
    int value;
    for (int i = 0; *(input + i) != '.' && *(input + i) != '\0'; i++)
    {
        if (*(input + i) > '9')
        {
            value = *(input + i) - 55;
        }
        else
        {
            value = *(input + i) - '0';
        }
        dec += value * pow(base, index - i);
    }

    // Decimal part
    if (*(dot) != '\0')
    {
        dot++;
        for (int i = 1; *dot != '\0'; i++, dot++)
        {
            if (*dot > '9')
            {
                value = *dot - 55;
            }
            else
            {
                value = *dot - '0';
            }
            fraction += value * pow(base, -i);
        }
    }

    dec += fraction;
    return dec;
}

// Convert decimal to other base. Prints the result in the specified base
void decimal_to_base(double input_decimal, int base)
{
    char intResult[65], floatResult[65];
    char digits[] = "0123456789ABCDEF";
    int index = 0;
    unsigned long long intPart = (unsigned long long)input_decimal;
    double floatPart = input_decimal - intPart;

    if (intPart == 0)
    {
        intResult[index] = '0';
        index++;
    }
    else
    {
        while (intPart > 0)
        {
            intResult[index] = digits[intPart % base];
            intPart /= base;
            index++;
        }
    }
    intResult[index] = '\0';

    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", intResult[i]);
    }

    // Check if decimal part exists
    if (floatPart == 0)
    {
        return;
    }
    else
    {
        index = 0;
        while (floatPart > 0)
        {
            floatPart *= base;
            int decimal = (int)floatPart;
            floatResult[index++] = digits[decimal];
            floatPart -= decimal;
        }
        floatResult[index] = '\0';

        printf(".");
        for (int i = 0; i < index; i++)
        {
            printf("%c", floatResult[i]);
        }
    }
}