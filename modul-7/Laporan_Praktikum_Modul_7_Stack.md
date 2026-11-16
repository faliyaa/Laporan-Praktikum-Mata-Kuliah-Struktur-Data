# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Adhara Faliya Utanti - 109082500033</p>

## Dasar Teori

Stack merupakan salah satu struktur data linear yang cara kerjanya mirip seperti tumpukan barang. Data yang terakhir dimasukkan akan menjadi data pertama yang bisa diambil. Aturan ini disebut **LIFO (Last In, First Out)**. Akses pada stack dilakukan melalui satu bagian saja, yaitu bagian paling atas yang disebut **Top** [1].

### A. Konsep Dasar Stack<br/>

#### 1. Pengertian Stack

Stack adalah struktur data yang menyimpan beberapa elemen dengan aturan penambahan dan pengambilan data hanya dilakukan dari bagian atas. Karena aturan tersebut, elemen yang paling baru masuk akan berada di posisi paling atas dan menjadi elemen pertama yang dikeluarkan. Contohnya seperti tumpukan piring, piring yang terakhir diletakkan di atas akan diambil terlebih dahulu.

#### 2. Komponen Stack

Komponen utama stack adalah elemen data dan penunjuk **Top**. Top digunakan untuk mengetahui posisi elemen yang berada paling atas. Pada implementasi menggunakan array, Top dapat menyimpan jumlah elemen yang ada di dalam stack. Jika Top bernilai 0, berarti stack masih kosong. Jika menggunakan array berukuran 20, maka jumlah data yang dapat disimpan maksimal adalah 20 elemen.

#### 3. Prinsip LIFO

LIFO merupakan singkatan dari *Last In, First Out*, artinya data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Misalnya data 3, 4, dan 8 dimasukkan secara berurutan. Data yang berada di posisi Top adalah 8, sehingga ketika dilakukan operasi pengambilan, data 8 akan keluar lebih dulu.

### B. Operasi pada Stack<br/>

#### 1. Push

Push merupakan operasi untuk menambahkan data ke dalam stack. Data baru akan diletakkan pada posisi paling atas dan posisi Top akan diperbarui. Pada stack berbasis array dengan Top sebagai jumlah elemen, prosesnya dilakukan dengan menyimpan data pada indeks `Top`, kemudian menaikkan nilai Top satu angka. Sebelum menambahkan data, perlu diperiksa apakah stack masih memiliki ruang kosong [1].

#### 2. Pop

Pop merupakan operasi untuk mengambil sekaligus menghapus data yang berada di posisi paling atas. Data pada indeks `Top - 1` diambil terlebih dahulu, kemudian nilai Top dikurangi satu. Jika stack kosong, operasi pop tidak dapat dilakukan karena tidak ada data yang bisa diambil [1].

#### 3. Representasi Stack Menggunakan Array

Stack dapat dibuat menggunakan array yang memiliki ukuran tetap. Pada praktikum ini, array digunakan untuk menyimpan data bertipe integer dengan kapasitas 20 elemen. Variabel Top digunakan untuk menandai jumlah elemen yang sedang tersimpan. Representasi array cukup mudah digunakan, tetapi jumlah data yang dapat dimasukkan dibatasi oleh ukuran array.

## Guided

### 1. [Header - Stack.h]

File `Stack.h` berisi deklarasi struktur data Stack dan daftar fungsi yang akan digunakan. Pada bagian ini, `infotype` dibuat dalam bentuk struktur yang menyimpan NIM dan nama, sedangkan Stack memiliki array untuk menyimpan maksimal 10 data serta variabel Top untuk menunjukkan jumlah data yang tersimpan.

```cpp
/* file : Stack.h
   contoh ADT stack dengan representasi tabel */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};

struct Stack {
    infotype info[10];
    int Top;
};

/* prototype */
/******** pengecekan apakah Stack kosong *********/
int isEmpty(Stack S);
/* mengembalikan nilai 0 jika stack kosong */

/******** pembuatan Stack ********/
void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack dengan Top=0 */

/******** penambahan elemen pada Stack ********/
void push(Stack &S, infotype X);
/* I.S. Stack mungkin kosong
   F.S. menambahkan elemen pada stack dengan nilai X, TOP=TOP+1 */

/******** penghapusan elemen pada Stack ********/
void pop(Stack &S, infotype &X);
/* I.S. stack tidak kosong
   F.S. nilai info pada indeks TOP disimpan pada X, kemudian TOP=TOP-1 */

/******** proses semua elemen Stack *********/
void viewStack(Stack S);
/* I.S. stack mungkin kosong
   F.S. jika stack tidak kosong menampilkan semua info yang ada pada stack
*/

#endif // STACK_H_INCLUDED
```
Penjelasan:

