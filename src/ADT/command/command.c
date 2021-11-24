/* File: command.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "command.h"

int Round ;
int minval;                     // = 1;
int maxval;                     // = MaxRoll;
boolean isEndTurn = FALSE;  // Apakah player sudah ENDTURN
boolean isNotRoll = TRUE ;  // Apakah player belum ROLL


void SKILL (TabPlayer *Tp, TabSkill *Ts, Skill *s, sPlayer *sp, sSkill *ss, int X)
/* Menampilkan skillyang DIMILIKI pemain dengan Turn(P) = X */
/* Pemain dapat memilih untuk keluar, membuang, atau menggunakan skill */
{
    ShowSkill(*ss);

    int in;
    printf("Apa yang ingin Anda lakukan?\n");
    printf("([0] Keluar [X] Buang [-X] Gunakan) >>> ");
    scanf("%d", &in);

    if (!in)
    {
        /* Keluar */
    }
    else if (in < 0)
    {
        DelSkill(ss, abs(in)); // DEBUG: Need update SkillSet
        printf("Anda telah membuang skill [%d].\n", abs(in));
        SkillSet(*s) = *ss; // Update skill.
    }
    else if (in > 0)
    {
        if (strcmp(ElmtSkill(*ss, in-1), "Pintu Ga Ke Mana Mana") == 0)
        {
            BUFF_AKTIF = "# Imunitas Teleport #";
        }
        else if (strcmp(ElmtSkill(*ss, in-1), "Cermin Pengganda") == 0)
        {
            AddSkill(ss, GenerateSkill(X));
            AddSkill(ss, GenerateSkill(X));
        }
        else if (strcmp(ElmtSkill(*ss, in-1), "Mesin Penukar Posisi") == 0)
        {
            int Y, PP1, PP2;
            printf("Input ID (Turn) pemain yang ingin ditukan posisinya dengan Anda! >>> ");
            scanf("%d", &Y);

            Player P1 = SearchPlayer(*Tp, X);
            Player P2 = SearchPlayer(*Tp, Y);
            PP1 = Position(DataPlayer(P1));
            PP2 = Position(DataPlayer(P2));
            Move(&P1, X, PP2);
            Move(&P2, Y, PP1);
            Position(*sp) = Position(DataPlayer(P1));
        }
        else if (strcmp(ElmtSkill(*ss, in-1), "Senter Pengecil Hoki") == 0)
        {
            printf("Senter Pengecil Hoki diaktifkan.\n");
            minval = 1;
            maxval = MaxRoll/2;
        }
        else if (strcmp(ElmtSkill(*ss, in-1), "Senter Pembesar Hoki") == 0)
        {
            printf("Senter Pembesar Hoki diaktifkan.\n");
            minval = MaxRoll/2;
            maxval = MaxRoll;
        }
        DelSkill(ss, in);
        SkillSet(*s) = *ss; // Update skill.
    }
    else
    {
        printf("Input tidak valid.\n");
    }
}

void MAP (Map M, TabPlayer Tp)
/* Menampilkan Position(P) tiap pemain */
{
    int i;
    Player P = FirstPlayer(Tp);

    while (P != Nil)
    {
        printf("%s\t: ", Name(DataPlayer(P)));
        for (i = 0; i < NEff(M); i++)
        {
            if ((Position(DataPlayer(P)) - 1) == i)
            {
                printf("*");
            }
            else
            {
                printf("%c", Petak(M,i));
            }
        }
        P = NextPlayer(P);
        printf("\n");
    }
}

void BUFF()
/* Menampilkan buff yang DIMILIKI pemain */
{
    printf("Buff yang aktif pada Anda saat ini: %s\n", BUFF_AKTIF);
}

void INSPECT (Map M, ArrayOfTeleporter AoT)
/* Menampilkan apakah petak kosong, terlarang, atau berteleporter */
{
    int in, i;
    printf("ID Petak >>>");
    scanf("%d", &in);

    for (i = 0; i < NEff(AoT); i++)
    {
        if (TelIn(AoT,i) == in)
        {
            printf("Petak %d memiliki teleporter menuju %d\n", TelIn(AoT,i), TelOut(AoT,i));
        }
    }

    printf("Bentuk petak: %c\n", Petak(M,i-1));
}

