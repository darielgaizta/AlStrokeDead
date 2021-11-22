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
#include "ADT/mesinkar/mesinkar.c"
#include "ADT/mesinkata/mesinkata.c"
#include "ADT/command/command.c"
#include "ADT/player/player.c"
#include "ADT/state/state.c"
#include "ADT/skill/skill.c"
#include "ADT/map/map.c"

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
	printf("                         ___                                                ___            \n");            
    printf("                        (   )                                              (   )           \n");          
    printf(" ___  ___  ___   .--.    | |    .--.      .--.    ___ .-. .-.     .--.      | |_       .--.\n");     
    printf("(   )(   )(   ) /    \\   | |   /    \\    /    \\  (   )   '   \\   /    \\    (   __)    /    \\ \n");    
    printf(" | |  | |  | | |  .-. ;  | |  |  .-. ;  |  .-. ;  |  .-.  .-. ; |  .-. ;    | |      |  .-. |\n");   
    printf(" | |  | |  | | |  | | |  | |  |  |(___) | |  | |  | |  | |  | | |  | | |    | | ___  | |  | |\n");   
    printf(" | |  | |  | | |  |/  |  | |  |  |      | |  | |  | |  | |  | | |  |/  |    | |(   ) | |  | |\n");   
    printf(" | |  | |  | | |  ' _.'  | |  |  | ___  | |  | |  | |  | |  | | |  ' _.'    | | | |  | |  | |\n");    
    printf(" | |  ; '  | | |  .'.-.  | |  |  '(   ) | '  | |  | |  | |  | | |  .'.-.    | ' | |  | '  | |\n");    
    printf(" ' `-'   `-' ' '  `-' /  | |  '  `-' |  '  `-' /  | |  | |  | | '  `-' /    ' `-' ;  '  `-' /\n");    
    printf("  '.__.'.__.'   `.__.'  (___)  `.__,'    `.__.'  (___)(___)(___) `.__.'      `.__.    `.__.'  \n"); 


    printf("___  ___      _     _ _                                  _                               _        ______            ______           _ \n");
    printf("|  \\/  |     | |   (_) |                                | |                             | |    _  |  _  \\           |  _  \\         | |\n");
    printf("| .  . | ___ | |__  _| |_ __ _ _ __   __ _  __ _  __ _  | |     ___  __ _  ___ _ __   __| |___(_) | | | |___  _ __  | | | |___  _ __| |\n");
    printf("| |\\/| |/ _ \\| '_ \\| | __/ _` | '_ \\ / _` |/ _` |/ _` | | |    / _ \\/ _` |/ _ \\ '_ \\ / _` / __|   | | | / _ \\| '__| | | | / _ \\| '__| |\n");
    printf("| |  | | (_) | |_) | | || (_| | | | | (_| | (_| | (_| | | |___|  __/ (_| |  __/ | | | (_| \\__ \\_  | |/ / (_) | |    | |/ / (_) | |  |_|\n");
    printf("\\_|  |_/\\___/|_.__/|_|\\__\\__,_|_| |_|\\__, |\\__, |\\__,_| \\_____/\\___|\\__, |\\___|_| |_|\\__,_|___(_) |___/ \\___/|_|    |___/ \\___/|_|  (_)\n");
    printf("                                      __/ | __/ |                    __/ |                                                             \n");
    printf("                                     |___/ |___/                    |___/                                                              \n");   

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
		boolean isMove = FALSE;
		boolean isPlaying = TRUE;
		boolean isEndTurn = FALSE;

		char com[20];
		int buff = -1, round = 1;
		int count = 1-JML_PEMAIN;

		while (isPlaying) {

			MAP(M, Tp);
			LowerRoll = 1;
			UpperRoll = MaxRoll;
			isMove = FALSE;
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
						ROLL(M, Turn(P), Position(P), LowerRoll, UpperRoll, &Tp, &isMove);
						isRolled = TRUE;

						/* Teleporter Check */
						if (isMove) {
							for (i = 0; i < NEff(AoT); i++) {
								if (TelIn(AoT, i) == Position(P)) {
									printf("Petak %d memiliki teleporter menuju Petak %d\n", TelIn(AoT,i), TelOut(AoT,i));

									/* Imunitas Teleport Check */
									if (strcmp(BUFF_AKTIF, "# Imunitas Teleport #") == 0) {
										printf("Anda memiliki buff # Imunitas Teleport #. Apakah Anda ingin teleport?\n");
										printf("([0] Tidak [1] Ya!) => ");
										scanf("%d", &in);
										if (in) {
											Move(&Tp, Turn(P), TelOut(AoT,i));
											BUFF_AKTIF = "Tidak ada.";
										}
									} else {
										Move(&Tp, Turn(P), TelOut(AoT,i));
									}
									break;
								}
							}
						}
						if (Position(P) == NEff(M)) {
							isPlaying = FALSE;
						}
					}
					else
					{
						printf("Anda sudah melakukan ROLL pada turn ini!\n");
					}

				} else if (strcmp(com, "ENDTURN") == 0) {
					if (isPlaying) {
						if (isRolled) {
							ENDTURN(&S, round, Tp, &P, Ts, &s);
							isEndTurn = TRUE;
							count++;
						} else {
							printf("Silakan ROLL terlebih dahulu.\n");
						}
					} else {
						isEndTurn = TRUE;
					}

				} else if (strcmp(com, "UNDO") == 0) {
					UNDO(&S, &Tp, &Ts);
					P = FirstPlayer(Tp);
					s = First(Ts);
					isEndTurn = TRUE;

				} else {
					printf("Input tidak valid.\n");
				}

			}

			/* End of Game: if Position(P) = NEff(M) */
			/* Bug => UNDO */
			
		}

		printf("\n##########################################################\n");
		printf("CONGRATULATIONS, %s! You are among the legends!\n", Name(P));
		printf("##########################################################\n");
		printf("\nFinal position:\n");
		MAP(M, Tp);

	}

	/* End of Game */
	printf("\n--- End of Game ---\n");
	printf("Dear players, Thanks for playing Mobitangga Legends: Dor Dor. We would be pleased if you can send your feedback about this game to us. ");
	printf("Let us know if you're happy while playing the game by sending us GoFood, GrabFood, etc. :D\n");
	printf("Open for feedback: 182XXXXX@std.stei.itb.ac.id\n");
	printf("(see the NIM at the documentation)\n");
	printf("\nCiao!\n");

	return 0;
}