/* File: driver_state.c */

#include "state.c"
#include "../skill/skill.c"
#include "../player/player.c"


int main(int argc, char const *argv[])
{
	TabPlayer Tp;
	CreateEmptyPlayer(&Tp);

	TabSkill Ts;
	State S;

	CreateEmpty(&Ts);
	CreateEmptyState(&S);

	int in;

	AddPlayer(&Tp, (1), "Mobita");
	AddPlayer(&Tp, (2), "Suzuka");
	AddPlayer(&Tp, (3), "Borakemon");

	ShowPlayer(Tp);

	RemovePlayer(&Tp, 2);
	
	ShowPlayer(Tp);	

	InsVLast(&Ts, 1);
	InsVLast(&Ts, 2);

	Player P = FirstPlayer(Tp);
	sPlayer sp = DataPlayer(P);

	printf("Posisi sebelum pindah: %d\n", Position(sp));

	Push(&S, Tp, Ts);

	Move(&P, 1, 5);

	printf("Posisi setelah pindah #1: %d\n", Position(sp));
	printf("Posisi setelah pindah #2: %d\n", Position(DataPlayer(P)));

	printf("\n##### PROSES POP #####\n");
	Pop(&S, &Tp, &Ts);

	printf("=====| Print #1 |=====\n");
	printf("Posisi setelah pop #1: %d\n", Position(sp));
	printf("Posisi setelah pop #2: %d\n", Position(DataPlayer(P)));

	sp = DataPlayer(P); // Update.

	printf("=====| Print #2 |=====\n");
	printf("Posisi setelah pop #1: %d\n", Position(sp));
	printf("Posisi setelah pop #2: %d\n", Position(DataPlayer(P)));

	P = FirstPlayer(Tp);	// Redefine.
	sp = DataPlayer(P);		// Redefine.

	printf("=====| Print #2 |=====\n");
	printf("Posisi setelah pop #1: %d\n", Position(sp));
	printf("Posisi setelah pop #2: %d\n", Position(DataPlayer(P)));

	printf("\n[PRESS ENTER]\n");
	scanf("%d", &in);

	return 0;
}
/*
int main(int argc, char const *argv[])
{
	TabPlayer Tp;
	CreateEmptyPlayer(&Tp);

	TabSkill Ts;
	State S;
	CreateEmpty(&Ts);
	CreateEmptyState(&S);

	int in;

	InsVLast(&Ts, 1);

	Skill s = First(Ts);
	sSkill ss = SkillSet(s);

	printf("$$$$$ SAAT DIPUSH $$$$$\n");	
	ShowSkill(SkillSet(s));
	ShowSkill(ss);

	Push(&S, Tp, Ts);

	AddSkill(&ss, "Nyampah");
	AddSkill(&ss, "Tidur");

	ShowSkill(SkillSet(s));
	ShowSkill(ss);

	Pop(&S, &Tp, &Ts);

	printf("$$$$$ SETELAH POP #1 $$$$$\n");
	ShowSkill(SkillSet(s));
	ShowSkill(ss);

	printf("$$$$$ SETELAH POP #2 $$$$$\n");
	s = First(Ts);
	ss = SkillSet(s);

	ShowSkill(SkillSet(s));
	ShowSkill(ss);


	printf("\n[PRESS ENTER]\n");
	scanf("%d", &in);

	return 0;
}
*/