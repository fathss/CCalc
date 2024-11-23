#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void display();
void aritmatika();
void matematika();
void programming();
double tambah(double a, double b);
double kurang(double a, double b);
double kali(double a, double b);
double bagi(double a, double b);
double arbiner(double (*operasi)(double, double));
double aroktal(double (*operasi)(double, double));
double arheksa(double (*operasi)(double, double));
double arbeda(double (*operasi)(double, double));
void konversi();
double baseToDecimal(char *x, int base);
void decimalToBase(double x, int base);

int main (){
    int pilihan;
    do
    {
        display();
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
                aritmatika();
                break;
            case 2:
                konversi();
                break;
            case 3:
                puts("Keluar");
                return 0;
            default:
                puts("Input salah, coba lagi\n");
                break;
        }
    }while (pilihan != 3);

    return 0;
}

void display(){
    puts("K A L K U L A T O R  P R O G R A M M E R");
    puts("----------------------------------------");
    puts("1. Operasi aritmatika");
    puts("2. Konversi dasar");
    puts("3. Keluar");
    printf("Pilih pilihan menu: ");
}

void aritmatika(){
    int pilihan, run = 1;
    do
    {
        puts("\nA R I T M A T I K A");
        puts("-------------------");
        puts("1. Matematika");
        puts("2. Programming");
        printf("Pilih jenis operasi aritmatika: ");
        scanf("%d", &pilihan);


        switch (pilihan)
        {
            case 1:
                matematika();
                run = 0;
                break;
            case 2:
                programming();
                run = 0;
                break;
            default:
                puts("Input salah coba lagi\n");
                break;
        }
    } while (run);
}

void matematika(){
    int run = 1;
    double bil1, bil2, hasil;
    char op;
    do
    {
        printf("Masukkan bilangan beserta operasinya (bil1) (operator) (bil2): ");
        scanf("%lf %c %lf", &bil1, &op, &bil2);

        switch (op)
        {
            case '+':
                hasil = bil1 + bil2;
                run = 0;
                break;
            case '-':
                hasil = bil1 - bil2;
                run = 0;
                break;
            case '*':
                hasil = bil1 * bil2;
                run = 0;
                break;
            case '/':
                if (bil2 == 0){
                    printf("Pembagian dengan 0!\nProgram berhenti\n");
                    exit(0);
                }
                hasil = bil1 / bil2;
                run = 0;
                break;
            default:
                puts("Operator salah, coba lagi");
                break;
        }
    } while (run);

    printf("Hasil: %g\n\n", hasil);
}

void programming(){
    int pilihan, run = 1;
    double hasil;
    do
    {
        puts("1. Biner");
        puts("2. Oktal");
        puts("3. Heksadesimal");
        puts("4. Beda jenis");
        printf("Pilih tipe data untuk operasi aritmatika: ");
        scanf("%d", &pilihan);

        if (pilihan < 1 || pilihan > 4){
            printf("Input salah, coba lagi\n\n");
            continue;
        }

        int operasi;
        puts("1. Penambahan");
        puts("2. Pengurangan");
        puts("3. Perkalian");
        puts("4. Pembagian");
        printf("Pilih operasi yang diinginkan: ");
        scanf("%d", &operasi);

        switch (pilihan)
        {
            case 1:
                switch (operasi)
                {
                    case 1:
                        hasil = arbiner(tambah);
                        break;
                    case 2:
                        hasil = arbiner(kurang);
                        break;
                    case 3:
                        hasil = arbiner(kali);
                        break;
                    case 4:
                        hasil = arbiner(bagi);
                        break;
                }
                run = 0;
                break;
            case 2:
                switch (operasi)
                {
                    case 1:
                        hasil = aroktal(tambah);
                        break;
                    case 2:
                        hasil = aroktal(kurang);
                        break;
                    case 3:
                        hasil = aroktal(kali);
                        break;
                    case 4:
                        hasil = aroktal(bagi);
                        break;
                }
                run = 0;
                break;

            case 3:
                switch (operasi)
                {
                    case 1:
                        hasil = arheksa(tambah);
                        break;
                    case 2:
                        hasil = arheksa(kurang);
                        break;
                    case 3:
                        hasil = arheksa(kali);
                        break;
                    case 4:
                        hasil = arheksa(bagi);
                        break;
                }
                run = 0;
                break;

            case 4:
                switch (operasi)
                {
                    case 1:
                        hasil = arbeda(tambah);
                        break;
                    case 2:
                        hasil = arbeda(kurang);
                        break;
                    case 3:
                        hasil = arbeda(kali);
                        break;
                    case 4:
                        hasil = arbeda(bagi);
                        break;
                }
                run = 0;
                break;

            default:
                puts("Input salah, coba lagi");
                break;
        }
    } while (run);
    printf("\nBiner        : ");
    decimalToBase(hasil, 2);
    printf("\nDesimal      : %g", hasil);
    printf("\nOktal        : ");
    decimalToBase(hasil, 8);
    printf("\nHeksadesimal : ");
    decimalToBase(hasil, 16);
    puts("\n");
}

