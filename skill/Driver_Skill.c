#include "skill.h"
#include "skill.c"

int main(int argc, char const *argv[])
{
	TabSkill L;
	CreateEmpty(&L);
	// L terdefinisi

	InsVLast(&L, 1);
	InsVLast(&L, 2);

	Skill S1 = First(L);
	sSkill ss1 = SkillSet(S1);
	AddSkill(&ss1, "Teknologi Gagal (Junk)");
	AddSkill(&ss1, "Senter Pembesar Hoki");
	AddSkill(&ss1, "Pintu Ga Ke Mana Mana");

	ShowSkill(ss1);

	Skill S2 = Last(L);
	sSkill ss2 = SkillSet(S2);
	AddSkill(&ss2, "Senter Pengecil Hoki");
	AddSkill(&ss2, "Teknologi Gagal (Junk)");
	AddSkill(&ss2, "Senter Pengecil Hoki");

	ShowSkill(ss2);

	printf("\n### PENGHAPUSAN Ke-1 ###\n");

	DelSkill(&ss1, 1);
	ShowSkill(ss1);

	printf("\n### PENGHAPUSAN Ke-2 ###\n");

	DelSkill(&ss1, 3);
	ShowSkill(ss1);

	printf("ID pemain yang sudah memiliki skill: ");
	PrintForward(L);

	int z;
	printf("\n[Input any key to continue]");
	scanf("%d", &z);

	return 0;
}