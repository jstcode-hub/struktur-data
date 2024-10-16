#include <stdio.h>
#include <stdlib.h>

// Struktur Node
typedef struct node
{
    int data;
    struct node *next;
} node;

// Deklarasi Fungsi
void tambahAwal(node **head, int bil);
void tambahAkhir(node **head, int bil);
void tambahTengah(node **head, int bil, int pos);
void hapusAwal(node **head);
void hapusAkhir(node **head);
void hapusTengah(node **head, int val);
void tranverse(node *head);
void cariData(node *head, int target);
void jumlahData(node *head);
void totalData(node *head);

int main()
{
    node *head = NULL;
    char pilih;
    int val, bil, pos;

    do
    {
        printf("\nPilih Menu:\n");
        printf("1. Tambah data di awal\n2. Tambah data di akhir\n");
        printf("3. Tambah data di tengah\n4. Hapus data di awal\n");
        printf("5. Hapus data di akhir\n6. Hapus data di tengah\n");
        printf("7. Cetak list\n8. Cari data\n9. Jumlah data\n");
        printf("10. Total penjumlahan data\nq. Keluar\nPilihan: ");
        scanf(" %d", &pilih);

        switch (pilih)
        {
        case '1':
            printf("Masukkan data: ");
            scanf("%d", &bil);
            tambahAwal(&head, bil);
            break;
        case '2':
            printf("Masukkan data: ");
            scanf("%d", &bil);
            tambahAkhir(&head, bil);
            break;
        case '3':
            printf("Masukkan data: ");
            scanf("%d", &bil);
            printf("Masukkan posisi setelah data: ");
            scanf("%d", &pos);
            tambahTengah(&head, bil, pos);
            break;
        case '4':
            hapusAwal(&head);
            break;
        case '5':
            hapusAkhir(&head);
            break;
        case '6':
            printf("Masukkan data yang ingin dihapus: ");
            scanf("%d", &val);
            hapusTengah(&head, val);
            break;
        case '7':
            tranverse(head);
            break;
        case '8':
            printf("Masukkan data yang dicari: ");
            scanf("%d", &val);
            cariData(head, val);
            break;
        case '9':
            jumlahData(head);
            break;
        case '10':
            totalData(head);
            break;
        case 'q':
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid, coba lagi.\n");
            break;
        }
    } while (pilih != 'q');

    return 0;
}

// Definisi Fungsi

void tambahAwal(node **head, int bil)
{
    node *pNew = (node *)malloc(sizeof(node));
    if (pNew)
    {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
    }
    else
    {
        printf("Alokasi memori gagal.\n");
    }
}

void tambahAkhir(node **head, int bil)
{
    node *pNew = (node *)malloc(sizeof(node));
    if (!pNew)
    {
        printf("Alokasi memori gagal.\n");
        return;
    }
    pNew->data = bil;
    pNew->next = NULL;

    if (*head == NULL)
    {
        *head = pNew;
    }
    else
    {
        node *pCur = *head;
        while (pCur->next)
        {
            pCur = pCur->next;
        }
        pCur->next = pNew;
    }
}

void tambahTengah(node **head, int bil, int pos)
{
    node *pCur = *head;
    while (pCur && pCur->data != pos)
    {
        pCur = pCur->next;
    }

    if (!pCur)
    {
        printf("Node dengan nilai %d tidak ditemukan.\n", pos);
        return;
    }

    node *pNew = (node *)malloc(sizeof(node));
    if (!pNew)
    {
        printf("Alokasi memori gagal.\n");
        return;
    }

    pNew->data = bil;
    pNew->next = pCur->next;
    pCur->next = pNew;
}

void hapusAwal(node **head)
{
    if (*head)
    {
        node *pTemp = *head;
        *head = (*head)->next;
        free(pTemp);
    }
    else
    {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
    }
}

void hapusAkhir(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        node *pCur = *head;
        while (pCur->next->next)
        {
            pCur = pCur->next;
        }
        free(pCur->next);
        pCur->next = NULL;
    }
}

void hapusTengah(node **head, int val)
{
    if (*head == NULL)
    {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    node *pCur = *head, *pPrev = NULL;
    while (pCur && pCur->data != val)
    {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (!pCur)
    {
        printf("Node dengan nilai %d tidak ditemukan.\n", val);
    }
    else
    {
        if (pPrev == NULL)
        {
            *head = pCur->next;
        }
        else
        {
            pPrev->next = pCur->next;
        }
        free(pCur);
    }
}

void tranverse(node *head)
{
    if (!head)
    {
        printf("List kosong.\n");
        return;
    }
    node *pWalker = head;
    while (pWalker)
    {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}

void cariData(node *head, int target)
{
    int index = 0;
    node *pCur = head;

    while (pCur)
    {
        if (pCur->data == target)
        {
            printf("Data %d ditemukan pada index %d\n", target, index);
            return;
        }
        pCur = pCur->next;
        index++;
    }
    printf("Data tidak ditemukan.\n");
}

void jumlahData(node *head)
{
    int count = 0;
    node *pCur = head;

    while (pCur)
    {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data dalam list adalah %d\n", count);
}

void totalData(node *head)
{
    int total = 0;
    node *pCur = head;

    while (pCur)
    {
        total += pCur->data;
        pCur = pCur->next;
    }

    printf("Total penjumlahan data dalam list adalah %d\n", total);
}
