#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node Double Linked List
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

// Deklarasi pointer untuk head (awal) dari list
Node *pHead = NULL;

// Fungsi untuk menambahkan data di akhir Double Linked List
void insertNodeAtEnd(int item) {
    Node *pNew = (Node*) malloc(sizeof(Node));  // Alokasi memori dengan casting eksplisit
    if (pNew == NULL) {  // Cek alokasi memori
        printf("Alokasi memori gagal.\n");
        return;
    }
    pNew->data = item;
    pNew->left = NULL;
    pNew->right = NULL;

    if (pHead == NULL) {
        pHead = pNew;
    } else {
        Node *currentNode = pHead;
        while (currentNode->right != NULL) {
            currentNode = currentNode->right;
        }
        currentNode->right = pNew;
        pNew->left = currentNode;
    }
}

// Fungsi untuk menghapus node pertama dari Double Linked List
void deleteNodeAtBeginning() {
    if (pHead == NULL) {
        printf("List kosong. Tidak ada yang bisa dihapus.\n");
        return;
    }

    Node *currentNode = pHead;
    if (currentNode->right == NULL) {
        pHead = NULL;
    } else {
        pHead = pHead->right;
        pHead->left = NULL;
    }
    free(currentNode);
    currentNode = NULL;  // Hindari dangling pointer
}

// Fungsi untuk menghapus node di posisi tertentu dalam Double Linked List
void deleteNodeAtMiddle(int position) {
    if (pHead == NULL || position < 1) {
        printf("List kosong atau posisi tidak valid.\n");
        return;
    }

    if (position == 1) {
        deleteNodeAtBeginning();
        return;
    }

    Node *currentNode = pHead;
    int count = 1;

    while (count < position && currentNode != NULL) {
        currentNode = currentNode->right;
        count++;
    }

    if (currentNode != NULL) {
        if (currentNode->left != NULL) {
            currentNode->left->right = currentNode->right;
        }
        if (currentNode->right != NULL) {
            currentNode->right->left = currentNode->left;
        }
        free(currentNode);
        currentNode = NULL;
    } else {
        printf("Posisi melebihi jumlah node di list.\n");
    }
}

// Fungsi untuk menghapus node terakhir dari Double Linked List
void deleteNodeAtEnd() {
    if (pHead == NULL) {
        printf("List kosong. Tidak ada yang bisa dihapus.\n");
        return;
    }

    Node *currentNode = pHead;

    if (currentNode->right == NULL) {
        free(pHead);
        pHead = NULL;
    } else {
        while (currentNode->right != NULL) {
            currentNode = currentNode->right;
        }
        currentNode->left->right = NULL;
        free(currentNode);
        currentNode = NULL;
    }
}

// Fungsi untuk mencari data pada Double Linked List
void searchNode(int item) {
    if (pHead == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node *currentNode = pHead;
    int position = 1;

    while (currentNode != NULL) {
        if (currentNode->data == item) {
            printf("Data %d ditemukan di posisi %d.\n", item, position);
            return;
        }
        currentNode = currentNode->right;
        position++;
    }

    printf("Data %d tidak ditemukan di list.\n", item);
}

// Fungsi untuk menghitung jumlah node di Double Linked List
void countNodes() {
    if (pHead == NULL) {
        printf("List kosong. Tidak ada node yang dapat dihitung.\n");
        return;
    }

    int count = 0;
    Node *currentNode = pHead;

    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->right;
    }

    printf("Jumlah node di list: %d\n", count);
}

// Fungsi untuk menampilkan hasil penjumlahan dari semua data di Double Linked List
void sumNodes() {
    if (pHead == NULL) {
        printf("List kosong. Tidak ada node untuk dijumlahkan.\n");
        return;
    }

    int sum = 0;
    Node *currentNode = pHead;

    while (currentNode != NULL) {
        sum += currentNode->data;
        currentNode = currentNode->right;
    }

    printf("Hasil penjumlahan semua data di list: %d\n", sum);
}

// Fungsi untuk menampilkan isi list dari awal ke akhir
void displayList() {
    if (pHead == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node *currentNode = pHead;
    printf("List berisi: ");
    while (currentNode != NULL) {
        printf("%d <-> ", currentNode->data);
        currentNode = currentNode->right;
    }
    printf("NULL\n");
}

// Fungsi untuk menampilkan isi list dari akhir ke awal
void displayListFromEnd() {
    if (pHead == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node *currentNode = pHead;

    while (currentNode->right != NULL) {
        currentNode = currentNode->right;
    }

    printf("List berisi (dari akhir ke awal): ");
    while (currentNode != NULL) {
        printf("%d <-> ", currentNode->data);
        currentNode = currentNode->left;
    }
    printf("NULL\n");
}

// Fungsi utama untuk menerima input pengguna
int main() {
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah data\n");
        printf("2. Hapus data pertama\n");
        printf("3. Hapus data di posisi tertentu\n");
        printf("4. Hapus data terakhir\n");
        printf("5. Cari data\n");
        printf("6. Tampilkan jumlah node\n");
        printf("7. Tampilkan hasil penjumlahan semua data\n");
        printf("8. Tampilkan list dari awal ke akhir\n");
        printf("9. Tampilkan list dari akhir ke awal\n");
        printf("10. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan data yang ingin ditambahkan: ");
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 2:
                deleteNodeAtBeginning();
                break;
            case 3:
                printf("Masukkan posisi node yang ingin dihapus: ");
                scanf("%d", &position);
                deleteNodeAtMiddle(position);
                break;
            case 4:
                deleteNodeAtEnd();
                break;
            case 5:
                printf("Masukkan data yang ingin dicari: ");
                scanf("%d", &data);
                searchNode(data);
                break;
            case 6:
                countNodes();
                break;
            case 7:
                sumNodes();
                break;
            case 8:
                displayList();
                break;
            case 9:
                displayListFromEnd();
                break;
            case 10:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
