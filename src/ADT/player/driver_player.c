/* File: driver_player.c */

#include "player.c"

/* Test Case #1 */
/*
int main(int argc, char const *argv[])
{
	TabPlayer Tp;
	CreateEmptyPlayer(&Tp);

	int i, in;
	char com[20];

	for (i = 0; i < 3; i++) {
		printf("Masukkan nama: ");
		scanf("%s", &com);
		AddPlayer(&Tp, (i+1), com);
	}

	ShowPlayer(Tp);

	printf("\n[PRESS ENTER]\n");
	scanf("%d", &in);


	return 0;
}
*/

int main(int argc, char const *argv[])
{
	TabPlayer Tp;
	CreateEmptyPlayer(&Tp);

	int in;

	AddPlayer(&Tp, (1), "Mobita");
	AddPlayer(&Tp, (2), "Suzuka");
	AddPlayer(&Tp, (3), "Borakemon");

	ShowPlayer(Tp);

	RemovePlayer(&Tp, 2);
	
	ShowPlayer(Tp);	

	Player P = FirstPlayer(Tp);

	printf("Posisi sebelum pindah: %d\n", Position(DataPlayer(P)));
	Move(&Tp, 1, 5);
	printf("Posisi setelah pindah: %d\n", Position(DataPlayer(P)));

	printf("\n[PRESS ENTER]\n");
	scanf("%d", &in);
	return 0;
}