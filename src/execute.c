#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "execute.h"

/* Kelompok fungsi mencari tempat kosong */
int searchAvailable (Matrix m) {
/* KAMUS LOKAL */
	int	i, j;
	boolean found;
/* ALGORITMA */
    i = 0;
    j = 0;
    found = 0;
    while (i < ROW_EFF(m) && found == 0) {
        if (ELMT(m, i, j) == 0) {
            found = 1;
        } else {
            i = i + 1;
        }
    }
    
    return (i);
}

int searchAvailableC (MatrixC m) {
/* KAMUS LOKAL */
	int	i, j;
	boolean found;
/* ALGORITMA */
    i = 0;
    j = 0;
    found = 0;
    while (i < ROW_EFFC(m) && found == 0) {
        if (ELMTC(m, i, j) == '\0') {
            found = 1;
        } else {
            i = i + 1;
        }
    }
    
    return (i);
}

int arrSearchAvailable (int a[], int n) {
/* KAMUS LOKAL */
	int	i;
	boolean found;
/* ALGORITMA */
    i = 0;
    found = 0;
    while ((i < n) && found == 0) {
        if (a[i] == 0) {
            found = 1;
        } else {
            i = i + 1;
        }
    }
    return (i);
}


/* Kelompok fungsi menerima dan membuat input */
boolean validateInput(char w[]) {
    if (strlen(w) > 1) {
        if ((w[0] = '1') && (w[1] == '0')) {
            return (1);
        } else {
            return (0);
        }
    } else if (strlen(w) == 1) {
        if (w[0] == 'A' || w[0] == '2' || w[0] == '3' || w[0] == '4' || w[0] == '5' || w[0] == '6' || w[0] == '7' || w[0] == '8' || w[0] == '9' || w[0] == 'J' || w[0] == 'Q' || w[0] == 'K') {
            return (1);
        } else {
            return (0);
        }
    } else {
        return (0);
    }
}

void makeInputs (char arr[], int out[]) {
    if (strlen(arr) > 1) {
	    out[arrSearchAvailable(out, 4)] = 10;
	} else if (arr[0] == 'A') {
	    out[arrSearchAvailable(out, 4)] = 1;
	} else if (arr[0] == '2') {
	    out[arrSearchAvailable(out, 4)] = 2;
	} else if (arr[0] == '3') {
	    out[arrSearchAvailable(out, 4)] = 3;
	} else if (arr[0] == '4') {
	    out[arrSearchAvailable(out, 4)] = 4;
	} else if (arr[0] == '5') {
	    out[arrSearchAvailable(out, 4)] = 5;
	} else if (arr[0] == '6') {
	    out[arrSearchAvailable(out, 4)] = 6;
	} else if (arr[0] == '7') {
	    out[arrSearchAvailable(out, 4)] = 7;
	} else if (arr[0] == '8') {
	    out[arrSearchAvailable(out, 4)] = 8;
	} else if (arr[0] == '9') {
	    out[arrSearchAvailable(out, 4)] = 9;
	} else if (arr[0] == 'J') {
	    out[arrSearchAvailable(out, 4)] = 11;
	} else if (arr[0] == 'Q') {
	    out[arrSearchAvailable(out, 4)] = 12;
	} else if (arr[0] == 'K') {
	    out[arrSearchAvailable(out, 4)] = 13;
	}
}

void make_from_random (int num, int out[]) {
    out[arrSearchAvailable(out, 4)] = num;
}


