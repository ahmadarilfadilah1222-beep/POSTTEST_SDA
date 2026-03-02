#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << "\n=================================" << endl;
    cout << "= Soal 4: Pointer pada Fungsi   ="   << endl;
    cout << "================================="   << endl;
    
    int x, y;
    
    cout << "\n=================================" << endl;
    cout << "Masukkan nilai ke-1 (x): ";
    cin >> x;
    cout << "Masukkan nilai ke-2 (y): ";
    cin >> y;
    cout << "================================="   << endl;

    cout << "\n=================================" << endl;
    cout << "     Sebelum pertukaran:           " << endl;
    cout << "================================="   << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "================================="   << endl;


    tukar(x, y);
    cout << "\n=================================" << endl;
    cout << "\nSesudah pertukaran:" << endl;
    cout << "================================="   << endl;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "================================="   << endl;

    return 0;
}