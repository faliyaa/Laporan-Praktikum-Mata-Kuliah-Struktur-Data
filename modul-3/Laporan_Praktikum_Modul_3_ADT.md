# Laporan Praktikum Modul 3 – Abstract Data Type (ADT)

<p align="center">Nama: Adhara Faliya Utanti – NIM: 109082500033</p>

## Dasar Teori

### A. Abstract Data Type (ADT)

#### 1. Pengertian ADT

Abstract Data Type (ADT) adalah konsep yang menggabungkan suatu tipe data dengan operasi yang bisa digunakan untuk mengolah data tersebut. ADT menjelaskan data apa yang disimpan dan operasi apa yang tersedia, tanpa mengharuskan pengguna mengetahui seluruh detail cara kerja di dalamnya. Pada Modul 3, ADT dikenalkan melalui tipe data `mahasiswa` beserta fungsi untuk mengisi data dan menghitung rata-rata nilai.

#### 2. Bagian-bagian ADT

Berdasarkan Modul 3, penerapan ADT memiliki tiga bagian utama, yaitu deklarasi tipe dan prototipe fungsi pada file header `.h`, implementasi fungsi pada file `.cpp`, serta program utama atau *driver* yang menggunakan fungsi tersebut. Pemisahan ini membuat susunan program lebih teratur. Ketika fungsi perlu diperbaiki, bagian implementasinya dapat diubah tanpa harus menuliskan ulang seluruh program utama.

#### 3. Operasi pada ADT

Operasi ADT dapat berupa konstruktor untuk membentuk data, selector untuk mengambil bagian data, prosedur untuk mengubah data, serta fungsi baca dan tulis untuk berinteraksi dengan pengguna. Bentuk operasi yang digunakan bergantung pada kebutuhan tipe data. Pada contoh mahasiswa, `inputMhs()` digunakan untuk mengisi data, sedangkan `rata2()` menghasilkan rata-rata dari dua nilai yang dimasukkan.

### B. Penerapan ADT dalam C++

#### 1. File Header (`.h`)

File header berisi deklarasi tipe data dan prototipe fungsi yang dapat digunakan oleh file lain. Pada program Guided, `mahasiswa.h` mendefinisikan struktur `mahasiswa` yang menyimpan NIM dan dua nilai. Header guard `#ifndef`, `#define`, dan `#endif` digunakan untuk mencegah deklarasi header diproses berulang kali ketika file disertakan lebih dari sekali.

#### 2. File Implementasi (`.cpp`)

File implementasi berisi isi dari fungsi-fungsi yang sudah dideklarasikan pada header. Dalam contoh, `mahasiswa.cpp` memuat fungsi `inputMhs()` untuk menerima input NIM dan nilai, serta `rata2()` untuk menghitung rata-rata. Dengan pemisahan ini, deklarasi dan cara kerja fungsi tidak bercampur dalam satu file.

#### 3. Program Utama (`main.cpp`)

File `main.cpp` menjadi titik awal program dijalankan. File ini membuat variabel bertipe `mahasiswa`, memanggil fungsi untuk mengisi data, lalu menampilkan hasil rata-ratanya. File utama cukup menggunakan deklarasi yang tersedia di header sehingga tidak perlu menuliskan kembali isi fungsi.

## Guided

### 1. Header – `mahasiswa.h`

```cpp
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif // MAHASISWA_H_INCLUDED
```

**Penjelasan**

File `mahasiswa.h` menjadi tempat untuk mengenalkan bentuk data mahasiswa dan fungsi yang bisa digunakan. Struktur `mahasiswa` menyimpan NIM pada `nim`, lalu dua nilai pada `nilai1` dan `nilai2`. Baris `void inputMhs(mahasiswa &m);` menyatakan bahwa fungsi `inputMhs()` menerima data mahasiswa melalui referensi, sehingga nilai yang dimasukkan bisa disimpan langsung ke variabel yang dikirim. Sementara itu, `rata2()` menerima data mahasiswa dan mengembalikan hasil bertipe `float`. Header guard di awal dan akhir file membantu mencegah deklarasi yang sama dimasukkan berulang kali.

