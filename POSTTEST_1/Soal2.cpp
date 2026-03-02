#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama_mahasiswa;
    string nim_mahasiswa;
    float ipk_mahasiswa;
};

int main() {
    const int JUMLAH = 5;
    Mahasiswa mhs[JUMLAH]; 
    
    cout << "\n=========================================" << endl;
    cout << "= Soal 2: Struct + Array Data Mahasiswa ="   << endl;
    cout << "========================================="   << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << "\n=========================================" << endl;
        cout << "             Mahasiswa ke-" << (i + 1)       << endl;
        cout << "========================================="   << endl;
        
        cout << "Nama: "; 
        cin >> mhs[i].nama_mahasiswa;
        
        cout << "NIM: "; 
        cin >> mhs[i].nim_mahasiswa;
        
        cout << "IPK: "; 
        cin >> mhs[i].ipk_mahasiswa;
        
        cin.ignore(100, '\n');
        
        cout << "========================================="   << endl;
    }

    int idxTertinggi = 0;
    float maxIPK = mhs[0].ipk_mahasiswa;

    for (int i = 1; i < JUMLAH; i++) {
        if (mhs[i].ipk_mahasiswa > maxIPK) {
            maxIPK = mhs[i].ipk_mahasiswa;
            idxTertinggi = i;
        }
    }


    cout << "\n=========================================" << endl;
    cout << "     Mahasiswa dengan IPK Tertinggi:     "   << endl;
    cout << "========================================="   << endl;
    cout << "Nama: " << mhs[idxTertinggi].nama_mahasiswa  << endl;
    cout << "NIM : " << mhs[idxTertinggi].nim_mahasiswa   << endl;
    cout << "IPK : " << mhs[idxTertinggi].ipk_mahasiswa   << endl;
    cout << "========================================="   << endl;
    return 0;
}