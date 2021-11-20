/* File: command.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "command.h"

int LowerRoll;
int UpperRoll;

void SKILL(TabSkill *Ts, TabPlayer *Tp, int t)
/* Menampilkan skill yang DIMILIKI pemain */
/* Diberi pilihan untuk keluar, membuang, atau memakai skill */
{
    Skill S = First(*Ts);
    while (Info(S) != t) {
        S = Next(S);
    }

    sSkill ss = SkillSet(S);
    ShowSkill(ss);

    int chosen_skill;
    printf("Apa yang ingin Anda lakukan?\n");
    printf("([0] Keluar, [X] Use skill, [-X] Remove skill, [999] Help) >>> ");
    scanf("%d", &chosen_skill);

    if (chosen_skill == 999) {
        printf("\n=======================|       Help       |===================================\n");
        printf("Input: 1\t=> Anda menggunakan skill nomor [1]\n");
        printf("Input: -1\t=> Anda membuang skill nomor [1]\n");
    } else {
        if (chosen_skill < 0) {
            DelSkill(&ss, abs(chosen_skill));
            printf("Anda telah membuang skill [%d].\n", abs(chosen_skill));
        } else if (chosen_skill > 0) {
            DelSkill(&ss, chosen_skill);
            if (strcmp(ElmtSkill(ss, chosen_skill-1), "Pintu Ga Ke Mana Mana") == 0) {
                BUFF_AKTIF = "# Imunitas Teleport #"; // Activate Imunitas Teleport
            } else if (strcmp(ElmtSkill(ss, chosen_skill-1), "Cermin Pengganda") == 0) {
                AddSkill(&ss, GenerateSkill(Info(S)));
                AddSkill(&ss, GenerateSkill(Info(S)));
            } else if (strcmp(ElmtSkill(ss, chosen_skill-1), "Mesin Penukar Posisi") == 0) {
                int p;
                printf("\n#======================[Ms Penukar Posisi]==================================#\n");
                printf("Silakan input ID (Turn) dari pemain yang ingin Anda tukar posisinya dengan Anda!\n");
                printf("Masukkan ID: \n");
                scanf("%d", &p);
                Player P1 = FirstPlayer(*Tp);
                Player P2 = FirstPlayer(*Tp);
                while (Turn(P1) != t) {
                    P1 = NextPlayer(P1);
                }
                while (Turn(P2) != p) {
                    P2 = NextPlayer(P2);
                }
                int pP1 = Position(P1);
                int pP2 = Position(P2);
                Move(Tp, t, pP2);
                Move(Tp, p, pP1);
            } else if (strcmp(ElmtSkill(ss, chosen_skill-1), "Senter Pengecil Hoki") == 0) {
                printf("Senter Pengecil Hoki diaktifkan.\n");
                LowerRoll = 1;
                UpperRoll = MaxRoll/2;
            } else if (strcmp(ElmtSkill(ss, chosen_skill-1), "Senter Pembesar Hoki") == 0) {
                printf("Senter Pembesar Hoki diaktifkan.\n");
                LowerRoll = MaxRoll/2;
                UpperRoll = MaxRoll;
            }
        } else {
            /* keluar */
        }
    }
}

void MAP(Map M, TabPlayer Tp)
/* Menampilkan posisi tiap pemain di peta */
/* Posisi pemain ditandai dengan petak '*' */
{
    int i;
    Player P = FirstPlayer(Tp);
    while (P != Nil) {
        printf("%s\t: ", Name(P));
        for (i = 0; i < NEff(M); i++) {
            if (i == Position(P)) {
                printf("*");
            } else {
                printf("%c", Petak(M,i));
            }
        }
        
        P = NextPlayer(P);
        printf("\n");
    }
}

int BUFF()
/* Menampilkan daftar buff yang DIMILIKI pemain */
{
    printf("Buff yang aktif pada Anda saat ini: %s\n", BUFF_AKTIF);
    if (strcmp(BUFF_AKTIF, "# Cermin Pengganda #") == 0) {
        return 0;
    } else if (strcmp(BUFF_AKTIF, "# Imunitas Teleport #") == 0) {
        return 1;
    } else if (strcmp(BUFF_AKTIF, "# Senter Pengecil Hoki #") == 0) {
        return 2;
    } else if (strcmp(BUFF_AKTIF, "# Senter Pembesar Hoki #") == 0) {
        return 3;
    } else {
        return -1;
    }
}

void INSPECT(Map M, ArrayOfTeleporter A)
/* Menampilkan apakah suatu petak itu kosong,
   terlarang, atau memiliki teleporter */
{
    int p, i;
    printf("ID Petak >>> ");
    scanf("%d", &p);

    /* Cek Teleporter */
    for (i = 0; i < NEff(A); i++) {
        if (TelIn(A,i) == p) {
            printf("Petak %d memiliki teleporter menuju %d\n", TelIn(A,i), TelOut(A,i));
        }
    }

    /* Cek Petak Biasa */
    printf("Bentuk Petak: %c\n", Petak(M,i));
}

void ROLL(Map M, int t, int p, int lower, int upper, TabPlayer *T)
/* Generate random integer dari 1--MaxRoll */
/* Pemain berpindah dengan fungsi Move() */
{
    srand(time(0));
    int val = (rand() % (upper - lower + 1)) + lower;
    printf("Anda mendapatkan angka %d\n", val);

    int counter = 1;
    int p1 = (p + val), p2 = (p - val);
    printf("Ingin kemana Anda berpindah:\n");
    if ((p1 >= 0) && (p1 < NEff(M)) && (Petak(M,p1) != '#')) {
        printf("[A] Petak %d\n", p1);
        counter++;
    }
    if ((p2 >= 0) && (p2 < NEff(M)) && (Petak(M,p2) != '#')) {
        printf("[B] Petak %d\n", p2);
        counter++;
    }
    if (counter == 1) {
        printf("Anda tidak bisa pergi ke mana-mana karena tidak ada petak yang tersedia.\n");
    } else {
        char move;
        printf("Pilihan Anda >>> ");
        scanf("%c", &move);

        if (move == 'A') {
            Move(T, t, p1);
        } else if (move == 'B') {
            Move(T, t, p2);
        }
    }

}

void ENDTURN(State *S, int X, TabPlayer Tp, Player *P)
/* Mengakhiri turn pemain, turn berpindah ke NextPlayer */
/* Jika LastPlayer sudah ENDTURN, state game disimpan (Push) */
{
    if (LastPlayer(Tp) == *P) {
        Push(S, X, Tp);
    } else {
        *P = NextPlayer(*P);
    }
}

void UNDO(State *S, TabPlayer *Tp)
/* Mengembalikan state game ke akhir ronde sebelumnya */
/* Skill yang didapat pemain akan direset */
{
    int dcs;
    printf("Dalam setiap ronde hanya bisa melakukan satu kali UNDO. Apakah Anda yakin ingin melakukan UNDO?\n");
    printf("([0] Tidak [1] Ya!) >>> ");

    scanf("%d", &dcs);
    if (dcs == 1){
        ElmtStack E;
        Pop(S, &E);
        *Tp = Player(E);
    } else {
        printf("UNDO dibatalkan.\n");
    }
}

char * ReadLine()
/* Mengembalikan sebuah string */
/* Expected: IO sebuah command */
{
	static char c[20];
    fgets(c, sizeof(c), stdin);
    return c;
}