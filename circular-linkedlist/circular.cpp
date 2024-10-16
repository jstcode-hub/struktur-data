#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node Circular Linked List
struct node {
    int data;  // Bagian data
    struct node *next;  // Pointer menunjuk ke node selanjutnya
};

typedef struct node Node;

// Deklarasi `pList` sebagai pointer yang menunjuk ke salah satu node dalam Circular Linked List
Node *pList = NULL;  // Inisialisasi linked list kosong

// Fungsi untuk menambahkan data di akhir Circular Linked List
void insertAtEnd(int item) {
    Node *pNew = (Node *) malloc(sizeof(Node));  // Alokasi memori untuk node baru
    pNew->data = item;  // Inisialisasi data node baru
    pNew->next = NULL;

    if (pList == NULL) {  // Menambahkan pada list kosong
        pNew->next = pNew;  // Node menunjuk dirinya sendiri
        pList = pNew;
    } else {
        Node *pCur = pList;
        // Menemukan node terakhir yang menunjuk ke head
        while (pCur->next != pList) {
            pCur = pCur->next;
        }
        pCur->next = pNew;  // Node terakhir menunjuk ke node baru
        pNew->next = pList;  // Node baru menunjuk ke head
    }
}

// Fungsi untuk menghapus data di awal Circular Linked List
void deleteAtBeginning() {
    if (pList == NULL) {
        printf("List kosong. Tidak ada yang bisa dihapus.\n");
        return;
    }

    Node *pCur = pList;

    if (pList->next == pList) {  // Hanya ada satu node dalam list
        free(pList);
        pList = NULL;
    } else {
        // Temukan node terakhir
        while (pCur->next != pList) {
            pCur = pCur->next;
        }
        Node *temp = pList;  // Simpan node pertama untuk dihapus
        pCur->next = pList->next;  // Node terakhir menunjuk ke node kedua
        pList = pList->next;  // Head menjadi node kedua
        free(temp);
    }
}

// Fungsi untuk menghapus data di tengah Circular Linked List (di posisi tertentu)
void deleteAtMiddle(int position) {
    if (pList == NULL || position < 1) {
        printf("List kosong atau posisi tidak valid.\n");
        return;
    }

    Node *pCur = pList, *pPre = NULL;

    // Jika posisi adalah 1, hapus node pertama
    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    int count = 1;

    // Temukan posisi yang akan dihapus
    while (count < position && pCur->next != pList) {
        pPre = pCur;
        pCur = pCur->next;
        count++;
    }

    // Jika posisi ditemukan
    if (count == position) {
        pPre->next = pCur->next;
        free(pCur);
    } else {
        printf("Posisi melebihi jumlah node di list.\n");
    }
}

// Fungsi untuk menghapus data di akhir Circular Linked List
void deleteAtEnd() {
    if (pList == NULL) {
        printf("List kosong. Tidak ada yang bisa dihapus.\n");
        return;
    }

    Node *pCur = pList, *pPre = NULL;

    // Jika hanya ada satu node
    if (pList->next == pList) {
        free(pList);
        pList = NULL;
    } else {
        // Temukan node terakhir dan node sebelumnya
        while (pCur->next != pList) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = pList;  // Node sebelumnya menunjuk ke head
        free(pCur);  // Hapus node terakhir
    }
}

// Fungsi untuk mencari data pada Circular Linked List
void search(int item) {
    if (pList == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node *pCur = pList;
    int position = 1;

    // Lakukan pencarian hingga kembali ke head
    do {
        if (pCur->data == item) {
            printf("Data %d ditemukan di posisi %d.\n", item, position);
            return;
        }
        pCur = pCur->next;
        position++;
    } while (pCur != pList);

    printf("Data %d tidak ditemukan.\n", item);
}

// Fungsi untuk menampilkan informasi jumlah data di Circular Linked List
void countNodes() {
    if (pList == NULL) {
        printf("List kosong.\n");
        return;
    }

    int count = 0;
    Node *pCur = pList;

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Jumlah node di list: %d\n", count);
}

// Fungsi untuk menampilkan hasil penjumlahan dari semua data di Circular Linked List
void sumNodes() {
    if (pList == NULL) {
        printf("List kosong.\n");
        return;
    }

    int sum = 0;
    Node *pCur = pList;

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Hasil penjumlahan semua data di list: %d\n", sum);
}

// Traversing Circular Linked List
void displayList() {
    if (pList == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node *pCur = pList;
    printf("List berisi: ");
    do {
        printf("%d -> ", pCur->data);
        pCur = pCur->next;
    } while (pCur != pList);
    printf("(kembali ke head)\n");
}

// Fungsi utama untuk menguji Circular Linked List
int main() {
    char pilih;
    int value, pos;

    do {
        system("cls");
        printf("Pilih menu:\n");
        printf("1. Tambah data di akhir\n");
        printf("2. Hapus data di awal\n");
        printf("3. Hapus data di tengah\n");
        printf("4. Hapus data di akhir\n");
        printf("5. Cari data\n");
        printf("6. Hitung jumlah node\n");
        printf("7. Hitung jumlah data\n");
        printf("8. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        
        scanf(" %c", &pilih);

        switch (pilih) {
            case '1':
                printf("Masukkan data yang ingin ditambahkan: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case '2':
                deleteAtBeginning();
                break;
            case '3':
                printf("Masukkan posisi yang ingin dihapus: ");
                scanf("%d", &pos);
                deleteAtMiddle(pos);
                break;
            case '4':
                deleteAtEnd();
                break;
            case '5':
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &value);
                search(value);
                break;
            case '6':
                countNodes();
                break;
            case '7':
                sumNodes();
                break;
            case '8':
                displayList();
                break;
            case 'q':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }

        printf("Tekan Enter untuk melanjutkan...\n");
        getchar();
        getchar();

    } while (pilih != 'q');

    return 0;
}
