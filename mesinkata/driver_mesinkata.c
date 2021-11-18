/* driver_mesinkata.c */

#include "../mesinkar/mesinkar.c"
#include "mesinkata.c"


int main(int argc, char const *argv[])
{
	STARTKATA("Test.txt");
	while(!EndKata) {
		printKata(CKata);
		ADVKATA();
	}

	int z;
	printf("[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}