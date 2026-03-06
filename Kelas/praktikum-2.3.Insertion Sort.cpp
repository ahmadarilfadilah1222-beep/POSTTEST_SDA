#include <iostream>
#include <string>

using namespace std;

// Definisi struktur data buku
struct Buku {
    int idBuku;
    string judul;
};

// Insertion sort dengan akses pointer
void insertionSort(Buku *rak, int n) {
    // mulai dari buku ke‑2 (index 1)
    for (int i = 1; i < n; ++i) {
        Buku key = *(rak + i);
        int j = i - 1;

        // cari posisi yang tepat untuk key
        while (j >= 0 && (rak + j)->idBuku > key.idBuku) {
            // geser buku yang lebih besar ke kanan
            *(rak + j + 1) = *(rak + j);
            --j;
        }
        // letakkan key di slot yang kosong
        *(rak + j + 1) = key;
    }
}

// tampilkan daftar buku di rak
void tampilkanRak(Buku *rak, int n) {
    cout << "ID\t| Judul Buku\n";
    cout << "--------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << (rak + i)->idBuku << "\t| " << (rak + i)->judul << '\n';
    }
    cout << '\n';
}

int main() {
    const int n = 5;

    // --- SKENARIO 1: BEST CASE ---
    // buku sudah terurut dari ID terkecil ke terbesar
    Buku rakUrut[] = {
        {101, "Laskar Pelangi"},
        {102, "Bumi Manusia"},
        {103, "Negeri 5 Menara"},
        {104, "Filosofi Teras"},
        {105, "Hujan"}
    };

    cout << ">>> SKENARIO: BEST CASE (Sudah Terurut) <<<\n";
    cout << "Data Sebelum: (Sudah rapi)\n";
    insertionSort(rakUrut, n);
    tampilkanRak(rakUrut, n);
    cout << "Analisis: Loop 'while' tidak pernah berjalan. Hanya perlu n iterasi.\n";
    cout << "Kompleksitas Waktu: O(n)\n";
    cout << "------------------------------------------\n\n";

    // --- SKENARIO 2: WORST CASE ---
    // buku terurut terbalik (ID terbesar di depan)
    Buku rakTerbalik[] = {
        {105, "Hujan"},
        {104, "Filosofi Teras"},
        {103, "Negeri 5 Menara"},
        {102, "Bumi Manusia"},
        {101, "Laskar Pelangi"}
    };

    cout << ">>> SKENARIO: WORST CASE (Terurut Terbalik) <<<\n";
    cout << "Data Sebelum:\n";
    tampilkanRak(rakTerbalik, n);

    insertionSort(rakTerbalik, n);
    cout << "Data Sesudah (Berhasil Diurutkan):\n";
    tampilkanRak(rakTerbalik, n);
    cout << "Analisis: Setiap buku harus dibandingkan dan digeser ke posisi paling awal.\n";
    cout << "Kompleksitas Waktu: O(n^2)\n";

    return 0;
}