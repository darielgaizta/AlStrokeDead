/* File: player.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

int JML_PEMAIN = 0;

/* =======================|  Inisiasi Game   |=================================== */

boolean IsEmptyPlayer (TabPlayer T)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (FirstPlayer(T) == Nil && LastPlayer(T) == Nil);
}

void CreateEmptyPlayer (TabPlayer *T)
/* I.S. T sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	FirstPlayer(*T)= Nil;
    LastPlayer(*T) = Nil;
}

/* =======================| Manajemen Memori  |================================== */

Player AlokasiPlayer (int X, char * nama)
/* Mengirimkan Player hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Player tidak nil. */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	Player P = (GetPlayer*) malloc (sizeof(GetPlayer));
	if (P != Nil) {
		Turn(P) = X;
		NextPlayer(P) = Nil;
		DataPlayer(P) = AddData(nama);
		return P;
	} else {
		return Nil;
	}
}

void DealokasiPlayer (Player P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Player P */
{
	free(P);
}

/* =======================|    Akses Player    |================================== */

Player SearchPlayer (TabPlayer T, int X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan Player elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmptyPlayer(T)) {
		return Nil;
	} else {
		Player P = FirstPlayer(T);
		while ((Turn(P) != X) && (P != Nil)) {
			P = NextPlayer(P);
		}
		return P;
	}
}

Player SearchPosition (TabPlayer T, int X)
/* Mencari apakah ada elemen list dengan Position(P)=X */
/* Jika ada, mengirimkan Player elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmptyPlayer(T)) {
		return Nil;
	} else {
		Player P = FirstPlayer(T);
		while ((Position(DataPlayer(P))) != X && (P != Nil)) {
			P = NextPlayer(P);
		}
		return P;
	}
}

sPlayer AddData (char * nama)
/* Mengembalikan data player dengan Name(P) = nama
   dan Position(P) = p */
{
	sPlayer sp;
	Name(sp) = nama;
	Position(sp) = 1;
	return sp;
}

void AddPlayer (TabPlayer *T, int X, char * nama)
/* I.S. T mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	Player P = AlokasiPlayer(X, nama);
	if (P != Nil) {
		InsertLastPlayer(T, P);
		printf("Player successfully added.\n");
		JML_PEMAIN++;
	} else {
		printf("Failed to add player.\n");
	}
}

void Move (Player *P, int t, int p)
/* Mengubah Position(P) dengan Turn(P)=t menjadi p */
{
	printf("Player %d berpindah ke Petak %d\n", t, p);
	
	Position(DataPlayer(*P)) = p;
}

/* =======================|   Insert Element   |================================== */

void InsertFirstPlayer (TabPlayer *T, Player P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen dengan Player P sebagai elemen pertama */
{
	if (IsEmptyPlayer(*T)) {
		FirstPlayer(*T) = P;
		LastPlayer(*T) = P;
		NextPlayer(P) = Nil;
	} else {
		NextPlayer(P) = FirstPlayer(*T);
		FirstPlayer(*T) = P;
	}
}

void InsertLastPlayer (TabPlayer *T, Player P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyPlayer(*T)) {
		InsertFirstPlayer(T, P);
	} else {
		NextPlayer(LastPlayer(*T)) = P;
        LastPlayer(*T) = P;
	}
}

