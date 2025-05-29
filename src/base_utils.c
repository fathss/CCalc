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