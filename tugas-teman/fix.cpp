#include <iostream>
using namespace std;

const int Max = 6;
string arrayBuku[Max];
int top = 0;

bool isFull() 
{ // fungsi ini digunakan untuk memeriksa apakah data pada stack sudah penuh
    if( top == Max ){       // jika nilai top ( indeks teratas) sama dengan max (kapasitas maksimum data pada stack)         
        return true;            // maka kembalikan true, atau berarti stack sudah penuh
    }else{
        return false;           // Jika top belum sama dengan max, maka kembalikan false, berarti setack belum penuh
    }
}

bool isEmpty()
{ // fungsi ini digunakan untuk mengecek apakah data pada stack kosong
    if( top == 0 ){         //Jika nilai Top sama dengan 0, berarti tidak ada data pada stack     
        return true;            // maka kembalikan true, atau berarti stack kosong
    }else{
        return false;           // Jika top lebih dari 0, kembalikan false, berarti stack tidak kosong.
    }
}

void pushArray( string data ){ 
    // Fungsi ini digunakan untuk menambahkan elemen baru (push) ke dalam stack.
    if( isFull() ){  // Memeriksa apakah stack sudah penuh dengan memanggil fungsi isFull()
        cout << "Data penuh" << endl;  // Jika stack penuh, tampilkan pesan "Data penuh"
    } else {
        arrayBuku[top] = data;  // Masukkan data baru ke posisi yang ditunjuk oleh variabel top
        top++;  // Setelah menambahkan data, dan belum penuh simpan data yang baru dimasukan ke posisi teratas stack
        // top++ berarti data yang baru ditambahkan ke stack berada di paling atas stack dan setiap ada data baru yang di tambahkan 
        // data yang sebelumnya akan turun dan posisi teratas akan digantikan data yang baru dimasukan.
    }  
}

void popArray(){
    // fungsi ini digunakan untuk menghapus data teratas yang ada pada stack
    if ( isEmpty() ){ //fungsi ini digunakan untuk mengecek apakah data pada stack kosong
        cout <<"Data Kosong " << endl; //jika data pada stack kosong maka akan muncul tampilan "data kosong"
    } else{
        arrayBuku[ top -1 ] = ""; // Jika tidak kosong, hapus data teratas dengan mengatur elemen tersebut menjadi string kosong
        top--; // mengurangi nilai top untuk mengurangi jumlah data pada stack dan memindahkan posisi data karena telah di hapus
    }
} 

void viewArray(){ // fungsi ini digunakan untuk menampilkan semua data yang ada pada stack
    if ( isEmpty()){  //fungsi ini digunakan untuk mengecek apakah data pada stack kosong
        cout << " Data kosong " << endl; //jika data pada stack kosong maka akan muncul tampilan "data kosong"
    } else{
        cout <<"Data Stack Array : " << "\n"; // Menampilkan tulisan "Data Stack Array" sebelum menampilkan data stack     
        for( int i = top - 1; i >= 0; i--){  // Mulai iterasi dari indeks data teratas (top - 1) hingga indeks 0
             // Loop ini mencetak data yang ada pada stack dari yang terbaru (teratas) ke yang terlama (paling bawah) / descending                              
            if ( arrayBuku[i] != "" ){  // memeriksa apakah data pada indeks i tidak kosong dan 
                                        //mengecek apakah data stack pada indeks i berisi data (bukan string kosong)
                cout << "Data : " << arrayBuku [i] << endl; // Ini mencetak data stack yang ada, dengan format "Data : [nilai elemen  / nama data ]"
            // Jika data kosong (string kosong), maka tidak akan dicetak 
            }
        }   
        cout <<"\n" << endl; // menambahkan baris kosong
    }                                      
}

