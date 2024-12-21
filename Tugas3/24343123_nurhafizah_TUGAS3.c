#include <stdio.h>
#include <math.h>

// Fungsi rekursif untuk Menara Hanoi
void hanoi(int n, char asal, char tujuan, char bantu) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", asal, tujuan);
        return;
    }
    hanoi(n - 1, asal, bantu, tujuan);
    printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, asal, tujuan);
    hanoi(n - 1, bantu, tujuan, asal);
}

int main() {
    printf("Project tugas 1.c\n");
    printf("Programmer : Nurhafizah\n");
    printf("NIM : 24343123\n");
    printf("========================\n");

    int cakram;

    // Meminta input jumlah cakram dari pengguna
    printf("Masukkan jumlah cakram: ");
    scanf("%d", &cakram);

    // Menghitung jumlah total langkah yang diperlukan
    int totalLangkah = pow(2, cakram) - 1;

    // Menampilkan jumlah langkah dan langkah-langkah pemindahan cakram
    printf("Jumlah total langkah yang diperlukan: %d\n", totalLangkah);
    printf("Langkah-langkah untuk memindahkan %d cakram:\n", cakram);
    hanoi(cakram, 'A', 'C', 'B'); // 'A' adalah tiang asal, 'C' adalah tiang tujuan, 'B' adalah tiang bantu

    return 0;
}
