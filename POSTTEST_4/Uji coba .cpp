#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
    Hewan* next;
};

struct NodeAntrian {
    int id;
    string nama;
    NodeAntrian* next;
};

struct NodeRiwayat {
    int id;
    string nama;
    string tindakan;
    NodeRiwayat* next;
};

Hewan* headHewan = nullptr;
NodeAntrian* frontQueue = nullptr;
NodeAntrian* rearQueue = nullptr;
NodeRiwayat* topStack = nullptr;

void swapData(Hewan* a, Hewan* b) {
    if (a == nullptr || b == nullptr) return;
    
    int tempId = a->id;
    string tempNama = a->nama;
    string tempJenis = a->jenis;
    int tempHarga = a->harga;

    a->id = b->id;
    a->nama = b->nama;
    a->jenis = b->jenis;
    a->harga = b->harga;

    b->id = tempId;
    b->nama = tempNama;
    b->jenis = tempJenis;
    b->harga = tempHarga;
}

void tambahData() {
    int x;
    cout << "\nJumlah data yang akan ditambahkan: ";
    cin >> x;

    for (int i = 0; i < x; i++) {
        Hewan* newNode = new Hewan();
        
        cout << "\nData ke-" << i + 1 << endl;
        cout << "ID    : "; cin >> newNode->id;
        cout << "Nama  : "; cin.ignore(); getline(cin, newNode->nama);
        cout << "Jenis : "; getline(cin, newNode->jenis);
        cout << "Harga : "; cin >> newNode->harga;
        
        newNode->next = nullptr;

        if (headHewan == nullptr) {
            headHewan = newNode;
        } else {
            Hewan* temp = headHewan;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    cout << "\nData berhasil ditambahkan!\n";
}

void tampilData() {
    if (headHewan == nullptr) {
        cout << "\nData kosong!\n";
        return;
    }

    cout << "\n====================================================\n";
    cout << setw(5) << "ID"
         << setw(15) << "Nama"
         << setw(15) << "Jenis"
         << setw(10) << "Harga" << endl;
    cout << "====================================================\n";

    Hewan* curr = headHewan;
    while (curr != nullptr) {
        cout << setw(5) << curr->id
             << setw(15) << curr->nama
             << setw(15) << curr->jenis
             << setw(10) << curr->harga << endl;
        curr = curr->next;
    }
}

Hewan* cariHewanById(int id) {
    Hewan* curr = headHewan;
    while (curr != nullptr) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void enqueue() {
    int id;
    cout << "\nMasukkan ID hewan untuk masuk antrian: ";
    cin >> id;

    Hewan* hewanPtr = cariHewanById(id);

    if (hewanPtr == nullptr) {
        cout << "\nID tidak ditemukan dalam data hewan!\n";
        return;
    }

    NodeAntrian* newNode = new NodeAntrian();
    newNode->id = hewanPtr->id;
    newNode->nama = hewanPtr->nama;
    newNode->next = nullptr;

    if (rearQueue == nullptr) {
        frontQueue = newNode;
        rearQueue = newNode;
    } else {
        rearQueue->next = newNode;
        rearQueue = newNode;
    }

    cout << "\n" << hewanPtr->nama << " berhasil masuk antrian!\n";
}

void dequeue() {
    if (frontQueue == nullptr) {
        cout << "\nAntrian kosong! (Underflow)\n";
        return;
    }

    NodeAntrian* temp = frontQueue;
    
    cout << "\nMemanggil pasien:\n";
    cout << "ID   : " << temp->id << endl;
    cout << "Nama : " << temp->nama << endl;

    frontQueue = frontQueue->next;
    
    if (frontQueue == nullptr) {
        rearQueue = nullptr;
    }

    NodeRiwayat* histNode = new NodeRiwayat();
    histNode->id = temp->id;
    histNode->nama = temp->nama;
    histNode->tindakan = "Diperiksa";
    histNode->next = topStack;
    topStack = histNode;

    delete temp;
}

void tampilAntrian() {
    if (frontQueue == nullptr) {
        cout << "\nAntrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN PASIEN ===\n";
    NodeAntrian* curr = frontQueue;
    while (curr != nullptr) {
        cout << "ID: " << curr->id
             << " | Nama: " << curr->nama << endl;
        curr = curr->next;
    }
}

void peekQueue() {
    if (frontQueue == nullptr) {
        cout << "\nAntrian kosong!\n";
        return;
    }
    cout << "\nPasien terdepan:\n";
    cout << "ID   : " << frontQueue->id << endl;
    cout << "Nama : " << frontQueue->nama << endl;
}

void popRiwayat() {
    if (topStack == nullptr) {
        cout << "\nRiwayat kosong! (Underflow)\n";
        return;
    }

    NodeRiwayat* temp = topStack;
    cout << "\nMenghapus riwayat teratas:\n";
    cout << "Nama: " << temp->nama << endl;
    cout << "Tindakan: " << temp->tindakan << endl;

    topStack = topStack->next;
    delete temp;
}

void tampilRiwayat() {
    if (topStack == nullptr) {
        cout << "\nRiwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT TINDAKAN (Terbaru di Atas) ===\n";
    NodeRiwayat* curr = topStack;
    while (curr != nullptr) {
        cout << "ID: " << curr->id
             << " | Nama: " << curr->nama
             << " | Tindakan: " << curr->tindakan << endl;
        curr = curr->next;
    }
}

void peekStack() {
    if (topStack == nullptr) {
        cout << "\nRiwayat kosong!\n";
        return;
    }
    cout << "\nRiwayat terakhir:\n";
    cout << "Nama: " << topStack->nama
         << " | Tindakan: " << topStack->tindakan << endl;
}

void resetData() {
    Hewan* currH = headHewan;
    while (currH != nullptr) {
        Hewan* nextH = currH->next;
        delete currH;
        currH = nextH;
    }
    headHewan = nullptr;

    NodeAntrian* currQ = frontQueue;
    while (currQ != nullptr) {
        NodeAntrian* nextQ = currQ->next;
        delete currQ;
        currQ = nextQ;
    }
    frontQueue = nullptr;
    rearQueue = nullptr;

    NodeRiwayat* currS = topStack;
    while (currS != nullptr) {
        NodeRiwayat* nextS = currS->next;
        delete currS;
        currS = nextS;
    }
    topStack = nullptr;

    cout << "\nSemua data dan memori telah direset!\n";
}

int main() {
    int pilih;

    do {
        cout << "\n\n=== PAWCARE PETSHOP ===";
        cout << "\n1. Tambah Data Hewan";
        cout << "\n2. Tampil Data Hewan";
        cout << "\n3. Enqueue (Masuk Antrian)";
        cout << "\n4. Dequeue (Panggil Pasien)";
        cout << "\n5. Tampil Antrian";
        cout << "\n6. Peek Antrian";
        cout << "\n7. Pop Riwayat (Hapus Terakhir)";
        cout << "\n8. Tampil Riwayat";
        cout << "\n9. Peek Riwayat";
        cout << "\n10. Reset Semua Data";
        cout << "\n0. Keluar";
        cout << "\nPilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: tampilAntrian(); break;
            case 6: peekQueue(); break;
            case 7: popRiwayat(); break;
            case 8: tampilRiwayat(); break;
            case 9: peekStack(); break;
            case 10: resetData(); break;
            case 0: cout << "\nProgram selesai. Terima kasih!\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }

    } while (pilih != 0);

    resetData();

    return 0;
}
