/* File: driver_state.c */

#include "state.c"
#include "../skill/skill.c"
#include "../player/player.c"

int main(int argc, char const *argv[])
{
	State S;
	CreateEmptyState(&S);

	TabPlayer T;
	CreateEmptyPlayer(&T);

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
				TabSkill S1;
				CreateEmpty(&S1);
				InsVFirst(&S1,1);
				InsVFirst(&S1,2);
				AddPlayer(&T, "Mobita-kun", (i+1), 1, S1);
			} else if (j == 2) {
				TabSkill S2;
				CreateEmpty(&S2);
				InsVFirst(&S2,1);
				InsVFirst(&S2,2);
				AddPlayer(&T, "Emon-san", (i+1), 1, S2);
			} else if (j == 3) {
				TabSkill S3;
				CreateEmpty(&S3);
				InsVFirst(&S3,1);
				InsVFirst(&S3,2);
				AddPlayer(&T, "Jayen-sama", (i+1), 1, S3);
			} else if (j == 4) {
				TabSkill S4;
				CreateEmpty(&S4);
				InsVFirst(&S4,1);
				InsVFirst(&S4,2);
				AddPlayer(&T, "Suzuka-chan", (i+1), 1, S4);
			} else if (j == 5) {
				TabSkill S5;
				CreateEmpty(&S5);
				InsVFirst(&S5,1);
				InsVFirst(&S5,2);
				AddPlayer(&T, "Shizuneo-senpai", (i+1), 1, S5);
			}
		}
	}

	ShowPlayer(T);

	while (in) {
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

	int z;
	printf("\n[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}