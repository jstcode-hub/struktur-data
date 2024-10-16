#include <iostream>
#include <limits> 
using namespace std;

struct Node {
    int data;
    Node* next;
};

void tambahAwal(Node** head);
void tambahData(Node** head);
void hapusAwal(Node** head);
void hapusAkhir(Node** head);
void hapusData(Node** head, int val);
void traverse(Node* head);
bool isDuplicate(Node* head, int data);
int countNodes(Node* head);
int sumNodes(Node* head);
void pauseScreen(); 

int main() {
    Node* head = nullptr; 
    char pilih;

    do {
        cout << "Masukkan Pilihan" << endl;
        cout << "1. Tambah data di awal" << endl;
        cout << "2. Tambah data di tengah list" << endl;
        cout << "3. Hapus data di awal" << endl;
        cout << "4. Cetak isi list" << endl;
        cout << "5. Hapus data di akhir" << endl;
        cout << "6. Hapus data tertentu" << endl;
        cout << "7. Jumlah total node" << endl;
        cout << "8. Jumlahkan semua data" << endl;
        cout << "MASUKKAN PILIHAN (tekan q untuk keluar) : ";
        cin >> pilih;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            pilih = 'x'; 
        }

        switch (pilih) {
            case '1':
                tambahAwal(&head);
                break;
            case '2':
                tambahData(&head);
                break;
            case '3':
                hapusAwal(&head);
                break;
            case '4':
                traverse(head);
                pauseScreen();
                break;
            case '5':
                hapusAkhir(&head);
                break;
            case '6': {
                int val;
                traverse(head);                
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> val;
                hapusData(&head, val);
                break;
            }
            case '7':
                cout << "Jumlah total node di linked list: " << countNodes(head) << endl;
                pauseScreen();
                break;
            case '8':
                cout << "Jumlah semua data di linked list: " << sumNodes(head) << endl;
                pauseScreen();
                break;
            case 'q':
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                pauseScreen();
                break;
        }
    } while (pilih != 'q');

    return 0;
}

void pauseScreen() {
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
}

void tambahAwal(Node** head) {
    int bil;
    cout << "Masukkan bilangan: ";
    cin >> bil;

    if (isDuplicate(*head, bil)) {
        cout << "Nilai " << bil << " sudah ada di linked list. Input akan diskip." << endl;
        pauseScreen();
        return;
    }

    Node* pNew = new Node();
    if (pNew != nullptr) {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
    } else {
        cout << "Alokasi memori gagal" << endl;
        pauseScreen();
    }
}

void tambahData(Node** head) {
    int pos, bil;
    char pilihan;
    traverse(*head);
    cout << "\nPilih untuk menyisipkan node:" << endl;
    cout << "1. Sebelum data tertentu" << endl;
    cout << "2. Setelah data tertentu" << endl;
    cout << "Pilihan (1/2): ";
    cin >> pilihan;

    cout << "\nMasukkan nilai data referensi: ";
    cin >> pos;
    cout << "\nMasukkan nilai bilangan baru: ";
    cin >> bil;

    if (isDuplicate(*head, bil)) {
        cout << "Nilai " << bil << " sudah ada di linked list. Input akan diskip." << endl;
        pauseScreen();
        return;
    }

    Node* pNew = new Node();
    if (pNew == nullptr) {
        cout << "Alokasi memori gagal" << endl;
        pauseScreen();
        return;
    }
    pNew->data = bil;

    if (pilihan == '1') {

        if (*head != nullptr && (*head)->data == pos) {
            pNew->next = *head;
            *head = pNew;
        } else {
            Node* current = *head;
            Node* previous = nullptr;

            while (current != nullptr && current->data != pos) {
                previous = current;
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Node dengan nilai " << pos << " tidak ditemukan." << endl;
                delete pNew;
                pauseScreen();
                return;
            }

            pNew->next = current;
            if (previous != nullptr) {
                previous->next = pNew;
            }
        }
    } 

    else if (pilihan == '2') {
        Node* current = *head;
        while (current != nullptr && current->data != pos) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "\nNode tidak ditemukan." << endl;
            delete pNew; 
            pauseScreen();
            return;
        }

        pNew->next = current->next;
        current->next = pNew;
    } else {
        cout << "Pilihan tidak valid." << endl;
        delete pNew; 
    }

    pauseScreen();
}

bool isDuplicate(Node* head, int data) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == data) {
            return true;  
        }
        temp = temp->next;
    }
    return false;  
}

void traverse(Node* head) {
    Node* pWalker = head;
    while (pWalker != nullptr) {
        cout << pWalker->data << " -> ";
        pWalker = pWalker->next;
    }
    cout << "NULL" << endl;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sumNodes(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

void hapusAwal(Node** head) {
    if (*head == nullptr) {
        cout << "Linked list kosong. Tidak ada node yang bisa dihapus." << endl;
        pauseScreen();
        return;
    }
    Node* temp = *head;
    *head = (*head)->next; 
    delete temp;
    cout << "Node pertama telah dihapus." << endl;
    pauseScreen();
}

void hapusAkhir(Node** head) {
    if (*head == nullptr) {
        cout << "Linked list kosong. Tidak ada node yang bisa dihapus." << endl;
        pauseScreen();
        return;
    }

    Node* temp = *head;
    Node* prev = nullptr;

    if (temp->next == nullptr) {
        delete temp;
        *head = nullptr;
    } else {
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }
    cout << "Node terakhir telah dihapus." << endl;
    pauseScreen();
}

void hapusData(Node** head, int val) {
    if (*head == nullptr) {
        cout << "Linked list kosong. Tidak ada node yang bisa dihapus." << endl;
        pauseScreen();
        return;
    }

    Node* temp = *head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == val) {
        *head = temp->next;
        delete temp;
        cout << "Node dengan nilai " << val << " telah dihapus." << endl;
        pauseScreen();
        return;
    }

    while (temp != nullptr && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node dengan nilai " << val << " tidak ditemukan." << endl;
        pauseScreen();
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node dengan nilai " << val << " telah dihapus." << endl;
    traverse(*head);
    pauseScreen();
}
