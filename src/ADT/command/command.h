/* File : command.h */

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../../boolean.h"
#include "../skill/skill.h"
#include "../player/player.h"
#include "../state/state.h"
#include "../map/map.h"

extern int Round ;         // = 1;
extern int minval;         // = 1;
extern int maxval;         // = MaxRoll;
extern boolean isEndTurn;  // Apakah player sudah ENDTURN
extern boolean isNotRoll;  // Apakah player belum ROLL
extern boolean immuneTel;  // Apakah sudah mengaktifkan # Imunitas Teleport #

void SKILL (TabPlayer *Tp, TabSkill *Ts, Map M, Player *P, Skill *s, sPlayer *sp, sSkill *ss, int X, boolean *isPlaying);
/* Menampilkan skillyang DIMILIKI pemain dengan Turn(P) = X */
/* Pemain dapat memilih untuk keluar, membuang, atau menggunakan skill */

void MAP (Map M, TabPlayer Tp);
/* Menampilkan Position(P) tiap pemain */

void BUFF();
/* Menampilkan buff yang DIMILIKI pemain */

void INSPECT (Map M, ArrayOfTeleporter AoT);
/* Menampilkan apakah petak kosong, terlarang, atau berteleporter */

void ROLL (Map M, ArrayOfTeleporter AoT, Player *P, sPlayer *sp, int X);
/* F.S. Posisi pemain berpindah sejauh angka yang didapat */
/* Pemain dapat memilih untuk mundur ataupun maju */
/* Pemain tidak bisa berpindah ke petak terlarang (#) */

void ENDTURN (State *S, TabSkill Ts, TabPlayer Tp, Player *P, Skill *s, sSkill *ss);
/* Menandakan turn pemain telah berakhir dan berganti ke NextPlayer(P) */
/* Apabila pemain terakhir ENDTURN, state ronde akan dipush ke stack S */

void UNDO (State *S, TabPlayer *Tp, TabSkill *Ts, Player *P, Skill *s);
/* Mengembalikan state ke akhir awal ronde, di mana:
   1. Skill tiap pemain diacak ulang
   2. Posisi tiap pemain diulang. */

void SAVE(TabPlayer Tp, TabSkill Ts);
/* Menyimpan file backup_player.txt dan backup_skill.txt */

#endif