void ROLL (Map M, ArrayOfTeleporter AoT, Player *P, sPlayer *sp, int X)
/* F.S. Posisi pemain berpindah sejauh angka yang didapat */
/* Pemain dapat memilih untuk mundur ataupun maju */
/* Pemain tidak bisa berpindah ke petak terlarang (#) */
{
    if (isNotRoll)
    {
        srand(time(0));
        int val = (rand() % (maxval - minval + 1)) + minval;
        printf("Anda mendapatkan angka %d\n", val);

        int ds = 0;
        int d1 = Position(*sp) + val, d2 = Position(*sp) - val;
        if ((d1 > 0) && (d1 < NEff(M)) && (Petak(M,d1-1) != '#'))
        {
            printf("[1] Petak %d\n", d1);
            ds++;
        }
        if ((d2 > 0) && (d2 < NEff(M)) && (Petak(M,d2-1) != '#'))
        {
            printf("[2] Petak %d\n", d2);
            ds++;
        }
        if (!ds)
        {
            printf("Anda tidak bisa pergi ke mana-mana karena tidak ada petak yang tersedia.\n");
            isNotRoll = FALSE;
        }
        else
        {
            int m;
            while (isNotRoll)
            {
                printf("[Kemana Anda ingin berpindah?] >>> ");
                scanf("%d", &m);
                if (m == 1)
                {
                    Move(P, X, d1);
                    isNotRoll = FALSE;
                    Position(*sp) = Position(DataPlayer(*P));
                }
                else if (m == 2)
                {
                    Move(P, X, d2);
                    isNotRoll = FALSE;
                    Position(*sp) = Position(DataPlayer(*P));
                }
                else
                {
                    printf("Input tidak valid.\n");
                }
            }

            /* Teleporter check */
            int in, i;
            for (i = 0; i < NEff(AoT); i++)
            {
                if (TelIn(AoT,i) == Position(*sp))
                {
                    printf("Petak %d memiliki teleporter menuju Petak %d\n", TelIn(AoT,i), TelOut(AoT,i));
                    if (strcmp(BUFF_AKTIF, "# Imunitas Teleport #") == 0)
                    {
                        printf("Anda memiliki buff %s. Apakah Anda ingin teleport?", BUFF_AKTIF);
                        printf("([0] Tidak [1] Ya!) => ");
                        scanf("%d", &in);
                        if (in)
                        {
                            Move(P, X, TelOut(AoT,i));
                            BUFF_AKTIF = "Tidak ada.";
                        }
                    }
                    else
                    {
                        Move(P, X, TelOut(AoT,i));
                    }
                    break;
                }
            }
        }
    }
    else
    {
        printf("Anda sudah melakukan ROLL pada turn ini!\n");
    }
}

void ENDTURN (State *S, TabSkill Ts, TabPlayer Tp, Player *P, Skill *s)
/* Menandakan turn pemain telah berakhir dan berganti ke NextPlayer(P) */
/* Apabila pemain terakhir ENDTURN, state ronde akan dipush ke stack S */
{
    if (!isNotRoll){
        isEndTurn = TRUE;
        if (LastPlayer(Tp) == *P)
        {
            Push(S, Tp, Ts);
            *P = FirstPlayer(Tp);
            *s = First(Ts);
            Round++;
        }
        else
        {
            *P = NextPlayer(*P);
            *s = Next(*s);
        }
    }
    else
    {
        printf("Silakan ROLL terlebih dahulu!\n");
    }
}

void UNDO (State *S, TabPlayer *Tp, TabSkill *Ts, Player *P, Skill *s)
/* Mengembalikan state ke akhir awal ronde, di mana:
   1. Skill tiap pemain diacak ulang
   2. Posisi tiap pemain diulang. */
{
    int in;
    printf("Yakin ingin UNDO?\n");
    printf("([0] Tidak [1] Ya!) >>> ");
    scanf("%d", &in);

    if (in)
    {
        Pop(S, Tp, Ts);
        *P = FirstPlayer(*Tp);
        *s = First(*Ts);
        isEndTurn = TRUE;
    }
    else
    {
        printf("UNDO dibatalkan.\n");
    }
}