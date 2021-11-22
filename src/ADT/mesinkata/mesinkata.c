/* mesinkata.c */
/* Mengakses tiap kata di FILE * Pita */
/* CKata berisi kata pada tiap baris */

#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "../../boolean.h"
#include "../mesinkar/mesinkar.h"


boolean EndKata;
Kata CKata;


void IgnoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
	while ((CC == BLANK || CC == '\n') && CC != MARK) {
		ADV(); // Read next character
	}
}

void STARTKATA(char* filename) {
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	EndKata = FALSE;
	START(filename);
	if (CC != MARK) {
		IgnoreBlank();
		SalinKata();
	} else {
		printf("File kosong.\n");
		EndKata = TRUE;
	}
}

void ADVKATA() {
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	IgnoreBlank();
	if (CC != MARK) {
		SalinKata();
	} else {
		EndKata = TRUE;
	}
}

void SalinKata() {
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int i = 0;
	while (CC != BLANK && i <= 50 && CC != MARK) {
		CKata.TabKata[i] = CC;
		i++;
		ADV();
	} // CKata berisi kata
	CKata.Length = i-1;
}

void printKata(Kata kata){
	int i;
	for (i = 0; i <= kata.Length; i++) {
  		printf("%c", kata.TabKata[i]);
	}
	if (!EOP) {
		printf(" ");
	} else {
		printf("\n");
	}
}