#include <iostream>
#include <iomanip>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

int n = 0;

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
        cout << "\nData ke-" << i+1 << endl;
        cout << "ID    : "; cin >> (arr + n)->id;
        cout << "Nama  : "; cin >> (arr + n)->nama;
        cout << "Jenis : "; cin >> (arr + n)->jenis;
        cout << "Harga : "; cin >> (arr + n)->harga;
        n++;
    }
}

void tampilData(Hewan *arr){
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

void linearSearch(Hewan *arr){
    string cari;
    cout << "\nCari nama: ";
    cin >> cari;

    for(int i = 0; i < n; i++){
        if((arr + i)->nama == cari){
            cout << "\nData ditemukan!\n";
            cout << "ID    : " << (arr + i)->id << endl;
            cout << "Nama  : " << (arr + i)->nama << endl;

            swapData((arr + i), (arr + 0));
            return;
        }
    }
    cout << "\nData tidak ditemukan!\n";
}

void fibonacciSearch(Hewan *arr){
    int x;
    cout << "\nCari ID: ";
    cin >> x;

    int fib2 = 0, fib1 = 1, fib = 1;

    while(fib < n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    cout << "\nProses pencarian:\n";

    while(fib > 1){
        int i = offset + fib2;
        if(i >= n) i = n - 1;

        cout << "Cek index " << i 
             << " (ID: " << (arr + i)->id << ")\n";

        if((arr + i)->id < x){
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if((arr + i)->id > x){
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else{
            cout << "\nData ditemukan!\n";
            cout << "Nama: " << (arr + i)->nama << endl;

            swapData((arr + i), (arr + 0));
            return;
        }
    }

    cout << "\nData tidak ditemukan!\n";
}

void bubbleSort(Hewan *arr){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if((arr + j)->nama > (arr + j + 1)->nama){
                swapData((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "\nData diurutkan berdasarkan nama\n";
}

void selectionSort(Hewan *arr){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if((arr + j)->harga < (arr + min)->harga){
                min = j;
            }
        }
        swapData((arr + i), (arr + min));
    }
    cout << "\nData diurutkan berdasarkan harga\n";
}

void resetData(Hewan* &arr){
    n = 0;
    arr = arr;
    cout << "\nData berhasil direset!\n";
}

int main(){
    Hewan data[100];
    Hewan* ptr = data;

    int pilih;

    do{
        cout << "\n=== PAWCARE PETSHOP ===";
        cout << "\n1. Tambah Data";
        cout << "\n2. Tampil Data";
        cout << "\n3. Linear Search";
        cout << "\n4. Fibonacci Search";
        cout << "\n5. Bubble Sort (Nama)";
        cout << "\n6. Selection Sort (Harga)";
        cout << "\n7. Reset Data";
        cout << "\n0. Keluar";
        cout << "\nPilih: ";
        cin >> pilih;

        if(pilih == 1){
            tambahData(ptr);
        }
        else if(pilih == 2){
            tampilData(ptr);
        }
        else if(pilih == 3){
            linearSearch(ptr);
        }
        else if(pilih == 4){
            fibonacciSearch(ptr);
        }
        else if(pilih == 5){
            bubbleSort(ptr);
        }
        else if(pilih == 6){
            selectionSort(ptr);
        }
        else if(pilih == 7){
            resetData(ptr);
        }
        else if(pilih == 0){
            cout << "\nProgram selesai\n";
        }
        else{
            cout << "\nPilihan tidak valid!\n";
        }

    } while(pilih != 0);

    return 0;
}
