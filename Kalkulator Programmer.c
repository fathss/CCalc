#include <stdio.h>
#include <string.h>
#include <math.h>

void display(){
    puts("K A L K U L A T O R  P R O G R A M M E R");
    puts("----------------------------------------");
    puts("1. Operasi aritmatika");
    puts("2. Konversi dasar");
    puts("3. Keluar");
    printf("Pilih pilihan menu: ");
}

void aritmatika(){
    int pilihan;
    puts("A R I T M A T I K A");
    puts("-------------------");
    puts("1. Matematika");
    puts("2. Programming");
    printf("Pilih jenis operasi aritmatika: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
        case 1:
            matematika();
            break;
        case 2:
            programming();
            break;
        default:
            puts("Input salah coba lagi");
            break;
    }
}

void matematika(){
    double bil1, bil2, hasil;
    char op;
    printf("Masukkan bilangan beserta operasinya (bil1) (operator) (bil2): ");
    scanf("%lf %c %lf", &bil1, &op, &bil2);

    switch (op)
    {
        case '+':
            hasil = bil1 + bil2;
            break;
        case '-':
            hasil = bil1 - bil2;
            break;
        case '*':
            hasil = bil1 * bil2;
            break;
        case '/':
            if (bil2 == 0){
                printf("Pembagian dengan 0!\nProgram berhenti\n");
                exit(0);
            }
            hasil = bil1 / bil2;
            break;
        default:
            puts("Operator salah, coba lagi");
            matematika();
            break;
    }

    printf("Hasil: %g\n\n", hasil);
}

long long int tambah(long int a, long int b){
    return a + b;
}

long long int kurang(long int a, long int b){
    return a - b;
}

long long int kali(long int a, long int b){
    return a * b;
}

void programming(){
    int pilihan;
    long long int hasil;
    puts("1. Biner");
    puts("2. Oktal");
    puts("3. Heksadesimal");
    puts("4. Beda jenis");
    printf("Pilih tipe data untuk operasi aritmatika: ");
    scanf("%d", &pilihan);

    int operasi;
    puts("1. Penambahan");
    puts("2. Pengurangan");
    puts("3. Perkalian");
    puts("4. Pembagian");
    printf("Pilih operasi yang diingingkan: ");
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
            }
            printf("Hasil: ");
            desimalToBiner(hasil);
            puts("");
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
            }
            printf("Hasil: %o\n", hasil);
        default:
            puts("Input salah, coba lagi");
            programming();
            break;
    }
}

int arbiner(long long int (*operasi)(long long int, long long int)){
    long long int biner1, biner2;
    printf("Masukkan biner 1: ");
    scanf("%lld", &biner1);
    printf("Masukkan biner 2: ");
    scanf("%lld", &biner2);

    long int des1 = binerToDesimal(biner1);
    long int des2 = binerToDesimal(biner2);

    return operasi(des1, des2);
}

int aroktal(long long int (*operasi)(long long int, long long int)){
    long long int oktal1, oktal2;
    printf("Masukkan oktal 1: ");
    scanf("%lld", &oktal1);
    printf("Masukkan oktal 2: ");
    scanf("%lld", &oktal2);

    long int des1 = oktalToDesimal(oktal1);
    long int des2 = oktalToDesimal(oktal2);

    return operasi(des1, des2);
}

void konversi(){
    int pilihan;
    long long int desimal, biner, oktal;
    char heksa[20];
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
            scanf("%d", &desimal);
            printf("Biner        : ");
            desimalToBiner(desimal);
            printf("\nOktal        : %o\n", desimal);
            printf("Heksadesimal : %X\n\n", desimal);
            break;
        case 2:
            printf("Masukkan biner : ");
            scanf("%lld", &biner);
            printf("Desimal      : %lld\n", binerToDesimal(biner));
            printf("Oktal        : %o\n", binerToDesimal(biner));
            printf("Heksadesmial : %X\n\n", binerToDesimal(biner));
            break;
        case 3:
            printf("Masukkan Oktal : ");
            scanf("%lld", &oktal);
            printf("Desimal      : %lld\n", oktalToDesimal(oktal));
            printf("Biner        : ");
            desimalToBiner(oktalToDesimal(oktal));
            printf("\nHeksadesimal : %X\n\n", oktalToDesimal(oktal));
            break;
        case 4:
            printf("Masukkan Heksadesimal : ");
            scanf("%s", heksa);
            int valid = heksaToDesimal(heksa);
            if (valid == -1){
                printf("Input invalid, coba lagi\n");
                konversi();
                break;
            }
            else{
                printf("Desimal      : %d\n", heksaToDesimal(heksa));
                desimalToBiner(heksaToDesimal(heksa));
                printf("Oktal        : %o\n\n", heksaToDesimal(heksa));
            }
            break;
        default:
            puts("Input salah, coba lagi\n");
            konversi();
            break;
    }
}

void desimalToBiner(long long int x){
    int biner[64];
    int i = 0;
    while (x > 0){
        biner[i] = x % 2;
        x /= 2;
        i++;
    }
    for (int j = i-1; j >= 0; j--){
        printf("%d", biner[j]);
    }
}

int binerToDesimal(long long int x){
    long long int hasil = 0;
    long long int i = 0;
    while (x > 0){
        hasil += (x % 10) * pow(2, i);
        x /= 10;
        i++;
    }
    return hasil;
}

int oktalToDesimal(long long int x){
    long int hasil = 0;
    int i = 0;
    while (x > 0){
        hasil += (x % 10) * pow(8, i);
        x /= 10;
        i++;
    }
    return hasil;
}

int heksaToDesimal(char x[]){
    int hasil = 0;
    int isValid = 1;
    for (int i = 0; i < strlen(x); i++){
        if (x[i] >= 48 && x[i] <= 57){
            hasil += (x[i] - 48) * pow(16, strlen(x)-1-i);
        }
        else if (x[i] >= 65 && x[i] <= 70){
            hasil += (x[i] - 55) * pow(16, strlen(x)-1-i);
        }
        else{
            isValid = 0;
            hasil = 0;
            break;
        }
    }
    return hasil + isValid - 1;
}





main (){

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
                exit(0);
            default:
                puts("Input salah, coba lagi\n");
                break;
        }
    }while (pilihan != 3);

    return 0;
}
