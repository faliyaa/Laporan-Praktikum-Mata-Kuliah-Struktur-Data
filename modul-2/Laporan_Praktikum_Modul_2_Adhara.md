# <h1 align="center">Modul 2  PENGENALAN BAHASA C++ (BAGIAN KEDUA) </h1>
<p align="center">Adhara Faliya Utanti - 109082500033</p>

## Dasar Teori

### A. Array

Array adalah struktur data yang menampung banyak nilai bertipe sama dalam satu nama variabel. Masing-masing nilai (elemen) dapat diambil lewat nomor urutnya yang disebut indeks. Di C++, penomoran indeks selalu dimulai dari 0, jadi elemen paling awal berada di indeks 0, lalu disusul indeks 1, 2, dan seterusnya.

Berdasarkan banyaknya indeks yang diperlukan, array dibagi menjadi array satu dimensi, dua dimensi, dan multidimensi. Array satu dimensi berbentuk deretan data tunggal. Array dua dimensi menyerupai tabel (baris dan kolom) sehingga butuh dua indeks. Sedangkan array multidimensi memakai tiga indeks atau lebih untuk menunjuk satu elemen.

### B. Pointer dan Alamat Memori

Setiap data yang diproses program ditempatkan di memori (RAM). Tiap sel memori punya alamat sendiri yang tidak sama dengan sel lain, sehingga data dapat ditemukan kembali. Saat sebuah variabel dibuat, sistem operasi menyediakan sejumlah ruang memori untuk menampungnya.

Untuk melihat alamat suatu variabel, kita menulis operator `&` sebelum nama variabelnya. Pointer adalah variabel khusus yang isinya berupa alamat memori milik variabel lain. Lewat pointer, nilai pada alamat tujuan bisa dibaca atau diubah dengan operator `*` (dereference).

Karena pointer juga variabel, ia menempati memori dan memiliki alamat sendiri. Pointer harus dideklarasikan sesuai tipe data yang ditunjuknya, contohnya `int *p_int` untuk menunjuk data bertipe integer.

### C. Pointer dan Array

Pointer dan array saling berhubungan dekat. Sebuah pointer dapat diarahkan ke salah satu elemen array. Misalnya `pa = &a[0]` membuat `pa` menyimpan alamat elemen pertama array `a`. Isi elemen tersebut dapat dibaca dengan `*pa`.

Pointer juga bisa "berjalan" dari satu elemen ke elemen lain. Bila `pa` menunjuk elemen pertama, maka `pa + 1` menunjuk elemen kedua. Dengan kata lain, `pa + i` adalah alamat `a[i]`, dan `*(pa + i)` adalah isi dari `a[i]`.

### D. Pointer dan String

String dipakai untuk menyimpan teks. Di C++, string bergaya C pada dasarnya adalah array yang berisi karakter-karakter. Contoh deklarasinya `char nama[50]`, di mana angka 50 adalah batas maksimal karakter yang dapat ditampung.

Perintah `cin` hanya membaca teks sampai bertemu spasi. Jika ingin membaca satu baris penuh beserta spasinya, gunakan `getline()`. Selain itu, setiap string diakhiri karakter null `'\0'` sebagai penanda bahwa teks sudah selesai.

### E. Fungsi

Fungsi adalah potongan kode yang dibuat untuk mengerjakan satu tugas tertentu. Dengan fungsi, program dapat dipecah menjadi bagian-bagian kecil sehingga lebih rapi dan mudah dibaca. Fungsi juga mencegah penulisan kode yang sama berulang kali, sehingga program lebih ringkas.

Umumnya fungsi menerima masukan lewat parameter, memprosesnya, lalu mengirim hasil berupa nilai balik. Struktur fungsi di C++ terdiri dari tipe data keluaran, nama fungsi, daftar parameter, dan badan fungsi yang berisi pernyataan.

### F. Prosedur

Prosedur di C++ adalah fungsi yang tidak menghasilkan nilai balik, ditandai dengan tipe `void`. Prosedur dipakai untuk menjalankan suatu pekerjaan saja tanpa mengirim hasil kembali ke pemanggilnya.

Penulisannya diawali kata `void`, kemudian nama prosedur dan daftar parameternya. Seluruh perintah di dalam prosedur akan dieksekusi setiap kali prosedur itu dipanggil dari program utama.

