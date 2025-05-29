#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arithmetic.h"
#include "base_utils.h"
#include "math_interface.h"
#include "prog_interface.h"
#include "error_handling.h"

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
            printf("Invalid input: %s\n", errorMessage);
        }
    }
}