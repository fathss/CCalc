#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "base_utils.h"
#include "error_handling.h"

// Checking what base from input
double baseCheck(char *x)
{
    // Binary type check
    if (strncmp(x, "0b", 2) == 0 || strncmp(x, "0B", 2) == 0)
    {
        x += 2;
        if (!validBase(x, 2))
        {
            error(INVALID_BINARY);
            return -1;
        }
        return baseToDecimal(x, 2);
    }
    // Hexadecimal type check
    else if (strncmp(x, "0x", 2) == 0 || strncmp(x, "0X", 2) == 0)
    {
        x += 2;
        if (!validBase(x, 16))
        {
            error(INVALID_HEX);
            return -1;
        }
        return baseToDecimal(x, 16);
    }
    // Octal type check
    else if (x[0] == '0')
    {
        x++;
        if (!validBase(x, 8))
        {
            error(INVALID_OCTAL);
            return -1;
        }
        return baseToDecimal(x, 8);
    }
    // Decimal type check
    else if (x[0] >= '0' && x[0] <= '9')
    {
        if (!validBase(x, 10))
        {
            error(INVALID_DECIMAL);
            return -1;
        };
        return strtod(x, NULL);
    }
    // Prefix error
    else
    {
        error(INVALID_PREFIX);
        return -1;
    }
}

// Checking if the base input is valid
int validBase(char *x, int base)
{
    switch (base)
    {
    case 2:
        for (char *i = x; *i != '\0'; i++)
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
        for (char *i = x; *i != '\0'; i++)
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
        for (char *i = x; *i != '\0'; i++)
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
        for (char *i = x; *i != '\0'; i++)
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

// Convert other base to decimal
double baseToDecimal(char *x, int base)
{
    double dec = 0.0, fraction = 0.0;
    char *dot = strstr(x, ".");

    if (!dot)
    {
        dot = x + strlen(x);
    }

    // Integer part
    int index = dot - x - 1;
    int value;
    for (int i = 0; *(x + i) != '.' && *(x + i) != '\0'; i++)
    {
        if (*(x + i) > '9')
        {
            value = *(x + i) - 55;
        }
        else
        {
            value = *(x + i) - '0';
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

// Convert decimal to other base
void decimalToBase(double x, int base)
{
    char intResult[65], floatResult[65];
    char digits[] = "0123456789ABCDEF";
    int index = 0;
    unsigned long long intPart = (unsigned long long)x;
    double floatPart = x - intPart;

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