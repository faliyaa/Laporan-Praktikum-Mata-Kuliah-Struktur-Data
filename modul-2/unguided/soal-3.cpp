#include <iostream>
using namespace std;

int cariMinimum(int data[], int jumlah) {
    int terkecil = data[0];
    for (int idx = 1; idx < jumlah; idx++) {
        if (data[idx] < terkecil)
            terkecil = data[idx];
    }
    return terkecil;
}

int cariMaksimum(int data[], int jumlah) {
    int terbesar = data[0];
    for (int idx = 1; idx < jumlah; idx++) {
        if (data[idx] > terbesar)
            terbesar = data[idx];
    }
    return terbesar;
}

void hitungRataRata(int data[], int jumlah) {
    int total = 0;
    for (int idx = 0; idx < jumlah; idx++)
        total += data[idx];

    cout << "Nilai rata-rata = " << (float) total / jumlah << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int banyak = sizeof(arrA) / sizeof(arrA[0]);
    int menu = 0;

    while (menu != 5) {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "\nIsi array: ";
                for (int idx = 0; idx < banyak; idx++)
                    cout << arrA[idx] << " ";
                cout << endl;
                break;
            case 2:
                cout << "\nNilai maksimum = " << cariMaksimum(arrA, banyak) << endl;
                break;
            case 3:
                cout << "\nNilai minimum = " << cariMinimum(arrA, banyak) << endl;
                break;
            case 4:
                cout << "\n";
                hitungRataRata(arrA, banyak);
                break;
            case 5:
                cout << "\nProgram selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }
    }

    return 0;
}