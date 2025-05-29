#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mathematics.h"
#include "interface_utils.h"
#include "base_utils.h"
#include "prog_op.h"
#include "error_handling.h"

void arithmetic();
void conversion();
void mathInterface();
void progInterface();

char input[64];
int choice;

int main()
{
    int repeat = 1;

    while (repeat)
    {
        main_display();
        printf(">>>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
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
            repeat = 0;
            break;
        default:
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }
    }

    return 0;
}

void arithmetic()
{
    int repeat = 1;

    while (repeat)
    {
        arithmetic_display();
        printf(">>>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }

        choice = atoi(input);

        switch (choice)
        {
        case 1:
            mathInterface();
            break;
        case 2:
            progInterface();
            break;
        case 3:
            repeat = 0;
            break;
        default:
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }
    }
}

void conversion()
{
    double dec;
    while (1)
    {
        char decimal[32], binary[32], octal[32], hexadecimal[32];

        conversion_display();
        printf(">>>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }

        choice = atoi(input);

        switch (choice)
        {
        case 1:
            printf("Enter decimal : ");
            scanf("%s", decimal);
            getchar();

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
        case 2:
            printf("Enter binary  : ");
            scanf("%s", binary);
            getchar();

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
        case 3:
            printf("Enter octal : ");
            scanf("%s", octal);
            getchar();

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
        case 4:
            printf("Enter Hexadecimal : ");
            scanf("%s", hexadecimal);
            getchar();

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
        case 5:
            return;
        default:
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }
    }
}

void mathInterface()
{
    double result, num1, num2;
    int repeat = 1;
    char input1[64], input2[64];
    char op;

    while (repeat)
    {
        printf("Enter numbers and operation (num1) (operator) (num2): ");
        scanf("%s %c %s", &input1, &op, &input2);
        getchar();

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
        repeat = 0;
    }
}

void progInterface()
{
    double result;
    int repeat = 1;
    int operation;

    while (repeat)
    {
        puts("");
        prog_interface_display_choice();
        printf(">>>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

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
        else if (choice == 5)
            repeat = 0;

        prog_interface_display_op();
        printf(">>>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

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
        else if (operation == 5)
            continue;

        result = prog_op(choice, operation);

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
    }
}