### G. Parameter Fungsi

Parameter dibedakan menjadi parameter formal dan parameter aktual. Parameter formal adalah variabel yang ditulis pada definisi fungsi, sedangkan parameter aktual adalah nilai/argumen yang diberikan saat fungsi dipanggil. Parameter aktual boleh berupa variabel, konstanta, ataupun ekspresi.

C++ menyediakan tiga cara pengiriman parameter, yaitu *call by value*, *call by pointer*, dan *call by reference*.

#### 1. Call by Value

Pada cara ini, isi parameter aktual disalin ke parameter formal. Akibatnya, apa pun perubahan pada parameter formal di dalam fungsi tidak berpengaruh ke variabel aslinya di luar fungsi.

#### 2. Call by Pointer

Di sini yang dikirim adalah alamat variabel, ditampung oleh parameter bertipe pointer. Karena fungsi memegang alamat aslinya, nilai variabel di luar fungsi ikut berubah. Saat memanggil fungsi, alamat dikirim dengan operator `&`.

#### 3. Call by Reference

Pada cara ini parameter ditulis dengan tanda `&` sehingga menjadi referensi (alias) dari variabel aslinya. Fungsi pun dapat mengubah nilai variabel di luar. Bedanya dengan call by pointer, saat pemanggilan tidak perlu menambahkan operator apa pun pada argumen.

## Guided

### 1. Program Array 1

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << nilai[i] << endl;
    }

    return 0;
}

```
Kode ini memperagakan array satu dimensi paling dasar. Dibuat sebuah array bernama `nilai` bertipe `int` dengan lima slot. Kelima slot itu diisi satu per satu secara manual: 80, 85, 90, 75, dan 95, mulai dari indeks 0 sampai 4.

Setelah terisi, loop `for` berjalan dari indeks 0 hingga 4 dan mencetak tiap elemen, masing-masing diakhiri `endl` sehingga hasilnya tampil menurun ke bawah.

Intinya, program ini menunjukkan tiga hal: cara membuat array, cara mengisi elemennya, dan cara menampilkannya dengan perulangan.

### 2. Program Array 2

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
    {80, 85, 90},
    {75, 80, 85},
    {90, 95, 100}
};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
Program ini memakai array dua dimensi berukuran 3×3 yang menyerupai matriks. Sembilan angka langsung dimasukkan ketika array dideklarasikan. Untuk menampilkannya dipakai dua loop yang bertingkat: loop bagian luar berganti baris, sedangkan loop bagian dalam menelusuri kolom pada baris tersebut. Hasilnya muncul sebagai tabel 3 baris × 3 kolom.

### 3. Program Array Banyak

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        },
        {
            {
                {9, 10},
                {11, 12}
            },
            {
                {13, 14},
                {15, 16}
            }
        }
    };

    cout << data[0][0][0][0] << endl; // 1
    cout << data[1][1][1][1] << endl; // 16

    return 0;
}
```
Contoh ini menunjukkan array dengan empat dimensi. Array `data` berukuran [2][2][2][2], jadi menyimpan 2 × 2 × 2 × 2 = 16 elemen. Isinya adalah angka 1 sampai 16 yang ditulis dalam kurung kurawal bersarang sesuai tingkat dimensinya.

Dua elemen kemudian diambil dan dicetak: `data[0][0][0][0]` yang berisi 1 (elemen paling awal) dan `data[1][1][1][1]` yang berisi 16 (elemen paling akhir). Dari sini terlihat bahwa untuk mengakses elemen array multidimensi, kita menyebutkan satu indeks untuk setiap dimensinya.

