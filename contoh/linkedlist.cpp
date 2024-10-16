#include <iostream>  // Gunakan iostream untuk masukan dan keluaran standar pada C++
#include <stdlib.h>

// Definisi struktur node
struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Deklarasi fungsi
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);

// Fungsi utama
int main() {
    node *head = NULL;  // Inisialisasi head sebagai pointer NULL
    char pilih;

    do {
        std::system("cls");  // Bersihkan layar (opsional)
        std::cout << "Masukkan pilihan:\n";
        std::cout << "1. Tambah data di awal\n";
        std::cout << "2. Tambah data di tengah list\n";
        std::cout << "4. Cetak isi list\n";
        std::cout << "MASUKKAN PILIHAN (tekan q untuk keluar): ";
        
        std::cin >> pilih;  // Gunakan std::cin untuk masukan karakter

        switch (pilih) {
            case '1':
                tambahAwal(&head);
                break;
            case '2':
                tambahData(&head);
                break;
            case '4':
                tranverse(head);
                std::cin.get();  // Tunggu input agar hasil dapat dilihat sebelum layar dibersihkan
                std::cin.get();  // Gunakan std::cin.get() untuk menunggu input tanpa tampilan karakter
                break;
            case 'q':
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilih != 'q');

    return 0;
}

// Fungsi untuk menambah node di awal linked list
void tambahAwal(node **head) {
    int bil;
    node *pNew;

    std::system("cls");
    std::cout << "Masukkan bilangan: ";
    std::cin >> bil;

    pNew = (node *)malloc(sizeof(node));  // Alokasi memori untuk node baru
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;  // Node baru menunjuk ke node pertama
        *head = pNew;  // Head menunjuk ke node baru
    } else {
        std::cout << "Alokasi memori gagal\n";
    }
}

// Fungsi untuk menambah node di tengah linked list
void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    std::system("cls");
    tranverse(*head);
    std::cout << "\nPosisi penyisipan setelah data bernilai: ";
    std::cin >> pos;
    std::cout << "\nBilangan: ";
    std::cin >> bil;

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {  // Temukan node dengan nilai 'pos'
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        std::cout << "\nNode tidak ditemukan.\n";
    } else {
        pNew = (node *)malloc(sizeof(node));  // Alokasi memori untuk node baru
        if (pNew == NULL) {
            std::cout << "\nAlokasi memori gagal.\n";
        } else {
            pNew->data = bil;
            pNew->next = pCur->next;  // Node baru menunjuk ke node setelah 'pCur'
            pCur->next = pNew;  // Node sebelumnya menunjuk ke node baru
        }
    }
}

// Fungsi untuk menampilkan seluruh node dalam linked list
void tranverse(node *head) {
    node *pWalker;

    std::system("cls");
    pWalker = head;
    std::cout << "Isi linked list: ";
    while (pWalker != NULL) {  // Traverse hingga node terakhir (NULL)
        std::cout << pWalker->data << " -> ";
        pWalker = pWalker->next;
    }
    std::cout << "NULL\n";
}
