#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int validasi();
void akhir();
void menu();

void seedArray(int arr[], int n) {
    int i;
    srand(0);
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("-Angka ke-%d : %d", i, arr[i]);
        printf("\n");
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void swap(int * i1, int * i2) {
    int temp = * i1;
    * i1 = * i2;
    * i2 = temp;
}

void bubbleSortPointer(int arr[], int n) {
    int i, a;
    for (i = 0; i < n - 1; i++) {
        int flag = 0;
        for (a = 0; a < n - 1 - i; a++) {
            if (arr[a] > arr[a + 1]) {
                swap( & arr[a], & arr[a + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

float countBubbleSort(int arr[], int n) {
    clock_t waktu = clock();
    bubbleSort(arr, n);
    waktu = clock() - waktu;
    float waktu_dibutuhkan = (float)(waktu) / CLOCKS_PER_SEC;
}

float countBubbleSortPointer(int arr[], int n) {
    clock_t waktu = clock();
    bubbleSortPointer(arr, n);
    waktu = clock() - waktu;
    float waktu_dibutuhkan = (float)(waktu) / CLOCKS_PER_SEC;
}

void menu() {
    int pilihan;
    int cek;
    int n;
    char d;
    char checkchar;


    printf("|==========[ MENU BUBBLE SORTING ]===========|\n");
    printf("|============================================|\n");
    printf("|          This Program Created By :  	     |\n");
    printf("|                KELOMPOK 13         	     |\n");
    printf("|============================================|\n");
    printf("|1. 1000 Angka                               |\n");
    printf("|2. 16000 Angka             	             |\n");
    printf("|3. 64000 Angka                              |\n");
    printf("|============================================|\n");
    printf("Masukkan sesuai dengan menu di atas = ");
    pilihan = validasi();
    if (pilihan) {
        switch (pilihan) {
            case 1:
                n = 1000;
                break;
            case 2:
                n = 16000;
                break;
            case 3:
                n = 64000;
                break;
            default:
                system("cls");
                printf("Input Tidak Benar!!!\n");
                return menu();
                break;
        }
        int arr[n];
        seedArray(arr, n);
        printf("Array %d data random sebelum di sort :", n);
        printArray(arr, n);
        float detik1 = countBubbleSortPointer(arr, n);
        float detik2 = countBubbleSort(arr, n);
        printf("\n=====================================================================================================");
        printf("Array %d data random sesudah di sort :", n);
        printArray(arr, n);
        printf("\n=====================================================================================================");
        printf("\nWaktu Bubble Sort pointer : %lf", detik1);
        printf("\nWaktu Bubble Sort : %lf", detik2);
    } else {
        system("cls");
        printf("Input Tidak Benar!!!\n");
        return menu();
    }

}


int main() {

    menu();

    return 0;
}

void cetakAkhir() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("* TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI *\n");
    printf("|                GOOD BYE >_<                 |\n");
    printf("*             FROM KELOMPOK 13                *\n");
    printf("-----------------------------------------------\n");
}

int validasi() { //validasi input
    int angka;
    char karakter;
    if (scanf("%d%c", & angka, & karakter) != 2 || angka <= 0 || karakter != '\n') {
        printf("\nInput Invalid!\n");
        printf("Masukkan sesuai dengan menu di atas = ");
        fflush(stdin);
        return validasi();
    } else {
        return angka;
    }
}
