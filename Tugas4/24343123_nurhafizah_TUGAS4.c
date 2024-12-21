/*
    Nama File        : tugas4.c
    Nama Programmer  : Nurhafizah
    NIM              : 24343123
    Tgl pembuatan    : 01 November 2024
    Deskripsi        : program manajemen buku perpustakaan
*/
#include <stdio.h>
#include <string.h>

#define MAX_BUKU 100 // maksimal jumlah buku yang bisa dimasukkan
#define MAX_STRING 100 // panjang maksimal string (judul dan pengarang)

// definisi struct Buku
struct Buku {
    char judul[MAX_STRING];
    char pengarang[MAX_STRING];
    int tahun;
};

void tambahBuku(struct Buku *perpustakaan, int *jumlahBuku);
void tampilkanBuku(struct Buku *perpustakaan, int jumlahBuku);
void cariBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulCari);
void hapusBuku(struct Buku *perpustakaan, int *jumlahBuku, char *judulHapus);
void editBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulEdit);

int main () {
    printf("=================================\n");
    printf("Program manajemen buku perpustakaan\n");
    printf("Programmer : Nurhafizah\n");
    printf("NIM : 24343103\n");
    printf("=================================\n");
    struct Buku perpustakaan[MAX_BUKU]; //array untuk menyimpan buku
    int jumlahBuku = 0; //jumlah buku saat ini
    int pilihan;
    char judulCari[MAX_STRING];
    char judulHapus[MAX_STRING];
    char judulEdit[MAX_STRING];

    do {
        //menu utama
        printf("\n--- Manajemen Buku Perpustakaan ---\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Semua Buku\n");
        printf("3. Cari Buku Berdasarkan Judul\n");
        printf("4. Hapus Buku Berdasarkan Judul\n");
        printf("5. Edit Buku Berdasarkan Judul\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // membersihkan karakter newline dari buffer input

        switch (pilihan) {
            case 1:
                tambahBuku(perpustakaan, &jumlahBuku);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlahBuku);
                break;
            case 3:
                printf("Masukkan judul buku yang ingin dicari: ");
                fgets(judulCari, MAX_STRING, stdin);
                judulCari[strcspn(judulCari, "\n")] = 0; //menghapus karakter newline
                cariBuku(perpustakaan, jumlahBuku, judulCari);
                break;
            case 4:
                printf("Masukkan judul buku yang ingin dihapus: ");
                fgets(judulHapus, MAX_STRING, stdin);
                judulHapus[strcspn(judulHapus, "\n")] = 0;
                hapusBuku(perpustakaan, &jumlahBuku, judulHapus);
                break;
            case 5:
                printf("Masukkan judul buku yang ingin diedit: ");
                fgets(judulEdit, MAX_STRING, stdin);
                judulEdit[strcspn(judulEdit, "\n")] = 0;
                editBuku(perpustakaan, jumlahBuku, judulEdit);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 6);
    
    return 0;
}

// fungsi untuk menambah buku
void tambahBuku(struct Buku *perpustakaan, int *jumlahBuku) {
    if (*jumlahBuku < MAX_BUKU) {
        printf("Masukkan judul buku: ");
        fgets(perpustakaan[*jumlahBuku].judul, MAX_STRING, stdin);
        perpustakaan[*jumlahBuku].judul[strcspn(perpustakaan[*jumlahBuku].judul, "\n")] = 0;

        printf("Masukkan pengarang buku: ");
        fgets(perpustakaan[*jumlahBuku].pengarang, MAX_STRING, stdin);
        perpustakaan[*jumlahBuku].pengarang[strcspn(perpustakaan[*jumlahBuku].pengarang, "\n")] = 0;

        printf("Masukkan tahun terbit: ");
        scanf("%d", &perpustakaan[*jumlahBuku].tahun);
        getchar();

        (*jumlahBuku)++;
        printf("Buku berhasil ditambahkan!\n");
    } else {
        printf("Perpustakaan penuh, tidak bisa menambah buku lagi!\n");
    }
}

// fungsi untuk menampilkan semua buku
void tampilkanBuku(struct Buku *perpustakaan, int jumlahBuku) {
    if (jumlahBuku == 0){
        printf("Tidak ada buku di perpustakaan.\n");
    } else {
        printf("\n--- Daftar Buku di Perpustakaan ---\n");
        for (int i = 0; i < jumlahBuku; i++) {
            printf("Buku %d:\n", i + 1);
            printf("Judul       : %s\n", perpustakaan[i].judul);
            printf("Pengarang   : %s\n", perpustakaan[i].pengarang);
            printf("Tahun       : %d\n", perpustakaan[i].tahun);
        }
    }
}

// fungsi untuk mencari buku berdasarkan judul
void cariBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulCari) {
    int ditemukan = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judulCari) == 0) {
            printf("\nBuku ditemukan:\n");
            printf("Judul       : %s\n", perpustakaan[i].judul);
            printf("Pengarang   : %s\n", perpustakaan[i].pengarang);
            printf("Tahun       : %d\n", perpustakaan[i].tahun);
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", judulCari);
    } 
}

// fungsi untuk menghapus buku berdasarkan judul
void hapusBuku(struct Buku *perpustakaan, int *jumlahBuku, char *judulHapus) {
    int ditemukan = 0;
    for (int i = 0; i < *jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judulHapus) == 0) {
            ditemukan = 1;
            for (int j = i; j < *jumlahBuku - 1; j++) {
                perpustakaan[j] = perpustakaan[j + 1];
            }
            (*jumlahBuku)--;
            printf("Buku dengan judul '%s' berhasil dihapus.\n", judulHapus);
            break;
        }
    }
    if (!ditemukan) {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", judulHapus);
    }
}

// fungsi untuk mengedit buku berdasarkan judul
void editBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulEdit) {
    int ditemukan = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, judulEdit) == 0) {
            printf("Buku ditemukan. Masukkan informasi baru:\n");
            printf("Masukkan judul baru: ");
            fgets(perpustakaan[i].judul, MAX_STRING, stdin);
            perpustakaan[i].judul[strcspn(perpustakaan[i].judul, "\n")] = 0;

            printf("Masukkan pengarang baru: ");
            fgets(perpustakaan[i].pengarang, MAX_STRING, stdin);
            perpustakaan[i].pengarang[strcspn(perpustakaan[i].pengarang, "\n")] = 0;

            printf("Masukkan tahun terbit baru: ");
            scanf("%d", &perpustakaan[i].tahun);
            getchar();
            
            printf("Informasi buku berhasil diperbarui.\n");
            ditemukan = 1;
            break;
        }
    }
    if (!ditemukan) {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", judulEdit);
    }
}