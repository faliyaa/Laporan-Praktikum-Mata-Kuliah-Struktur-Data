# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Adhara Faliya Utanti - 109082500033</p>

## Dasar Teori
Queue (atau antrean) adalah struktur data linear yang cara kerjanya persis seperti antrean di dunia nyata, misalnya saat kita mengantre membeli tiket kereta api di loket [1]. Orang yang datang paling awal akan dilayani lebih dulu, sedangkan yang datang belakangan harus menunggu di belakang sampai gilirannya tiba. Prinsip inilah yang disebut dengan **FIFO (First In, First Out)**, di mana data yang pertama kali masuk ke dalam antrean akan menjadi data yang pertama kali keluar [1][3].

Dalam penerapannya di bahasa C++, struktur data Queue bisa dibangun menggunakan dua cara utama, yaitu memakai **Linked List (Pointer)** atau memakai **Array (Tabel)** [2][4]. Keduanya sama-sama menerapkan aturan FIFO, tetapi punya cara kerja yang berbeda dalam hal manajemen memori dan batas kapasitas datanya.

### A. Operasi Dasar pada Queue<br/>
Agar struktur data Queue bisa digunakan dengan baik, ada beberapa operasi utama dan pendukung yang biasa didefinisikan di dalam ADT (Abstract Data Type) Queue [1][4].

#### 1. Enqueue (Insert)
Operasi ini dipakai untuk memasukkan data baru ke dalam antrean. Karena mengikuti prinsip FIFO, data baru selalu diletakkan di posisi paling belakang yang ditandai oleh penunjuk `tail` [3]. Kalau antreannya masih kosong, maka elemen baru tersebut langsung menjadi `head` sekaligus `tail`.

#### 2. Dequeue (Delete)
Operasi ini kebalikan dari enqueue, yaitu mengambil atau menghapus data dari antrean. Penghapusan selalu dilakukan pada posisi paling depan yang ditunjuk oleh `head` [3]. Setelah data paling depan diambil, posisi `head` akan disesuaikan ke elemen berikutnya (atau elemen di belakangnya digeser maju, tergantung representasi yang dipakai).

#### 3. Operasi Pendukung
Selain tambah dan hapus, Queue juga butuh beberapa fungsi bantu seperti `CreateQueue` untuk menginisialisasi antrean kosong, `isEmpty` untuk mengecek apakah antrean sedang tidak ada isinya, `isFull` (khusus representasi array) untuk mengecek apakah kapasitas sudah mentok, serta `printInfo` atau `viewQueue` untuk menampilkan seluruh isi antrean ke layar [1][2].

### B. Representasi Queue (Linked List dan Array)<br/>
Pemilihan representasi Queue biasanya disesuaikan dengan kebutuhan program, apakah jumlah datanya sudah pasti atau bisa terus bertambah secara dinamis [4].

#### 1. Representasi Linked List (Pointer)
Pada representasi ini, setiap data disimpan di dalam sebuah node yang memiliki bagian informasi (`info`) dan penunjuk ke node berikutnya (`next`) [1]. Kelebihannya adalah jumlah antrean tidak terbatas selama memori komputer masih mencukupi, karena memori dialokasikan secara dinamis saat data masuk (`alokasi`) dan dibebaskan kembali saat data keluar (`dealokasi`).

#### 2. Representasi Array (Tabel)
Pada representasi array, kapasitas antrean sudah ditentukan sejak awal sehingga jumlah elemennya terbatas dan tidak perlu manajemen memori manual dengan pointer [2][4]. Dalam praktiknya, ada tiga mekanisme pengelolaan indeks `head` dan `tail` pada array:
- **Alternatif 1 (Head diam, Tail bergerak):** Posisi `head` selalu bertahan di indeks 0 selama antrean tidak kosong. Setiap kali `dequeue` dilakukan, semua elemen di belakangnya harus digeser maju satu langkah dan `tail` mundur. Cara ini mirip antrean asli, tapi kurang efisien kalau datanya banyak.
- **Alternatif 2 (Head bergerak, Tail bergerak):** Saat `dequeue`, elemen tidak digeser melainkan `head` yang dimajukan. Cara ini lebih cepat, tetapi punya kelemahan yaitu bisa terjadi kondisi "penuh semu" saat `tail` sudah mentok di indeks terakhir padahal di bagian depan masih ada slot kosong, sehingga perlu digeser ke depan ketika kondisi penuh semu terjadi.
- **Alternatif 3 (Circular Queue / Head dan Tail berputar):** Solusi dari masalah penuh semu tanpa perlu menggeser elemen sama sekali. Indeks array dibuat seolah-olah melingkar menggunakan operasi modulo (`%`). Jadi kalau `tail` sudah sampai di ujung array tapi indeks awal masih kosong, `tail` bisa berputar kembali ke indeks 0 [3][4].

