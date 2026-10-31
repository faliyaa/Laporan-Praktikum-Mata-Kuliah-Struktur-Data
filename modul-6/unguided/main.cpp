#include <iostream>
#include "Buku.h"
using namespace std;

bool inputBuku(List &L) {
    infotype data;

    cout << endl;
    cout << "masukkan kode buku: ";
    cin >> data.kodeBuku;

    cout << "masukkan judul buku: ";
    cin >> data.judul;

    cout << "masukkan tahun terbit: ";
    cin >> data.thnTerbit;

    if (findElm(L, data.kodeBuku) != Nil) {
        cout << "kode buku sudah terdaftar" << endl;
        return false;
    }

    insertLast(L, alokasi(data));
    return true;
}

int main() {
    List L;
    CreateList(L);

    inputBuku(L);
    inputBuku(L);
    inputBuku(L);
    inputBuku(L);

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    string kodeCari;
    cout << endl << "Masukkan Kode Buku yang dicari : ";
    cin >> kodeCari;

    address hasil = findElm(L, kodeCari);

    if (hasil != Nil) {
        cout << endl;
        cout << "Kode Buku    : " << hasil->info.kodeBuku << endl;
        cout << "Judul        : " << hasil->info.judul << endl;
        cout << "Tahun Terbit : " << hasil->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << kodeCari
             << " tidak ditemukan." << endl;
    }

    string kodeHapus;
    bool hapusBerhasil;

    cout << endl << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> kodeHapus;

    deleteElm(L, kodeHapus, hapusBerhasil);

    if (hapusBerhasil) {
        cout << "Data dengan kode buku " << kodeHapus
             << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan kode buku " << kodeHapus
             << " tidak ditemukan." << endl;
    }

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    while (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
    L.Last = Nil;

    return 0;
}