Pada bagian header, `struct infotype` digunakan untuk menyimpan dua informasi, yaitu NIM dan nama. Setelah itu, `struct Stack` menyiapkan array `info[10]` sebagai tempat penyimpanan data dan variabel `Top` untuk mengetahui jumlah elemen di dalam stack. Fungsi seperti `createStack`, `push`, `pop`, dan `viewStack` baru dideklarasikan di sini. Isi dari masing-masing fungsi akan dibuat pada file `Stack.cpp`.

### 2. [Implementasi - Stack.cpp]

File `Stack.cpp` berisi isi dari fungsi-fungsi yang sebelumnya sudah dideklarasikan pada `Stack.h`. Di dalamnya terdapat proses untuk mengecek stack kosong, membuat stack baru, menambahkan data, mengambil data, dan menampilkan seluruh isi stack.

```cpp
#include "Stack.h"

int isEmpty(Stack S) {
    /* Top = 0 berarti kosong, sesuai komentar di Stack.h dikembalikan 0 */
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;   /* Top 1..10 dipetakan ke indeks array 0..9 */
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}
```
Penjelasan:

Fungsi `createStack()` mengatur nilai Top menjadi 0 agar stack dimulai dalam keadaan kosong. Fungsi `isEmpty()` mengecek kondisi tersebut. Pada program ini, nilai 0 berarti stack kosong, sedangkan nilai selain 0 berarti masih ada data.

Pada fungsi `push()`, program mengecek apakah Top masih kurang dari 10. Jika masih tersedia tempat, nilai Top ditambah satu dan data disimpan pada indeks `Top - 1`. Sebaliknya, jika kapasitas sudah penuh, program menampilkan pesan bahwa data tidak bisa ditambahkan.

Fungsi `pop()` mengambil data yang berada di posisi paling atas, menyimpannya ke variabel X, lalu mengurangi nilai Top. Sementara itu, `viewStack()` menampilkan data mulai dari posisi Top sampai elemen paling bawah. Dengan begitu, data yang ditampilkan pertama adalah data yang paling terakhir dimasukkan.

### 3. [Program Utama - main.cpp]

File `main.cpp` digunakan untuk menjalankan dan mencoba fungsi-fungsi stack. Program membuat stack baru, memasukkan tiga data mahasiswa, mengambil satu data, lalu melakukan pop sampai stack kosong.

```cpp
#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```
Penjelasan:

Pertama, program membuat variabel Stack S dan dua variabel bertipe `infotype`, yaitu `data` dan `hasil`. Setelah `createStack(S)` dipanggil, program menampilkan kondisi awal stack yang masih kosong.

Selanjutnya, program mengisi data NIM dan nama menggunakan `strcpy()`, kemudian memasukkannya satu per satu dengan `push()`. Setelah tiga data masuk, `viewStack()` menampilkan isi stack dari data paling atas. Program lalu memanggil `pop()` untuk mengambil satu data teratas dan menyimpannya ke variabel `hasil`. Terakhir, dua data yang tersisa juga di-pop sampai stack kosong. Bagian ini memperlihatkan bahwa data yang diambil selalu dimulai dari data yang terakhir dimasukkan.

## Unguided

### 1. Implementasi ADT Stack Menggunakan Array

Pada soal nomor 1, diminta membuat ADT Stack menggunakan array berukuran 20 dengan tipe data integer. Fungsi yang dibuat meliputi `createStack()`, `push()`, `pop()`, `printInfo()`, dan `balikStack()`. Implementasi dipisahkan menjadi tiga file, yaitu `Stack.h`, `Stack.cpp`, dan `main.cpp`.

#### [Header - Stack.h]

