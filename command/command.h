/* File: command.h */

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../boolean.h"
#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"


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

char * ReadLine();
/* Mengembalikan sebuah string */
/* Expected: IO sebuah command */