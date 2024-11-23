#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void display();
void arithmetic();
void mathematics();
void programming();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double binary(double (*operation)(double, double));
double octal(double (*operation)(double, double));
double hexadecimal(double (*operation)(double, double));
double differentTypes(double (*operation)(double, double));
void conversion();
double baseToDecimal(char *x, int base);
void decimalToBase(double x, int base);

int main (){
    int choice;
    do
    {
        display();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                arithmetic();
                break;
            case 2:
                conversion();
                break;
            case 3:
                puts("Exit");
                return 0;
            default:
                puts("Invalid input, try again\n");
                break;
        }
    }while (choice != 3);

    return 0;
}

void display(){
    puts("P R O G R A M M I N G  C A L C U L A T O R");
    puts("----------------------------------------");
    puts("1. Arithmetic operations");
    puts("2. Base conversion");
    puts("3. Exit");
    printf("Choose a menu option: ");
}

void arithmetic(){
    int choice, run = 1;
    do
    {
        puts("\nA R I T H M E T I C");
        puts("-------------------");
        puts("1. Mathematics");
        puts("2. Programming");
        printf("Choose arithmetic operation type: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
                mathematics();
                run = 0;
                break;
            case 2:
                programming();
                run = 0;
                break;
            default:
                puts("Invalid input, try again\n");
                break;
        }
    } while (run);
}

void mathematics(){
    int run = 1;
    double num1, num2, result;
    char op;
    do
    {
        printf("Enter numbers and operation (num1) (operator) (num2): ");
        scanf("%lf %c %lf", &num1, &op, &num2);

        switch (op)
        {
            case '+':
                result = num1 + num2;
                run = 0;
                break;
            case '-':
                result = num1 - num2;
                run = 0;
                break;
            case '*':
                result = num1 * num2;
                run = 0;
                break;
            case '/':
                if (num2 == 0){
                    printf("Division by 0!\nProgram will stop\n");
                    exit(0);
                }
                result = num1 / num2;
                run = 0;
                break;
            default:
                puts("Invalid operator, try again");
                break;
        }
    } while (run);

    printf("Result: %g\n\n", result);
}

void programming(){
    int choice, run = 1;
    double result;
    do
    {
        puts("1. Binary");
        puts("2. Octal");
        puts("3. Hexadecimal");
        puts("4. Different types");
        printf("Choose data type for arithmetic operation: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 4){
            printf("Invalid input, try again\n\n");
            continue;
        }

        int operation;
        puts("1. Addition");
        puts("2. Subtraction");
        puts("3. Multiplication");
        puts("4. Division");
        printf("Choose desired operation: ");
        scanf("%d", &operation);

        switch (choice)
        {
            case 1:
                switch (operation)
                {
                    case 1:
                        result = binary(add);
                        break;
                    case 2:
                        result = binary(subtract);
                        break;
                    case 3:
                        result = binary(multiply);
                        break;
                    case 4:
                        result = binary(divide);
                        break;
                }
                run = 0;
                break;
            case 2:
                switch (operation)
                {
                    case 1:
                        result = octal(add);
                        break;
                    case 2:
                        result = octal(subtract);
                        break;
                    case 3:
                        result = octal(multiply);
                        break;
                    case 4:
                        result = octal(divide);
                        break;
                }
                run = 0;
                break;

            case 3:
                switch (operation)
                {
                    case 1:
                        result = hexadecimal(add);
                        break;
                    case 2:
                        result = hexadecimal(subtract);
                        break;
                    case 3:
                        result = hexadecimal(multiply);
                        break;
                    case 4:
                        result = hexadecimal(divide);
                        break;
                }
                run = 0;
                break;

            case 4:
                switch (operation)
                {
                    case 1:
                        result = differentTypes(add);
                        break;
                    case 2:
                        result = differentTypes(subtract);
                        break;
                    case 3:
                        result = differentTypes(multiply);
                        break;
                    case 4:
                        result = differentTypes(divide);
                        break;
                }
                run = 0;
                break;

            default:
                puts("Invalid input, try again");
                break;
        }
    } while (run);
    printf("\nBinary       : ");
    decimalToBase(result, 2);
    printf("\nDecimal      : %g", result);
    printf("\nOctal        : ");
    decimalToBase(result, 8);
    printf("\nHexadecimal  : ");
    decimalToBase(result, 16);
    puts("\n");
}

double add(double a, double b){
    return a + b;
}

double subtract(double a, double b){
    return a - b;
}

double multiply(double a, double b){
    return a * b;
}

double divide(double a, double b){
    return a / b;
}

double binary(double (*operation)(double, double)){
    char binary1[32], binary2[32];
    printf("Enter binary 1: ");
    scanf("%s", binary1);
    printf("Enter binary 2: ");
    scanf("%s", binary2);

    double dec1 = baseToDecimal(binary1, 2);
    double dec2 = baseToDecimal(binary2, 2);

    return operation(dec1, dec2);
}

double octal(double (*operation)(double, double)){
    char octal1[32], octal2[32];
    printf("Enter octal 1: ");
    scanf("%s", octal1);
    printf("Enter octal 2: ");
    scanf("%s", octal2);

    double dec1 = baseToDecimal(octal1, 8);
    double dec2 = baseToDecimal(octal2, 8);

    return operation(dec1, dec2);
}

