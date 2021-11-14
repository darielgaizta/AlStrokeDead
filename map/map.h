/* File: map.h */

#ifndef __MAP_H__
#define __MAP_H__

#include "../boolean.h"
#include "../state/state.h"


typedef int Petak;
typedef struct pos *Address;
typedef struct pos {
	Petak info,
	char inspect;
	Petak teleport;
	Address next;
	Address prev;
} Pos;
typedef struct {
	Address start;
	Address finish;
} Map;

/*
ADT Map menggunakan representasi list dua pointer
Pemain mulai di Start(M) dan dikatakan menang jika posisinya berada di Finish(M)
Definisi untuk map kosong: Start(M) = Nil dan Finish(M) = Nil
Misal		: Petak pertama adalah ., maka Info(P) = 1 dan Inspect(P) = '.'
		  	  Petak kedua adalah #, maka Info(P) = 2 dan Inspect(P) = '#'
*/

#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define Start(M) (M)->start
#define Finish(M) (M)->finish
#define Inspect(P) (P)->inspect
#define Teleport(P) (P)->teleport

/* =======================|   Opening Game   |=================================== */

boolean IsMapEmpty(Map M);
/* Mengembalikan True jika map kosong */

void CreateMap(Map *M);
/* Terbentuk map kosong */

/* =======================| Manajemen Memori  |================================== */

Address AllocMap(Petak X, char I);
/* Alokasi memori untuk petak X:
   Info(P) = X,
   Next(P) = Nil,
   Prev(P) = Nil,
   Inspect(P) = I 
   Teleport(P) = Nil */
/* Mengirimkan Nil jika alokasi gagal */

void DeallocMap(Address P);
/* Dealokasi petak dengan address P */

/* =======================| Konfigurasi State |================================== */

void AddPetak(Map *M, Petak X, char I);
/* Menambahkan Petak X dengan Inspect I ke dalam map */
/* AddPetak ~ InsVLast */

void DelPetak(Map *M, Petak X);
/* Menghapus petak dengan Info(P) = X dari map */
/* DelPetak ~ DelP */

/* =======================|     Akses Map     |================================== */

Address Browse(Map M, Petak X);
/* Mengirimkan address dari petak X */
/* Jika tidak ditemukan, kirim Nil */

void AddTeleport(char *B, Map *M);
/* Membaca konfigurasi bagian teleport baris per baris lalu input semua teleport
   ke petaknya masing-masing di map */
/* Misal: file konfigurasi bertuliskan '3 10' -> AddTeleport("3 10", &M)
   maka, input Teleport(P) = 10 pada P yang memiliki Info(P) = 3 */

void AddInspect(char *B, Map *M);
/* Membaca konfigurasi bagian inspect lalu append tiap petak */
/* Misal: file konfigurasi bertuliskan '..#..#.' -> AddInspect("..#..#.", &M)
	maka, AddPetak(&M, 1, '.'), AddPetak(&M, 2, '.'), AddPetak(&M, 3, '#'), dst.*/

void LoadMap(Map *M, Map Dm);
/* Map M menjadi Map Dm, Dm berasal dari State yang diload (pop) */
/* Expected: mengandung fungsi AddTeleport dan AddInspect, tetapi bisa juga tidak */

#endif