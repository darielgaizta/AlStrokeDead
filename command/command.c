/* File: command.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "command.h"


void SKILL(Status S) {
	/* Asumsi: command = SKILL */
	SkElmt E = First(Skillset(S));
	int jml_skill = NbElmt(Skillset(S));
	int counter;

	printf("Daftar SKILL %s:\n", Nama(S));
	for (counter = 0; counter < jml_skill; counter++) {
		printf("[%d] %s\n", (counter+1), Type(E));
		E = Next(E);
	} // Expected: 1. Senter Pembesar Hoki

	int choose_skill;
	printf("NOTE: Masukkan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
	printf("Pilih skill: ");
	scanf("%d", &choose_skill);

	if (choose_skill > 0) {
		/* use skill & proses */
	} else if (choose_skill < 0) {
		/* delete skill */
	} else {
		/* keluar */
	}
}

void MAP(Player P, Map M) {
	/* Asumsi: command = MAP */
	Status S = First(P);
	char *RoadMap = GetMap(M);
	while (S != Nil) {
		RoadMap[Posisi(S)] = '*';
		printf("%s\n", RoadMap);
		S = Next(S);
		RoadMap = GetMap(M);
	}
}

void BUFF(Player P) {
	/* Apa maksudnya BUFF? */
}

void ROLL(Player *P) {
	/* int d = Roll(); */
	/* Cek apakah player bisa bergerak sejauh d */
	/* Cek apakah ketemu teleport */
	/* Cek apakah punya BUFF */
	/* Putuskan apakah player akan teleport atau tidak */
}

void ENDTURN(State *S, Player *P) {
	/* Apa maksudnya ENDTURN? */
	/* Bagaimana skema jalannya permainan? */
}

void UNDO(State *S) {
	/* Apa yang di-UNDO? */
}


char * ReadCommand() {
	static char c[10];
    fgets(c, sizeof(c), stdin);
    return c;
}
