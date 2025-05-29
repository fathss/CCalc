#ifndef BASE_UTILS_H
#define BASE_UTILS_H

double base_check(char *input);
int valid_base(char *input, int base);
double base_to_decimal(char *input, int base);
void decimal_to_base(double input_decimal, int base);

#endif