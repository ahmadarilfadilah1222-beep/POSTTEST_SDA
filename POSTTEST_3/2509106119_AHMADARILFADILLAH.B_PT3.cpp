#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

struct Antrian {
    int id;
    string nama;
};

struct Riwayat {
    int id;
    string nama;
    string tindakan;
};

int n = 0;

int front = -1, rear = -1;
Antrian queueArr[MAX];

int top = -1;
Riwayat stackArr[MAX];

void swapData(Hewan *a, Hewan *b){
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambahData(Hewan *arr){
    int x;
    cout << "\nJumlah data: ";
    cin >> x;

    for(int i = 0; i < x; i++){
        if(n == MAX){
            cout << "\nData penuh!\n";
            return;
        }

        cout << "\nData ke-" << i+1 << endl;
        cout << "ID    : "; cin >> (arr + n)->id;
        cout << "Nama  : "; cin >> (arr + n)->nama;
        cout << "Jenis : "; cin >> (arr + n)->jenis;
        cout << "Harga : "; cin >> (arr + n)->harga;
        n++;
    }
}

void tampilData(Hewan *arr){
    if(n == 0){
        cout << "\nData kosong!\n";
        return;
    }

    cout << "\n====================================================\n";
    cout << setw(5) << "ID"
         << setw(15) << "Nama"
         << setw(15) << "Jenis"
         << setw(10) << "Harga" << endl;
    cout << "====================================================\n";

    for(int i = 0; i < n; i++){
        cout << setw(5)  << (arr + i)->id
             << setw(15) << (arr + i)->nama
             << setw(15) << (arr + i)->jenis
             << setw(10) << (arr + i)->harga << endl;
    }
}

void enqueue(Hewan *arr){
    if(rear == MAX-1){
        cout << "\nAntrian penuh! (Overflow)\n";
        return;
    }

    int id;
    cout << "\nMasukkan ID hewan: ";
    cin >> id;

    for(int i = 0; i < n; i++){
        if((arr + i)->id == id){

            if(front == -1) front = 0;

            rear++;
            queueArr[rear].id = (arr + i)->id;
            queueArr[rear].nama = (arr + i)->nama;

            cout << "\nMasuk antrian!\n";
            return;
        }
    }
    cout << "\nID tidak ditemukan!\n";
}

void dequeue(){
    if(front == -1 || front > rear){
        cout << "\nAntrian kosong! (Underflow)\n";
        return;
    }

    cout << "\nMemanggil pasien:\n";
    cout << "ID   : " << queueArr[front].id << endl;
    cout << "Nama : " << queueArr[front].nama << endl;

    if(top == MAX-1){
        cout << "\nRiwayat penuh! (Overflow)\n";
    } else {
        top++;
        stackArr[top].id = queueArr[front].id;
        stackArr[top].nama = queueArr[front].nama;
        stackArr[top].tindakan = "Diperiksa";
    }

    front++;
}

void tampilAntrian(){
    if(front == -1 || front > rear){
        cout << "\nAntrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN PASIEN ===\n";
    for(int i = front; i <= rear; i++){
        cout << "ID: " << (queueArr + i)->id
             << " | Nama: " << (queueArr + i)->nama << endl;
    }
}

void peekQueue(){
    if(front == -1 || front > rear){
        cout << "\nAntrian kosong!\n";
        return;
    }

    cout << "\nPasien terdepan:\n";
    cout << "ID   : " << queueArr[front].id << endl;
    cout << "Nama : " << queueArr[front].nama << endl;
}

void popRiwayat(){
    if(top == -1){
        cout << "\nRiwayat kosong! (Underflow)\n";
        return;
    }

    cout << "\nMenghapus riwayat:\n";
    cout << "Nama: " << stackArr[top].nama << endl;

    top--;
}

void tampilRiwayat(){
    if(top == -1){
        cout << "\nRiwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT TINDAKAN ===\n";
    for(int i = top; i >= 0; i--){
        cout << "ID: " << (stackArr + i)->id
             << " | Nama: " << (stackArr + i)->nama
             << " | Tindakan: " << (stackArr + i)->tindakan << endl;
    }
}

void peekStack(){
    if(top == -1){
        cout << "\nRiwayat kosong!\n";
        return;
    }

    cout << "\nRiwayat terakhir:\n";
    cout << "Nama: " << stackArr[top].nama
         << " | Tindakan: " << stackArr[top].tindakan << endl;
}

void resetData(Hewan* &arr){
    n = 0;
    front = rear = -1;
    top = -1;
    cout << "\nSemua data direset!\n";
}

int main(){
    Hewan data[MAX];
    Hewan* ptr = data;

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

        if(pilih == 1) tambahData(ptr);
        else if(pilih == 2) tampilData(ptr);
        else if(pilih == 3) enqueue(ptr);
        else if(pilih == 4) dequeue();
        else if(pilih == 5) tampilAntrian();
        else if(pilih == 6) popRiwayat();
        else if(pilih == 7) tampilRiwayat();
        else if(pilih == 8) peekQueue();
        else if(pilih == 9) peekStack();
        else if(pilih == 10) resetData(ptr);
        else if(pilih == 0) cout << "\nProgram selesai\n";
        else cout << "\nPilihan tidak valid!\n";

    } while(pilih != 0);

    return 0;
}
