#include "list.h"
#include <iostream>
using namespace std;

// I.S. = Initial State / kondisi awal
// F.S. = Final State / kondisi akhir

// Fungsi untuk mengecek apakah list kosong atau tidak
bool isEmpty(linkedList list) {
    if (list.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// Pembuatan linked list kosong
void createList(linkedList &list) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    list.first = Nil;
}

// Pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isi data sesuai parameter dan next = Nil */

    // Membuat node baru di memori
    address nodeBaru = new node;

    // Mengisi data pada node baru
    nodeBaru->info.nama = nama;
    nodeBaru->info.nim = nim;
    nodeBaru->info.umur = umur;

    // Node baru belum menunjuk ke node lain
    nodeBaru->next = Nil;

    // Mengembalikan alamat node yang sudah dibuat
    return nodeBaru;
}

// Penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */

    // Memutus hubungan node dengan node berikutnya
    node->next = Nil;

    // Menghapus node dari memori
    delete node;
}

// Prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasi
       F.S. menempatkan elemen list (node) pada awal list */

    // Node baru menunjuk ke elemen pertama sebelumnya
    nodeBaru->next = list.first;

    // Node baru menjadi elemen pertama list
    list.first = nodeBaru;
}

// Prosedur untuk menyisipkan node baru setelah node Prev
void insertAfter(linkedList &list, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat sah elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */

    if (Prev != Nil) {
        // Node baru menunjuk ke node setelah Prev
        nodeBaru->next = Prev->next;

        // Node Prev menunjuk ke node baru
        Prev->next = nodeBaru;
    } else {
        // Menampilkan pesan jika node sebelumnya tidak valid
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen baru pada akhir list */

    // Jika list kosong, node baru menjadi elemen pertama
    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        // Membuat pointer bantuan untuk menelusuri list
        address nodeBantu = list.first;

        // Menelusuri list sampai node terakhir
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }

        // Node terakhir menunjuk ke node baru
        nodeBantu->next = nodeBaru;
    }
}

// Prosedur untuk menghapus node yang ada di dalam list
void delFirst(linkedList &list) {
    /* I.S. list tidak kosong
       F.S. node pertama dari list terhapus */

    // Variabel untuk menyimpan node yang akan dihapus
    address nodeHapus;

    // Memastikan list tidak kosong
    if (isEmpty(list) == false) {
        // Menyimpan alamat node pertama
        nodeHapus = list.first;

        // Memindahkan first ke node berikutnya
        list.first = list.first->next;

        // Memutus hubungan node yang akan dihapus
        nodeHapus->next = Nil;

        // Menghapus node dan membebaskan memori
        dealokasi(nodeHapus);
    } else {
        // Menampilkan pesan jika list kosong
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &list) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */

    // Variabel untuk menyimpan node yang dihapus
    // dan node sebelum node yang dihapus
    address nodeHapus, nodePrev;

    // Memastikan list tidak kosong
    if (isEmpty(list) == false) {
        // Menunjuk ke node pertama
        nodeHapus = list.first;

        // Jika hanya ada satu node di dalam list
        if (nodeHapus->next == Nil) {
            list.first = Nil;
            dealokasi(nodeHapus);
        } else {
            // Menelusuri list sampai node terakhir
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            // Memutus hubungan node sebelumnya dengan node terakhir
            nodePrev->next = Nil;

            // Menghapus node terakhir
            dealokasi(nodeHapus);
        }
    } else {
        // Menampilkan pesan jika list kosong
        cout << "List kosong!" << endl;
    }
}

// Prosedur untuk menghapus node terakhir dari list
void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */

    address nodeHapus, nodePrev;

    // Mengecek apakah list tidak kosong
    if (isEmpty(List) == false) {
        // Menunjuk ke node pertama
        nodeHapus = List.first;

        // Jika hanya ada satu node di dalam list
        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            // Menelusuri list sampai node terakhir
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            // Memutus hubungan node sebelumnya
            // dengan node terakhir
            nodePrev->next = Nil;

            // Menghapus node terakhir
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Prosedur untuk menghapus node setelah node Prev
void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next,
       menghapus Prev->next dari list */

    // Mengecek apakah list kosong
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        // Memastikan node sebelumnya valid
        // dan memiliki node setelahnya
        if (nodePrev != Nil && nodePrev->next != Nil) {
            // Menyimpan alamat node yang akan dihapus
            nodeHapus = nodePrev->next;

            // Menghubungkan node sebelumnya
            // dengan node setelah node yang dihapus
            nodePrev->next = nodeHapus->next;

            // Memutus hubungan node yang akan dihapus
            nodeHapus->next = Nil;

            // Menghapus node dan membebaskan memori
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// Prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. mungkin kosong
       F.S. jika list tidak kosong menampilkan semua
       informasi yang ada pada list */

    // Mengecek apakah list kosong
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        // Menunjuk ke node pertama
        address nodeBantu = List.first;

        // Menelusuri semua node sampai akhir list
        while (nodeBantu != Nil) {
            // Menampilkan data mahasiswa
            cout << "Nama : " << nodeBantu->info.nama
                 << ", NIM : " << nodeBantu->info.nim
                 << ", Usia : " << nodeBantu->info.umur
                 << endl;

            // Berpindah ke node berikutnya
            nodeBantu = nodeBantu->next;
        }
    }
}

// Prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info
       yang ada pada list */

    // Mengecek apakah list kosong
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        // Menunjuk ke node pertama
        address nodeBantu = List.first;

        // Menelusuri semua node di dalam list
        while (nodeBantu != Nil) {
            // Menampilkan data mahasiswa
            cout << "Nama : " << nodeBantu->info.nama
                 << ", NIM : " << nodeBantu->info.nim
                 << ", Usia : " << nodeBantu->info.umur
                 << endl;

            // Berpindah ke node berikutnya
            nodeBantu = nodeBantu->next;
        }
    }
}

// Function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */

    // Variabel untuk menghitung jumlah node
    int count = 0;

    // Menunjuk ke node pertama
    address nodeBantu = List.first;

    // Menelusuri semua node di dalam list
    while (nodeBantu != Nil) {
        // Menambah hitungan setiap menemukan node
        count++;

        // Berpindah ke node berikutnya
        nodeBantu = nodeBantu->next;
    }

    // Mengembalikan jumlah node
    return count;
}

// Prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node di dalam list */

    // Variabel untuk menyimpan node sementara
    address nodeBantu, nodeHapus;

    // Memulai dari node pertama
    nodeBantu = List.first;

    // Menghapus node satu per satu sampai list habis
    while (nodeBantu != Nil) {
        // Menyimpan alamat node yang akan dihapus
        nodeHapus = nodeBantu;

        // Berpindah ke node berikutnya sebelum node dihapus
        nodeBantu = nodeBantu->next;

        // Menghapus node dan membebaskan memori
        dealokasi(nodeHapus);
    }

    // Menandai bahwa list sekarang kosong
    List.first = Nil;

    // Menampilkan pesan bahwa list sudah terhapus
    cout << "List sudah terhapus!" << endl;
}