### 2. Implementasi – `mahasiswa.cpp`

```cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim= ";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```

**Penjelasan**

File `mahasiswa.cpp` berisi cara kerja fungsi yang sudah dikenalkan di header. Fungsi `inputMhs()` menampilkan pertanyaan lalu menyimpan jawaban pengguna ke anggota struktur `mahasiswa`. Tanda `&` pada parameter `m` membuat perubahan tersebut berlaku pada variabel mahasiswa yang dikirim dari `main.cpp`. Fungsi `rata2()` menjumlahkan `nilai1` dan `nilai2`, kemudian membaginya dengan dua. Bagian `float(...)` membuat hasil pembagian dapat berupa bilangan desimal, bukan hanya bilangan bulat.

### 3. Program Utama – `main.cpp`

```cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata = " << rata2(mhs);
    return 0;
}
```

**Penjelasan**

Pada program utama, variabel `mhs` dibuat dengan tipe `mahasiswa`. Setelah itu, `inputMhs(mhs)` dipanggil untuk menerima NIM dan dua nilai dari pengguna. Ketika input selesai, `rata2(mhs)` menghitung nilai rata-rata dan hasilnya ditampilkan lewat `cout`. Ketiga file ini perlu dikompilasi bersama agar program bisa dijalankan, karena `main.cpp` menggunakan fungsi yang implementasinya ada di `mahasiswa.cpp`.

