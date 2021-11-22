/* File: command.h */

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../../boolean.h"
#include "../skill/skill.h"
#include "../player/player.h"
#include "../state/state.h"
#include "../map/map.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"

extern int LowerRoll;
extern int UpperRoll;

void SKILL(TabPlayer *Tp, sSkill *ss, int t);
/* Menampilkan skill yang DIMILIKI pemain */
/* Diberi pilihan untuk keluar, membuang, atau memakai skill */

void MAP(Map M, TabPlayer Tp);
/* Menampilkan posisi tiap pemain di peta */
/* Posisi pemain ditandai dengan petak '*' */

int BUFF();
/* Menampilkan daftar buff yang DIMILIKI pemain */

void INSPECT(Map M, ArrayOfTeleporter A);
/* Menampilkan apakah suatu petak itu kosong,
   terlarang, atau memiliki teleporter */

void ROLL(Map M, int t, int p, int lower, int upper, TabPlayer *T, boolean *bMove);
/* Generate random integer dari 1--MaxRoll */
/* Pemain berpindah dengan fungsi Move() */

void ENDTURN(State *S, int X, TabPlayer Tp, Player *P, TabSkill Ts, Skill *s);
/* Mengakhiri turn pemain, turn berpindah ke NextPlayer */
/* Jika LastPlayer sudah ENDTURN, state game disimpan (Push) */

void UNDO(State *S, TabPlayer *Tp, TabSkill *s);
/* Mengembalikan state game ke akhir ronde sebelumnya */
/* Skill yang didapat pemain akan direset */

char * ReadLine();
/* Mengembalikan sebuah string */
/* Expected: IO sebuah command */



#endif