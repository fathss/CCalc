#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function Prototypes
void display();
void arithmetic();
void conversion();
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
double typecheck(char *x);
int validcheck(char *x, int base);
double baseToDecimal(char *x, int base);
void decimalToBase(double x, int base);

int main (){
    int choice;
    while(1){
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
    }

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
    int choice;
    while(1){
        puts("\nA R I T H M E T I C");
        puts("-------------------");
        puts("1. Mathematics");
        puts("2. Programming");
        printf("Choose arithmetic operation type: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 2){
            printf("Invalid Input try again\n");
            continue;
        } else if (choice == 1){
            mathematics();
            break;
        } else if (choice == 2){
            programming();
            break;
        }
    }
}

void mathematics(){
    double result, num1, num2;
    char op;
    while(1){
        printf("Enter numbers and operation (num1) (operator) (num2): ");
        scanf("%lf %c %lf", &num1, &op, &num2);

        if (op == '+'){
            result = add(num1, num2);
        } else if (op == '-'){
            result = subtract(num1, num2);
        } else if (op == '*'){
            result = multiply(num1, num2);
        } else if (op == '/'){
            result = divide(num1, num2);
        } else{
            puts("Invalid operator, try again\n");
            continue;
        }
        printf("Result: %g\n\n", result);
        break;
    }
}

void programming(){
    double result;

    while(1){
        int choice;
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

        if (operation < 1 || operation > 4){
            printf("Invalid input, try again\n\n");
            continue;
        }

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
                break;
        }
        if (result < 0) continue;
        printf("\nBinary       : ");
        decimalToBase(result, 2);
        printf("\nDecimal      : %g", result);
        printf("\nOctal        : ");
        decimalToBase(result, 8);
        printf("\nHexadecimal  : ");
        decimalToBase(result, 16);
        puts("\n");
        break;
    }
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

    if(!validcheck(binary1, 2)){
        printf("Input invalid, try again");
        return -1;
    }

    printf("Enter binary 2: ");
    scanf("%s", binary2);

    if(!validcheck(binary2  , 2)){
        printf("Input invalid, try again");
        return -1;
    }

    double dec1 = baseToDecimal(binary1, 2);
    double dec2 = baseToDecimal(binary2, 2);

    return operation(dec1, dec2);
}

double octal(double (*operation)(double, double)){
    char octal1[32], octal2[32];

    printf("Enter octal 1: ");
    scanf("%s", octal1);

    if(!validcheck(octal1, 8)){
        printf("Input invalid, try again");
        return -1;
    }

    printf("Enter octal 2: ");
    scanf("%s", octal2);

    if(!validcheck(octal2, 8)){
        printf("Input invalid, try again");
        return -1;
    }

    double dec1 = baseToDecimal(octal1, 8);
    double dec2 = baseToDecimal(octal2, 8);

    return operation(dec1, dec2);
}

double hexadecimal(double (*operation)(double, double)){
    char hex1[32], hex2[32];

    printf("Enter hex 1: ");
    scanf("%s", hex1);

    if(!validcheck(hex1, 16)){
        printf("Input invalid, try again");
        return -1;
    }

    printf("Enter hex 2: ");
    scanf("%s", hex2);

    if(!validcheck(hex2, 16)){
        printf("Input invalid, try again");
        return -1;
    }

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

    dec1 = typecheck(input);
    if (dec1 < 0){
        printf("Input invalid, try again\n");
        return -1;
    }

    printf("Enter input 2: ");
    scanf("%s", input);

    dec2 = typecheck(input);
    if (dec2 < 0){
        printf("Input invalid, try again\n");
        return -1;
    }

    return operation(dec1, dec2);
}

double typecheck(char *x){
    if (strncmp(x, "0b", 2) == 0 || strncmp(x, "0B", 2) == 0){  // Binary
        x += 2;
        if (!validcheck(x, 2)) return -1;
        return baseToDecimal(x, 2);
    } else if (strncmp(x, "0x", 2) == 0 || strncmp(x, "0X", 2) == 0){  // Hexadecimal
        x += 2;
        if (!validcheck(x, 16)) return -1;
        return baseToDecimal(x, 16);
    } else if (x[0] == '0'){  // Octal
        x++;
        if (!validcheck(x, 8)) return -1;
        return baseToDecimal(x, 8);
    } else{  // Decimal
        if (!validcheck(x, 10)) return -1;
        return strtod(x, NULL);
    }
}

int validcheck(char *x, int base){
    switch (base)
    {
        case 2:
            for (char *i = x; *i != '\0'; i++){
                if (isdigit(*i) && *i >= '0' && *i <= '1'){
                    continue;
                } else{
                    return 0;
                }
            }
            break;

        case 8:
            for (char *i = x; *i != '\0'; i++){
                if (isdigit(*i) && *i >= '0' && *i <= '7'){
                    continue;
                } else{
                    return 0;
                }
            }
            break;

        case 10:
            for (char *i = x; *i != '\0'; i++){
                if (isdigit(*i)){
                    continue;
                } else{
                    return 0;
                }
            }
            break;

        case 16:
            for (char *i = x; *i != '\0'; i++){
                if (*i >= '0' && *i <= '9' || *i >= 'A' && *i <= 'F'){
                    continue;
                } else{
                    return 0;
                }
            }
            break;
    }
    return 1;
}

void conversion(){

    double dec;
    while(1){
        int choice;
        char decimal[32], binary[32], octal[32], hexadecimal[32];
        puts("\nBASE CONVERSION");
        puts("----------------");
        puts("1. Decimal");
        puts("2. Binary");
        puts("3. Octal");
        puts("4. Hexadecimal");
        printf("Choose starting type: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4){
            printf("Input invalid, try again\n");
            continue;
        } else if (choice == 1){
            printf("Enter decimal : ");
            scanf("%s", decimal);
            if (!validcheck(decimal, 10)){
                printf("Input invalid, try again\n");
                continue;
            }

            dec = strtod(decimal, NULL);
            printf("Binary        : ");
            decimalToBase(dec, 2);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
        } else if (choice == 2){
            printf("Enter binary : ");
            scanf("%s", binary);
            if (!validcheck(binary, 2)){
                printf("Input invalid, try again\n");
                continue;
            }

            dec = baseToDecimal(binary, 2);
            printf("Decimal       : %g", dec);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
        } else if (choice == 3){
            printf("Enter octal : ");
            scanf("%s", octal);
            if (!validcheck(octal, 8)){
                printf("Input invalid, try again\n");
                continue;
            }

            dec = baseToDecimal(octal, 8);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimalToBase(dec, 2);
            printf("\nHexadecimal   : ");
            decimalToBase(dec, 16);
            puts("\n");
        } else if (choice == 4){
            printf("Enter Hexadecimal : ");
            scanf("%s", hexadecimal);
            if (!validcheck(hexadecimal, 16)){
                printf("Input invalid, try again\n");
                continue;
            }

            dec = baseToDecimal(hexadecimal, 16);
            printf("Decimal       : %g", dec);
            printf("\nBinary        : ");
            decimalToBase(dec, 2);
            printf("\nOctal         : ");
            decimalToBase(dec, 8);
            puts("\n");
        }
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
    unsigned long long intPart = (unsigned long long)x;
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