## Guided 

### 1. Guided 1 - Queue Representasi Linked List (Pointer)

#### [Header - queue.h]
```C++
#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>
using namespace std;

#define Nil NULL

typedef bool boolean;
typedef int infotype;
typedef struct elmQ *address;

struct elmQ {
    infotype info;
    address next;
};

struct queue {
    address head, tail;
};

boolean isEmpty(queue Q);
void CreateQueue(queue &Q);
address alokasi(infotype X);
void dealokasi(address P);
address findElm(queue Q, infotype X);
boolean fFindElm(queue Q, address P);
void insert(queue &Q, address P);
void deleteQueue(queue &Q, address &P);
void printInfo(queue Q);
int nbList(queue Q);
void delAll(queue &Q);

#endif
```
File `queue.h` ini isinya semacam blueprint untuk struktur Queue berbasis linked list. Di sini kita mendefinisikan struct `elmQ` yang menyimpan nilai `info` bertipe integer dan pointer `next` buat nyambungin ke node setelahnya. Lalu ada struct `queue` yang cuma butuh dua penunjuk utama, yaitu `head` untuk elemen paling depan dan `tail` untuk elemen paling belakang. Di bagian bawahnya, kita daftarkan semua prototipe fungsi dan prosedur yang nanti bakal diisi logikanya di file `.cpp`, mulai dari alokasi memori, cari elemen, tambah, hapus, sampai hitung jumlah isi antrean.

#### [Source - queue.cpp]
```C++
#include "queue.h"

boolean isEmpty(queue Q) {
    return (Q.head == Nil);
}

void CreateQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

address alokasi(infotype X) {
    address P = new (nothrow) elmQ;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

address findElm(queue Q, infotype X) {
    address P = Q.head;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

boolean fFindElm(queue Q, address P) {
    address R = Q.head;
    while (R != Nil) {
        if (R == P) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void insert(queue &Q, address P) {
    if (isEmpty(Q)) {
        Q.head = P;
        Q.tail = P;
    } else {
        (Q.tail)->next = P;
        Q.tail = P;
    }
}

void deleteQueue(queue &Q, address &P) {
    P = Q.head;
    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = P->next;
    }
    P->next = Nil;
}

void printInfo(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        address P = Q.head;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

int nbList(queue Q) {
    int jumlah = 0;
    address P = Q.head;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void delAll(queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        deleteQueue(Q, P);
        dealokasi(P);
    }
}
```
Di file `queue.cpp` ini semua logika antreannya dijalankan. Saat `CreateQueue` dipanggil, `head` dan `tail` diset ke `Nil` dulu sebagai tanda antreannya masih kosong. Untuk bikin node baru, kita pakai fungsi `alokasi` yang memesan memori baru dengan `new`, lalu waktu mau nambah data lewat `insert`, kalau antrean kosong maka node baru langsung jadi `head` sekaligus `tail`, tapi kalau sudah ada isinya tinggal disambungkan di belakang `tail`. Sementara itu, `deleteQueue` selalu mengambil data dari `head` lalu memindahkan `head` ke node berikutnya. Di sini juga ada tambahan fungsi buat cari data (`findElm` dan `fFindElm`), ngitung total elemen (`nbList`), sampai bersihin seluruh isi antrean sekaligus (`delAll`) biar memorinya tidak bocor.

