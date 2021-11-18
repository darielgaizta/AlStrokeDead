/* command.c */

#include <stdio.h>
#include <stdlib.h>
#include "command.h"


void SKILL();

void MAP();

void BUFF();

void INSPECT();

void ROLL();

void SAVE();

void ENDTURN();

void UNDO();

void LogCommand();
/* IO file log_command.txt yang berisi command terbaru */
/* Expected: log_command.txt hanya berisi satu command */
{
	FILE * F;
	F = fopen("log_command.txt", "r");
	fputs(ReadLine(), F);
	fputs(MARK, F);
	fclose(F);
}

char * ReadLine()
/* Mengembalikan sebuah string */
/* Expected: IO sebuah command */
{
	static char c[20];
    fgets(c, sizeof(c), stdin);
    return c;
}