/* mesinkar.c */
/* Membaca tiap karakter yang ada di file. Pembacaan akan berhenti bila ketemu MARK */
/* Expected: Setiap file yang dibaca pasti memiliki MARK! */

#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"
#include "../../boolean.h"


char CC;
boolean EOP;
FILE * Pita;


void START(char* filename) {
	// Mulai membaca file 'filename'
	Pita = fopen(filename, "r");
	ADV();
}

void ADV() {
	// Mengambil 1 karakter dari Pita dan assign ke CC
	fscanf(Pita, "%c", &CC);
	EOP = (CC == MARK);
	if (EOP) {
		fclose(Pita);
	}
}