/* Kelompok fungsi permutasi */
void swap (int arr[], int i, int j) {
/* KAMUS LOKAL */
	int	t;
/* ALGORITMA */
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void permutation (int v[], int n, int i, Matrix *result) {
/* KAMUS LOKAL */
	int	j;
	int row;
/* ALGORITMA */
    row = searchAvailable(*result);
	if (i == n) {
		for (j = 0; j < n; j++) {
		    ELMT(*result, row, j) = v[j];
		}
	} else {
		for (j = i; j < n; j++) {
			swap (v, i, j);
			permutation (v, n, i+1, result);
			swap (v, i, j);
		}
	}
}

boolean isDuplicate (Matrix m, int x) {
/* KAMUS LOKAL */
	int	i, j;
	boolean same;
/* ALGORITMA */
    for (i = 0; i < ROW_EFF(m); i++) {
        same = true;
        for (j = 0; j < COL_EFF(m); j++) {
            if ((i != x) && (ELMT(m, i, j) != ELMT(m, x, j))) {
                same = false;
            } else if (i == x) {
                same = false;
            }
        }
        if (same == true) {
            break;
        }
    }
    return (same);
}

void makeOpsCombo (Matrix *result) {
/* KAMUS LOKAL */
    int temp1, row, col;
	int numbers = 3;
	int a[numbers+1], above = 4, temp2;
/* ALGORITMA */
	for (temp2 = 1 ; temp2 <= numbers; temp2++) {
		a[temp2] = 1;
	}
	a[numbers] = 0;
	temp1 = numbers;
	while (1) {
		if(a[temp1] == above){
			temp1--;
			if(temp1 == 0) {
				break;
			}
		}
		else {
			a[temp1]++;
			while (temp1 < numbers) {
				temp1++;
				a[temp1] = 1;
			}
			
			row = searchAvailable(*result);
			col = 0;
			for (temp2 = 1 ; temp2 <= numbers; temp2++) {
				ELMT(*result, row, col) = a[temp2];
				col = col + 1;
			}
		}
	}
}



/* Kelompok fungsi operasi */
float operation (float a, float b, int op) {
/* KAMUS LOKAL */
    float result;
/* ALGORITMA */
    if (op == 1) {
        result = (float) a + (float) b;
        return (result);
    } else if (op == 2) {
        result = (float) a - (float) b;
        return (result);
    } else if (op == 3) {
        result = (float) a * (float) b;
        return (result);
    } else if (op == 4) {
        result = (float) a / (float) b;
        return (result);
    }
}

void setElmtC (MatrixC *valid_combo, Matrix num_combo, int num, int no, int row, int *col) {
/* KAMUS LOKAL */
    /* - */
/* ALGORITMA */
    if (ELMT(num_combo, num, no) == 10) {
        ELMTC(*valid_combo, row, *col) = '1';
        ELMTC(*valid_combo, row, *col+1) = '0';
        *col = *col + 2;
    } else if (ELMT(num_combo, num, no) == 11) {
        ELMTC(*valid_combo, row, *col) = 'J';
        *col = *col + 1;
    } else if (ELMT(num_combo, num, no) == 12) {
        ELMTC(*valid_combo, row, *col) = 'Q';
        *col = *col + 1;
    } else if (ELMT(num_combo, num, no) == 13) {
        ELMTC(*valid_combo, row, *col) = 'K';
        *col = *col + 1;
    } else if (ELMT(num_combo, num, no) == 1) {
        ELMTC(*valid_combo, row, *col) = 'A';
        *col = *col + 1;
    } else {
        ELMTC(*valid_combo, row, *col) = ELMT(num_combo, num, no) + '0';
        *col = *col + 1;
    }
}



/* Kelompok fungsi evaluasi */
void evaluate1 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution) {
/* KAMUS LOKAL */
     float result1, result2, result3;
     int row, col;
/* ALGORITMA */
    /* ((a + b) + c) + d */
	result1 = operation(ELMT(num_combo, num, 0), ELMT(num_combo, num, 1), ELMT(op_combo, op, 0));
	result2 = operation(result1, ELMT(num_combo, num, 2), ELMT(op_combo, op, 1));
	result3 = operation(result2, ELMT(num_combo, num, 3), ELMT(op_combo, op, 2));
	if (result3 == 24) {
	    *num_of_solution = *num_of_solution + 1;
	    row = searchAvailableC(*valid_combo);
	    col = 0;
        
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 0, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 0));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 1, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 1));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 2, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 2));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 3, row, &col);
	}
}

void evaluate2 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution) {
/* KAMUS LOKAL */
     float result1, result2, result3;
     int row, col;
/* ALGORITMA */
    /* (a + (b + c)) + d */
	result1 = operation(ELMT(num_combo, num, 1), ELMT(num_combo, num, 2), ELMT(op_combo, op, 1));
	result2 = operation(ELMT(num_combo, num, 0), result1, ELMT(op_combo, op, 0));
	result3 = operation(result2, ELMT(num_combo, num, 3), ELMT(op_combo, op, 2));
	if (result3 == 24) {
	    *num_of_solution = *num_of_solution + 1;
	    row = searchAvailableC(*valid_combo);
	    col = 0;
	    
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 0, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 0));
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 1, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 1));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 2, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 2));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 3, row, &col);
	}
}

