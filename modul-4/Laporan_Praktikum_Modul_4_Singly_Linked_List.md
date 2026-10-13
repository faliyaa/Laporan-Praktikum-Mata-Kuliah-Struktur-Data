# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Adhara Faliya Utanti - 109082500033</p>

## Dasar Teori

Linked list adalah struktur data yang menyimpan beberapa elemen atau *node* yang saling terhubung. Setiap node berisi data dan pointer yang menunjukkan node berikutnya. Berbeda dengan array yang umumnya memakai lokasi penyimpanan berurutan, linked list menggunakan pointer sehingga jumlah elemennya bisa bertambah atau berkurang sesuai kebutuhan [1].

### A. Konsep Singly Linked List<br/>

#### 1. Pengertian Singly Linked List

Singly Linked List (SLL) adalah linked list yang setiap node-nya hanya memiliki satu pointer, yaitu `next`. Pointer tersebut menyimpan alamat node berikutnya. Karena hubungan antarnode hanya satu arah, penelusuran list dilakukan dari node pertama sampai node terakhir.

#### 2. Bagian-bagian Node

Satu node SLL terdiri dari dua bagian, yaitu `info` untuk menyimpan data dan `next` untuk menunjuk node berikutnya. Pointer `first` menyimpan alamat node pertama. Jika list kosong, `first` bernilai `Nil` (`nullptr` pada program ini). Node terakhir memiliki `next` bernilai `Nil`.

#### 3. Kelebihan dan Cara Kerja Pointer

SLL bersifat dinamis karena node dibuat ketika dibutuhkan menggunakan `new`, lalu memorinya dibebaskan menggunakan `delete`. Pointer membuat setiap node dapat terhubung meskipun lokasi memorinya tidak bersebelahan. Namun, untuk mencapai node tertentu, program harus menelusuri list dari awal karena SLL tidak dapat bergerak mundur secara langsung [1][2].

### B. Operasi Dasar Singly Linked List<br/>

#### 1. Create List, Alokasi, dan Dealokasi

`createList()` menyiapkan list kosong dengan mengatur `first = Nil`. Fungsi `alokasi()` membuat node baru dan mengisi datanya. Sementara itu, `dealokasi()` menghapus node yang sudah tidak digunakan agar memori yang dialokasikan dapat dikembalikan ke sistem.

#### 2. Insert First, Insert Last, dan Insert After

`insertFirst()` menambahkan node di awal sehingga `first` berpindah ke node baru. `insertLast()` menelusuri list sampai node terakhir, kemudian menghubungkannya dengan node baru. `insertAfter()` menyisipkan node setelah node tertentu dengan mengatur pointer `next` agar urutan node tetap terhubung.

#### 3. Delete, View, dan Menghitung Node

`delFirst()` menghapus node pertama, sedangkan `delLast()` menghapus node terakhir. `delAfter()` menghapus node yang berada setelah node tertentu. `printList()` menelusuri dan menampilkan data setiap node, `nbList()` menghitung jumlah node, dan `deleteList()` menghapus semua node sampai list kosong.

## Guided 

### 1. [Header - list.h]

```C++
#ifndef LIST_H
#define LIST_H
#define Nil nullptr

#include <iostream>
using namespace std;

// Menyimpan data mahasiswa di setiap node
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

// Struktur untuk satu node
struct node {
    dataMahasiswa info;
    address next;
};

// Struktur list yang menyimpan alamat node pertama
struct linkedList {
    address first;
};

// Deklarasi fungsi dan prosedur yang digunakan
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);
void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```

**Penjelasan**

File `list.h` berisi bentuk data dan daftar fungsi yang bisa dipakai oleh file lain. `mahasiswa` menyimpan nama, NIM, dan umur. Tipe `address` merupakan pointer ke `node`, sedangkan `linkedList` menyimpan pointer `first` sebagai penanda node pertama. `Nil` didefinisikan sebagai `nullptr`, yaitu penanda bahwa pointer tidak menunjuk ke node mana pun. Deklarasi fungsi di bagian bawah menjadi penghubung antara `main.cpp` dan implementasi yang ada di `list.cpp`.

