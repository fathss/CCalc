#ifndef BASE_UTILS_H
#define BASE_UTILS_H

double baseCheck(char *x);
int validBase(char *x, int base);
double binary(double (*operation)(double, double));
double octal(double (*operation)(double, double));
double hexadecimal(double (*operation)(double, double));
double differentTypes(double (*operation)(double, double));
double baseToDecimal(char *x, int base);
void decimalToBase(double x, int base);

#endif