void evaluate3 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution) {
/* KAMUS LOKAL */
     float result1, result2, result3;
     int row, col;
/* ALGORITMA */
    /* a + ((b + c) + d) */
	result1 = operation(ELMT(num_combo, num, 1), ELMT(num_combo, num, 2), ELMT(op_combo, op, 1));
	result2 = operation(result1, ELMT(num_combo, num, 3), ELMT(op_combo, op, 2));
	result3 = operation(ELMT(num_combo, num, 0), result2, ELMT(op_combo, op, 0));
	if (result3 == 24) {
	    *num_of_solution = *num_of_solution + 1;
	    row = searchAvailableC(*valid_combo);
	    col = 0;
	    
	    setElmtC (valid_combo, num_combo, num, 0, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 0));
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 1, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 1));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 2, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 2));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 3, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
	}
}

void evaluate4 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution) {
/* KAMUS LOKAL */
     float result1, result2, result3;
     int row, col;
/* ALGORITMA */
    /* a + (b + (c + d)) */
	result1 = operation(ELMT(num_combo, num, 2), ELMT(num_combo, num, 3), ELMT(op_combo, op, 2));
	result2 = operation(ELMT(num_combo, num, 1), result1, ELMT(op_combo, op, 1));
	result3 = operation(ELMT(num_combo, num, 0), result2, ELMT(op_combo, op, 0));
	if (result3 == 24) {
	    *num_of_solution = *num_of_solution + 1;
	    row = searchAvailableC(*valid_combo);
	    col = 0;
	    
	    setElmtC (valid_combo, num_combo, num, 0, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 0));
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 1, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 1));
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 2, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 2));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 3, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = ')';
	}
}

void evaluate5 (Matrix num_combo, Matrix op_combo, MatrixC *valid_combo, int num, int op, int *num_of_solution) {
/* KAMUS LOKAL */
     float result1, result2, result3;
     int row, col;
/* ALGORITMA */
    /* (a + b) + (c + d) */
	result1 = operation(ELMT(num_combo, num, 0), ELMT(num_combo, num, 1), ELMT(op_combo, op, 0));
	result2 = operation(ELMT(num_combo, num, 2), ELMT(num_combo, num, 3), ELMT(op_combo, op, 2));
	result3 = operation(result1, result2, ELMT(op_combo, op, 1));
	if (result3 == 24) {
	    *num_of_solution = *num_of_solution + 1;
	    row = searchAvailableC(*valid_combo);
	    col = 0;
	    
	    ELMTC(*valid_combo, row, col) = '(';
	    col = col + 1;
        setElmtC (valid_combo, num_combo, num, 0, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 0));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 1, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
        col = col + 1;
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 1));
        col = col + 1;
        ELMTC(*valid_combo, row, col) = '(';
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 2, row, &col);
        ELMTC(*valid_combo, row, col) = num_to_op(ELMT(op_combo, op, 2));
        col = col + 1;
        setElmtC (valid_combo, num_combo, num, 3, row, &col);
        ELMTC(*valid_combo, row, col) = ')';
	}
}


/* Kelompok fungsi mencetak */
void print_from_num (int num) {
    if (num == 1) {
	    printf("A");
	} else if (num == 2) {
	    printf("2");
	} else if (num == 3) {
	    printf("3");
	} else if (num == 4) {
	    printf("4");
	} else if (num == 5) {
	    printf("5");
	} else if (num == 6) {
	    printf("6");
	} else if (num == 7) {
	    printf("7");
	} else if (num == 8) {
	    printf("8");
	} else if (num == 9) {
	    printf("9");
	} else if (num == 10) {
	    printf("10");
	} else if (num == 11) {
	    printf("J");
	} else if (num == 12) {
	    printf("Q");
	} else if (num == 13) {
	    printf("K");
	}
}

