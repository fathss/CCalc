#include <stdio.h>
#include <stdlib.h>
#include "interface_utils.h"
#include "error_handling.h"

int get_validated_choice(const char *prompt, int min, int max)
{
    char input[64];
    int choice;
    while (1)
    {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (!valid_base(input, 10))
        {
            error(INVALID_NUMBER);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }
        choice = atoi(input);
        if (choice < min || choice > max)
        {
            error(INPUT_OUT_OF_RANGE);
            printf("Invalid input: %s\n\n", error_message);
            continue;
        }
        return choice;
    }
}

void main_display()
{
    puts("\nP R O G R A M M I N G  C A L C U L A T O R");
    puts("----------------------------------------");
    puts("1. Arithmetic operations");
    puts("2. Base conversion");
    puts("3. Exit");
}

void arithmetic_display()
{
    puts("\nA R I T H M E T I C");
    puts("-------------------");
    puts("1. Mathematics");
    puts("2. Programming");
    puts("3. Back");
}

void conversion_display()
{
    puts("\nB A S E  C O N V E R S I O N");
    puts("----------------------------");
    puts("1. Decimal");
    puts("2. Binary");
    puts("3. Octal");
    puts("4. Hexadecimal");
    puts("5. Back");
}

void prog_interface_display_choice()
{
    puts("1. Binary");
    puts("2. Octal");
    puts("3. Hexadecimal");
    puts("4. Different types");
    puts("5. Back");
}

void prog_interface_display_op()
{
    puts("1. Addition");
    puts("2. Subtraction");
    puts("3. Multiplication");
    puts("4. Division");
    puts("5. Back");
}