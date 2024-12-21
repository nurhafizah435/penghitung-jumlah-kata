/* Nama File        : tugas1.c
   Proggramer       : Nurhafizah
   NIM              : 24343123
   tanggal pembuatan: 04/10/2024
   */
#include <stdio.h.>

int main () {
    printf("Nama    :Nurhafizah\n");
    printf("NIM     :24343123\n");
    printf("tanggal :04/10/2024\n");

    // deklarasi variabel
    float nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
    int lulus;

    // input nilai dari pengguna 
    printf("Masukkan nilai tugas (0-100): ");
    scanf("%f", &nilaiTugas);
    printf("Masukkan  nilai UTS (0-100): ");
    scanf("%f", &nilaiUTS);
    printf("Masukkan nilai UAS (0-100): ");
    scanf("%ff,", &nilaiUAS);

    //Hitung nilai akhir
    nilaiAkhir = (0.3 * nilaiTugas) + (0.3 * nilaiUTS) + (0.4 * nilaiUAS);

    //Tentukan apakah lulus atau tidak 
    lulus = (nilaiAkhir >=60) && (nilaiUAS >=50);

    //Output hasil
    printf("Nilai Akhir Anda : %.2f\n", nilaiAkhir);

    if (lulus){
        printf("Selamat anda LULUS.\n");
    } else{
        printf("Maaf, Anda TIDAK LULUS.\n");
    }

    return 0;
}