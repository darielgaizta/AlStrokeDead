/* File: skill.h */
/* ADT Skill mengimplementasikan ADT List linier */

#ifndef __SKILL_H__
#define __SKILL_H__

#include "../boolean.h"

typedef char * SkType;
typedef struct skset * SkElmt;
typedef struct skset {
	SkType type;
	SkElmt next;
} SkSet;

typedef struct {
	SkElmt first;
} Skill;

/* Type(E) bertipe string, contoh: "Senter Pembesar Hoki" */

#define Type(E) (E)->type
#define Next(E) (E)->next
#define First(S) (S)->first

/* =======================|   Opening Game   |=================================== */

void CreateSkill(Skill *S);
/* Membentuk Skill kosong */
/* Skill kosong: First(S) = Nil*/

boolean IsSkillEmpty(Skill S);
/* True jika skill kosong */

/* =======================| Manajemen Memori  |================================== */

SkElmt Alokasi (SkType T);
/* Mengirimkan SkElmt hasil alokasi dari SkType */
/* Jika alokasi berhasil, Type(E) = T, Next(E) = Nil*/
/* Jika alokasi gagal, kirim Nil */

void Dealokasi (SkElmt *E);
/* free(E) */

/* =======================|    Akses Skill    |================================== */

int NbElmt (Skill S);
/* Mengembalikan banyaknya skill, 0 jika skill kosong */

SkElmt SearchSkill (Skill S, SkType T);
/* Mengembalikan salah satu elemen skill, Nil jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Skill *L, SkType X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (Skill *L, SkType X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (Skill *L, SkType *X);
/* I.S. Skill L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (Skill *L, SkType *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (Skill *L, SkElmt P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (Skill *L, SkElmt P, SkElmt Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (Skill *L, SkElmt P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (Skill *L, SkElmt *P);
/* I.S. Skill tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (Skill *L, SkType X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* Skill mungkin menjadi kosong karena penghapusan */
void DelLast (Skill *L, SkElmt *P);
/* I.S. Skill tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (Skill *L, SkElmt *Pdel, SkElmt Prec);
/* I.S. Skill tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

#endif