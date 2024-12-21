#include <stdio.h>
void judul() {
    printf("Nama  : Nurhafizah\n");
    printf("NIM   : 24343123\n");
}

int main() {
    judul();
    int angka[5] = {10, 20, 30, 40, 50};
    int indeks, nilaiBaru;

    printf("Array awal: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    printf("Masukkan nomor indeks elemen yang ingin diganti (0-4): ");
    scanf("%d", &indeks);

    if(indeks >= 0 && indeks < 5) {
        printf("Masukkan nilai baru: ");
        scanf("%d", &nilaiBaru);
        angka[indeks] = nilaiBaru;

        printf("Array setelah diganti: ");
        for(int i = 0; i < 5; i++) {
            printf("%d ", angka[i]);
        }
        printf("\n");
    } 
    
    return 0;
}