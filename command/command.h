/* File: command.h */

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../boolean.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../player/player.h"
#include "../state/state.h"
#include "../skill/skill.h"
#include "../buff/buff.h"
#include "../map/map.h"


void SKILL(Player P);
/* Menampilkan daftar skill */
/* Player dapat memilih apakah ingin keluar, menggunakan, atau 
   membuang skill yang dimilikinya*/

void MAP(Player P);
/* Untuk setiap posisi player, assign petak pada map menjadi '*' */

void BUFF(Player P);

void INSPECT(Map M);

void ROLL(Player *P);

void SAVE(State *S, Player P, Map M, char *FileConfig);

void ENDTURN(State *S, Player *P);
/* S&K: Hanya boleh dilakukan ketika selesai ROLL dan
   tidak boleh dipanggil oleh pemain dengan nomor urut terakhir */

void UNDO(State *S);
/* Tunggu FAQ */

/* =======================|   Akses Command   |================================== */

char * ReadCommand();
/* Meminta input berupa command dari user dan mengembalikan
   command tersebut dalam bentuk string */
/* Asumsi: command tidak lebih dari 10 karakter */


#endif