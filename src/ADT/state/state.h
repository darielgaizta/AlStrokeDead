/* File: state.h */

#ifndef __STATE_H__
#define __STATE_H__

#include "../../boolean.h"
#include "../player/player.h"
#include "../skill/skill.h"

typedef struct
{
	TabPlayer Tp[100];
	TabSkill Ts[100];
	int TOP;
} State;

#define Top(S) (S).TOP
#define StatePlayer(S) (S).Tp[(S).TOP]
#define StateSkill(S) (S).Ts[(S).TOP]


void CreateEmptyState (State *S);
/* Membuat State kosong berkapasitas 100 */

boolean IsEmptyState (State S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullState (State S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke State ************ */
void Push (State * S, TabPlayer Tp, TabSkill Ts);
/* Menambahkan X sebagai elemen State S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen State ************ */
void Pop (State * S, TabPlayer* Tp, TabSkill* Ts);
/* Menghapus X dari State S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif