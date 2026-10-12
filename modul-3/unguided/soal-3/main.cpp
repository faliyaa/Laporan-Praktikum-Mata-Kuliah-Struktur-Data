#include <iostream>
using namespace std;

void tampilArray(int arr[3][3], const char nama[]) {
    cout << nama << ":\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}

void tukarPosisiArray(int a[3][3], int b[3][3],
                      int baris, int kolom) {
    int sementara = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = sementara;
}

void tukarPointer(int *p1, int *p2) {
    int sementara = *p1;
    *p1 = *p2;
    *p2 = sementara;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int x = 100;
    int y = 200;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Sebelum pertukaran:\n";
    tampilArray(A, "Array A");
    tampilArray(B, "Array B");

    // Menukar elemen pada baris ke-2, kolom ke-3 (indeks 1, 2).
    tukarPosisiArray(A, B, 1, 2);

    cout << "\nSetelah elemen A[1][2] dan B[1][2] ditukar:\n";
    tampilArray(A, "Array A");
    tampilArray(B, "Array B");

    cout << "\nSebelum tukar pointer: x = " << x
         << ", y = " << y << '\n';
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x = " << x
         << ", y = " << y << '\n';

    return 0;
}