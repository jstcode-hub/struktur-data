#include <stdio.h>
#include <stdlib.h>

// Definisi node dari linked list
struct Node
{
    int data;
    struct Node *next;
};

// Fungsi untuk menambahkan node di depan linked list
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Fungsi untuk mencetak linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    printList(head);

    return 0;
}