#### [Main - main.cpp]
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue Q;
    address P;

    CreateQueue(Q);
    cout << "isEmpty: " << isEmpty(Q) << endl;
    printInfo(Q);

    insert(Q, alokasi(5));
    insert(Q, alokasi(2));
    insert(Q, alokasi(7));
    cout << "Setelah insert 5, 2, 7" << endl;
    printInfo(Q);
    cout << "nbList : " << nbList(Q) << endl;

    P = findElm(Q, 2);
    if (P != Nil) {
        cout << "findElm(2) ketemu, info = " << P->info << endl;
        cout << "fFindElm : " << fFindElm(Q, P) << endl;
    }
    if (findElm(Q, 9) == Nil) {
        cout << "findElm(9) tidak ketemu" << endl;
    }

    deleteQueue(Q, P);
    cout << "Setelah delete, elemen yang keluar = " << P->info << endl;
    dealokasi(P);
    printInfo(Q);

    delAll(Q);
    cout << "Setelah delAll" << endl;
    printInfo(Q);
    cout << "isEmpty: " << isEmpty(Q) << endl;

    return 0;
}
```
File `main.cpp` dipakai buat ngetes semua fitur yang sudah dibikin tadi. Awalnya kita bikin antrean kosong dan cek apakah benar kosong, lalu masukin angka 5, 2, dan 7 secara berurutan. Setelah dicetak dan dicek jumlah elemennya, program nyoba nyari angka 2 (yang ada di antrean) dan angka 9 (yang memang tidak ada). Berikutnya kita tes `deleteQueue`, dan karena prinsipnya FIFO, angka 5 yang pertama kali masuk bakal keluar duluan lalu memorinya dihapus pakai `dealokasi`. Terakhir, `delAll` dipanggil supaya antreannya benar-benar bersih lagi.

---

### 2. Guided 2 - Queue Representasi Array (Tabel)

#### [Header - queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
Berbeda dari Guided 1, di Guided 2 ini antreannya pakai array statis dengan kapasitas maksimal 5 data yang disimpan dalam konstanta `MAKSIMAL`. Karena datanya berupa nama orang, array di dalam struct `queue` memakai tipe data `string`, sedangkan `head` dan `tail` cukup pakai tipe `int` biasa buat menyimpan nomor indeks array-nya. Karena pakai array yang ukurannya terbatas, di sini muncul satu fungsi tambahan yaitu `isFull` untuk mengecek apakah antrean sudah penuh atau belum.

#### [Source - queue.cpp]
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```
Di `queue.cpp` versi array ini, sebenarnya sudah disiapkan tiga model implementasi sekaligus, dan yang sedang aktif dipakai adalah Implementasi 1 (head diam, tail bergerak), sementara Implementasi 2 dan 3 dikomentari sebagai perbandingan. Antrean dianggap kosong kalau `head` dan `tail` bernilai `-1`. Pas `enQueue` dipanggil, program ngecek dulu apakah array-nya sudah penuh di indeks ke-4 (`MAKSIMAL - 1`). Kalau belum penuh, `tail` maju dan nama dimasukkan. Nah, waktu `deQueue` dijalankan pada Implementasi 1, data paling depan dihapus lalu seluruh nama di belakangnya digeser maju satu indeks pakai perulangan `for`, setelah itu nilai `tail` dikurangi satu. Kalau ternyata antreannya sudah habis (`tail < 0`), `head` dan `tail` langsung di-reset balik ke `-1`.

#### [Main - main.cpp]
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Di `main.cpp` ini kita mencoba memasukkan 6 nama sekaligus padahal kapasitas array-nya cuma 5. Tujuannya buat melihat respons program saat kapasitas penuh, jadi 5 nama pertama berhasil masuk sedangkan nama ke-6 ("Daffa") akan ditolak dengan pesan antrean penuh. Setelah isi antrean ditampilkan dengan `viewQueue`, program menjalankan `deQueue` sebanyak 4 kali sehingga 4 nama terdepan keluar secara berurutan, dan ketika ditampilkan lagi yang tersisa tinggal satu nama paling terakhir yaitu "Fathur".

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY pada file `queue.h` dan implementasinya pada file `queue.cpp` dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

