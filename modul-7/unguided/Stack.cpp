#include <iostream>
#include "Stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX_SIZE) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    }
    cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    return 0;
}

void printInfo(const Stack &S) {
    if (S.top == 0) {
        cout << "[TOP] Stack kosong" << endl;
        return;
    }

    cout << "[TOP]";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << " " << S.info[i];
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;

    while (kiri < kanan) {
        infotype temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri++;
        kanan--;
    }
}

/* Khusus soal nomor 2 */
void pushAscending(Stack &S, infotype x) {
    if (S.top >= MAX_SIZE) {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
        return;
    }

    int i = S.top;
    while (i > 0 && S.info[i - 1] > x) {
        S.info[i] = S.info[i - 1];
        i--;
    }

    S.info[i] = x;
    S.top++;
}

/* Khusus soal nomor 3: setiap karakter angka disimpan sebagai satu elemen */
void getInputStream(Stack &S) {
    cout << "Masukkan angka (akhiri dengan Enter): ";
    char karakter;

    while (cin.get(karakter) && karakter != '\n') {
        if (karakter >= '0' && karakter <= '9') {
            push(S, karakter - '0');
        }
    }
}