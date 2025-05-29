#ifndef ERROR_MSG_H
#define ERROR_MSG_H

#include "error_type.h"

void error(ErrorType errorType);

extern char errorMessage[50];

#endif