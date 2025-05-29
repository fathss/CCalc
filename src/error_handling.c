#include <stdio.h>
#include <string.h>
#include "error_handling.h"

char error_message[50];

void error(ErrorType error_type)
{
    switch (error_type)
    {
    case INVALID_PREFIX:
        strcpy(error_message, "not a valid prefix, try again");
        break;
    case INVALID_NUMBER:
        strcpy(error_message, "not a valid number, try again");
        break;
    case INVALID_OPERATOR:
        strcpy(error_message, "not a valid operator, try again");
        break;
    case INPUT_OUT_OF_RANGE:
        strcpy(error_message, "input out of range, try again");
        break;
    case DIVISION_BY_ZERO:
        strcpy(error_message, "division by zero, try again");
        break;
    case INVALID_BINARY:
        strcpy(error_message, "not a valid binary, try again");
        break;
    case INVALID_OCTAL:
        strcpy(error_message, "not a valid octal, try again");
        break;
    case INVALID_HEX:
        strcpy(error_message, "not a valid hexadecimal, try again");
        break;
    case INVALID_DECIMAL:
        strcpy(error_message, "not a valid decimal, try again");
        break;
    }
}