### 4. Program Pointer 1

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';

    cout << a << endl;
    cout << &a << endl;
    cout << j << endl;
    cout << &j << endl;

    cout << &(arr[4]) << endl;

    return 0;
    
}
```
Program ini mengenalkan operator alamat `&`, yang menjadi dasar pemahaman pointer. Dideklarasikan variabel `a` (char), `j` (int), dan array `arr[6]`, tetapi hanya `a` dan `arr[3]` yang diberi nilai. Selanjutnya program mencetak nilai sekaligus alamat variabel-variabel tersebut.

Ada dua hal menarik. Pertama, `cout` menganggap alamat bertipe `char` sebagai string, sehingga keluarannya berupa deretan karakter yang tampak acak, bukan angka heksadesimal. Kedua, `j` tidak pernah diberi nilai awal, jadi yang tercetak adalah garbage value, yaitu sisa data acak yang kebetulan ada di memori.

### 5. Program Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;

    return 0;
}
```
Program ini memperlihatkan alur kerja pointer secara lengkap. Ada `x` dan `y` bertipe `int`, serta `px` yang merupakan pointer ke `int`. Mula-mula `x` diisi 87, lalu `px` diarahkan ke alamat `x` dengan `&x`. Setelah itu `*px` dipakai untuk mengambil nilai di alamat tersebut dan menyalinnya ke `y`, sehingga `y` ikut bernilai 87.

Saat dijalankan, alamat `x` dan isi `px` akan tampil sama (berupa kode heksadesimal) karena `px` memang menyimpan alamat `x`. Sementara `x`, `*px`, dan `y` semuanya menampilkan angka 87.

### 6. Program Pointer 3

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    for (i = 0; i < MAX; i++) {
        cout << "masukkan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    for (i = 0; i < MAX; i++)
        cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;

    cout << "\n nilai tahunan : \n";

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];
        cout << "\n";
    }

    return 0;
}
```
Konstanta `MAX` bernilai 5 dipakai sebagai ukuran array di program ini. Ada array satu dimensi `nilai[5]` bertipe `float` yang isinya dimasukkan pengguna lewat `cin`, dan array dua dimensi `nilai_tahun[5][5]` yang sudah berisi data sejak awal.

Setelah input selesai, program menampilkan kembali kelima nilai secara berurutan. Kemudian isi `nilai_tahun` dicetak sebagai matriks 5×5 menggunakan loop bersarang. Program ini menggabungkan penggunaan array satu dan dua dimensi dalam satu contoh.

### 7. Program Pointer 4

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```
Program kecil ini menunjukkan string sebagai array karakter. Array `nama` diisi kata "strukdat" dan ditampilkan utuh lewat `cout`. Setelah itu dicetak satu karakter saja, yakni `nama[3]`, yang hasilnya adalah huruf `u`. Jadi string bisa dicetak sekaligus, tetapi juga bisa diambil per karakter menggunakan indeks.

### 8. Program Fungsi

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
    int x, y, z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 =";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 =";
    cin >> z;
    cout << "nilai maksimumnya adalah = " << maks3(x, y, z);
    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
    return (temp_max);
}
```
Program ini mencari bilangan terbesar dari tiga masukan dengan bantuan fungsi `maks3`. Fungsi `main` bertugas menerima tiga angka dari pengguna, lalu menyerahkannya ke `maks3`. Di dalam fungsi, angka pertama dijadikan patokan sementara (`temp_max`), kemudian dibandingkan dengan angka kedua dan ketiga; kalau ada yang lebih besar, patokan diganti. Nilai akhirnya dikembalikan dengan `return` dan dicetak oleh `main`.

Contoh ini menggambarkan fungsi yang menerima parameter dan memberikan nilai balik.

### 9. Program Procedure

```C++
#include <iostream>
using namespace std;

void tulis(int x);

