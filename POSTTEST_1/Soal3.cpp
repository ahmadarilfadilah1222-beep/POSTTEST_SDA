#include <iostream>
using namespace std;

void tampilkanArray(int* arr, int n) {
    int* p = arr; 
    for (int i = 0; i < n; i++) {
        cout << "Elemen [" << i << "] = " << *p 
             << " | Alamat: " << p << endl;
        p++;  
    }
}

void reverseArray(int* arr, int n) {
    int* start = arr;           
    int* end = arr + n - 1;     

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;  
        end--;    
    }
}

int main() {
    cout << "\n======================================="  << endl;
    cout << "=       Soal 3: Array & Pointer       ="    << endl;
    cout << "======================================="    << endl;
    
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;
    
    cout << "\n======================================="  << endl;
    cout << "         Array Sebelum Dibalik:        "    << endl;
    cout << "======================================="    << endl;
    tampilkanArray(prima, n);
    cout << "======================================="    << endl;
    
    reverseArray(prima, n);
    
    cout << "\n======================================="  << endl;
    cout << "         Array Sesudah Dibalik:        "    << endl;
    cout << "======================================="    << endl;
    tampilkanArray(prima, n);
    cout << "======================================="    << endl;

    return 0;
}