#### [Header - queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### [Source - queue.cpp]
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4); // Maksimal indeks 4 karena array[5]
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head]; // Elemen terdepan selalu di indeks head (0)
        if (Q.head == Q.tail) {
            // Jika hanya tersisa 1 elemen, kembalikan ke kondisi kosong
            createQueue(Q);
        } else {
            // Menggeser semua elemen maju satu indeks ke depan (Alternatif 1)
            for (int i = 0; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

#### [Main - main.cpp]
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    
    cout << "---------------------------" << endl;
    cout << " H - T \t| Queue Info" << endl;
    cout << "---------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1


Pada Unguided 1 ini kita menerapkan mekanisme **Alternatif 1**, di mana posisi `head` selalu diam di indeks `0` selama antrean ada isinya, dan hanya `tail` yang bergerak. Di dalam `queue.h`, kita siapkan `struct Queue` dengan array `info[5]` bertipe `int` serta `head` dan `tail`. Saat `enqueue` dipanggil di `queue.cpp`, program mengecek dulu apakah `tail` sudah mencapai indeks `4` lewat `isFullQueue`. Kalau belum penuh dan antreannya masih kosong, `head` dan `tail` langsung diset ke `0`; kalau sudah ada isinya, cukup `tail` saja yang dinaikkan lalu datanya dimasukkan ke `Q.info[Q.tail]`.

Untuk fungsi `dequeue`, awalnya variabel `x` diberi nilai default `-1` sebagai nilai balik jika ternyata antrean kosong. Kalau ada isinya, data di `Q.info[Q.head]` diambil dulu ke `x`. Nah, kalau elemennya tinggal satu (`Q.head == Q.tail`), kita tinggal memanggil kembali `createQueue(Q)` supaya antrean langsung kembali kosong (`-1 - -1`). Tapi kalau elemennya lebih dari satu, seluruh isi array digeser maju satu langkah mulai dari indeks `0` sampai sebelum `Q.tail` pakai perulangan `for`, lalu `Q.tail` dikurangi satu. Dengan cara ini, waktu `main.cpp` dijalankan dan dicetak lewat `printInfo`, nilai `H` akan terus bertahan di angka `0` meskipun `dequeue` dipanggil berulang kali, sampai akhirnya antrean benar-benar kosong lagi.

---

### 2. Buatlah implementasi ADT Queue pada file `queue.cpp` dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### [Header - queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### [Source - queue.cpp]
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

// Pada Alternatif 2, antrean dikatakan benar-benar penuh 
// HANYA JIKA tail sudah mencapai indeks akhir DAN head berada di indeks awal (0)
bool isFullQueue(Queue Q) {
    return (Q.tail == 4 && Q.head == 0); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            // Cek kondisi antrean penuh "semu" (tail di akhir, tapi head > 0)
            if (Q.tail == 4 && Q.head > 0) {
                // Geser seluruh elemen ke depan untuk menciptakan ruang kosong
                int geser = Q.head;
                for (int i = Q.head; i <= Q.tail; i++) {
                    Q.info[i - geser] = Q.info[i];
                }
                Q.tail = Q.tail - geser;
                Q.head = 0; // Kembalikan head ke 0 setelah digeser
            }
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            // Jika hanya tersisa 1 elemen, kembalikan ke kondisi kosong
            createQueue(Q);
        } else {
            // Pada Alternatif 2, elemen TIDAK digeser saat dequeue,
            // melainkan indeks head yang bergerak maju.
            Q.head++;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

#### [Main - main.cpp]
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    
    cout << "---------------------------" << endl;
    cout << " H - T \t| Queue Info" << endl;
    cout << "---------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    
    // Perhatikan nilai head akan bertambah (bergerak) saat dequeue
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    
    return 0;
}
```

### Output Unguided 2 :

##### Output 1


Pada Unguided 2 ini kita menerapkan **Alternatif 2**, di mana `head` dan `tail` sama-sama bisa bergerak. Bedanya dengan Alternatif 1 langsung terasa di fungsi `dequeue`: waktu data paling depan diambil ke variabel `x`, kita tidak perlu menggeser isi array sama sekali. Kalau datanya tinggal satu (`Q.head == Q.tail`), kita reset pakai `createQueue(Q)`, sedangkan kalau masih ada sisa elemen lain, cukup majukan indeks `Q.head++`.

Karena `head` bisa bergeser ke kanan, pengecekan `isFullQueue` juga dibuat lebih akurat, yaitu antrean baru dianggap benar-benar penuh kalau `Q.tail == 4` sekaligus `Q.head == 0`. Nah, supaya tidak kena masalah "penuh semu" (saat `tail` sudah mentok di indeks `4`, tapi `head > 0` yang artinya di bagian depan array sebenarnya masih ada slot kosong), di dalam `enqueue` ditambahkan pengecekan khusus. Jika kondisi penuh semu itu terjadi, seluruh elemen yang tersisa bakal digeser ke depan sejauh nilai `Q.head`, lalu `Q.tail` disesuaikan dan `Q.head` dikembalikan ke `0`, baru setelah itu data baru bisa masuk ke belakang `tail`. Saat `main.cpp` dijalankan, bisa langsung dilihat nilai `H` ikut bertambah dari `0` menjadi `1`, `2`, dan `3` setiap kali `dequeue` dipanggil.

---

### 3. Buatlah implementasi ADT Queue pada file `queue.cpp` dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### [Header - queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;
const int MAKSIMAL = 5;

struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### [Source - queue.cpp]
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

// Pada Alternatif 3, antrean penuh jika indeks setelah tail adalah head
// Operasi modulo (%) digunakan agar indeks berputar (4 + 1) % 5 = 0
bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAKSIMAL == Q.head); 
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            // Tail bergerak maju dengan konsep melingkar
            Q.tail = (Q.tail + 1) % MAKSIMAL;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            // Jika hanya tersisa 1 elemen, kembalikan ke kondisi kosong
            createQueue(Q);
        } else {
            // Head bergerak maju dengan konsep melingkar
            Q.head = (Q.head + 1) % MAKSIMAL;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        // Loop khusus untuk mencetak elemen yang melingkar
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) {
                break;
            }
            i = (i + 1) % MAKSIMAL;
        }
        cout << endl;
    }
}
```

#### [Main - main.cpp]
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);
    
    cout << "---------------------------" << endl;
    cout << " H - T \t| Queue Info" << endl;
    cout << "---------------------------" << endl;
    
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q); // Tail ada di indeks 3
    
    dequeue(Q); printInfo(Q); // Head maju ke 1
    dequeue(Q); printInfo(Q); // Head maju ke 2
    
    // Antrean saat ini menyisakan 2 elemen, tetapi indeks 0 dan 1 sudah kosong.
    // Memasukkan 2 elemen baru untuk memaksa Tail berputar ke indeks 0
    enqueue(Q, 1); printInfo(Q); // Tail maju ke 4
    enqueue(Q, 9); printInfo(Q); // Tail berputar (4+1)%5 ke 0!
    
    return 0;
}
```

### Output Unguided 3 :

##### Output 1


Pada Unguided 3 ini kita menggunakan **Alternatif 3 (Circular Queue)** supaya tidak perlu lagi melakukan pergeseran elemen seperti di Alternatif 1 maupun saat penuh semu di Alternatif 2. Di `queue.h`, ukuran array disimpan dalam konstanta `MAKSIMAL = 5` agar lebih rapi saat dipakai di perhitungan modulo. Kunci utamanya ada pada operasi `% MAKSIMAL`: di `isFullQueue`, antrean dianggap penuh kalau satu posisi setelah `tail` sudah bertemu `head` (`(Q.tail + 1) % MAKSIMAL == Q.head`). Saat `enqueue`, `tail` dimajukan melingkar dengan `(Q.tail + 1) % MAKSIMAL`, dan begitu pula saat `dequeue`, `head` maju dengan `(Q.head + 1) % MAKSIMAL` kecuali jika elemen tinggal satu yang langsung di-reset lewat `createQueue(Q)`.

Untuk menampilkan datanya di `printInfo`, kita memakai perulangan `while (true)` yang berjalan mulai dari `Q.head`, mencetak elemennya, lalu berhenti ketika `i == Q.tail`, dengan indeks yang terus berputar memakai `(i + 1) % MAKSIMAL`. Nah, di `main.cpp` skenario ujinya sengaja dibuat untuk membuktikan efek berputar ini: setelah memasukkan 4 angka (`5, 2, 7, 4`) hingga `tail` di indeks `3`, kita lakukan `dequeue` dua kali supaya `head` maju ke indeks `2` dan indeks `0` serta `1` jadi kosong. Ketika kita memasukkan angka `1`, `tail` maju ke indeks `4`, dan pas angka `9` dimasukkan, `tail` otomatis berputar kembali ke indeks `0` (`(4 + 1) % 5 = 0`) sehingga pada output akhirnya posisi `H - T` menjadi `2 - 0` dengan isi antrean `7 4 1 9`.

## Kesimpulan
Dari praktikum Modul 8 tentang Queue ini, bisa dipahami bahwa Queue adalah struktur data yang bekerja dengan aturan FIFO (First In, First Out), di mana data masuk lewat belakang (`tail`) menggunakan operasi `enqueue` dan keluar lewat depan (`head`) menggunakan operasi `dequeue`. Implementasinya bisa memakai Linked List yang kapasitasnya fleksibel karena memakai alokasi memori dinamis, atau memakai Array yang lebih simpel tapi kapasitasnya terbatas. Pada implementasi Array, cara menggerakkan `head` dan `tail` sangat memengaruhi efisiensi program: Alternatif 1 paling mudah dibayangkan tapi lambat karena selalu menggeser elemen tiap `dequeue`, Alternatif 2 tidak menggeser elemen saat `dequeue` dan baru menggeser saat terjadi kondisi penuh semu, sedangkan Alternatif 3 (Circular Queue) menjadi solusi paling efisien karena bisa memanfaatkan ruang kosong di awal array secara melingkar menggunakan operasi modulo tanpa perlu menggeser data sama sekali.

## Referensi
[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.
<br>[2] Indahyati, Uce., & Rahmawati, Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4
<br>[3] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). *Introduction to Algorithms* (4th ed.). Cambridge, MA: MIT Press.
<br>[4] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). *Data Structures and Algorithms in C++* (2nd ed.). Hoboken, NJ: John Wiley & Sons.