int main() {
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++)
        cout << "baris ke-" << i + 1 << endl;
}
```
Di sini `tulis` adalah prosedur (fungsi `void`). Pengguna diminta mengisi jumlah baris, lalu angka itu dikirim ke `tulis`, yang mencetak "baris ke-1", "baris ke-2", dan seterusnya sebanyak angka tersebut menggunakan loop `for`.

Karena bertipe `void`, `tulis` tidak mengirim nilai apa pun kembali ke `main`; ia hanya mengerjakan tugasnya. Inilah pembeda utama prosedur dengan fungsi biasa seperti `maks3` pada contoh sebelumnya.


## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;

const int UKURAN = 3;

void bacaMatriks(int m[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cin >> m[baris][kolom];
        }
    }
}

void tampilMatriks(int m[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            cout << m[baris][kolom] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int p[UKURAN][UKURAN], int q[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++)
        for (int kolom = 0; kolom < UKURAN; kolom++)
            hasil[baris][kolom] = p[baris][kolom] + q[baris][kolom];
}

void kurangMatriks(int p[UKURAN][UKURAN], int q[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++)
        for (int kolom = 0; kolom < UKURAN; kolom++)
            hasil[baris][kolom] = p[baris][kolom] - q[baris][kolom];
}

void kaliMatriks(int p[UKURAN][UKURAN], int q[UKURAN][UKURAN], int hasil[UKURAN][UKURAN]) {
    for (int baris = 0; baris < UKURAN; baris++) {
        for (int kolom = 0; kolom < UKURAN; kolom++) {
            int total = 0;
            for (int k = 0; k < UKURAN; k++) {
                total += p[baris][k] * q[k][kolom];
            }
            hasil[baris][kolom] = total;
        }
    }
}

int main() {
    int matA[UKURAN][UKURAN], matB[UKURAN][UKURAN];
    int hasilTambah[UKURAN][UKURAN], hasilKurang[UKURAN][UKURAN], hasilKali[UKURAN][UKURAN];

    cout << "Masukkan elemen matriks A (3x3):\n";
    bacaMatriks(matA);

    cout << "\nMasukkan elemen matriks B (3x3):\n";
    bacaMatriks(matB);

    jumlahMatriks(matA, matB, hasilTambah);
    kurangMatriks(matA, matB, hasilKurang);
    kaliMatriks(matA, matB, hasilKali);

    cout << "\nHasil Penjumlahan:\n";
    tampilMatriks(hasilTambah);

    cout << "\nHasil Pengurangan:\n";
    tampilMatriks(hasilKurang);

    cout << "\nHasil Perkalian:\n";
    tampilMatriks(hasilKali);

    return 0;
}
```
### Output Unguided 1 :
![Screenshot Output Unguided 1](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-2/output/Output-Unguided-1.png)

Program ini mengerjakan tiga operasi pada dua matriks 3×3: tambah, kurang, dan kali. Agar kodenya tidak menumpuk di `main`, setiap pekerjaan dipisah menjadi fungsi tersendiri, yaitu `bacaMatriks`, `tampilMatriks`, `jumlahMatriks`, `kurangMatriks`, dan `kaliMatriks`. Ukuran matriks disimpan dalam konstanta `UKURAN` sehingga mudah diubah.

Untuk penjumlahan dan pengurangan, elemen yang berada di posisi baris dan kolom yang sama pada matriks A dan B dioperasikan langsung. Pada perkalian, tiap elemen hasil didapat dengan menjumlahkan hasil kali elemen sebaris dari A dengan elemen sekolom dari B, menggunakan tiga loop bersarang. Terakhir, ketiga hasil ditampilkan dalam bentuk matriks lewat `tampilMatriks`.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukarDua(int *p, int *q) {
    int sementara = *p;
    *p = *q;
    *q = sementara;
}

void tukar(int *a, int *b, int *c) {
    tukarDua(a, b);
    tukarDua(b, c);
}