double tambah(double a, double b){
    return a + b;
}

double kurang(double a, double b){
    return a - b;
}

double kali(double a, double b){
    return a * b;
}

double bagi(double a, double b){
    return a / b;
}

double arbiner(double (*operasi)(double, double)){
    char biner1[32], biner2[32];
    printf("Masukkan biner 1: ");
    scanf("%s", biner1);
    printf("Masukkan biner 2: ");
    scanf("%s", biner2);

    double des1 = strtol(biner1, NULL, 2);
    double des2 = strtol(biner2, NULL, 2);

    return operasi(des1, des2);
}

double aroktal(double (*operasi)(double, double)){
    char oktal1[32], oktal2[32];
    printf("Masukkan oktal 1: ");
    scanf("%s", oktal1);
    printf("Masukkan oktal 2: ");
    scanf("%s", oktal2);

    double des1 = strtol(oktal1, NULL, 8);
    double des2 = strtol(oktal2, NULL, 8);

    return operasi(des1, des2);
}

double arheksa(double (*operasi)(double, double)){
    char heksa1[32], heksa2[32];
    printf("Masukkan oktal 1: ");
    scanf("%s", heksa1);
    printf("Masukkan oktal 2: ");
    scanf("%s", heksa2);

    double des1 = strtol(heksa1, NULL, 16);
    double des2 = strtol(heksa2, NULL, 16);

    return operasi(des1, des2);
}

double arbeda(double (*operasi)(double, double)) {
    char input1[32], input2[32];
    double des1, des2;
    puts("HATI-HATI!\nIKUTI ATURAN DIBAWAH");
    puts("Awalan Biner   : 0b || 0B");
    puts("Awalan Oktal   : 0");
    puts("Awalan Heksa   : 0x || 0X");
    puts("Awalan Desimal : Tanpa awalan");

    printf("Masukkan input ke 1: ");
    scanf("%s", input1);
    char *input1ptr = input1;

    if (strncmp(input1, "0b", 2) == 0 || strncmp(input1, "0B", 2) == 0){
        input1ptr += 2;
        des1 = strtol(input1ptr, NULL, 2); // Biner
    } else if (strncmp(input1, "0x", 2) == 0 || strncmp(input1, "0X", 2) == 0){
        input1ptr += 2;
        des1 = strtol(input1ptr, NULL, 16); // Heksa
    } else if (input1[0] == '0'){
        input1ptr++;
        des1 = strtol(input1ptr, NULL, 8); // Oktal
    } else{
        des1 = strtol(input1ptr, NULL, 10); // Desimal
    }

    printf("Masukkan input ke 2: ");
    scanf("%s", input2);
    char *input2ptr = input2;

    if (strncmp(input2, "0b", 2) == 0 || strncmp(input2, "0B", 2) == 0){
        input2ptr += 2;
        des2 = strtol(input2ptr, NULL, 2);
    } else if (strncmp(input2, "0x", 2) == 0 || strncmp(input2, "0X", 2) == 0){
        input2ptr += 2;
        des2 = strtol(input2ptr, NULL, 16);
    } else if (input2[0] == '0'){
        input2ptr++;
        des2 = strtol(input2ptr, NULL, 8);
    } else{
        des2 = strtol(input2ptr, NULL, 10);
    }

    return operasi(des1, des2);
}

