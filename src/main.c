#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Error Message
char errorMessage[50];

// Error Types
enum ErrorType
{
    INVALID_PREFIX,
    INVALID_NUMBER,
    INVALID_OPERATOR,
    INPUT_OUT_OF_RANGE,
    DIVISION_BY_ZERO,
    INVALID_BINARY,
    INVALID_OCTAL,
    INVALID_HEX,
    INVALID_DECIMAL
};

// Function Prototypes
void display();
void arithmetic();
void conversion();
void mathematics();
void programming();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double binary(double (*operation)(double, double));
double octal(double (*operation)(double, double));
double hexadecimal(double (*operation)(double, double));
double differentTypes(double (*operation)(double, double));
double baseCheck(char *x);
int validBase(char *x, int base);
double baseToDecimal(char *x, int base);
void decimalToBase(double x, int base);
void error(enum ErrorType errorType);

int main()
{
    char input[64];
    int choice;
    while (1)
    {
        display();
        scanf("%s", input);

        if (!validBase(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input : %s\n", errorMessage);
            continue;
        }

        choice = atoi(input);

        switch (choice)
        {
        case 1:
            arithmetic();
            break;
        case 2:
            conversion();
            break;
        case 3:
            puts("Exit");
            return 0;
        default:
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n", errorMessage);
            break;
        }
    }

    return 0;
}

void display()
{
    puts("\nP R O G R A M M I N G  C A L C U L A T O R");
    puts("----------------------------------------");
    puts("1. Arithmetic operations");
    puts("2. Base conversion");
    puts("3. Exit");
    printf(">>>> ");
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
            mathematics();
        }
        else if (choice == 2)
        {
            programming();
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

void mathematics()
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

void programming()
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
        printf("Invalid input: division by zero, try again\n\n");
        return -1;
    }
    return a / b;
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

void error(enum ErrorType errorType)
{
    switch (errorType)
    {
    case INVALID_PREFIX:
        strcpy(errorMessage, "not a valid prefix, try again");
        break;
    case INVALID_NUMBER:
        strcpy(errorMessage, "not a valid number, try again");
        break;
    case INVALID_OPERATOR:
        strcpy(errorMessage, "not a valid operator, try again");
        break;
    case INPUT_OUT_OF_RANGE:
        strcpy(errorMessage, "input out of range, try again");
        break;
    case DIVISION_BY_ZERO:
        strcpy(errorMessage, "division by zero, try again");
        break;
    case INVALID_BINARY:
        strcpy(errorMessage, "not a valid binary, try again");
        break;
    case INVALID_OCTAL:
        strcpy(errorMessage, "not a valid octal, try again");
        break;
    case INVALID_HEX:
        strcpy(errorMessage, "not a valid hexadecimal, try again");
        break;
    case INVALID_DECIMAL:
        strcpy(errorMessage, "not a valid decimal, try again");
        break;
    }
}
