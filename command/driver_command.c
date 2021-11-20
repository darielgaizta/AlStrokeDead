/* File: driver_command.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "command.c"
#include "../skill/skill.c"
#include "../player/player.c"
#include "../state/state.c"
#include "../map/map.c"
#include "../mesinkar/mesinkar.c"
#include "../mesinkata/mesinkata.c"

int main(int argc, char const *argv[])
{
	State S;
	CreateEmptyState(&S);

	TabPlayer T;
	CreateEmptyPlayer(&T);

	TabSkill L;
	CreateEmpty(&L);


	int in;
	printf("([0] Exit [1] Play!) => ");
	scanf("%d", &in);

	if (in) {
		int i, j;
		printf("\n=======================|  Pick Your Hero!  |===================================\n");
		printf("[1] Mobita-kun [2] Emon-san [3] Jayen-sama [4] Suzuka-chan [5] Shizuneo-senpai\n");
		for (i = 0; i < 5; i++) {
			printf("Masukkan nama pemain ke-%d: ", (i+1));
			scanf("%d", &j);
			if (j == 1) {
				InsVLast(&L, (i + 1));
				AddPlayer(&T, "Mobita-kun", (i+1), 1, L);
			} else if (j == 2) {
				InsVLast(&L, (i + 1));
				AddPlayer(&T, "Emon-san", (i+1), 1, L);
			} else if (j == 3) {
				InsVLast(&L, (i + 1));
				AddPlayer(&T, "Jayen-sama", (i+1), 1, L);
			} else if (j == 4) {
				InsVLast(&L, (i + 1));
				AddPlayer(&T, "Suzuka-chan", (i+1), 1, L);
			} else if (j == 5) {
				InsVLast(&L, (i + 1));
				AddPlayer(&T, "Shizuneo-senpai", (i+1), 1, L);
			}
		}
	}

	ShowPlayer(T);

	/* ====== Gameplay ====== */
	Player P = FirstPlayer(T);

	SKILL(&L, &T, Turn(P));

	Skill s = First(L);

	ShowSkill(SkillSet(s));



	while (1) {
		printf("([0] Keluar [1] Save [2] Load) => ");
		scanf("%d", &in);
		if (in == 1) {
			Push(&S, 1, T);
		} else if (in == 2) {
			ElmtStack E;
			Pop(&S, &E);
			ShowPlayer(Player(E));
		} else {
			break;
		}
	}


	return 0;
}