#include <stdio.h>
#include <string.h>
#include <math.h>

void display();
void operasiMTK();
void konversi();
void desimalToBiner (int x);
int binerToDesimal (int x);
int oktalToDesimal (int x);
int heksaToDesimal (char x[]);
void negatif (int x);

main (){

    int pilihan;
    do
    {
        display();
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
                operasiMTK();
                break;
            case 2:
                konversi();
                break;
            case 3:
                puts("Keluar");
                break;
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
    puts("1. Operasi matematika");
    puts("2. Konversi dasar");
    puts("3. Keluar");
    printf("Pilih pilihan menu: ");
}

void operasiMTK(){
    int pilihan;
    float bil1, bil2;
    puts("\nOPERASI MATEMATIKA");
    puts("--------------------");
    puts("1. Penjumlahan");
    puts("2. Pengurangan");
    puts("3. Perkalian");
    puts("4. Pembagian");
    puts("5. Sisa pembagian");
    printf("Pilih pilihan menu: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
        case 1:
            printf("Masukkan dua bilangan (bil1 bil2): ");
            scanf("%f %f", &bil1, &bil2);
            printf("Hasil penjumlahan %.f + %.f: %.f\n\n", bil1, bil2, bil1+bil2);
            break;
        case 2:
            printf("Masukkan dua bilangan (bil1 bil2): ");
            scanf("%f %f", &bil1, &bil2);
            printf("Hasil pengurangan %.f - %.f: %.f\n\n", bil1, bil2, bil1-bil2);
            break;
        case 3:
            printf("Masukkan dua bilangan (bil1 bil2): ");
            scanf("%f %f", &bil1, &bil2);
            printf("Hasil perkalian %.f x %.f: %.f\n\n", bil1, bil2, bil1*bil2);
            break;
        case 4:
            printf("Masukkan dua bilangan (bil1 bil2): ");
            scanf("%f %f", &bil1, &bil2);
            printf("Hasil pembagian %.f / %.f: %.f\n\n", bil1, bil2, bil1/bil2);
            break;
        default:
            puts("Input salah, coba lagi\n");
            operasiMTK();
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
            desimalToBiner(oktalToDesimal(oktal));
            printf("Heksadesimal : %X\n\n", oktalToDesimal(oktal));
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

void desimalToBiner(int x){
    printf("Biner        : ");
    int biner[32];
    int i = 0;
    while (x > 0){
        biner[i] = x % 2;
        x /= 2;
        i++;
    }
    for (int j = i-1; j >= 0; j--){
        printf("%d", biner[j]);
    }
    puts("");
}

int binerToDesimal(int x){
    int hasil = 0;
    int i = 0;
    while (x > 0){
        hasil += (x % 10) * pow(2, i);
        x /= 10;
        i++;
    }
    return hasil;
}

int oktalToDesimal(int x){
    int hasil = 0;
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

void negatif(int x){
    printf("Biner            : ");
    int biner[32];
    int i = 0;
    while (x > 0){
        biner[i] = x % 2;
        x /= 2;
        i++;
    }

    for (i = 31; i >= 0; i--){
        if (biner[i] == 1) printf("0");
        else printf("1");
    }
}