void peekArray(int posisi){        
    // Peek digunakan untuk melihat data pada posisi tertentu, oleh karena itu kita menggunakan int posisi 
    // Posisi ini dimulai dari 1 (bukan 0 seperti array biasa)
    if ( isEmpty() ){  // Jika tumpukan (stack) kosong dan kita menjalankan fungsi peek
        cout << "Data kosong" << endl;  // Maka akan ditampilkan pesan "Data kosong"
    } else {
        int index = top;  // Variabel index diset sama dengan posisi teratas tumpukan jadi posisi 1 akan dimulai dari atas Karena descending
        for ( int i = 0; i < posisi ; i++ ){  // Looping untuk mengurangi nilai index sesuai dengan posisi yang diminta
            index--;  // Setiap iterasi atau pengulangan, index akan dikurangi 1 untuk mendekati posisi yang diminta
        }
        cout << "Data posisi ke- " << posisi << " : " << arrayBuku[index] << 
        endl;  // Tampilkan nilai index (posisi yang dihitung berdasarkan nilai top dan posisi) dan 
    }             // untuk menampilkan data yang ada pada array buku pada index yang di hitung atau yang diminta
}

void changeArray( string data, int posisi ){// Fungsi ini digunakan untuk mengganti nama data di posisi tertentu dalam stack dengan data baru
    if ( isEmpty() ){  // Memeriksa apakah stack kosong
        cout << "Data kosong:" << endl;  // Jika kosong, maka akan menampilkan pesan "Data kosong"
    } else {
        int index = top;  // Variabel index diset sama dengan posisi teratas tumpukan jadi posisi 1 akan dimulai dari atas Karena descending
        for ( int i = 0; i < posisi ; i++ ){  // Looping untuk mengurangi nilai index sesuai dengan posisi yang diminta
            index--;  // Setiap iterasi atau pengulangan, index akan dikurangi 1 untuk mendekati posisi yang diminta
        }
        arrayBuku[index] = data;  // mengganti data pada posisi yang dihitung atau yang di minta dengan data baru
    }
}

int countArray(){ // Fungsi ini digunakan untuk menghitung jumlah data yang ada di stack.
    if ( isEmpty() ){  // Memeriksa apakah stack kosong menggunakan fungsi isEmpty()
        return 0;  // Jika stack kosong, kembalikan nilai 0 karena tidak ada data pada stack
    } else {
        return top;  // Jika stack tidak kosong, kembalikan nilai top, yaitu posisi data teratas dalam stack
    }                // karena perhitungan data dimulai dari bawah atau ascending jadi posisi data teratas menjadi
}                    // penentu jumlah data yang ada pada stack

void destroyArray(){// Fungsi ini digunakan untuk menghapus semua data yang ada di dalam stack dan mengatur stack kembali ke kondisi kosong.
    for ( int i = 0; i < top; i++ ){ // Loop untuk iterasi dari indeks 0 hingga top - 1
        arrayBuku[i] = "";  // Setiap elemen di arrayBuku pada indeks i diatur menjadi string kosong
    }
    top = 0; // Mengatur variabel top ke menandakan bahwa stack kosong karena semua data telah dihapus dan posisi teratas telah direset
}

// Pakai Linked List
struct dataBarang{
    string namaBarang;
    int hargaBarang;

    // Pointer
    dataBarang *prev;
    dataBarang *next;
};

dataBarang *head, *tail, *cur, *newNode, *del;
int MaxBarang = 5;

