#include "skill.h"
#include "skill.c"

int main(int argc, char const *argv[])
{
	TabSkill L;
	CreateEmpty(&L);
	// L terdefinisi

	InsVFirst(&L, 1);
	InsVFirst(&L, 2);

	PrintForward(L);

	int z;
	printf("[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}