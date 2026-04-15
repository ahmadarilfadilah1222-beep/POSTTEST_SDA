#include <iostream>
#include <iomanip>
using namespace std;

// ================== STRUCT ==================
struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
    Hewan* next;
};

struct Antrian {
    int id;
    string nama;
    Antrian* next;
};

struct Riwayat {
    int id;
    string nama;
    string tindakan;
    Riwayat* next;
};

// ================== GLOBAL ==================
Hewan* head = NULL;

Antrian* front = NULL;
Antrian* rear = NULL;

Riwayat* top = NULL;

// ================== TAMBAH DATA ==================
void tambahData(Hewan* &head){
    int x;
    cout << "\nJumlah data: ";
    cin >> x;

    for(int i = 0; i < x; i++){
        Hewan* baru = new Hewan;

        cout << "\nData ke-" << i+1 << endl;
        cout << "ID    : "; cin >> baru->id;
        cout << "Nama  : "; cin >> baru->nama;
        cout << "Jenis : "; cin >> baru->jenis;
        cout << "Harga : "; cin >> baru->harga;
        baru->next = NULL;

        if(head == NULL){
            head = baru;
        } else {
            Hewan* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = baru;
        }
    }
}

// ================== TAMPIL DATA ==================
void tampilData(Hewan* head){
    if(head == NULL){
        cout << "\nData kosong!\n";
        return;
    }

    cout << "\n============================================\n";
    cout << setw(5) << "ID"
         << setw(15) << "Nama"
         << setw(15) << "Jenis"
         << setw(10) << "Harga" << endl;
    cout << "============================================\n";

    Hewan* temp = head;
    while(temp != NULL){
        cout << setw(5)  << temp->id
             << setw(15) << temp->nama
             << setw(15) << temp->jenis
             << setw(10) << temp->harga << endl;
        temp = temp->next;
    }
}

// ================== ENQUEUE ==================
void enqueue(Hewan* head){
    if(head == NULL){
        cout << "\nData hewan kosong!\n";
        return;
    }

    int id;
    cout << "\nMasukkan ID hewan: ";
    cin >> id;

    Hewan* temp = head;
    while(temp != NULL){
        if(temp->id == id){
            Antrian* baru = new Antrian;
            baru->id = temp->id;
            baru->nama = temp->nama;
            baru->next = NULL;

            if(front == NULL){
                front = rear = baru;
            } else {
                rear->next = baru;
                rear = baru;
            }

            cout << "\nMasuk antrian!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "\nID tidak ditemukan!\n";
}

// ================== DEQUEUE ==================
void dequeue(){
    if(front == NULL){
        cout << "\nAntrian kosong! (Underflow)\n";
        return;
    }

    Antrian* hapus = front;

    cout << "\nMemanggil pasien:\n";
    cout << "ID   : " << hapus->id << endl;
    cout << "Nama : " << hapus->nama << endl;

    // PUSH ke stack
    Riwayat* baru = new Riwayat;
    baru->id = hapus->id;
    baru->nama = hapus->nama;
    baru->tindakan = "Diperiksa";
    baru->next = top;
    top = baru;

    front = front->next;
    delete hapus;

    if(front == NULL){
        rear = NULL;
    }
}

// ================== TAMPIL ANTRIAN ==================
void tampilAntrian(){
    if(front == NULL){
        cout << "\nAntrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    Antrian* temp = front;
    while(temp != NULL){
        cout << "ID: " << temp->id
             << " | Nama: " << temp->nama << endl;
        temp = temp->next;
    }
}

// ================== PEEK QUEUE ==================
void peekQueue(){
    if(front == NULL){
        cout << "\nAntrian kosong!\n";
        return;
    }

    cout << "\nTerdepan:\n";
    cout << "ID   : " << front->id << endl;
    cout << "Nama : " << front->nama << endl;
}

// ================== POP ==================
void popRiwayat(){
    if(top == NULL){
        cout << "\nRiwayat kosong! (Underflow)\n";
        return;
    }

    Riwayat* hapus = top;
    cout << "\nHapus riwayat: " << hapus->nama << endl;

    top = top->next;
    delete hapus;
}

// ================== TAMPIL RIWAYAT ==================
void tampilRiwayat(){
    if(top == NULL){
        cout << "\nRiwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    Riwayat* temp = top;
    while(temp != NULL){
        cout << "ID: " << temp->id
             << " | Nama: " << temp->nama
             << " | Tindakan: " << temp->tindakan << endl;
        temp = temp->next;
    }
}

// ================== PEEK STACK ==================
void peekStack(){
    if(top == NULL){
        cout << "\nRiwayat kosong!\n";
        return;
    }

    cout << "\nTerakhir:\n";
    cout << top->nama << " - " << top->tindakan << endl;
}

// ================== RESET ==================
void resetData(){
    head = NULL;
    front = rear = NULL;
    top = NULL;
    cout << "\nSemua data direset!\n";
}

// ================== MAIN ==================
int main(){
    int pilih;

    do{
        cout << "\n=== PAWCARE PETSHOP ===";
        cout << "\n1. Tambah Data";
        cout << "\n2. Tampil Data";
        cout << "\n3. Enqueue";
        cout << "\n4. Dequeue";
        cout << "\n5. Tampil Antrian";
        cout << "\n6. Pop Riwayat";
        cout << "\n7. Tampil Riwayat";
        cout << "\n8. Peek Antrian";
        cout << "\n9. Peek Riwayat";
        cout << "\n10. Reset";
        cout << "\n0. Keluar";
        cout << "\nPilih: ";
        cin >> pilih;

        if(pilih == 1) tambahData(head);
        else if(pilih == 2) tampilData(head);
        else if(pilih == 3) enqueue(head);
        else if(pilih == 4) dequeue();
        else if(pilih == 5) tampilAntrian();
        else if(pilih == 6) popRiwayat();
        else if(pilih == 7) tampilRiwayat();
        else if(pilih == 8) peekQueue();
        else if(pilih == 9) peekStack();
        else if(pilih == 10) resetData();
        else if(pilih == 0) cout << "\nProgram selesai\n";
        else cout << "\nPilihan tidak valid!\n";

    } while(pilih != 0);

    return 0;
}