void creatBarang( string namaBarang, int hargaBarang ){
    head = new dataBarang();
    head->namaBarang = namaBarang;
    head->hargaBarang = hargaBarang;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countBarang(){
    if( head == NULL ){
        return 0;
    }else{
        int banyak = 0;
        cur = head;
        while( cur != NULL ){
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

bool isFullBarang(){
    if( countBarang() == MaxBarang ){
        return true;
    }else{
        return false;
    }
}

bool isEmptyBarang(){
    if( countBarang() == 0 ){
        return true;
    }else{
        return false;
    }
}

void pushBarang( string namaBarang, int hargaBarang ){
    if( isFullBarang() ){
        cout << "Stack Full!!" << endl;
    }else{
        if( isEmptyBarang() ){
            creatBarang(namaBarang, hargaBarang);
        }else
            newNode = new dataBarang();
            newNode->namaBarang = namaBarang;
            newNode->hargaBarang = hargaBarang;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
    }
}

void popBarang(){
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void displayBarang(){
    if( isEmptyBarang()){
        cout << "Data Barang Kosong" << endl;
    }else{
        cout << "\n\nData Barang : " << endl;
        cur = tail;
        while( cur != NULL ){
            cout << "Data Barang : " << cur->namaBarang << "- Rp." << cur->hargaBarang << endl;
            cur = cur-> prev;
        }
    }
}

void peekBarang(int posisi){
     if( isEmptyBarang()){
        cout << "Data Barang Kosong" << endl;
    }else{
        int nomor = 1;
        cur = tail;
        while( nomor < posisi ){
            cur = cur->prev;
            nomor++;
        }
        cout << "Data Barang Posisi ke- : " << posisi << ":" << cur->namaBarang << "- Rp." << cur->hargaBarang << endl;
    }
}

void changeBarang(string namaBarang, int hargaBarang, int posisi){
     if( isEmptyBarang()){
        cout << "Data Barang Kosong" << endl;
    }else{
        int nomor = 1;
        cur = tail;
        while( nomor < posisi ){
            cur = cur->prev;
            nomor++;
        }
        cur->namaBarang = namaBarang;
        cur->hargaBarang = hargaBarang;
    }
}


void destroyBarang()
{
    cur = head;
    while( cur!= NULL ){
        del = cur;
        head = head-> next;
        delete del;
        cur = cur->next;
    }
}


int main (){
    pushArray("Sistem Operasi");
    viewArray();
    pushArray("Metode Numerik");
    viewArray();
    pushArray("Struktur Data");
    viewArray();
    pushArray("Basis Data Lanjut");
    viewArray();
    pushArray("Stastik komputasi");
    viewArray();
    pushArray("Pemrograman lanjut");
    viewArray();
    pushArray("Kewirausahaan");
    viewArray();
        
    cout << "Apakah data sudah penuh ? : " << (isFull() ? "data sudah penuh" : "data belum penuh") << endl;  //menampilkan data apakah sudah penuh apa belum
    cout << "Apakah data pada stack kosong ? : " << (isEmpty() ? "data kosong" : "data tidak kosong") << endl; //menampilkan data apakah kosong

    popArray(); // untuk menghapus data yang paling atas
    viewArray(); //ini bisa di hapus untuk mempraktekan pushArray

    cout << "Apakah data sudah penuh ? : " << (isFull() ? "data sudah penuh" : "data belum penuh") << endl;  //menampilkan data apakah sudah penuh apa belum
    cout << "Apakah data pada stack kosong ? : " << (isEmpty() ? "data kosong" : "data tidak kosong") << endl;     //menampilkan data apakah data kosong

    peekArray(2); // untuk menampilkan data yang di panggil berada di posisi ke berapa

    cout << "Banyak data adalah : " << countArray() << endl; // Untuk menampilkan banyak data yang ada pada stack

    destroyArray(); // untuk menghapus semua data

    cout << "Apakah data sudah penuh ? : " << isFull() << endl; //menampilkan data apakah sudah penuh apa belum
    cout << "Apakah data pada stack kosong ? : " << isEmpty() << endl; //menampilkan data apakah data kosong


    pushBarang("RAM", 500000);
    displayBarang();

    pushBarang("Motherboard", 1000000);
    pushBarang("Monitor", 1800000);
    pushBarang("Joystick", 250000);
    pushBarang("Keyboard", 650000);
    displayBarang();
    pushBarang("Motherboard", 1500000);
    displayBarang();

    cout << "Apakah data barang sudah penuh ? : " << isFullBarang() << endl; //menampilkan data apakah sudah penuh apa belum
    cout << "Apakah data barang kosong ? : " << isEmptyBarang() << endl; //menampilkan data apakah data kosong
    cout << "Jumlah data barang : " << countBarang() << endl; //menampilkan

    popBarang();
    displayBarang();

    peekBarang(3);

    changeBarang("Webcam", 750000,2);
    displayBarang();

    destroyBarang();
    cout << "Apakah data barang sudah penuh ? : " << isFullBarang() << endl; //menampilkan data apakah sudah penuh apa belum
    cout << "Apakah data barang kosong ? : " << isEmptyBarang() << endl; //menampilkan data apakah data kosong
    cout << "Jumlah data barang : " << countBarang() << endl; //menampilkan

}
