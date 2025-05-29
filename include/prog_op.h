#ifndef PROG_OP_H
#define PROG_OP_H

double prog_op(int choice, int operation);
double binary(double (*operation)(double, double));
double octal(double (*operation)(double, double));
double hexadecimal(double (*operation)(double, double));
double different_types(double (*operation)(double, double));

// Operations

#endif