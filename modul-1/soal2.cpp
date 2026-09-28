#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };

    string puluhan[] = {
        "", "", "dua puluh", "tiga puluh", "empat puluh",
        "lima puluh", "enam puluh", "tujuh puluh",
        "delapan puluh", "sembilan puluh"
    };

    if (angka == 100) {
        cout << "seratus";
    }
    else if (angka < 10) {
        cout << satuan[angka];
    }
    else if (angka == 10) {
        cout << "sepuluh";
    }
    else if (angka == 11) {
        cout << "sebelas";
    }
    else if (angka < 20) {
        cout << satuan[angka - 10] << " belas";
    }
    else {
        cout << puluhan[angka / 10];

        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }

    return 0;
}