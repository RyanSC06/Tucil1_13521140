#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "execute.h"


int main() {
    /* KAMUS */
    Matrix num_combo, op_combo;
    MatrixC valid_combo;
    char w[2], x[2], y[2], z[2];
    boolean valid_input = 0, go = 0;
    int question, lower, upper, file_question;
    int random1, random2, random3, random4;
    int inputs[4], num, op, num_of_solution;
    clock_t start, end;
    double execution_time;
    
    /* ALGORITMA */
    /* Inisialisasi */
    num_of_solution = 0;
    createMatrix(24, 4, &num_combo);
    createMatrix(64, 3, &op_combo);
    createMatrixC(150, 15, &valid_combo);
    
    for (int i = 0; i < 4; i++) {
        inputs[i] = 0;
    }
    
    
	/* Tampilan pembuka */
	printf("\n");
    printf(" $$$$$$\\  $$\\   $$\\          $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\        $$$$$$\\   $$$$$$\\  $$\\   $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\ \n");
    printf("$$  __$$\\ $$ |  $$ |        $$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|      $$  __$$\\ $$  __$$\\ $$ |  $$ |   $$ |$$  _____|$$  __$$\\ \n");
    printf("\\__/  $$ |$$ |  $$ |        $$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |            $$ /  \\__|$$ /  $$ |$$ |  $$ |   $$ |$$ |      $$ |  $$ | \n");
    printf(" $$$$$$  |$$$$$$$$ |$$$$$$\\ $$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\          \\$$$$$$\\  $$ |  $$ |$$ |  \\$$\\  $$  |$$$$$\\    $$$$$$$  | \n");
    printf("$$  ____/ \\_____$$ |\\______|$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|          \\____$$\\ $$ |  $$ |$$ |   \\$$\\$$  / $$  __|   $$  __$$< \n");
    printf("$$ |            $$ |        $$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |            $$\\   $$ |$$ |  $$ |$$ |    \\$$$  /  $$ |      $$ |  $$ | \n");
    printf("$$$$$$$$\\       $$ |        \\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\       \\$$$$$$  | $$$$$$  |$$$$$$$$\\\\$  /   $$$$$$$$\\ $$ |  $$ | \n");
    printf("\\________|      \\__|         \\______/ \\__|  \\__|\\__|     \\__|\\________|       \\______/  \\______/ \\________|\\_/    \\________|\\__|  \\__| \n");
                                                                                                                                      
	printf("           _____\n");
    printf("          |A .  | _____\n");
    printf("          | /.\\ ||A ^  | _____\n");
    printf("          |(_._)|| / \\ ||A _  | _____                                                               by: Ryan Samuel Chandra (13521140)\n");
    printf("          |  |  || \\ / || ( ) ||A_ _ |\n");
    printf("          |____V||  .  ||(_'_)||( v )|\n");
    printf("                 |____V||  |  || \\ / |\n");
    printf("                        |____V||  .  |\n");
    printf("                               |____V|\n\n");

	
	/* Meminta atau mengacak masukan */
	printf("Apakah Anda ingin memasukkan angka sendiri? (Ketik '0'/'1'): ");
	scanf("%d", &question);
	while (go == 0) {
    	if (question == 1) {
        	while (valid_input == 0) {
            	printf("\nMasukkan kartu ke-1: ");
            	scanf("%s", w);
            	printf("Masukkan kartu ke-2: ");
            	scanf("%s", x);
            	printf("Masukkan kartu ke-3: ");
            	scanf("%s", y);
            	printf("Masukkan kartu ke-4: ");
            	scanf("%s", z);
            	
            	if (validateInput(w) && validateInput(x) && validateInput(y) && validateInput(z)) {
            	    valid_input = 1;
            	    makeInputs(w, inputs);
        	        makeInputs(x, inputs);
        	        makeInputs(y, inputs);
        	        makeInputs(z, inputs);
        	        go = 1;
            	} else {
            	    printf("\nMasukan Anda tidak valid!");
            	    printf("\nMasukan yang valid: A,2,3,4,5,6,7,8,9,10,J,Q,K\n\n");
            	}
        	}
    	} else if (question == 0) {
    	    lower = 1;
    	    upper = 13;
    	    srand (time(NULL));
    	    random1 = (rand() % (upper - lower + 1)) + lower;
    	    random2 = (rand() % (upper - lower + 1)) + lower;
    	    random3 = (rand() % (upper - lower + 1)) + lower;
    	    random4 = (rand() % (upper - lower + 1)) + lower;
    	    printf("\nKartu ke-1: ");
    	    print_from_num(random1);
    	    printf("\nKartu ke-2: ");
    	    print_from_num(random2);
    	    printf("\nKartu ke-3: ");
    	    print_from_num(random3);
    	    printf("\nKartu ke-4: ");
    	    print_from_num(random4);
    	    printf("\n");
    	    
    	    make_from_random (random1, inputs);
    	    make_from_random (random2, inputs);
    	    make_from_random (random3, inputs);
    	    make_from_random (random4, inputs);
    	    go = 1;
    	} else {
    	    printf("Masukan Anda tidak valid. Masukkan hanya '0' atau '1'!\n");
    	    printf("Apakah Anda ingin memasukkan angka sendiri? (Ketik '0'/'1'): ");
	        scanf("%d", &question);
    	}
	}
    
    
	/* Memulai pencarian solusi */
	start = clock();
	permutation (inputs, 4, 0, &num_combo);
	for (int i = 0; i < 24; i++) {
	    if (isDuplicate(num_combo, i)) {
	        for (int j = 0; j < 4; j++) {
	            ELMT(num_combo, i, j) = 0;
	        }
	    }
	}
	makeOpsCombo(&op_combo);
	
	for (num = 0; num < 24; num++) {
	    for (op = 0; op < 64; op++) {
	        if (ELMT(num_combo, num, 0) != 0) {
                evaluate1 (num_combo, op_combo, &valid_combo, num, op, &num_of_solution);
                evaluate2 (num_combo, op_combo, &valid_combo, num, op, &num_of_solution);
                evaluate3 (num_combo, op_combo, &valid_combo, num, op, &num_of_solution);
                evaluate4 (num_combo, op_combo, &valid_combo, num, op, &num_of_solution);
                evaluate5 (num_combo, op_combo, &valid_combo, num, op, &num_of_solution);
	        }
	    }
	}
	
	end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    
    
    /* Menampilkan solusi */
    printf("\n");
    printf("\n%d solusi ditemukan!\n", num_of_solution);
	displayMatrixC(valid_combo);
	printf("\nWaktu eksekusi: %.5f detik", execution_time);
	printf("\n");
	
	
	/* Mengurus fail */
	go = 0;
	while (go == 0) {
    	printf("\nApakah Anda ingin menyimpan solusi ke dalam fail? (Ketik '0'/'1'): ");
    	scanf("%d", &file_question);
    	if (file_question == 1) {
    	    printToFile (inputs, valid_combo, num_of_solution, execution_time);
    	    printf("\nTerima kasih sudah menggunakan layanan 24-GAME SOLVER :)");
    	    go = 1;
    	} else if (file_question ==  0) {
    	    printf("Terima kasih sudah menggunakan layanan 24-GAME SOLVER :)");
    	    go = 1;
    	} else {
    	    printf("Masukan Anda tidak valid! Masukkan hanya '0' atau '1'!\n");
    	}
	}
	
	return (0);
}