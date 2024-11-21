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

void konversi(){
    int pilihan, desimal, biner, oktal;
    char heksa[20];
    puts("\nKONVERSI DASAR");
    puts("----------------");
    puts("1. Desimal");
    puts("2. Biner");
    puts("3. Oktal");
    puts("4. Heksadesimal");
    puts("5. Desimal Negatif");
    printf("Pilih tipe awal: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
        case 1:
            printf("Masukkan desimal : ");
            scanf("%d", &desimal);
            desimalToBiner(desimal);
            printf("Oktal        : %o\n", desimal);
            printf("Heksadesimal : %X\n\n", desimal);
            break;
        case 2:
            printf("Masukkan biner : ");
            scanf("%d", &biner);
            printf("Desimal      : %d\n", binerToDesimal(biner));
            printf("Oktal        : %o\n", binerToDesimal(biner));
            printf("Heksadesmial : %X\n\n", binerToDesimal(biner));
            break;
        case 3:
            printf("Masukkan Oktal : ");
            scanf("%d", &oktal);
            printf("Desimal      : %d\n", oktalToDesimal(oktal));
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
        case 5:
            printf("Masukkan desimal negatif : ");
            scanf("%d", &desimal);
            desimal *= -1;
            negatif(desimal);
            break;
        default:
            puts("Input salah, coba lagi\n");
            konversi();
            break;
    }
}

void desimalToBiner(long int x){
    int biner[20];
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
    long int hasil = 0;
    int i = 0;
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

long int tambah(long int a, long int b){
    return a + b;
}

long int kurang(long int a, long int b){
    return a - b;
}

long int kali(long int a, long int b){
    return a * b;
}

void programming(){
    int pilihan;
    long int hasil;
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
    }
}

int arbiner(long int (*operasi)(long long int, long long int)){
    long long int biner1, biner2;
    printf("Masukkan biner 1: ");
    scanf("%lld", &biner1);
    printf("Masukkan biner 2: ");
    scanf("%lld", &biner2);

    long int des1 = binerToDesimal(biner1);
    long int des2 = binerToDesimal(biner2);

    return operasi(des1, des2);
}

int aroktal(long int (*operasi)(long long int, long long int)){
    long long int oktal1, oktal2;
    printf("Masukkan oktal 1: ");
    scanf("%lld", &oktal1);
    printf("Masukkan oktal 2: ");
    scanf("%lld", &oktal2);

    long int des1 = oktalToDesimal(oktal1);
    long int des2 = oktalToDesimal(oktal2);

    return operasi(des1, des2);
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
