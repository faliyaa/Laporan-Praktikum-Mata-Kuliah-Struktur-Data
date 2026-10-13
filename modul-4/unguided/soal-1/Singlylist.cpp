#include "Singlylist.h"
#include <iostream>
using namespace std;

// Membuat list kosong
void CreateList(List &L) {
    L.first = Nil;
}

// Membuat node baru yang berisi nilai x
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Membebaskan memori node
void dealokasi(address &P) {
    if (P != Nil) {
        P->next = Nil;
        delete P;
        P = Nil;
    }
}

// Menampilkan data dari node pertama sampai terakhir
void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

// Menambahkan node pada awal list
void insertFirst(List &L, address P) {
    if (P == Nil) return;
    P->next = L.first;
    L.first = P;
}