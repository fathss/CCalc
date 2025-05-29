#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mathematics.h"
#include "base_utils.h"
#include "error_handling.h"

void display();
void arithmetic();
void mathInterface();
void progInterface();
void conversion();

char input[64];
int choice;

int main()
{
    while (1)
    {
        display();
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input : %s\n", error_message);
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
            printf("Invalid input: %s\n", error_message);
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
    while (1)
    {
        puts("\nA R I T H M E T I C");
        puts("-------------------");
        puts("1. Mathematics");
        puts("2. Programming");
        puts("3. Back");
        printf(">>>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input : %s\n", error_message);
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
            printf("Invalid input: %s\n", error_message);
        }
    }
}

void mathInterface()
{
    double result, num1, num2;
    char input1[64], input2[64];
    char op;
    while (1)
    {
        printf("Enter numbers and operation (num1) (operator) (num2): ");
        scanf("%s %c %s", &input1, &op, &input2);

        if (valid_base(input1, 10) && valid_base(input2, 10))
        {
            num1 = strtod(input1, NULL);
            num2 = strtod(input2, NULL);
        }
        else
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
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
                printf("Invalid input: %s\n\n", error_message);
                continue;
            }
            result = divide(num1, num2);
            break;
        default:
            error(INVALID_OPERATOR);
            printf("Invalid input: %s\n\n", error_message);
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

            if (!valid_base(input, 10))
            {
                error(INVALID_NUMBER);
                printf("Invalid input: %s\n\n", error_message);
                continue;
            }
            choice = atoi(input);

            if (choice < 1 || choice > 5)
            {
                error(INPUT_OUT_OF_RANGE);
                printf("Invalid input: %s\n\n", error_message);
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

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }

        operation = atoi(input);

        if (operation < 1 || operation > 5)
        {
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", error_message);
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
                result = different_types(add);
                break;
            case 2:
                result = different_types(subtract);
                break;
            case 3:
                result = different_types(multiply);
                break;
            case 4:
                result = different_types(divide);
                break;
            }
            break;
        }

        if (result < 0)
            continue;
        printf("\nBinary       : ");
        decimal_to_base(result, 2);
        printf("\nDecimal      : %g", result);
        printf("\nOctal        : ");
        decimal_to_base(result, 8);
        printf("\nHexadecimal  : ");
        decimal_to_base(result, 16);
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

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }

        choice = atoi(input);

        if (choice < 1 || choice > 5)
        {
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", error_message);
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

            if (!valid_base(decimal, 10))
            {
                error(INVALID_DECIMAL);
                printf("Invalid input: %s\n\n", error_message);
                continue;
            }

            dec = strtod(decimal, NULL);
            printf("Binary        : ");
            decimal_to_base(dec, 2);
            printf("\nOctal         : ");
            decimal_to_base(dec, 8);
            printf("\nHexadecimal   : ");
            decimal_to_base(dec, 16);
            puts("\n");
            continue;
        }
        else if (choice == 2)
        {
            printf("Enter binary  : ");
            scanf("%s", binary);

            if (!valid_base(binary, 2))
            {
                error(INVALID_BINARY);
                printf("Invalid input: %s\n\n", error_message);
                continue;
            }
            dec = base_to_decimal(binary, 2);
            printf("Decimal       : %g", dec);
            printf("\nOctal         : ");
            decimal_to_base(dec, 8);
            printf("\nHexadecimal   : ");
            decimal_to_base(dec, 16);
            puts("\n");
            continue;
        }
        else if (choice == 3)
        {
            printf("Enter octal : ");
            scanf("%s", octal);

            if (!valid_base(octal, 8))
            {
                error(INVALID_OCTAL);
                printf("Invalid input: %s\n\n", error_message);
                continue;
            }

            dec = base_to_decimal(octal, 8);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimal_to_base(dec, 2);
            printf("\nHexadecimal   : ");
            decimal_to_base(dec, 16);
            puts("\n");
            continue;
        }
        else if (choice == 4)
        {
            printf("Enter Hexadecimal : ");
            scanf("%s", hexadecimal);

            if (!valid_base(hexadecimal, 16))
            {
                error(INVALID_HEX);
                printf("Invalid input: %s\n\n", error_message);
                continue;
            }

            dec = base_to_decimal(hexadecimal, 16);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimal_to_base(dec, 2);
            printf("\nOctal         : ");
            decimal_to_base(dec, 8);
            puts("\n");
            continue;
        }
        break;
    }
}