/* =======================|   Delete Element   |================================== */
void DelFirstPlayer (TabPlayer *T, Player *P)
/* I.S. TabPlayer tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = FirstPlayer(*T);
	FirstPlayer(*T) = NextPlayer(*P);
}

void DelLastPlayer (TabPlayer *T, Player *P)
/* I.S. TabPlayer tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = LastPlayer(*T);
	Player Prec = FirstPlayer(*T);
	while (NextPlayer(Prec) != LastPlayer(*T)) {
		Prec = NextPlayer(Prec);
	}
	LastPlayer(*T) = Prec;
	NextPlayer(Prec) = Nil;
}

void RemovePlayer (TabPlayer *T, int X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list Player P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* TabPlayer mungkin menjadi kosong karena penghapusan */
{
	Player P = SearchPlayer(*T, X);
	if (P != Nil) {
		if ((P == FirstPlayer(*T)) && (P == LastPlayer(*T))) {
			CreateEmptyPlayer(T);
		} else if (P == FirstPlayer(*T)){
			DelFirstPlayer(T, &P);
		} else if ( P == LastPlayer(*T)) {
			DelLastPlayer(T, &P);
		} else {
			Player Prec = FirstPlayer(*T);
			while (NextPlayer(Prec) != P) {
				Prec = NextPlayer(Prec);
			}
			NextPlayer(Prec) = NextPlayer(P);
		}
		DealokasiPlayer(P);
		JML_PEMAIN--;
		printf("Player successfully removed.\n");
	}
}

/* =======================|   Output Element   |================================== */
void ShowPlayer (TabPlayer T)
/* I.S. TabPlayer mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	Player P; 
    P = FirstPlayer(T);
    printf("\nDaftar pemain\t: ");
    printf("[");
    if (!IsEmptyPlayer(T)) {
        printf("%s", Name(DataPlayer(P)));
        P = NextPlayer(P);
        while (P != Nil) {
            printf(", %s", Name(DataPlayer(P)));
            P = NextPlayer(P);
        }
    }
    printf("]\n");
    printf("Jumlah pemain\t: %d\n", JML_PEMAIN);
}

void WriteBackupDataPlayer(TabPlayer Tp)
/* Menyimpan data pemain: Name & Position */
/* Data disimpan ke dalam backup_player.txt */
{
	FILE *F;
	char pos[3];

	F = fopen("../data/backup_player.txt", "w");

	Player P = FirstPlayer(Tp);
	sPlayer sp;

	while (P != Nil)
	{
		sp = DataPlayer(P);
		
		if (strcmp(Name(sp), "Mobita-kun") == 0)
		{
			fputs("1", F);
		}
		else if (strcmp(Name(sp), "Emon-san") == 0)
		{
			fputs("2", F);
		}
		else if (strcmp(Name(sp), "Jayen-sama") == 0)
		{
			fputs("3", F);
		}
		else if (strcmp(Name(sp), "Suzuka-chan") == 0)
		{
			fputs("4", F);
		}
		else if (strcmp(Name(sp), "Shizuneo-senpai") == 0)
		{
			fputs("5", F);
		}
		fputs("\n", F);
		sprintf(pos, "%d", Position(sp));
		fputs(pos, F);
		fputs("\n", F);
		P = NextPlayer(P);
	}
	
	fclose(F);
}

void LoadPlayer(TabPlayer *Tp)
/* Membaca backup_player.txt dan load semua data */
{
	FILE *F;
	char buffer[10];
	int counter = 1;
	int i = 0;

	F = fopen("../data/backup_player.txt", "r");

	if (F != Nil)
	{
		while (fgets(buffer, sizeof(buffer), F))
		{
			if ((counter % 2) != 0)
			{
				if (atoi(buffer) == 1)
				{
					AddPlayer(Tp, (i+1), "Mobita-kun");
				}
				else if (atoi(buffer) == 2)
				{
					AddPlayer(Tp, (i+1), "Emon-san");
				}
				else if (atoi(buffer) == 3)
				{
					AddPlayer(Tp, (i+1), "Jayen-sama");
				}
				else if (atoi(buffer) == 4)
				{
					AddPlayer(Tp, (i+1), "Suzuka-chan");
				}
				else if (atoi(buffer) == 5)
				{
					AddPlayer(Tp, (i+1), "Shizuneo-senpai");
				}
				i++;
			}
			else
			{
				Position(DataPlayer(LastPlayer(*Tp))) = atoi(buffer);
			}
			counter++;
		}
	}
	else
	{
		printf("Failed to load player's data.\n");
	}

	fclose(F);
}