/* driver_mesinkata.c */

#include "../mesinkar/mesinkar.c"
#include "mesinkata.c"


int main(int argc, char const *argv[])
{
	STARTKATA("../map/konfigurasi.txt");
	while(!EndKata) {
		printKata(CKata);
		// printf("## %s ##\n", CKata.TabKata);
		ADVKATA();
	}

	int z;
	printf("[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}