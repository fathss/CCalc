#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "base_utils.h"
#include "error_handling.h"

// A global error message that can be used to store the error message based on the error type.
char error_message[50];

// Error handling function to set the global error message based on the error type.
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