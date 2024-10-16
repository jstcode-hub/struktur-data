#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menampilkan linked list
void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fungsi untuk memeriksa apakah suatu nilai sudah ada di dalam linked list
int isDuplicate(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;  // Nilai sudah ada di linked list
        }
        temp = temp->next;
    }
    return 0;  // Nilai belum ada di linked list
}

// Fungsi untuk memasukkan node ke dalam linked list secara terurut (dari besar ke kecil)
struct Node* insertSorted(struct Node* head, int data) {
    // Cek duplikasi sebelum menambahkan node
    if (isDuplicate(head, data)) {
        printf("Nilai %d sudah ada di linked list, input akan diskip.\n", data);
        return head;
    }

    struct Node* newNode = createNode(data);

    // Jika linked list kosong atau data lebih besar dari head, masukkan di depan
    if (head == NULL || head->data <= data) {
        newNode->next = head;
        return newNode;
    }

    // Temukan posisi yang tepat untuk menyisipkan node baru
    struct Node* current = head;
    while (current->next != NULL && current->next->data > data) {
        current = current->next;
    }

    // Sisipkan node baru pada posisi yang ditemukan
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Fungsi untuk membuat linked list dengan nilai yang diinputkan
struct Node* createLinkedList() {
    struct Node* head = NULL;
    int value;

    printf("Masukkan nilai (ketik -1 untuk berhenti):\n");
    while (1) {
        printf("Nilai: ");
        scanf("%d", &value);

        // Jika nilai adalah -1, maka berhenti
        if (value == -1) {
            break;
        }

        // Masukkan nilai ke linked list secara terurut jika belum ada
        head = insertSorted(head, value);
    }

    return head;
}

// Fungsi untuk mencari nilai tertentu di linked list
void searchNode(struct Node* head, int value) {
    struct Node* current = head;
    struct Node* prev = NULL;  // Menyimpan node sebelumnya
    struct Node* next = NULL;  // Menyimpan node sesudahnya
    int position = 0;

    // Iterasi melalui linked list untuk mencari nilai
    while (current != NULL) {
        position++;
        if (current->data == value) {
            next = current->next;

            // Menampilkan informasi node yang ditemukan
            printf("Nilai %d ditemukan pada posisi: %d\n", value, position);
            printf("Alamat Memori Node: %p\n", (void*)current);

            // Menampilkan nilai sebelum, jika ada
            if (prev != NULL) {
                printf("Nilai Sebelum: %d (Alamat Memori: %p)\n", prev->data, (void*)prev);
            } else {
                printf("Nilai Sebelum: NULL (Ini adalah node pertama)\n");
            }

            // Menampilkan nilai sesudah, jika ada
            if (next != NULL) {
                printf("Nilai Sesudah: %d (Alamat Memori: %p)\n", next->data, (void*)next);
            } else {
                printf("Nilai Sesudah: NULL (Ini adalah node terakhir)\n");
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    // Jika node dengan nilai yang dicari tidak ditemukan
    printf("Nilai %d tidak ditemukan di linked list.\n", value);
}

// Fungsi untuk menghapus node berdasarkan nilai yang diinputkan
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // Cek jika linked list kosong
    if (head == NULL) {
        printf("Linked list kosong. Tidak ada node yang bisa dihapus.\n");
        return head;
    }

    // Cek jika node yang ingin dihapus adalah head
    if (current != NULL && current->data == value) {
        head = current->next;  // Pindahkan head ke node berikutnya
        printf("Node dengan nilai %d telah dihapus.\n", value);
        free(current);  // Bebaskan memori node yang dihapus
        return head;
    }

    // Mencari node dengan nilai yang sesuai
    while (current != NULL && current->data != value) {
        prev = current;         // Simpan node sebelumnya
        current = current->next;  // Pindah ke node berikutnya
    }

    // Jika nilai tidak ditemukan dalam linked list
    if (current == NULL) {
        printf("Nilai %d tidak ditemukan di linked list.\n", value);
        return head;
    }

    // Hapus node dengan memindahkan pointer next dari node sebelumnya
    prev->next = current->next;
    printf("Node dengan nilai %d telah dihapus.\n", value);

    free(current);  // Bebaskan memori node yang dihapus
    return head;
}

// Fungsi untuk menjumlahkan semua nilai dalam linked list
int sumLinkedList(struct Node* head) {
    int sum = 0;
    struct Node* temp = head;

    // Iterasi melalui linked list dan tambahkan setiap nilai
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

// Fungsi utama untuk menjalankan program
int main() {
    struct Node* linkedList = createLinkedList();  // Membuat linked list
    displayLinkedList(linkedList);  // Menampilkan linked list

    // Menjumlahkan semua nilai dalam linked list
    int totalSum = sumLinkedList(linkedList);
    printf("Jumlah total semua nilai di linked list: %d\n", totalSum);

    int searchValue, deleteValue;

    // Cari node dalam linked list
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &searchValue);
    searchNode(linkedList, searchValue);

    // Hapus node dari linked list
    printf("Masukkan nilai yang ingin dihapus: ");
    scanf("%d", &deleteValue);
    linkedList = deleteNode(linkedList, deleteValue);
    displayLinkedList(linkedList);  // Menampilkan linked list setelah penghapusan

    // Bebaskan memori yang telah digunakan (opsional)
    struct Node* temp;
    while (linkedList != NULL) {
        temp = linkedList;
        linkedList = linkedList->next;
        free(temp);
    }

    return 0;
}