### 2. [Implementasi - list.cpp]

```C++
#include "list.h"
#include <iostream>
using namespace std;

// Mengecek apakah list kosong
bool isEmpty(linkedList list) {
    return list.first == Nil;
}

// Membuat list kosong
void createList(linkedList &list) {
    list.first = Nil;
}

// Membuat node baru dan mengisi data mahasiswa
address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->info.nama = nama;
    nodeBaru->info.nim = nim;
    nodeBaru->info.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Menghapus node dan membebaskan memorinya
void dealokasi(address &nodeHapus) {
    if (nodeHapus != Nil) {
        nodeHapus->next = Nil;
        delete nodeHapus;
        nodeHapus = Nil;
    }
}

// Menambahkan node pada awal list
void insertFirst(linkedList &list, address nodeBaru) {
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

// Menambahkan node setelah node Prev
void insertAfter(linkedList &list, address nodeBaru, address Prev) {
    if (Prev != Nil && nodeBaru != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

// Menambahkan node pada akhir list
void insertLast(linkedList &list, address nodeBaru) {
    if (nodeBaru == Nil) return;

    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// Menghapus node pertama
void delFirst(linkedList &list) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeHapus = list.first;
    list.first = nodeHapus->next;
    nodeHapus->next = Nil;
    dealokasi(nodeHapus);
}

// Menghapus node terakhir
void delLast(linkedList &list) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeHapus = list.first;

    // Jika list hanya berisi satu node
    if (nodeHapus->next == Nil) {
        list.first = Nil;
        dealokasi(nodeHapus);
        return;
    }

    address nodePrev = Nil;
    while (nodeHapus->next != Nil) {
        nodePrev = nodeHapus;
        nodeHapus = nodeHapus->next;
    }

    nodePrev->next = Nil;
    dealokasi(nodeHapus);
}

// Menghapus node yang berada setelah nodePrev
void delAfter(linkedList &list, address nodeHapus, address nodePrev) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    if (nodePrev == Nil || nodePrev->next == Nil) {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
        return;
    }

    nodeHapus = nodePrev->next;
    nodePrev->next = nodeHapus->next;
    nodeHapus->next = Nil;
    dealokasi(nodeHapus);
}

// Menampilkan seluruh data mahasiswa
void printList(linkedList list) {
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
        return;
    }

    address nodeBantu = list.first;
    while (nodeBantu != Nil) {
        cout << "Nama : " << nodeBantu->info.nama
             << ", NIM : " << nodeBantu->info.nim
             << ", Usia : " << nodeBantu->info.umur << endl;
        nodeBantu = nodeBantu->next;
    }
}

// Menghitung jumlah node dalam list
int nbList(linkedList list) {
    int count = 0;
    address nodeBantu = list.first;

    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Menghapus seluruh node dalam list
void deleteList(linkedList &list) {
    address nodeBantu = list.first;

    while (nodeBantu != Nil) {
        address nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    list.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

**Penjelasan**

File `list.cpp` berisi isi dari fungsi-fungsi yang dideklarasikan pada `list.h`. `createList()` mengawali list dalam keadaan kosong, lalu `alokasi()` membuat node dan mengisi data mahasiswa. Operasi insert mengatur ulang pointer supaya node baru masuk di posisi yang tepat. Operasi delete menyimpan alamat node yang akan dihapus, menyambungkan kembali node yang tersisa, kemudian memanggil `dealokasi()` untuk membebaskan memorinya. `printList()` menampilkan isi list, `nbList()` menghitung node, dan `deleteList()` menghapus semua node.

**Catatan perbaikan kode:** pada file awal terdapat definisi `delLast()` dan `printList()` yang tertulis dua kali. Jika dibiarkan, program akan mengalami *redefinition error*. Pada naskah ini masing-masing fungsi ditulis satu kali. `dealokasi()` juga dibuat mengatur pointer menjadi `Nil` setelah node dihapus agar alamat lama tidak digunakan lagi.

### 3. [Program Utama - main.cpp]

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;

    return 0;
}
```

**Penjelasan**