```cpp
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_SIZE = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_SIZE];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
Keterangan:

Pada `Stack.h`, `MAX_SIZE` menentukan kapasitas stack sebanyak 20 elemen. Tipe `infotype` menggunakan integer, sedangkan struktur `Stack` memiliki array `info` dan variabel `top`. Semua fungsi yang dibutuhkan juga dideklarasikan di file ini agar bisa digunakan oleh `main.cpp`.

#### [Implementasi - Stack.cpp]

```cpp
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
```
Keterangan:

Fungsi `createStack()` mengatur Top menjadi 0. Fungsi `push()` menyimpan angka pada indeks yang ditunjuk Top, lalu menaikkan Top. Fungsi `pop()` mengurangi Top terlebih dahulu, kemudian mengembalikan data yang sebelumnya berada di posisi paling atas. `printInfo()` menampilkan isi stack dari Top ke elemen terbawah.

Fungsi `balikStack()` membalik urutan elemen dengan menukar data dari sisi kiri dan kanan array sampai keduanya bertemu. Dengan cara ini, isi stack dapat dibalik tanpa membuat stack tambahan.

#### [Program Utama - main.cpp]

```cpp
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
Keterangan:

Program memasukkan angka 3, 4, dan 8. Setelah itu, angka paling atas diambil dengan `pop()`, kemudian program memasukkan angka 2 dan 3, mengambil lagi satu angka, lalu memasukkan angka 9. Isi stack sebelum dibalik menjadi `[TOP] 9 2 4 3`. Setelah `balikStack()` dijalankan, urutannya berubah menjadi `[TOP] 3 4 2 9`.

### Output Unguided 1 :

##### Output 1

Output yang diharapkan setelah program dijalankan:

```text
Hello world!
[TOP] 9 2 4 3
balik stack
[TOP] 3 4 2 9
```
##### Output 2
Output yang dihasilkan setelah program dijalankan:


Penjelasan output:

Sebelum dibalik, angka 9 berada di posisi Top karena angka tersebut merupakan data terakhir yang dimasukkan. Setelah fungsi `balikStack()` dijalankan, urutan elemen berubah sehingga angka 3 berada di posisi Top. Hasil ini sesuai dengan proses pembalikan isi array.

### 2. Menambahkan Prosedur pushAscending

Pada soal nomor 2, program nomor 1 dikembangkan dengan menambahkan prosedur `pushAscending()`. Prosedur ini memasukkan angka sambil menjaga isi array tetap terurut dari nilai terkecil di bagian bawah menuju nilai terbesar di bagian atas. Karena yang ditampilkan dimulai dari Top, hasil tampilannya akan terlihat menurun.

#### [Header - Stack.h]

Header yang digunakan sama seperti soal nomor 1 karena deklarasi `pushAscending()` sudah tersedia di dalamnya.

```cpp
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_SIZE = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_SIZE];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
#### [Implementasi - Stack.cpp]

```cpp
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
```
Keterangan:

Fungsi tambahan `pushAscending()` memeriksa kapasitas stack terlebih dahulu. Setelah itu, program membandingkan angka baru dengan elemen yang sudah ada dari posisi paling atas ke bawah. Selama elemen sebelumnya lebih besar dari angka baru, elemen tersebut digeser satu posisi ke kanan. Angka baru kemudian ditempatkan pada posisi yang sesuai dan nilai Top ditambah satu.

Dengan proses tersebut, urutan data di dalam array tetap terjaga dari kecil ke besar. Nilai yang sama tetap bisa dimasukkan karena pergeseran hanya dilakukan ketika elemen sebelumnya lebih besar dari angka baru.

#### [Program Utama - main.cpp]

```cpp
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
Keterangan:

Program memasukkan angka 3, 4, 8, 2, 3, dan 9 menggunakan `pushAscending()`. Setelah semua angka masuk, `printInfo()` menampilkan data dari posisi Top. Hasilnya adalah `[TOP] 9 8 4 3 3 2`. Kemudian `balikStack()` membalik urutannya menjadi `[TOP] 2 3 3 4 8 9`.

### Output Unguided 2 :

##### Output 1

Output yang diharapkan setelah program dijalankan:

```text
Hello world!
[TOP] 9 8 4 3 3 2
balik stack
[TOP] 2 3 3 4 8 9
```
##### Output 2
Output yang dihasilkan setelah program dijalankan:


Penjelasan output:

Angka yang dimasukkan tetap tersusun secara ascending di dalam array, yaitu dari kecil ke besar. Namun, karena `printInfo()` menampilkan data mulai dari Top, angka terbesar terlihat lebih dulu. Setelah stack dibalik, angka terkecil menjadi elemen paling atas dan hasil tampilannya menjadi urutan ascending.

### 3. Menambahkan Prosedur getInputStream

Pada soal nomor 3, program ditambahkan prosedur `getInputStream()` untuk menerima input dari pengguna sampai tombol Enter ditekan. Setiap karakter angka yang dimasukkan akan disimpan sebagai satu elemen integer ke dalam stack. Fungsi `printInfo()` dan `balikStack()` tetap digunakan seperti pada soal sebelumnya.

#### [Header - Stack.h]

Header yang digunakan tetap sama karena deklarasi `getInputStream()` sudah ditambahkan bersama deklarasi fungsi lainnya.

```cpp
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_SIZE = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX_SIZE];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
#### [Implementasi - Stack.cpp]

```cpp
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
```
Keterangan:

Pada `getInputStream()`, program membaca input karakter menggunakan `cin.get()`. Proses pembacaan akan terus berjalan selama karakter yang diterima bukan Enter. Jika karakter yang dimasukkan merupakan angka 0 sampai 9, karakter tersebut diubah menjadi nilai integer dengan mengurangkan karakter `'0'`, lalu dimasukkan ke stack menggunakan `push()`.

Dengan implementasi ini, setiap digit dianggap sebagai satu elemen. Contohnya, jika pengguna mengetik `1069274` lalu menekan Enter, stack akan menyimpan tujuh elemen angka secara berurutan. Jika kapasitas stack sudah mencapai 20, fungsi `push()` akan menampilkan pesan bahwa stack penuh.

#### [Program Utama - main.cpp]

```cpp
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
Keterangan:

Program membuat stack kosong, kemudian memanggil `getInputStream(S)` agar pengguna dapat memasukkan angka. Setelah pengguna menekan Enter, isi stack ditampilkan menggunakan `printInfo()`. Selanjutnya, program membalik urutan data dengan `balikStack()` dan menampilkan hasilnya kembali.

### Output Unguided 3 :

##### Output 1

Contoh input `1069274`, kemudian menekan Enter:

```text
Hello world!
Masukkan angka (akhiri dengan Enter): 1069274
[TOP] 4 7 2 9 6 0 1
balik stack
[TOP] 1 0 6 9 2 7 4
```
##### Output 2
Output yang dihasilkan setelah program dijalankan:


Penjelasan output:

Angka yang dimasukkan pengguna dibaca satu karakter demi satu karakter. Karena stack menerapkan prinsip LIFO, saat ditampilkan dari Top, digit terakhir yang dimasukkan akan muncul lebih dulu. Setelah fungsi `balikStack()` dijalankan, susunan digit kembali seperti urutan saat pertama kali diketik.

## Kesimpulan

Berdasarkan praktikum Modul 7, Stack merupakan struktur data yang menggunakan prinsip LIFO, yaitu data yang terakhir masuk akan menjadi data pertama yang keluar. Operasi utama pada stack adalah `push()` untuk menambahkan data dan `pop()` untuk mengambil data dari posisi Top. Pada implementasi menggunakan array, variabel Top membantu mengatur jumlah elemen dan menentukan posisi data paling atas.

Melalui latihan, fungsi stack juga dapat dikembangkan untuk membalik urutan data, memasukkan angka secara ascending, serta menerima input langsung dari pengguna. Dari percobaan tersebut, dapat dipahami bahwa pengelolaan posisi Top sangat penting agar proses penambahan, pengambilan, dan penampilan data berjalan sesuai aturan stack.

## Referensi

[1] Telkom University. (2026). *Modul Praktikum Struktur Data: Modul 7 - Stack*, hlm. 59–65. Materi praktikum yang diberikan pada pertemuan Modul 7.

<br>[2] OpenDSA. (n.d.). *Stacks*. Data Structures and Algorithms Modules, Virginia Tech. Diakses pada 16 November 2026 melalui https://opendsa-server.cs.vt.edu/ODSA/Books/pubbook/odsa-all-0013bb43-a12f-4ab3-9b86-73b317f1e37e/fall-2024/Public_OpenDSA_F24/html/StackArray.html.
