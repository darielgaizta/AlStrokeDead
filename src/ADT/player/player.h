/* File: player.h */
/* ADT Player mengimplementasikan ADT List Linier */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../boolean.h"

extern int JML_PEMAIN;

typedef struct {
    char *  name; 
    int position; 
} sPlayer;

typedef struct tTabPlayer * Player;
typedef struct tTabPlayer { 
	int turn;
	sPlayer data;
	Player nextp;
} GetPlayer;
typedef struct {
	Player firstp;
	Player  lastp;
} TabPlayer; 

#define Turn(P) (P)->turn
#define DataPlayer(P) (P)->data
#define NextPlayer(P) (P)->nextp
#define FirstPlayer(T) ((T).firstp)
#define LastPlayer(T) ((T).lastp)

/* Akses data pemain */
#define Name(S) (S).name
#define Position(S) (S).position

/* =======================|   Opening Game   |=================================== */

boolean IsEmptyPlayer (TabPlayer T);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyPlayer (TabPlayer *T);
/* I.S. T sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/* =======================| Manajemen Memori  |================================== */
Player AlokasiPlayer (int X, char * nama);
/* Mengirimkan Player hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Player tidak nil. */
/* Jika alokasi gagal, mengirimkan Nil. */

void DealokasiPlayer (Player P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Player P */

/* =======================|    Akses Player    |================================== */
Player SearchPlayer (TabPlayer T, int X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan Player elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

Player SearchPosition (TabPlayer T, int X);
/* Mencari player yang berada di posisi X di peta */

sPlayer AddData (char * nama);
/* Mengembalikan data player dengan Name(P) = nama
   dan Position(P) = p */

void AddPlayer (TabPlayer *T, int X, char * nama);
/* I.S. T mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void Move (Player *P, int t, int p);
/* Mengubah Position(P) dengan Turn(P)=t menjadi p */

/* =======================|   Insert Element   |================================== */

void InsertFirstPlayer (TabPlayer *T, Player P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen dengan Player P sebagai elemen pertama */

void InsertLastPlayer (TabPlayer *T, Player P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/* =======================|   Delete Element   |================================== */
void DelFirstPlayer (TabPlayer *T, Player *P);
/* I.S. TabPlayer tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLastPlayer (TabPlayer *T, Player *P);
/* I.S. TabPlayer tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

void RemovePlayer (TabPlayer *T, int X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list Player P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* TabPlayer mungkin menjadi kosong karena penghapusan */

/* =======================|   Output Element   |================================== */
void ShowPlayer (TabPlayer T);
/* I.S. TabPlayer mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void WriteBackupDataPlayer(TabPlayer Tp);
/* Menyimpan data pemain: Name & Position */
/* Data disimpan ke dalam backup_player.txt */

void LoadPlayer(TabPlayer *Tp);
/* Membaca backup_player.txt dan load semua data */

#endif