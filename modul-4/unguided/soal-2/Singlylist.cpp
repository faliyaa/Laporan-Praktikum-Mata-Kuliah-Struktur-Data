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

// Menghapus node pertama
void deleteFirst(List &L) {
    if (L.first == Nil) return;

    address P = L.first;
    L.first = P->next;
    dealokasi(P);
}

// Menghapus node terakhir
void deleteLast(List &L) {
    if (L.first == Nil) return;

    address P = L.first;

    // Jika hanya ada satu node
    if (P->next == Nil) {
        L.first = Nil;
        dealokasi(P);
        return;
    }

    address Prec = Nil;
    while (P->next != Nil) {
        Prec = P;
        P = P->next;
    }

    Prec->next = Nil;
    dealokasi(P);
}

// Menghapus node setelah Prec
void deleteAfter(List &L, address Prec) {
    if (L.first == Nil || Prec == Nil || Prec->next == Nil) return;

    address P = Prec->next;
    Prec->next = P->next;
    dealokasi(P);
}

// Menghitung jumlah node
int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

// Menghapus semua node
void deleteList(List &L) {
    while (L.first != Nil) {
        deleteFirst(L);
    }
}