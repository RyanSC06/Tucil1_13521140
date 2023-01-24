/* IMPLEMENTASI STRUKTUR DATA MATRIKS */
#ifndef MATRIX_H
#define MATRIX_H
#define _USE_MATH_DEFINES

#include "boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100
#define ROW_CAPC 200
#define COL_CAPC 200

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;  /* Elemen bertipe integer */
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;


typedef int IdxTypeC;  /* Index baris, kolom */
typedef char ElTypeC;  /* Elemen bertipe character */
typedef struct
{
   ElTypeC mem[ROW_CAPC][COL_CAPC];
   int rowEffC; /* banyaknya/ukuran baris yg terdefinisi */
   int colEffC; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixC;


/* KETERANGAN */
/* rowEff >= 1, colEff >= 1, rowEffC >= 1, colEffC >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] atau [0..ROW_CAPC-1][0..COL_CAPC-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */



/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m);
void createMatrixC(int nRows, int nCols, MatrixC *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]
#define ROW_EFFC(M) (M).rowEffC
#define COL_EFFC(M) (M).colEffC
#define ELMTC(M, i, j) (M).mem[(i)][(j)]

void displayMatrix(Matrix m);
void displayMatrixC(MatrixC m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom */

#endif