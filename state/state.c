/* File: state.c */

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

/* =======================| Manajemen Memori  |================================== */
void AlokasiState (address *addr, int X, TabPlayer P, TabSkill S)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka StateID(S)=X, 
        dan StatePlayer(S)=P  */
/*      P=Nil jika alokasi gagal */
{
	*addr = (ElmtState*) malloc(sizeof(ElmtState));
	if(*addr != Nil){
		StateID(*addr) = X;
		StatePlayer(*addr) = P;
		StateSkill(*addr) = S;
		NextState(*addr) = Nil;
	}
}

void DealokasiState (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}

/* =======================| Prototype Stacks  |================================== */

boolean IsEmptyState (State S)
/* Mengirim true jika State kosong: TOP(S) = Nil */
{
	return (Top(S) == Nil);
}

void CreateEmptyState (State * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{
	Top(*S) = Nil;
}

void Push (State * S, int X, TabPlayer P, TabSkill s)
/* Menambahkan X sebagai elemen State S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
	address addrState;
	AlokasiState(&addrState, X, P, s);
	if (addrState != Nil) {
		NextState(addrState) = Top(*S);
		Top(*S) = addrState;
	}
}

void Pop (State * S, ElmtStack *E)
/* Menghapus X dari State S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
	address P;
	*E = InfoState(Top(*S));
	P = Top(*S);
	Top(*S) = NextState(Top(*S));
	NextState(P) = Nil;
	DealokasiState(P);
}