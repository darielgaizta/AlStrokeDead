/* driver_kar.c */

#include "mesinkar.c"
#include "../mesinkata/mesinkata.c"

int main(int argc, char const *argv[])
{
	START("Test.txt");
	while (!EOP) {
		IgnoreBlank();
		printf("%c", CC);
		ADV();
	}

	int z;
	printf("\n[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}