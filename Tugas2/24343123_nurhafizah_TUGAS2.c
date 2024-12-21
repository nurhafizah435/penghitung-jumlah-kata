#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int angkaTebakan, tebakan, kesempatan, mainlagi;
	char pilihan; // Tambahkan tanda koma
	
	// Menginisialisasi generator angka acak
	srand(time(0));
	
	do {
		// Pilih angka acak antara 1 dan 100
		angkaTebakan = rand() % 200 + 1; // Menggunakan rand(), bukan ran()
		kesempatan = 5;
		printf("Selamat datang di permainan tebak angka!\n");
		printf("Saya telah memilih sebuah angka antara 1 dan 200.\n");
		printf("Anda memiliki 5 kesempatan untuk menebaknya.\n");
		
		// Mulai permainan dengan struktur kontrol loop
		while (kesempatan > 0){
			printf("\nMasukkan tebakan Anda: ");
			scanf("%d", &tebakan);
			
			// Struktur kontrol if-else untuk mengevaluasi tebakan
			if (tebakan > angkaTebakan) {
				printf("Tebakan Anda terlalu tinggi!");
			} else if (tebakan < angkaTebakan) {
				printf("Tebakan Anda terlalu rendah!");
			} else {
				printf("Selamat! Anda menebak dengan benar!\n");
				break;
			}
			kesempatan--; // Kurangi jumlah kesempatan
			printf("Kesempatan tersisa: %d\n", kesempatan);
		}
		// Evaluasi akhir jika gagal menebak dalam 5 kesempatan
		if (kesempatan == 0){
			printf("Maaf, Anda kehabisan kesempatan. Angka yang benar adalah %d.\n", angkaTebakan);
		}
		
		// Opsi untuk bermain lagi menggunakan switch
		printf("Apakah Anda ingin bermain lagi? (y/n): ");
		scanf(" %c", &pilihan); // Menggunakan scanf(), bukan scantf()
		
		switch (pilihan) {
			case 'y':
			case 'Y':
				mainlagi = 1; // Konsisten menggunakan mainlagi
				break; // Menghapus titik dua
			case 'n':
			case 'N':
				mainlagi = 0;
				printf("Terima kasih telah bermain!\n");
				break;
			default:
				printf("Pilihan tidak valid, keluar dari permainan.\n");
				mainlagi = 0;
				break;	
		}
	} while (mainlagi);
	
	return 0;
}
