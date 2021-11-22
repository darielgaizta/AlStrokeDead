/* File: state.h */

#ifndef _STATE_H
#define _STATE_H

#include "../../boolean.h"
#include "../skill/skill.h"
#include "../player/player.h"

typedef struct {
	int id;
	TabPlayer players;
	TabSkill skills;
} ElmtStack;

typedef struct tElmtState * address;
typedef struct tElmtState {
	ElmtStack infos;
	address nexts;
} ElmtState;

typedef struct {
	address tops;
} State;

#define StateID(S) (((S)->infos).id)
#define StatePlayer(S) (((S)->infos).players)
#define StateSkill(S) (((S)->infos).skills)
#define ID(E) ((E).id)
#define Player(E) ((E).players)
#define SkillS(E) ((E).skills)
#define InfoState(S) (S)->infos
#define NextState(S) (S)->nexts
#define Top(S) ((S).tops)

/* Prototype manajemen memori */
void AlokasiState (address *addr, int X, TabPlayer P, TabSkill S);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */

void DealokasiState (address P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyState (State S);
/* Mengirim true jika State kosong: TOP(S) = Nil */

void CreateEmptyState (State * S);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */

void Push (State * S, int X, TabPlayer P, TabSkill s);
/* Menambahkan X sebagai elemen State S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */

void Pop (State * S, ElmtStack *E);
/* Menghapus X dari State S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif