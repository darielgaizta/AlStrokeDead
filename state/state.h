/* File: state.h */
/* ADT State menyimpan state permainan, seperti:
   1. Status player	: State Player, menyimpan player ~ menyimpan listlinier
   2. Address map 	: State Map. menyimpan map ~ menyimpan listdp
   3. Konfigurasi	: Copy konfigurasi */
/* Konfigurasi dicopy untuk untuk menjaga jika sewaktu-waktu ingin diload */
/* ADT State menggunakan ADT Stack dengan representasi list berkait */

#ifndef __STATE_H__
#define __STATE_H__

#include "../boolean.h"
#include "../player/player.h"
#include "../map/map.h"


typedef struct data * PData;
typedef struct data {
	Player dplayer;
	Map dmap;
	const char *filename;
	PData next;
} Data;

typedef struct {
	PData latest;
} State;

/* Latest(State) ~ TOP(Stack) mengambil state terbaru dan diload */
/* Asumsi: ADT State membaca file konfigurasi (filename) lalu load semua
   data yang tersimpan pada file tersebut */
/* Contoh file konfigurasi: FileConfig(S) = "Konfigurasi.txt" */
/* State kosong: Latest(S) = Nil */

#define DPlayer(P) (P)->dplayer
#define DMap(P) (P)->dmap
#define FileConfig(P) (P)->filename
#define Latest(S) (S)->latest
#define Next(P) (P)->next


void AllocState(PData *PD, Player P, Map M, const char *filename);
/* PData PD dialokasikan dengan DPlayer(PD) = P, DMap(PD) = M,
   FileConfig(PD) = filename */
/* PD = Nil jika alokasi gagal */

void DeallocState(PData P);
/* Dealokasi PData */

boolean isStateEmpty(State S);
/* Mengirimkan True jika state kosong */

void CreateState(State *S);
/* Membuat state kosong */

void PushState(State *S, Player P, Map M, const char *filename);
/* Push data ke stack State dengan DPlayer(...) = P, DMap(...) = M
   FileConfig("...") = filename */

void PopState(State *S);
/* Latest(...) didealokasikan */
/* PopState ~ DelFirst */

#endif