/* File: map.c */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int MaxRoll;

void LoadMap(Map *M, ArrayOfTeleporter *AoT)
/* Membaca bentuk peta tiap petak dari config.txt */
/* NEff(M)= <CKata pertama yang diakuisi> dalam int */
{
	int i, counter, val;
	/* Panjang peta */
	i = 0;
	counter = 0;
	char MapLength[3];
	START("../data/config.txt");
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
/* Menuliskan config.txt berdasarkan format yang disediakan */
{
	printf("Set The Game's Configuration!\n");
	printf("(check our documentation for configuration format)\n");
	
	FILE * F;
	char c[100];
	int i, in;

	F = fopen("../data/config.txt", "w");
	getchar();

	for (i = 0; i < 4; i++) {
		fgets(c, sizeof(c), stdin);
		fputs(c, F);
		in = atoi(c);
	}

	for (i = 0; i < in; i++) {
		fgets(c, sizeof(c), stdin);
		fputs(c, F);	
	}

	fputs("~", F);

	fclose(F);
}

void WriteBackupDataConfig()
/* Copy-paste config.txt ke backup_config.txt */
{
	FILE *f1;
	FILE *f2;
	char buffer[100];

	f1 = fopen("../data/config.txt", "r");
	f2 = fopen("../data/backup_config.txt", "w");

	if (f1 != Nil)
	{
		while (fgets(buffer, sizeof(buffer), f1))
		{
			fputs(buffer, f2);
		}
	}

	fclose(f1);
	fclose(f2);
}

void LoadConfig()
/* Load backup_config.txt ke config.txt */
{
	FILE *f1;
	FILE *f2;
	char buffer[100];

	f2 = fopen("../data/config.txt", "w");
	f1 = fopen("../data/backup_config.txt", "r");

	if (f1 != Nil)
	{
		while (fgets(buffer, sizeof(buffer), f1))
		{
			fputs(buffer, f2);
		}
	}
	else
	{
		printf("Failed to load configuration.\n");
	}

	fclose(f1);
	fclose(f2);
}