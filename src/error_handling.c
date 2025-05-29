#include <stdio.h>
#include <string.h>
#include "error_handling.h"

char errorMessage[50];

void error(ErrorType errorType)
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