double hexadecimal(double (*operation)(double, double)){
    char hex1[32], hex2[32];
    printf("Enter octal 1: ");
    scanf("%s", hex1);
    printf("Enter octal 2: ");
    scanf("%s", hex2);

    double dec1 = baseToDecimal(hex1, 16);
    double dec2 = baseToDecimal(hex2, 16);

    return operation(dec1, dec2);
}

double differentTypes(double (*operation)(double, double)) {
    char input[32];
    double dec1, dec2;
    puts("CAUTION!\nFOLLOW THE RULES BELOW");
    puts("Binary Prefix   : 0b || 0B");
    puts("Octal Prefix    : 0");
    puts("Hexadecimal Prefix : 0x || 0X");
    puts("Decimal Prefix  : No prefix");

    printf("Enter input 1: ");
    scanf("%s", input);
    char *ptr = input;

    if (strncmp(input, "0b", 2) == 0 || strncmp(input, "0B", 2) == 0){
        ptr += 2;
        dec1 = baseToDecimal(ptr, 2); // Binary
    } else if (strncmp(input, "0x", 2) == 0 || strncmp(input, "0X", 2) == 0){
        ptr += 2;
        dec1 = baseToDecimal(ptr, 16); // Hexadecimal
    } else if (input[0] == '0'){
        ptr++;
        dec1 = baseToDecimal(ptr, 8); // Octal
    } else{
        dec1 = strtod(ptr, NULL); // Decimal
    }

    printf("Enter input 2: ");
    scanf("%s", input);
    ptr = input;

    if (strncmp(input, "0b", 2) == 0 || strncmp(input, "0B", 2) == 0){
        ptr += 2;
        dec1 = baseToDecimal(ptr, 2); // Binary
    } else if (strncmp(input, "0x", 2) == 0 || strncmp(input, "0X", 2) == 0){
        ptr += 2;
        dec1 = baseToDecimal(ptr, 16); // Hexadecimal
    } else if (input[0] == '0'){
        ptr++;
        dec1 = baseToDecimal(ptr, 8); // Octal
    } else{
        dec1 = strtod(ptr, NULL); // Decimal
    }

    return operation(dec1, dec2);
}

void conversion(){
    int choice;
    char decimal[32], binary[32], octal[32], hexadecimal[32];
    double dec;
    puts("\nBASE CONVERSION");
    puts("----------------");
    puts("1. Decimal");
    puts("2. Binary");
    puts("3. Octal");
    puts("4. Hexadecimal");
    printf("Choose starting type: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter decimal : ");
            scanf("%s", decimal);
            dec = strtod(decimal, NULL);
            printf("Binary        : ");
            decimalToBase(dec, 2);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
            break;
        case 2:
            printf("Enter binary : ");
            scanf("%s", binary);
            dec = baseToDecimal(binary, 2);
            printf("Decimal       : %g", dec);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
            break;
        case 3:
            printf("Enter octal : ");
            scanf("%s", octal);
            dec = baseToDecimal(octal, 8);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimalToBase(dec, 2);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
            break;
        case 4:
            printf("Enter Hexadecimal : ");
            scanf("%s", hexadecimal);
            dec = baseToDecimal(hexadecimal, 16);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimalToBase(dec, 2);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            puts("\n");
            break;
        default:
            puts("Invalid input, try again\n");
            conversion();
            break;
    }
}

double baseToDecimal(char *x, int base){
    double dec = 0.0, fraction = 0.0;
    char *dot = strstr(x, ".");

    if (!dot) {
        dot = x + strlen(x);
    }

    // Before the dot
    int index = dot - x - 1;
    int value;
    for (int i = 0; *(x + i) != '.' && *(x + i) != '\0'; i++){
        if (*(x + i) > '9'){
            value = *(x + i) - 55;
        } else{
            value = *(x + i) - '0';
        }
        dec += value * pow(base, index - i);
    }

    // After the dot
    if (*(dot) != '\0') {
        dot++;
        for (int i = 1; *dot != '\0'; i++, dot++){
            if (*dot > '9'){
                value = *dot - 55;
            } else{
                value = *dot - '0';
            }
            fraction += value * pow(base, -i);
        }
    }

    dec += fraction;
    return dec;
}

void decimalToBase(double x, int base){
    char intResult[65], floatResult[65];
    char digits[] = "0123456789ABCDEF";
    int index = 0;
    long intPart = (long)x;
    double floatPart = x - intPart;

    if (intPart == 0) {
        intResult[index] = '0';
        index++;
    } else {
        while (intPart > 0) {
            intResult[index] = digits[intPart % base];
            intPart /= base;
            index++;
        }
    }
    intResult[index] = '\0';

    for (int i = index-1; i >= 0; i--){
        printf("%c", intResult[i]);
    }

    // Check if decimal part exists
    if (floatPart == 0){
        return;
    }
    else{
        index = 0;
        while (floatPart > 0){
            floatPart *= base;
            int decimal = (int)floatPart;
            floatResult[index++] = digits[decimal];
            floatPart -= decimal;
        }
        floatResult[index] = '\0';

        printf(".");
        for (int i = 0; i < index; i++){
            printf("%c", floatResult[i]);
        }
    }
}
