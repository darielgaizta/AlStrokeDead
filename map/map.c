/* File: map.c */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int MaxRoll;

void LoadMap(Map *M, ArrayOfTeleporter *AoT)
/* Membaca bentuk peta tiap petak dari konfigurasi.txt */
/* NEff(M)= <CKata pertama yang diakuisi> dalam int */
{
	int i, counter, val;
	/* Panjang peta */
	i = 0;
	counter = 0;
	char MapLength[3];
	START("konfigurasi.txt");
	IgnoreBlank();
	while (CC != BLANK && CC !='\n') {
		MapLength[i] = CC;
		counter++;
		ADV();
		i++;
	}
	if (counter == 1) {
		val = (int) MapLength[0];
	} else {
		val = atoi(MapLength);
	}
	NEff(*M) = val;
	IgnoreBlank();

	/* Petak peta */
	i = 0;
	while (CC != BLANK && CC !='\n') {
		Petak(*M,i) = CC;
		ADV();
		i++;
	}
	IgnoreBlank();

	/* MaxRoll */
	i = 0;
	char RollLimit[3];
	while (CC != BLANK && CC !='\n'){
		RollLimit[i] = CC;
		ADV();
		i++;
	}	
	MaxRoll = atoi(RollLimit);
	IgnoreBlank();

	/* Banyaknya Teleporter */
	i = 0;
	char TeleLength[3];
	while (CC != BLANK && CC !='\n') {
		TeleLength[i] = CC;
		ADV();
		i++;
	}
	NEff(*AoT) = atoi(TeleLength);
	IgnoreBlank();

	/* Teleporter */
	int j;
	char in[3];
	char out[3];
	for (i = 0; i < NEff(*AoT); i++) {
		j = 0;
		while (CC != BLANK && CC !='\n') {
			in[j] = CC;
			ADV();
			j++;
		}
		TelIn(*AoT,i) = atoi(in);
		IgnoreBlank();
		in[1] = '\0' ;

		j = 0;
		while (CC != BLANK && CC !='\n') {
			out[j] = CC;
			ADV();
			j++;
		}
		TelOut(*AoT,i) = atoi(out);
		IgnoreBlank();
		out[1] = '\0';
	}

}

void Config()
/* Menuliskan konfigurasi.txt berdasarkan format yang disediakan */
{
	FILE * F;
	char c[100];
	int i;

	F = fopen("konfigurasi.txt", "w");
	
	for (i = 0; i < 4; i++) {
		fgets(c, sizeof(c), stdin);
		fputs(c, F);
	}

	for (i = 0; i < atoi(c); i++) {
		fgets(c, sizeof(c), stdin);
		fputs(c, F);	
	}

	fputs("~", F);

	fclose(F);
}