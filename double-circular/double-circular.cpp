#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void hapusData(node **head, int key);
void tranverse(node *head);
void tranverseBackward(node *head);
int cariData(node *head, int key);

//========================================================

int main() {
    node *head;
    char pilih;
    int key;

    head = NULL;
    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Hapus data\n");
        printf("4. Cetak isi list ke depan\n");
        printf("5. Cetak isi list ke belakang\n");
        printf("6. Cari data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);

        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3') {
            printf("Masukkan data yang akan dihapus: ");
            scanf("%d", &key);
            hapusData(&head, key);
            getch();
        }
        else if (pilih == '4') {
            tranverse(head);
            getch();
        }
        else if (pilih == '5') {
            tranverseBackward(head);
            getch();
        }
        else if (pilih == '6') {
            printf("Masukkan data yang dicari: ");
            scanf("%d", &key);
            if (cariData(head, key))
                printf("Data %d ditemukan\n", key);
            else
                printf("Data %d tidak ditemukan\n", key);
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew, *last;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew->prev = pNew;
            *head = pNew;
        } else {
            last = (*head)->prev;
            pNew->next = *head;
            pNew->prev = last;
            last->next = (*head)->prev = pNew;
            *head = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("\nBilangan: ");
    scanf("%d", &bil);

    pCur = *head;
    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->data != pos) {
        printf("Node tidak ditemukan\n");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL) {
        printf("Alokasi memori gagal\n");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pNew->prev = pCur;
        pCur->next->prev = pNew;
        pCur->next = pNew;
    }
}

//========================================================

void hapusData(node **head, int key) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    node *pCur = *head, *prevNode;

    // Mencari node dengan data sesuai key
    do {
        if (pCur->data == key) break;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->data != key) {
        printf("Node tidak ditemukan.\n");
        return;
    }

    if (pCur == *head) {
        if (pCur->next == *head) { // Jika hanya ada satu node
            free(pCur);
            *head = NULL;
        } else {
            node *last = (*head)->prev;
            last->next = (*head)->next;
            (*head)->next->prev = last;
            *head = (*head)->next;
            free(pCur);
        }
    } else {
        pCur->prev->next = pCur->next;
        pCur->next->prev = pCur->prev;
        free(pCur);
    }
}

//========================================================

void tranverse(node *head) {
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }

    node *pWalker = head;
    system("cls");
    do {
        printf("%d ", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    } while (pWalker != head);
    printf("HEAD\n");
}

//========================================================

void tranverseBackward(node *head) {
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }

    node *pWalker = head->prev;
    system("cls");
    do {
        printf("%d ", pWalker->data);
        pWalker = pWalker->prev;
        printf(" <- ");
    } while (pWalker != head->prev);
    printf("TAIL\n");
}

//========================================================

int cariData(node *head, int key) {
    if (head == NULL) return 0;

    node *pCur = head;
    do {
        if (pCur->data == key)
            return 1;
        pCur = pCur->next;
    } while (pCur != head);

    return 0;
}
