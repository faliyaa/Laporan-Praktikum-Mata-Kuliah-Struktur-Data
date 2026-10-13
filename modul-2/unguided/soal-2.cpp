#include <iostream>
using namespace std;

void tukarDua(int *p, int *q) {
    int sementara = *p;
    *p = *q;
    *q = sementara;
}

void tukar(int *a, int *b, int *c) {
    tukarDua(a, b);
    tukarDua(b, c);
}

void tampil(int a, int b, int c) {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:" << endl;
    tampil(a, b, c);

    tukar(&a, &b, &c);

    cout << "\nSetelah ditukar:" << endl;
    tampil(a, b, c);

    return 0;
}