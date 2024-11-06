#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 20

struct Mahasiswa {
    char nama[50];
    char jenisKelamin;
    struct Mahasiswa *next;
};
typedef struct Mahasiswa mahasiswa;

void tambahMahasiswa(mahasiswa **head, int *count);
void hapusMahasiswa(mahasiswa **head, char *nama, int *count);
void tampilkanSemuaMahasiswa(mahasiswa *head);
int cekPenambahanCindy(mahasiswa *head);
void pisahkanLingkaran(mahasiswa *head);


int main() {
    mahasiswa *head = NULL;
    char pilihan, nama[50];
    int count = 0;

    do {
        system("cls");
        printf("=== Sistem Data Mahasiswa (Maksimal 20 Mahasiswa) ===\n");
        printf("1. Tambah data mahasiswa\n");
        printf("2. Tampilkan semua mahasiswa\n");
        printf("3. Hapus data mahasiswa\n");
        printf("q. Keluar\n");
        printf("Masukkan pilihan: ");
        fflush(stdin);
        scanf("%c", &pilihan);

        if (pilihan == '1') {
            tambahMahasiswa(&head, &count);
        }
        else if (pilihan == '2') {
            tampilkanSemuaMahasiswa(head);
            printf("Tekan Enter untuk melanjutkan...");
            getchar();
            getchar();
        }
        else if (pilihan == '3') {
            printf("Masukkan nama mahasiswa yang akan dihapus: ");
            fflush(stdin);
            gets(nama);
            hapusMahasiswa(&head, nama, &count);
            printf("Tekan Enter untuk melanjutkan...");
            getchar();
            getchar();
        }

    } while (pilihan != 'q');

    return 0;
}

void tambahMahasiswa(mahasiswa **head, int *count) {
    if (*count >= MAX_MAHASISWA) {
        printf("Batas maksimal 20 mahasiswa tercapai, tidak bisa menambah lagi.\n");
        return;
    }

    char nama[50], jenisKelamin;
    mahasiswa *newMahasiswa, *last;

    system("cls");
    printf("Masukkan nama mahasiswa: ");
    fflush(stdin);
    gets(nama);

    if (strcmp(nama, "Cindy") == 0) {
        if (!cekPenambahanCindy(*head)) {
            printf("Cindy tidak bisa ditambahkan karena aturan kiri kanan harus perempuan tidak terpenuhi.\n");
            return;
        }
    }

    do {
        printf("Masukkan jenis kelamin (P/L): ");
        fflush(stdin);
        scanf("%c", &jenisKelamin);
    } while (jenisKelamin != 'L' && jenisKelamin != 'P');

    newMahasiswa = (mahasiswa *)malloc(sizeof(mahasiswa));

    if (newMahasiswa != NULL) {
        strcpy(newMahasiswa->nama, nama);
        newMahasiswa->jenisKelamin = jenisKelamin;

        if (*head == NULL) {
            newMahasiswa->next = newMahasiswa;  // Jika list kosong, node menunjuk ke dirinya sendiri
            *head = newMahasiswa;
        } else {
            last = *head;
            while (last->next != *head) {
                last = last->next;
            }
            last->next = newMahasiswa;
            newMahasiswa->next = *head;  // Membuat circular
        }

        (*count)++;
        printf("Mahasiswa %s berhasil ditambahkan.\n", nama);
    } else {
        printf("Alokasi memori gagal.\n");
    }
}

//========================================================

void hapusMahasiswa(mahasiswa **head, char *nama, int *count) {
    if (*head == NULL) {
        printf("Tidak ada data mahasiswa.\n");
        return;
    }

    mahasiswa *current = *head, *prev = NULL;

    if (strcmp((*head)->nama, nama) == 0) {
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            (*count)--;
            printf("Mahasiswa %s telah dihapus.\n", nama);
            return;
        }

        mahasiswa *last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        last->next = (*head)->next;
        current = *head;
        *head = (*head)->next;
        free(current);
        (*count)--;
        printf("Mahasiswa %s telah dihapus.\n", nama);
        return;
    }

    do {
        prev = current;
        current = current->next;
        if (strcmp(current->nama, nama) == 0) {
            prev->next = current->next;
            free(current);
            (*count)--;
            printf("Mahasiswa %s telah dihapus.\n", nama);
            return;
        }
    } while (current != *head);

    printf("Mahasiswa %s tidak ditemukan.\n", nama);
}

//========================================================

int cekPenambahanCindy(mahasiswa *head) {
    if (head == NULL) return 0;
    mahasiswa *current = head;
    do {
        if (current->next->jenisKelamin == 'L' && current->jenisKelamin == 'L') {
            return 1;
        }
        current = current->next;
    } while (current != head);

    return 0;
}


void tampilkanSemuaMahasiswa(mahasiswa *head) {
    if (head == NULL) {
        printf("Tidak ada data mahasiswa.\n");
        return;
    }

    mahasiswa *current = head;
    system("cls");
    printf("=== Daftar Mahasiswa ===\n");

    do {
        printf("Nama: %s, Jenis Kelamin: %s\n", current->nama, current->jenisKelamin == 'L' ? "Pria" : "Wanita");
        current = current->next;
    } while (current != head);
}

    if (head == NULL) {
        printf("Lingkaran kosong, tidak ada yang bisa dipisahkan.\n");
        return;
    }

    mahasiswa *current = head;
    mahasiswa *headMahasiswa = NULL, *headMahasiswi = NULL;
    mahasiswa *lastMahasiswa = NULL, *lastMahasiswi = NULL;

    do {
        if (current->jenisKelamin == 'P') {
            // Menambahkan ke lingkaran mahasiswa
            mahasiswa *newMahasiswa = (mahasiswa *)malloc(sizeof(mahasiswa));
            strcpy(newMahasiswa->nama, current->nama);
            newMahasiswa->jenisKelamin = 'P';
            newMahasiswa->next = newMahasiswa;

            if (headMahasiswa == NULL) {
                headMahasiswa = newMahasiswa;
                lastMahasiswa = newMahasiswa;
            } else {
                lastMahasiswa->next = newMahasiswa;
                newMahasiswa->next = headMahasiswa;
                lastMahasiswa = newMahasiswa;
            }
        } else if (current->jenisKelamin == 'L') {
            // Menambahkan ke lingkaran mahasiswi
            mahasiswa *newMahasiswi = (mahasiswa *)malloc(sizeof(mahasiswa));
            strcpy(newMahasiswi->nama, current->nama);
            newMahasiswi->jenisKelamin = 'L';
            newMahasiswi->next = newMahasiswi;

            if (headMahasiswi == NULL) {
                headMahasiswi = newMahasiswi;
                lastMahasiswi = newMahasiswi;
            } else {
                lastMahasiswi->next = newMahasiswi;
                newMahasiswi->next = headMahasiswi;
                lastMahasiswi = newMahasiswi;
            }
        }

        current = current->next;
    } while (current != head);

    // Menampilkan hasil lingkaran mahasiswa dan mahasiswi
    printf("\n=== Lingkaran Mahasiswa ===\n");
    tampilkanSemuaMahasiswa(headMahasiswa);

    printf("\n=== Lingkaran Mahasiswi ===\n");
    tampilkanSemuaMahasiswa(headMahasiswi);
}
