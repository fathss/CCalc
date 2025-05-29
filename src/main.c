#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "arithmetic.h"
#include "conversion.h"
#include "base_utils.h"
#include "error_handling.h"

void display();

int main()
{
    char input[64];
    int choice;
    while (1)
    {
        display();
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

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