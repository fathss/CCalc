#ifndef ERROR_MSG_H
#define ERROR_MSG_H

// Enumeration for error types. Allows for easy identification of specific errors.
typedef enum
{
    // Used to indicate that the input does not start with a valid prefix. This could be due to missing or incorrect prefix input like "0b", "0x", etc.
    INVALID_PREFIX,
    // Used to indicate that the input is not a valid number. This could be due to incorrect format or characters.
    INVALID_NUMBER,
    // Used to indicate that the input operator is not valid. This could be due to unsupported operations or incorrect operator input.
    INVALID_OPERATOR,
    // Used to indicate that the input is out of the expected range. This could be due to numerical limits or constraints.
    INPUT_OUT_OF_RANGE,
    // Used to indicate that a division operation was attempted with a divisor of zero, which is mathematically undefined.
    DIVISION_BY_ZERO,
    // Used to indicate that the input is not a valid binary number.
    INVALID_BINARY,
    // Used to indicate that the input is not a valid octal number.
    INVALID_OCTAL,
    // Used to indicate that the input is not a valid hex number.
    INVALID_HEX,
    // Used to indicate that the input is not a valid decimal number.
    INVALID_DECIMAL
} ErrorType;

void error(ErrorType error_type);

extern char error_message[50];

#endif