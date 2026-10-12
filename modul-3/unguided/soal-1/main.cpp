#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3f * uts + 0.4f * uas + 0.3f * tugas;
}

int main() {
    Mahasiswa data[10];
    int jumlah;

    cout << "Jumlah mahasiswa (1-10): ";
    cin >> jumlah;

    if (jumlah < 1 || jumlah > 10) {
        cout << "Jumlah mahasiswa harus antara 1 sampai 10.\n";
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << '\n';
        cout << "Nama  : ";
        getline(cin >> ws, data[i].nama);
        cout << "NIM   : ";
        cin >> data[i].nim;
        cout << "Nilai UTS   : ";
        cin >> data[i].uts;
        cout << "Nilai UAS   : ";
        cin >> data[i].uas;
        cout << "Nilai Tugas : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(
            data[i].uts, data[i].uas, data[i].tugas
        );
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << '\n';
        cout << "Nama        : " << data[i].nama << '\n';
        cout << "NIM         : " << data[i].nim << '\n';
        cout << "Nilai UTS   : " << data[i].uts << '\n';
        cout << "Nilai UAS   : " << data[i].uas << '\n';
        cout << "Nilai Tugas : " << data[i].tugas << '\n';
        cout << "Nilai Akhir : " << data[i].nilaiAkhir << '\n';
    }

    return 0;
}