File `main.cpp` menjadi tempat program dijalankan. Program membuat lima node berisi data mahasiswa, kemudian memasukkannya dengan beberapa cara: `insertFirst()`, `insertLast()`, dan `insertAfter()`. Setelah isi list dan jumlah node ditampilkan, program menguji `delFirst()`, `delLast()`, dan `delAfter()`. Terakhir, `deleteList()` menghapus semua node dan program menampilkan kembali list untuk memastikan bahwa list sudah kosong.

**Catatan:** contoh ini mengikuti data dan urutan operasi dari file yang diberikan. Saat `delAfter(List, nodeD, nodeC)` dipanggil, node yang dihapus adalah node setelah `nodeC`, yaitu `nodeD`. Karena `nodeD` sudah dihapus oleh pemanggilan tersebut, jangan gunakan pointer `nodeD` lagi setelahnya.

## Unguided 

### 1. Membuat ADT Singly Linked List dan Menampilkan Data

**[Header - Singlylist.h]**

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil nullptr

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

**[Implementasi - Singlylist.cpp]**

```C++
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
```

**[Program Utama - main.cpp]**

```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

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

    printInfo(L);
    return 0;
}
```

### Output Unguided 1 :
![Screenshot Output Unguided 1](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-4/output/Output-Unguided-1.png)


**Penjelasan Unguided 1**

Program membuat list kosong terlebih dahulu, lalu mengalokasikan lima node yang berisi nilai `2`, `0`, `8`, `12`, dan `9`. Semua node dimasukkan menggunakan `insertFirst()`, sehingga setiap nilai baru diletakkan di depan nilai yang sudah ada. Karena itu, urutan akhirnya menjadi `9 12 8 0 2`, sesuai dengan ilustrasi dan output yang diminta pada soal.

### 2. Menghapus Node, Menghitung Node, dan Menghapus Seluruh List

**[Tambahan deklarasi - Singlylist.h]**

Tambahkan deklarasi fungsi berikut sebelum `#endif` pada file `Singlylist.h`:

```C++
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);
```

**[Tambahan implementasi - Singlylist.cpp]**

Tambahkan implementasi berikut ke file `Singlylist.cpp`:

```C++
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
```

**[Program Utama - main.cpp]**

Untuk soal kedua, gunakan program utama berikut sebagai pengganti `main.cpp` soal pertama:

```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

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

    // Kondisi awal: 9 12 8 0 2
    deleteFirst(L);       // Menghapus 9
    deleteLast(L);        // Menghapus 2
    deleteAfter(L, L.first); // Menghapus node setelah 12, yaitu 8

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :
![Screenshot Output Unguided 2](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-4/output/Output-Unguided-2.png)


**Penjelasan Unguided 2**

Soal kedua melanjutkan list dari soal pertama, yaitu `9 12 8 0 2`. `deleteFirst()` menghapus nilai `9`, lalu `deleteLast()` menghapus nilai `2`. Setelah itu, `deleteAfter(L, L.first)` menghapus node setelah node pertama yang tersisa, yaitu nilai `8`. List menjadi `12 0` dengan jumlah dua node. Terakhir, `deleteList()` menghapus semua node, sehingga jumlah node menjadi nol.

## Kesimpulan

Singly Linked List menyimpan data dalam node-node yang terhubung melalui pointer `next`. Pointer `first` digunakan untuk mengakses node pertama, sedangkan `Nil` menandakan akhir list atau list yang kosong. Melalui praktikum ini, operasi pembuatan list, alokasi memori, penyisipan, penelusuran, penghapusan, dan penghitungan node dapat diterapkan dalam program C++. Pengaturan pointer harus dilakukan dengan urutan yang benar agar node tetap terhubung dan tidak ada memori yang tertinggal setelah node dihapus.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan. (Materi praktikum Modul 4, bagian Singly Linked List).

[2] Indahyati, U., & Rahmawati, Y. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4

[3] cppreference.com. *new expression*. https://en.cppreference.com/w/cpp/language/new

[4] cppreference.com. *delete expression*. https://en.cppreference.com/w/cpp/language/delete