void tampil(int a, int b, int c) {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:" << endl;
    tampil(a, b, c);

    tukar(&a, &b, &c);

    cout << "\nSetelah ditukar:" << endl;
    tampil(a, b, c);

    return 0;
}
```
### Output Unguided 2 :
![Screenshot Output Unguided 2](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-2/output/Output-Unguided-2.png)

Program ini menukar tiga variabel dengan *call by pointer*. Pertukaran dibangun dari dua langkah menukar dua variabel. Fungsi `tukarDua` menukar isi dua alamat memakai variabel `sementara`. Fungsi `tukar` memanggilnya dua kali: pertama menukar `a` dengan `b` (urutan menjadi 20, 10, 30), lalu menukar `b` dengan `c` (urutan menjadi 20, 30, 10).

Pemanggilan `tukar(&a, &b, &c)` mengirim alamat variabel asli, sehingga perubahan terjadi langsung pada `a`, `b`, dan `c` di `main`. Fungsi `tampil` dipakai untuk mencetak nilai sebelum dan sesudah penukaran.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array --- 1. Tampilkan isi array 2. cari nilai maksimum 3. cari nilai minimum 4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMinimum(int data[], int jumlah) {
    int terkecil = data[0];
    for (int idx = 1; idx < jumlah; idx++) {
        if (data[idx] < terkecil)
            terkecil = data[idx];
    }
    return terkecil;
}

int cariMaksimum(int data[], int jumlah) {
    int terbesar = data[0];
    for (int idx = 1; idx < jumlah; idx++) {
        if (data[idx] > terbesar)
            terbesar = data[idx];
    }
    return terbesar;
}

void hitungRataRata(int data[], int jumlah) {
    int total = 0;
    for (int idx = 0; idx < jumlah; idx++)
        total += data[idx];

    cout << "Nilai rata-rata = " << (float) total / jumlah << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int banyak = sizeof(arrA) / sizeof(arrA[0]);
    int menu = 0;

    while (menu != 5) {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "\nIsi array: ";
                for (int idx = 0; idx < banyak; idx++)
                    cout << arrA[idx] << " ";
                cout << endl;
                break;
            case 2:
                cout << "\nNilai maksimum = " << cariMaksimum(arrA, banyak) << endl;
                break;
            case 3:
                cout << "\nNilai minimum = " << cariMinimum(arrA, banyak) << endl;
                break;
            case 4:
                cout << "\n";
                hitungRataRata(arrA, banyak);
                break;
            case 5:
                cout << "\nProgram selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }
    }

    return 0;
}
```
### Output Unguided 3 :
![Screenshot Output Unguided 3](https://github.com/faliyaa/Laporan-Praktikum-Mata-Kuliah-Struktur-Data/blob/main/modul-2/output/Output-Unguided-3.png)

Program ini mengolah sebuah array berisi sepuluh angka (11, 8, 5, 7, 12, 26, 3, 54, 33, 55) lewat menu interaktif. Fungsi `cariMinimum()` dan `cariMaksimum()` menelusuri array sambil menyimpan nilai terkecil/terbesar yang ditemukan, lalu mengembalikannya. Prosedur `hitungRataRata()` menjumlahkan seluruh elemen, membaginya dengan banyak data, dan langsung mencetak hasilnya tanpa nilai balik.

Banyak elemen array dihitung otomatis dengan `sizeof(arrA) / sizeof(arrA[0])`, sehingga kode tetap benar bila isi array diubah. Pilihan menu ditangani oleh `switch-case`, dan perulangan `while` membuat menu muncul terus sampai pengguna memilih 5 (Keluar).

## Kesimpulan

Modul ini menunjukkan bagaimana C++ membantu menata data dan kode agar lebih teratur melalui array, pointer, fungsi, dan prosedur.

Array menyimpan sekumpulan data bertipe sama yang diakses dengan indeks mulai dari 0, dan dapat berbentuk satu dimensi, dua dimensi (seperti tabel), atau lebih. Elemen-elemennya tersusun berurutan di memori, sehingga memori sendiri dapat dipandang sebagai array satu dimensi besar yang tiap selnya beralamat unik.

Dari konsep alamat inilah pointer lahir, yakni variabel yang berisi alamat variabel lain. Operator & dipakai untuk mengambil alamat, dan * untuk membaca atau mengubah nilai pada alamat itu. Pointer berhubungan erat dengan array (pa + i adalah alamat a[i], dan *(pa + i) adalah nilainya) serta dengan string yang sejatinya array karakter berakhiran '\0'. Satu perbedaan penting: char amessage[] adalah array yang isinya boleh diubah, sementara char *pmessage menunjuk string konstan yang isinya tidak boleh diubah.

Fungsi membuat program lebih modular dan menghindari kode berulang. Fungsi menghasilkan nilai balik, sedangkan prosedur (fungsi void) hanya menjalankan tugas tanpa mengembalikan nilai. Untuk pengiriman parameter ada tiga cara. Call by value hanya menyalin nilai sehingga variabel asli tetap, jadi penukaran lewat cara ini gagal. Call by pointer (tukar(&a, &b)) dan call by reference (int &x) sama-sama dapat mengubah variabel asli; bedanya, call by reference lebih ringkas karena cukup dipanggil dengan tukar(a, b).

## Referensi
[1] Malik, D. S. (2010). *Data Structures Using C++* (2nd ed.). Boston: Cengage Learning.
<br>[2] Drozdek, A. (2013). *Data Structures and Algorithms in C++* (4th ed.). Boston: Cengage Learning.
