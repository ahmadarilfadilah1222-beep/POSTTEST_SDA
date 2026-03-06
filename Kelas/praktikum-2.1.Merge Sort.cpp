#include <iostream>
#include <string>
using namespace std;

// Definisi Struct
struct Produk {
    int id;
    string nama;
    int harga;
};

// Fungsi untuk menggabungkan dua bagian array Produk
void merge(Produk* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Membuat array sementara
    Produk* L = new Produk[n1];
    Produk* R = new Produk[n2];

    // Menyalin data ke array sementara
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);

    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;

    // Proses penggabungan berdasarkan harga
    while (i < n1 && j < n2) {
        if ((L + i)->harga <= (R + j)->harga) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    // Menyalin sisa elemen
    while (i < n1) {
        *(arr + k) = *(L + i);
        i++;
        k++;
    }

    while (j < n2) {
        *(arr + k) = *(R + j);
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Fungsi rekursif Merge Sort
void mergeSort(Produk* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Fungsi menampilkan data
void tampilkanData(Produk* arr, int n) {
    cout << "ID\tNama\tHarga" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < n; i++) {
        Produk* ptr = (arr + i);
        cout << ptr->id << "\t" << ptr->nama << "\t" << ptr->harga << endl;
    }

    cout << endl;
}

int main() {
    int n = 4;

    // Inisialisasi Array of Struct
    Produk daftarProduk[4] = {
        {101, "Laptop", 8000},
        {102, "Mouse", 150},
        {103, "Monitor", 2500},
        {104, "Keyboard", 500}
    };

    cout << "Data Sebelum Sorting (Berdasarkan Harga):" << endl;
    tampilkanData(daftarProduk, n);

    // Memanggil Merge Sort
    mergeSort(daftarProduk, 0, n - 1);

    cout << "Data Setelah Sorting (Merge Sort O(n log n)):" << endl;
    tampilkanData(daftarProduk, n);

    return 0;
}