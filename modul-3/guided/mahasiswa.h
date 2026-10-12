#ifndef MAHASISWA_H_INCLUDED //buat cek apakah header udah pernah di tambahin sebelumnya
#define MAHASISWA_H_INCLUDED //buat mencegah duplikasi header

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED