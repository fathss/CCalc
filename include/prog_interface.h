#ifndef PROG_INTERFACE_H
#define PROG_INTERFACE_H

double binary(double (*operation)(double, double));
double octal(double (*operation)(double, double));
double hexadecimal(double (*operation)(double, double));
double differentTypes(double (*operation)(double, double));

void progInterface();

#endif