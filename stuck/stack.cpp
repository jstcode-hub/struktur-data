#include <iostream>

using namespace std;

const int MAX_CAPACITY = 10; // Kapasitas maksimum stack

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *topNode;
    int count; 
    
public:
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    void push(int bil) {
        if (isFull()) {
            cout << "Stack penuh, tidak dapat menambahkan data." << endl;
            return;
        }
        Node *newNode = new Node;
        if (newNode == nullptr) {
            cout << "Alokasi memori gagal" << endl;
            return;
        }
        newNode->data = bil;
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada data yang dihapus." << endl;
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return -1; 
        }
        return topNode->data;
    }

    bool isEmpty() {
        if (topNode == nullptr) {
            cout << "Stack kosong." << endl;
            return true;
        } else {
            cout << "Stack tidak kosong, terisi " << count << " elemen." << endl;
            return false;
        }
    }

    bool isFull() {
        if (count >= MAX_CAPACITY) {
            cout << "Stack penuh." << endl;
            return true;
        } else {
            cout << "Stack belum penuh, tersisa " << (MAX_CAPACITY - count) << " slot." << endl;
            return false;
        }
    }

    int stackCount() {
        return count;
    }

    void destroy() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack berhasil dihapus." << endl;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return;
        }
        Node *temp = topNode;
        cout << "Isi stack (dari atas ke bawah): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        destroy();
    }
};

int main() {
    Stack stack;
    char pilih;
    int bil;

    do {
        cout << "\nMasukkan pilihan:\n";
        cout << "1. Push stack (tambah data)\n";
        cout << "2. Pop stack (hapus data di puncak)\n";
        cout << "3. Stack top (lihat data di puncak)\n";
        cout << "4. Empty stack (cek apakah kosong)\n";
        cout << "5. Full stack (cek apakah penuh)\n";
        cout << "6. Stack count (jumlah elemen dalam stack)\n";
        cout << "7. Destroy stack (hapus semua elemen)\n";
        cout << "8. Print stack (tampilkan isi stack)\n";
        cout << "q. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        switch (pilih) {
            case '1':
                cout << "Masukkan bilangan: ";
                cin >> bil;
                stack.push(bil);
                break;
            case '2':
                stack.pop();
                break;
            case '3':
                cout << "Data di puncak: " << stack.top() << endl;
                break;
            case '4':
                stack.isEmpty();
                break;
            case '5':
                stack.isFull();
                break;
            case '6':
                cout << "Jumlah elemen: " << stack.stackCount() << endl;
                break;
            case '7':
                stack.destroy();
                break;
            case '8':
                stack.print();
                break;
            case 'q':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih != 'q');

    return 0;
}
