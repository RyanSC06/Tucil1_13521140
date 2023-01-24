#include "boolean.h"

/* PERNYATAAN SUMBER */
/* swap & permutation mengacu pada: https://people.engr.tamu.edu/djimenez/ut/utsa/cs3343/lecture25.html */
/* makeOpsCombo mengacu pada : https://rosettacode.org/wiki/Permutations_with_repetitions#C */

/* Kelompok fungsi mencari tempat kosong */
int searchAvailable (Matrix m);
int searchAvailableC (MatrixC m);
int arrSearchAvailable (int a[], int n);

/* Kelompok fungsi menerima dan membuat input */
boolean validateInput(char w[]);
void makeInputs (char arr[], int out[]);
void make_from_random (int num, int out[]);

/* Kelompok fungsi permutasi */
void swap (int arr[], int i, int j);
void permutation (int v[], int n, int i, Matrix *result);
boolean isDuplicate (Matrix m, int x);
void makeOpsCombo (Matrix *result);

/* Kelompok fungsi operasi */
float operation (float a, float b, int op);
void setElmtC (MatrixC *valid_combo, Matrix num_combo, int num, int no, int row, int *col);

/* Kelompok fungsi evaluasi */
void evaluate1 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution);
void evaluate2 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution);
void evaluate3 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution);
void evaluate4 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution);
void evaluate5 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution);

/* Kelompok fungsi mencetak */
void print_from_num (int num);
char num_to_op (int num);
void print_from_num2 (int num, FILE *file);
void printToFile (int inputs[], MatrixC m, int num_of_solution, double execution_time);