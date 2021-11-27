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

int min;
int max;

int main(int argc, char const *argv[])
{
	int in;

	/* ========================================| Main Menu |======================================== */

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

	printf("\n([0] Exit [1] New Game [2] Load Game) >>> ");
	scanf("%d", &in);

	if (in)
	{
		/* ========================================| Init Game |======================================== */

		TabPlayer Tp;				// List of players
		TabSkill Ts;				// List of skills
		State S;						// Stack of states
		Map M;						// Map Representation
		ArrayOfTeleporter AoT;	// Teleporter Representation

		CreateEmptyPlayer(&Tp);	// Init. Tp
		CreateEmpty(&Ts);			// Init. Ts
		CreateEmptyState(&S);	// Init S

		if (in != 2)
		{
			Config();				// Set config
		}
		
		LoadMap(&M, &AoT);		// Init map, Load Game ~ baca config.txt lama

		/* ========================================|  Opening  |======================================== */

		int i, j;

		if (in != 2){
			printf("\nNumber of Players (Max. 4 Players): ");
			scanf("%d", &in);

			printf("\n=======================|  Pick Your Hero!  |==================================\n");
			printf("[1] Mobita-kun [2] Emon-san [3] Jayen-sama [4] Suzuka-chan [5] Shizuneo-senpai\n");

			for (i = 0; i < in; i++)
			{
				printf("Masukkan nama pemain ke-%d: ", (i+1));
				scanf("%d", &j);

				if (j == 1)
				{
					InsVLast(&Ts, (i+1));
					AddPlayer(&Tp, (i+1), "Mobita-kun");
				}
				else if (j == 2)
				{
					InsVLast(&Ts, (i+1));
					AddPlayer(&Tp, (i+1), "Emon-san");
				}
				else if (j == 3)
				{
					InsVLast(&Ts, (i+1));
					AddPlayer(&Tp, (i+1), "Jayen-sama");
				}
				else if (j == 4)
				{
					InsVLast(&Ts, (i+1));
					AddPlayer(&Tp, (i+1), "Suzuka-chan");
				}
				else if (j == 5)
				{
					InsVLast(&Ts, (i+1));
					AddPlayer(&Tp, (i+1), "Shizuneo-senpai");
				}
			}
		}
		else
		{
			/* Load data player dan data skill */
			printf("Loading data...\n");
			LoadPlayer(&Tp);
			LoadSkill(&Ts);
			if (IsEmptyPlayer(Tp))
			{
				printf("Data tidak ditemukan.\nSilakan tutup program, buka lagi, dan mulai permainan baru dengan memilih [1] New Game\n");
				printf("[Input any key to exit] >>> ");
				scanf("%d", &in);
				exit(0);
			}
			printf("\nData successfully loaded.\n");
		}

		ShowPlayer(Tp);

		/* ========================================| Game play |======================================== */

		char com[20];
		
		Round = 1;
		boolean isPlaying = TRUE;			// Apakah game masih berlanjut
		Player P = FirstPlayer(Tp);		// Pemain
		Skill  s = First(Ts);				// Skill pemain

		sPlayer sp;							// Data pemain
		sSkill  ss;							// Data skill pemain

		while (isPlaying)
		{
			printf("\n========================================|  Round %d |========================================\n", Round);
			
			MAP(M, Tp);
			minval = 1;
			maxval = MaxRoll;
			isEndTurn = FALSE;
			isNotRoll = TRUE ;
			immuneTel = FALSE;
			sp = DataPlayer(P);
			ss = SkillSet(s);

			BUFF_AKTIF = "Tidak ada.";

			if (Round > 1)
			{
				AddSkill(&ss, GenerateSkill(Turn(P)));
			}

			while (!isEndTurn)
			{
				printf("\n[%s] >>> ", Name(DataPlayer(P)));	// Show which player is playing
				scanf("%s", &com);									// Input command

				if (strcmp(com, "SKILL") == 0)
				{
					SKILL(&Tp, &Ts, M, &P, &s, &sp, &ss, Turn(P), &isPlaying);
				}
				else if (strcmp(com, "MAP") == 0)
				{
					MAP(M, Tp);
				}
				else if (strcmp(com, "BUFF") == 0)
				{
					BUFF();
				}
				else if (strcmp(com, "INSPECT") == 0)
				{
					INSPECT(M, AoT);
				}
				else if (strcmp(com, "ROLL") == 0)
				{
					ROLL(M, AoT, &P, &sp, Turn(P));
				}
				else if (strcmp(com, "ENDTURN") == 0)
				{
					ENDTURN(&S, Ts, Tp, &P, &s, &ss);
				}
				else if (strcmp(com, "UNDO") == 0)
				{
					UNDO(&S, &Tp, &Ts, &P, &s);
				}
				else if (strcmp(com, "SAVE") == 0)
				{
					SAVE(Tp, Ts);
				}
				else
				{
					printf("Input tidak valid.\n");
				}

				if (Position(DataPlayer(P)) == NEff(M))
				{
					isPlaying = FALSE;
					isEndTurn = TRUE ;
				}

			}

			/* End Game: isPlaying == FALSE */

		}

		printf("\n##########################################################\n");
		printf("CONGRATULATIONS, %s! You are among the legends!\n", Name(DataPlayer(P)));
		printf("##########################################################\n");
		printf("\nFinal position:\n");
		MAP(M, Tp);
	}

	/* End of Game */
	printf("\n--- End of Game ---\n");
	printf("Dear players, Thanks for playing Mobitangga Legends: Dor Dor. We would be pleased if you can send your feedback about this game to us.\n");
	printf("Let us know if you're happy while playing the game by sending us GoFood, GrabFood, etc. :D\n");
	printf("Open for feedback: 182XXXXX@std.stei.itb.ac.id\n");
	printf("(see the NIM at the documentation)\n");
	printf("\nCiao!\n");

	scanf("%d", &in);

	return 0;
}