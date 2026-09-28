# Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)

<p align="center">Adhara Faliya Utanti - 109082500033</p>

## Dasar Teori

C++ merupakan bahasa pemrograman yang dikembangkan dari bahasa C oleh Bjarne Stroustrup. C++ digunakan untuk membuat berbagai program dan memiliki fitur seperti tipe data, variabel, operator, input/output, percabangan, dan perulangan. Pada praktikum ini digunakan beberapa konsep dasar C++ untuk membuat program sederhana. [1]

### A. Dasar Pemrograman C++<br/>

Dasar pemrograman C++ digunakan untuk menyusun instruksi agar komputer dapat menjalankan suatu program.

#### 1. Tipe Data

Tipe data merupakan jenis data yang digunakan dalam program. Beberapa tipe data dasar pada C++ yaitu `int` untuk bilangan bulat, `float` untuk bilangan pecahan, `double` untuk bilangan pecahan dengan presisi lebih besar, dan `char` untuk karakter. [1]

#### 2. Variabel

Variabel digunakan untuk menyimpan suatu nilai di dalam program. Nilai pada variabel dapat berubah selama program dijalankan. Bentuk umum deklarasi variabel adalah `tipe_data nama_variabel;`. [1]

#### 3. Operator

Operator merupakan simbol yang digunakan untuk melakukan operasi atau manipulasi data. Beberapa operator yang digunakan dalam C++ adalah operator aritmatika seperti `+`, `-`, `*`, `/`, dan `%`. [1]

### B. Input, Output, dan Perulangan<br/>

Input dan output digunakan agar program dapat menerima data dari pengguna dan menampilkan hasil dari proses program.

#### 1. Input

`cin` digunakan untuk menerima masukan dari keyboard dan menyimpannya ke dalam variabel. Bentuk penggunaannya adalah `cin >> nama_variabel;`. [1]

#### 2. Output

`cout` digunakan untuk menampilkan data atau hasil proses program ke layar. Penggunaan `cout` dapat digabungkan dengan teks maupun variabel. [1]

#### 3. Percabangan dan Perulangan

Percabangan digunakan untuk menentukan perintah berdasarkan kondisi tertentu, seperti `if`, `if-else`, dan `switch`. Sedangkan perulangan digunakan untuk menjalankan perintah secara berulang menggunakan `for`, `while`, atau `do-while`. [1]

## Unguided

### 1. Program Operasi Dua Bilangan Float

Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Hasil penjumlahan = " << a + b << endl;
    cout << "Hasil pengurangan = " << a - b << endl;
    cout << "Hasil perkalian = " << a * b << endl;
    cout << "Hasil pembagian = " << a / b << endl;

    return 0;
}
```

### Output Unguided 1 :

#### Output 1

[!Screenshot Output Unguided 1_1](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-1/output/Output-Unguided1-1.png)

#### Output 2

![Screenshot Output Unguided 1_2](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-1/output/Output-Unguided1-2.png)

**Penjelasan Unguided 1:**

Program menerima dua bilangan bertipe `float` menggunakan `cin`. Kedua bilangan tersebut kemudian digunakan untuk melakukan operasi penjumlahan, pengurangan, perkalian, dan pembagian. Hasil dari setiap operasi ditampilkan menggunakan `cout`.

---

### 2. Program Mengubah Angka Menjadi Tulisan

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang di-input-kan user adalah bilangan bulat positif mulai dari 0 sampai 100.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };

    string puluhan[] = {
        "", "", "dua puluh", "tiga puluh", "empat puluh",
        "lima puluh", "enam puluh", "tujuh puluh",
        "delapan puluh", "sembilan puluh"
    };

    if (angka == 100) {
        cout << "seratus";
    }
    else if (angka < 10) {
        cout << satuan[angka];
    }
    else if (angka == 10) {
        cout << "sepuluh";
    }
    else if (angka == 11) {
        cout << "sebelas";
    }
    else if (angka < 20) {
        cout << satuan[angka - 10] << " belas";
    }
    else {
        cout << puluhan[angka / 10];

        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }

    return 0;
}
```

### Output Unguided 2 :

#### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-1/output/Output-Unguided2-1.png)

#### Output 2

![Screenshot Output Unguided 2_2](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-1/output/Output-Unguided2-2.png)

**Penjelasan Unguided 2:**

Program menerima input berupa bilangan bulat dari 0 sampai 100. Program menggunakan percabangan untuk menentukan bentuk tulisan dari angka yang dimasukkan. Angka satuan, belasan, puluhan, dan angka 100 diproses dengan kondisi yang berbeda.

---

### 3. Program Pola Mirror

Buatlah program yang dapat memberikan input dan output sesuai dengan pola pada gambar 1.25 Mirror.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 0; i--) {

        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

#### Output 1

![Screenshot Output Unguided 3_1](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-1/output/Output-Unguided3-1.png)

#### Output 2

![Screenshot Output Unguided 3_2](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-1/output/Output-Unguided3-2.png)

**Penjelasan Unguided 3:**

Program menerima sebuah bilangan sebagai ukuran pola. Perulangan `for` digunakan untuk membuat pola angka dan tanda bintang. Pada setiap baris, jumlah angka semakin berkurang dan posisi pola bergeser ke kanan sehingga membentuk pola mirror sesuai dengan contoh pada soal.

## Kesimpulan

Pada praktikum Modul 1, telah dipelajari dasar-dasar pemrograman menggunakan bahasa C++. Materi yang diterapkan pada program meliputi penggunaan tipe data, variabel, input dengan `cin`, output dengan `cout`, operator aritmatika, percabangan, dan perulangan. Ketiga program yang dibuat dapat menerapkan konsep tersebut untuk menyelesaikan permasalahan sederhana sesuai dengan soal yang diberikan.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: STRUKTUR DATA*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
