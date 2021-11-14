/* File: player.h */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../boolean.h"
#include "../map/map.h"
#include "../buff/buff.h"
#include "../state/state.h"
#include "../skill/skill.h"


typedef int Giliran;
typedef struct PlayerStat* Status;
typedef struct PlayerStat {
	Giliran info;
	Skill skillset;
	Buff buffset;
	Petak posisi;
	Status next;
} Stat;
typedef struct {
	Status first;
} Player;

/* Urutan giliran bermain ditentukan dari P1 - P2 - (P3 - P4)
   Player menggunakan representasi list berkait (Linked list)
   First(Player) -> Status -> Stat Player */

#define Skillset(S) (S)->skillset
#define Buffset(S) (S)->buffset
#define Posisi(S) (S)->posisi
#define Info(S) (S)->info
#define Next(S) (S)->next
#define First(P) (P)->first

/* Contoh reverse-access pada map.h: Info(Address) = Posisi(Player) */
/* Contoh mengambil teleporter: Info(Address) = Posisi(Status) -> Teleport(Address) != Nil */


/* =======================| Manajemen Memori  |================================== */

Status AllocPlayer(Giliran X);
/* Info(P1) = 1,
   Posisi(P1) = (import ADT Map),
   Skillset(P1) = (random),
   Buff(P1) = ... ,
   Next(P1) = Nil */
/* Mengirimkan Nil jika alokasi gagal */

void DeallocPlayer(Status S);
/* Player berstatus S didealokasikan */

/* =======================|   Opening Game   |=================================== */

void CreatePlayer(Player *P);
/* Mendaftarkan pemain baru ke dalam game. */
/* Pemain baru adalah pemain dengan posisi berada di awal,
   memiliki 1 skill yang diacak (random), buff, dan lawan
   yang Nil */
/* First(P) = Nil */

boolean IsNoPlayer(Player P);
/* Mengembalikan True jika tidak ada pemain dalam game */
/* Tidak ada pemain yang bermain ditandai dengan Data(P) = Nil */

/* =======================| Konfigurasi State |================================== */

void AddPlayer(Player *P, Giliran X);
/* Jika belum ada pemain, Pemain 1 ditambahkan sehingga First(P) = P1 */
/* Info(P1) = 1, Posisi(P1) = Start(M), Skillset(P1) = (random),
   Buff(P1) = ... , Next(P1) = Nil
   Misal: X = 1 sehingga menambahkan Player 1 */
/* Jika sudah ada pemain, maka Next(First(P1)) = P2 */
/* Setiap pemain yang ditambahkan pasti dialokasikan terlebih dahulu */
/* AddPlayer ~ InsVLast */

void DelPlayer(Player *P, Giliran X);
/* Player dengan Info(P) = X dihapus dan status didealokasi */
/* Dapat digunakan ketika seorang player telah selesai atau di-report :D */
/* DelPlayer ~ DelP */

/* =======================|   Akses Player    |================================== */

Status GetStat(Player P, Giliran X);
/* Mengembalikan status player dengan giliran X */

void Move(Player *P, Petak X);
/* Mengubah posisi player (jika bisa) ke petak X */
/* Dapat digunakan untuk berpindah karena teleport atau roll dadu
   Asumsi: Petak merupakan bagian dari ADT Map yang berbentuk list dua pointer */

void UseSkill(Player *P);
/* Player menggunakan skill */
/* Skill yang digunakan akan dihapus dari skillset */

boolean IsGetTeleport(Map M, Player P);
/* Mengembalikan True jika petak dengan Info(Address) = Posisi(Status)
   merupakan teleporter: Teleport(Address) != Nil */

void LoadPLayer(Player *P, Player Dp);
/* Player P menjadi Player Dp, Dp berasal dari State yang diload (pop) */
/* Expected: P = Dp, atau CreatePlayer NewP lalu AddPlayer(&NewP, ...)
   NOTE : (...) tergantung pada player di Dp */

#endif