/* File: driver_map.c */

#include "map.c"
#include "../mesinkar/mesinkar.c"
#include "../mesinkata/mesinkata.c"

/*
int main(int argc, char const *argv[])
{
	Config();
	return 0;
}
*/


int main(int argc, char const *argv[])
{
	int i;
	Map M;
	ArrayOfTeleporter AoT;

	LoadMap(&M, &AoT);

	printf("Panjang peta: %d => ", NEff(M));
	for (i = 0; i < NEff(M); i++) {
		printf("%c", Petak(M,i));
	}

	printf("\nMaxRoll: %d\n", MaxRoll);
	printf("Banyaknya Teleporter: %d\n", NEff(AoT));

	for (i = 0; i < NEff(AoT); i++) {
		printf("%d %d\n", TelIn(AoT,i), TelOut(AoT,i));
	}

	int z;
	printf("\n[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}