void konversi(){
    int pilihan;
    char desimal[32], biner[32], oktal[32], heksa[32];
    double des;
    puts("\nKONVERSI DASAR");
    puts("----------------");
    puts("1. Desimal");
    puts("2. Biner");
    puts("3. Oktal");
    puts("4. Heksadesimal");
    printf("Pilih tipe awal: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
        case 1:
            printf("Masukkan desimal : ");
            scanf("%s", desimal);
            des = strtod(desimal, NULL);
            printf("Biner        : ");
            decimalToBase(des, 2);
            printf("\nOktal        : ");
            decimalToBase(des, 8);
            printf("\nHeksadesimal : ");
            decimalToBase(des, 16);
            puts("\n");
            break;
        case 2:
            printf("Masukkan biner : ");
            scanf("%s", biner);
            des = baseToDecimal(biner, 2);
            printf("Desimal        : %g", des);
            printf("\nOktal          : ");
            decimalToBase(des, 8);
            printf("\nHeksadesimal   : ");
            decimalToBase(des, 16);
            puts("\n");
            break;
        case 3:
            printf("Masukkan oktal : ");
            scanf("%s", oktal);
            des = baseToDecimal(oktal, 8);
            printf("Desimal        : %g", des);
            printf("\nBiner          : ");
            decimalToBase(des, 2);
            printf("\nHeksadesimal   : ");
            decimalToBase(des, 16);
            puts("\n");
            break;
        case 4:
            printf("Masukkan Heksa : ");
            scanf("%s", heksa);
            des = baseToDecimal(heksa, 16);
            printf("Desimal        : %g", des);
            printf("\nBiner          : ");
            decimalToBase(des, 2);
            printf("\nOktal          : ");
            decimalToBase(des, 8);
            puts("\n");
            break;
        default:
            puts("Input salah, coba lagi\n");
            konversi();
            break;
    }
}

double baseToDecimal(char *x, int base){
    double des = 0.0, pecahan = 0.0;
    char *dot = strstr(x, ".");

    if (!dot) {
        dot = x + strlen(x);
    }

    // Sebelum titik
    int index = dot - x - 1;
    int value;
    for (int i = 0; *(x + i) != '.' && *(x + i) != '\0'; i++){
        if (*(x + i) > '9'){
            value = *(x + i) - 55;
        } else{
            value = *(x + i) - '0';
        }
        des += value * pow(base, index - i);
    }

    // Setelah titik
    if (*(dot) != '\0') {
        dot++;
        for (int i = 1; *dot != '\0'; i++, dot++){
            if (*dot > '9'){
                value = *dot - 55;
            } else{
                value = *dot - '0';
            }
            pecahan += value * pow(base, -i);
        }
    }

    des += pecahan;
    return des;
}

void decimalToBase(double x, int base){
    char hasilInt[65], hasilFloat[65];
    char digit[] = "0123456789ABCDEF";
    int index = 0;
    long bagianInt = (long)x;
    double bagianFloat = x - bagianInt;

    if (bagianInt == 0) {
        hasilInt[index] = '0';
        index++;
    } else {
        while (bagianInt > 0) {
            hasilInt[index] = digit[bagianInt % base];
            bagianInt /= base;
            index++;
        }
    }
    hasilInt[index] = '\0';

    for (int i = index-1; i >= 0; i--){
        putchar(hasilInt[i]);
    }

    // Cek apakah desimal pecahan
    if (bagianFloat == 0){
        return;
    }
    else{
        index = 0;
        while (bagianFloat > 0){
            bagianFloat *= base;
            int desimal = (int)bagianFloat;
            hasilFloat[index++] = digit[desimal];
            bagianFloat -= desimal;
        }
        hasilFloat[index] = '\0';

        printf(".");
        for (int i = 0; i < index; i++){
            putchar(hasilFloat[i]);
        }
    }
}
