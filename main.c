/* File: main.c */
/* Welcome to Mobitangga Legends: Dor Dor */
/* This file is meant to be the main program of the game, also 
   as the submission of IF2111 Algorithm and Data Structure final project */
/* Kelompok 1:
   - 18219052 Rahmah Putri Azzahra
   - 18220003 Made Adhika Wiwardhana
   - 18220009 Fatih Darielma Gaizta
   - 18220063 I Nyoman Aditya Ariputra
   - 18220089 David Nathanio Gabriel Siahaan
   - 18220093 Kyla Aisha */
/* Asisten: 13518114 Mario Gunawan */
/* Sistem dan Teknologi Informasi, ITB */
/* 21 November 2021 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "mesinkar/mesinkar.c"
#include "mesinkata/mesinkata.c"
#include "command/command.c"
#include "player/player.c"
#include "state/state.c"
#include "skill/skill.c"
#include "map/map.c"

int main(int argc, char const *argv[])
{
	/* Variables */
	TabPlayer Tp;
	TabSkill Ts;
	State S;
	Map M;
	ArrayOfTeleporter AoT;

	int in;

	/* Main Menu */
	printf("==============|  WELCOME TO MOBITANGGA LEGENDS: DOR DOR  |====================\n");
	printf("About: This game is intentionally made for IF2111 Algorithm and Data Structure project, by Kelompok 1\n");
	printf("Mobitangga Legends: Dor Dor is an 'ala-ala' of Snake&Ladder game. It can be played for 4 players. ");
	printf("Each player will start from Petak 1 and finish at the final Petak. While in the game, players can use their skill, buff, and move to another Petak using Teleporter. ");
	printf("The game will end if we have one player who has reached the final Petak. For further information, please check our documentation. Good luck!\n");

	printf("\n([0] Exit [1] New Game) >>> ");
	scanf("%d", &in);

	if (!in){
		exit(0);
	} else {
		/* Configuration */
		Config();

		/* Set Variables */
		CreateEmptyPlayer(&Tp);
		CreateEmpty(&Ts);
		CreateEmptyState(&S);
		LoadMap(&M, &AoT);

		/* Set Players */
		printf("\nNumber of Players (Max. 4 Players): ");
		scanf("%d", &in);

		int i, j;
		printf("\n=======================|  Pick Your Hero!  |===================================\n");
		printf("[1] Mobita-kun [2] Emon-san [3] Jayen-sama [4] Suzuka-chan [5] Shizuneo-senpai\n");
		for (i = 0; i < in; i++) {
			printf("Masukkan nama pemain ke-%d: ", (i+1));
			scanf("%d", &j);
			if (j == 1) {
				InsVLast(&Ts, (i + 1));
				AddPlayer(&Tp, "Mobita-kun", (i+1), 1, Ts);
			} else if (j == 2) {
				InsVLast(&Ts, (i + 1));
				AddPlayer(&Tp, "Emon-san", (i+1), 1, Ts);
			} else if (j == 3) {
				InsVLast(&Ts, (i + 1));
				AddPlayer(&Tp, "Jayen-sama", (i+1), 1, Ts);
			} else if (j == 4) {
				InsVLast(&Ts, (i + 1));
				AddPlayer(&Tp, "Suzuka-chan", (i+1), 1, Ts);
			} else if (j == 5) {
				InsVLast(&Ts, (i + 1));
				AddPlayer(&Tp, "Shizuneo-senpai", (i+1), 1, Ts);
			}
		}

		ShowPlayer(Tp);

		/* Gameplay */
		printf("\n=======================|    Game Start     |===================================\n");

		Skill  s = First(Ts);
		Player P = FirstPlayer(Tp);
		boolean isPlaying = TRUE;
		boolean isEndTurn = FALSE;

		char com[20];
		int buff, round = 1;
		int count = 1-JML_PEMAIN;

		while (isPlaying) {
			MAP(M, Tp);
			LowerRoll = 1;
			UpperRoll = MaxRoll;
			isEndTurn = FALSE;
			sSkill ss = SkillSet(s);
			boolean isRolled = FALSE;
			GenerateBuff(Ts, Turn(P));
			if (count > 0) {
				AddSkill(&ss, GenerateSkill(Turn(P)));
			}

			while (!isEndTurn) {
				printf("\n[%s] >>> ", Name(P));
				scanf("%s", &com);

				if (strcmp(com, "SKILL") == 0) {
					SKILL(&Tp, &ss, Turn(P));
					SkillSet(s) = ss;
				} else if (strcmp(com, "MAP") == 0) {
					MAP(M, Tp);
				} else if (strcmp(com, "BUFF") == 0) {
					buff = BUFF();
				} else if (strcmp(com, "INSPECT") == 0) {
					INSPECT(M, AoT);
				} else if (strcmp(com, "ROLL") == 0) {
					if (!isRolled) {
						ROLL(M, Turn(P), Position(P), LowerRoll, UpperRoll, &Tp);
						isRolled = TRUE;
						if (Position(P) == NEff(M)) {
							isPlaying = FALSE;
						}
					}
				} else if (strcmp(com, "ENDTURN") == 0) {
					if (isRolled) {
						ENDTURN(&S, round, Tp, &P);
						isEndTurn = TRUE;
						count++;
						if (s == Last(Ts)) {
							s = First(Ts);
						} else {
							s = Next(s);
						}
					} else {
						printf("Silakan ROLL terlebih dahulu.\n");
					}
				} else if (strcmp(com, "UNDO") == 0) {
					UNDO(&S, &Tp);
				} else {
					printf("Input tidak valid.\n");
				}

			}

			/* End of Game: if Position(P) = NEff(M) */
			/* Bug => Teleporter + Buff + UNDO */
			
		}

	}

	/* End of Game */
	printf("\nEnd of Game.\n");
	printf("Dear players, Thanks for playing Mobitangga Legends: Dor Dor. We would be pleased if you can send your feedback about this game to us. ");
	printf("Let us know if you're happy while playing the game by sending us GoFood, GrabFood, etc. :D\n");
	printf("Open for feedback: 182XXXXX@std.stei.itb.ac.id\n");
	printf("(see the NIM at the documentation)\n");
	printf("\nCiao!\n");

	int xxx;
	scanf("%d", &xxx);

	return 0;
}