**Contoh output Guided**
[!Screenshot Output Guided 1](https://github.com/faliyaaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-3/output/Output-Guided-1.png)


## Unguided

### 1. Program Data Mahasiswa dengan Array

**Soal:** Buat program yang dapat menyimpan data maksimal 10 mahasiswa ke dalam array dengan field nama, NIM, UTS, UAS, tugas, dan nilai akhir. Nilai akhir dihitung menggunakan rumus `0.3 * UTS + 0.4 * UAS + 0.3 * tugas`.

**Source code – `main.cpp`**

```cpp
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
```

**Output Unguided 1**
[!Screenshot Output Unguided 1](https://github.com/faliyaaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-3/output/Output-Unguided-1.png)


**Penjelasan**

Program ini menggunakan array `data` yang dapat menyimpan maksimal 10 data mahasiswa. Setiap elemen array memakai struktur `Mahasiswa` yang berisi nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Fungsi `hitungNilaiAkhir()` menghitung nilai akhir sesuai rumus pada soal. Perulangan `for` pertama dipakai untuk mengisi data, sedangkan perulangan kedua menampilkan kembali data beserta hasil perhitungannya. Pemeriksaan jumlah dilakukan supaya jumlah data tidak melebihi kapasitas array.

### 2. Implementasi ADT `pelajaran`

**Soal:** Buat ADT `pelajaran` dengan data `namaMapel` dan `kodeMapel`, fungsi `create_pelajaran()` untuk membentuk data, serta prosedur `tampil_pelajaran()` untuk menampilkan data. Program dibagi menjadi `pelajaran.h`, `pelajaran.cpp`, dan `main.cpp`.

#### a. Header – `pelajaran.h`

```cpp
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```

#### b. Implementasi – `pelajaran.cpp`

```cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << '\n';
    cout << "nilai : " << pel.kodeMapel << '\n';
}
```

#### c. Program utama – `main.cpp`

```cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

**Output Unguided 2**
[!Screenshot Output Unguided 2](https://github.com/faliyaaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-3/output/Output-Unguided-2.png)

**Penjelasan**

ADT `pelajaran` menyimpan nama mata pelajaran dan kode mata pelajaran. File header mendefinisikan struktur serta deklarasi fungsi. Fungsi `create_pelajaran()` pada file implementasi mengisi kedua anggota struktur, lalu mengembalikan data yang sudah dibuat. Setelah itu, `tampil_pelajaran()` menerima data tersebut dan menampilkan nama serta kodenya. Di `main.cpp`, data dibuat menggunakan nilai `"Struktur Data"` dan `"STD"`, sesuai contoh yang diberikan dalam modul.

**Cara kompilasi**

Simpan ketiga file dalam folder yang sama, lalu kompilasi bersama, misalnya dengan:

```bash
g++ main.cpp pelajaran.cpp -o pelajaran
```

Jalankan hasil kompilasi dengan `./pelajaran` pada Linux atau `pelajaran.exe` pada Windows.

### 3. Array 2D dan Pointer

**Soal:** Buat dua array integer 2D berukuran 3×3 dan dua pointer integer. Program memiliki fungsi untuk menampilkan array 2D, menukarkan isi dua array pada posisi tertentu, dan menukarkan nilai variabel yang ditunjuk oleh dua pointer.

**Source code – `main.cpp`**

```cpp
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3], const char nama[]) {
    cout << nama << ":\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}

void tukarPosisiArray(int a[3][3], int b[3][3],
                      int baris, int kolom) {
    int sementara = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = sementara;
}

void tukarPointer(int *p1, int *p2) {
    int sementara = *p1;
    *p1 = *p2;
    *p2 = sementara;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int x = 100;
    int y = 200;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Sebelum pertukaran:\n";
    tampilArray(A, "Array A");
    tampilArray(B, "Array B");

    // Menukar elemen pada baris ke-2, kolom ke-3 (indeks 1, 2).
    tukarPosisiArray(A, B, 1, 2);

    cout << "\nSetelah elemen A[1][2] dan B[1][2] ditukar:\n";
    tampilArray(A, "Array A");
    tampilArray(B, "Array B");

    cout << "\nSebelum tukar pointer: x = " << x
         << ", y = " << y << '\n';
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer: x = " << x
         << ", y = " << y << '\n';

    return 0;
}
```

**Output Unguided 3**
[!Screenshot Output Unguided 3](https://github.com/faliyaaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-3/output/Output-Unguided-3.png)


**Penjelasan**

Program ini membuat dua array 2D, yaitu `A` dan `B`, yang masing-masing memiliki tiga baris dan tiga kolom. Fungsi `tampilArray()` menampilkan isi array dengan perulangan bersarang. Fungsi `tukarPosisiArray()` menukar nilai pada posisi yang sama di kedua array; contoh ini menukar elemen baris indeks `1` dan kolom indeks `2`, yaitu `A[1][2]` dengan `B[1][2]`. Indeks array dalam C++ dimulai dari nol, sehingga posisi indeks `(1, 2)` berarti baris kedua dan kolom ketiga jika dihitung seperti biasa.

Dua pointer `p1` dan `p2` masing-masing menunjuk ke variabel `x` dan `y`. Fungsi `tukarPointer()` menggunakan operator dereferensi `*` untuk menukar nilai yang ditunjuk pointer tersebut. Jadi, yang ditukar adalah isi variabel `x` dan `y`, bukan alamat yang disimpan oleh pointer.

## Kesimpulan

Pada praktikum ini, ADT dipelajari dengan memisahkan deklarasi tipe dan fungsi, implementasi fungsi, serta program utama ke dalam file yang berbeda. Pemisahan tersebut membuat program lebih mudah dibaca dan dikelola. Latihan juga menerapkan struktur dan array untuk menyimpan data mahasiswa, membuat ADT mata pelajaran, serta menggunakan array 2D dan pointer untuk menukar nilai. Dari latihan ini, terlihat bahwa fungsi dapat membantu memisahkan pekerjaan tertentu agar program lebih mudah dipahami dan diuji.

## Referensi

[1] Telkom University. *Modul 3 Struktur Data: Abstract Data Type (ADT)*, bagian 3.1 dan 3.2, hlm. 32–35. Materi praktikum yang diberikan pada perkuliahan.

[2] Indahyati, Uce, dan Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4

[3] cppreference.com. *C++ language: Classes*. https://en.cppreference.com/w/cpp/language/classes

[4] cppreference.com. *C++ language: Pointers*. https://en.cppreference.com/w/cpp/language/pointer