char num_to_op (int num) {
/* KAMUS LOKAL */
    /* - */
/* ALGORITMA */
    if (num == 1) {
        return ('+');
    } else if (num == 2) {
        return ('-');
    } else if (num == 3) {
        return ('*');
    } else if (num == 4) {
        return ('/');
    }
}

void print_from_num2 (int num, FILE *file) {
    if (num == 1) {
	    fprintf(file, "A\n");
	} else if (num == 2) {
	    fprintf(file, "2\n");
	} else if (num == 3) {
	    fprintf(file, "3\n");
	} else if (num == 4) {
	    fprintf(file, "4\n");
	} else if (num == 5) {
	    fprintf(file, "5\n");
	} else if (num == 6) {
	    fprintf(file, "6\n");
	} else if (num == 7) {
	    fprintf(file, "7\n");
	} else if (num == 8) {
	    fprintf(file, "8\n");
	} else if (num == 9) {
	    fprintf(file, "9\n");
	} else if (num == 10) {
	    fprintf(file, "10\n");
	} else if (num == 11) {
	    fprintf(file, "J\n");
	} else if (num == 12) {
	    fprintf(file, "Q\n");
	} else if (num == 13) {
	    fprintf(file, "K\n");
	}
}

void printToFile (int inputs[], MatrixC m, int num_of_solution, double execution_time) {
/* KAMUS LOKAL */
    FILE *file;
    char name_file[15];
    int i, j;
/* ALGORITMA */
    printf("Masukkan nama fail (maksimal 15 karakter): ");
    scanf("%s", name_file);
    file = fopen(name_file, "w");
    
    fprintf(file, "\n");
    fprintf(file, " $$$$$$\\  $$\\   $$\\          $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\        $$$$$$\\   $$$$$$\\  $$\\   $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\ \n");
    fprintf(file, "$$  __$$\\ $$ |  $$ |        $$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|      $$  __$$\\ $$  __$$\\ $$ |  $$ |   $$ |$$  _____|$$  __$$\\ \n");
    fprintf(file, "\\__/  $$ |$$ |  $$ |        $$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |            $$ /  \\__|$$ /  $$ |$$ |  $$ |   $$ |$$ |      $$ |  $$ | \n");
    fprintf(file, " $$$$$$  |$$$$$$$$ |$$$$$$\\ $$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\          \\$$$$$$\\  $$ |  $$ |$$ |  \\$$\\  $$  |$$$$$\\    $$$$$$$  | \n");
    fprintf(file, "$$  ____/ \\_____$$ |\\______|$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|          \\____$$\\ $$ |  $$ |$$ |   \\$$\\$$  / $$  __|   $$  __$$< \n");
    fprintf(file, "$$ |            $$ |        $$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |            $$\\   $$ |$$ |  $$ |$$ |    \\$$$  /  $$ |      $$ |  $$ | \n");
    fprintf(file, "$$$$$$$$\\       $$ |        \\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\       \\$$$$$$  | $$$$$$  |$$$$$$$$\\\\$  /   $$$$$$$$\\ $$ |  $$ | \n");
    fprintf(file, "\\________|      \\__|         \\______/ \\__|  \\__|\\__|     \\__|\\________|       \\______/  \\______/ \\________|\\_/    \\________|\\__|  \\__| \n");
    fprintf(file, "\n");
    
    for (i = 0; i < 4; i++) {
        fprintf(file, "Kartu ke-%d: ", i+1);
        print_from_num2(inputs[i], file);
    }
    
    fprintf(file, "\n%d solusi ditemukan!\n", num_of_solution);
    
    for (i = 0; i <= ROW_EFFC(m)-1; i++) {
        if (ELMTC(m, i, 0) != '\0') {
            for (j = 0; j <= COL_EFFC(m)-1; j++) {
                if (ELMTC(m, i, j) == '\0') {
                    fprintf(file, "\n");
                    break;
                } else if (j == COL_EFFC(m)-1) {
                    fprintf(file, "%c\n", ELMTC(m, i, j));
                } else {
                    fprintf(file, "%c", ELMTC(m, i, j));
                }
            }
        }
    }
    
    fprintf(file, "\nWaktu eksekusi: %.5f detik", execution_time);
    fclose(file);
}
