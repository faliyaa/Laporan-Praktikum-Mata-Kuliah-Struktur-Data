#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi list: ";
    printInfo(L);

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "Data tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah "
         << totalInfo(L) << endl;

    while (L.first != Nil) {
        address hapus = L.first;
        L.first = L.first->next;
        dealokasi(hapus);
    }

    return 0;
}