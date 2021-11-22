/* File: map.h */

#ifndef _MAP_H
#define _MAP_H

#include "../../boolean.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"


extern int MaxRoll;

typedef struct {
	int in;
	int out;
} Teleporter;

typedef struct {
	Teleporter T[88];
	int NEff;
} ArrayOfTeleporter;

typedef struct {
	char P[100];
	int NEff;
} Map;

#define NEff(M) (M).NEff
#define Path(M) (M).P
#define Petak(M,i) (M).P[(i)]
#define TelIn(A,i) (A).T[(i)].in
#define TelOut(A,i) (A).T[(i)].out


void LoadMap(Map *M, ArrayOfTeleporter *AoT);
/* Membaca bentuk peta tiap petak dari konfigurasi.txt */
/* Load teleporter dari konfigurasi.txt */
/* NEff(M)= <CKata pertama yang diakuisi> dalam int */

void Config();
/* Menuliskan konfigurasi.txt berdasarkan format yang disediakan */

#endif