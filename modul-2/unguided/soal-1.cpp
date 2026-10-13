#include <iostream>
using namespace std;

const int UKURAN = 3;

void bacaMatriks(int m[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cin >> m[baris][kolom];
        }
    }
}

void tampilMatriks(int m[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cout << m[baris][kolom] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int p[UKURAN][UKURAN], int q[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++)
        for (int kolom = 0; kolom < UKURAN; kolom++)
            hasil[baris][kolom] = p[baris][kolom] + q[baris][kolom];
}

void kurangMatriks(int p[UKURAN][UKURAN], int q[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++)
        for (int kolom = 0; kolom < UKURAN; kolom++)
            hasil[baris][kolom] = p[baris][kolom] - q[baris][kolom];
}

void kaliMatriks(int p[UKURAN][UKURAN], int q[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            int total = 0;
            for (int k = 0; k < UKURAN; k++) {
                total += p[baris][k] * q[k][kolom];
            }
            hasil[baris][kolom] = total;
        }
    }
}

int main() {
    int matA[UKURAN][UKURAN], matB[UKURAN][UKURAN];
    int hasilTambah[UKURAN][UKURAN], hasilKurang[UKURAN][UKURAN], hasilKali[UKURAN][UKURAN];

    cout << "Masukkan elemen matriks A (3x3):\n";
    bacaMatriks(matA);

    cout << "\nMasukkan elemen matriks B (3x3):\n";
    bacaMatriks(matB);

    jumlahMatriks(matA, matB, hasilTambah);
    kurangMatriks(matA, matB, hasilKurang);
    kaliMatriks(matA, matB, hasilKali);

    cout << "\nHasil Penjumlahan:\n";
    tampilMatriks(hasilTambah);

    cout << "\nHasil Pengurangan:\n";
    tampilMatriks(hasilKurang);

    cout << "\nHasil Perkalian:\n";
    tampilMatriks(hasilKali);

    return 0;
}