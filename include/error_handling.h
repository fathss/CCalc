#ifndef ERROR_MSG_H
#define ERROR_MSG_H

typedef enum
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
} ErrorType;

void error(ErrorType errorType);

extern char errorMessage[50];

#endif