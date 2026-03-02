#include <iostream>
using namespace std;
void FindMin(int A[], int n, int &minValue, int &minIndex) {
    minValue = A[0];
    minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < minValue) {
            minValue = A[i];
            minIndex = i;
        }
    }
}

int main() {
    int fib[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int minVal, minIdx;

    FindMin(fib, n, minVal, minIdx);
    cout << "\n========================="   << endl;
    cout << "=    Soal 1: FindMin    = "    << endl;
    cout << "========================="     << endl;
    cout << " Nilai Minimum :" << minVal    << endl;
    cout << " Indeks Minimum:" << minIdx    << endl;
    cout << "========================="     << endl;

    return 0;
}