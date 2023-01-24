#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
/* KAMUS LOKAL */
    /* - */
/* ALGORITMA */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

void displayMatrix(Matrix m) {
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
/* KAMUS LOKAL */
    IdxType i, j;
/* ALGORITMA */
    j = 0;
    for (i = 0; i <= ROW_EFF(m)-1; i++) {
        while (j != COL_EFF(m)-1) {
            printf ("%d ", ELMT(m, i, j));
            j = j + 1;
        } 
        printf ("%d\n", ELMT(m, i, j));
        j = 0;
    }
}

void createMatrixC(int nRows, int nCols, MatrixC *m) {
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
/* KAMUS LOKAL */
    /* - */
/* ALGORITMA */
    ROW_EFFC(*m) = nRows;
    COL_EFFC(*m) = nCols;
}

void displayMatrixC(MatrixC m) {
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom */
/* KAMUS LOKAL */
    IdxTypeC i, j;
/* ALGORITMA */
    for (i = 0; i <= ROW_EFFC(m)-1; i++) {
        if (ELMTC(m, i, 0) != '\0') {
            for (j = 0; j <= COL_EFFC(m)-1; j++) {
                if (j == COL_EFFC(m)-1) {
                    printf("%c\n", ELMTC(m, i, j));
                } else {
                    printf("%c", ELMTC(m, i, j));
                }
            }
        }
    }
}