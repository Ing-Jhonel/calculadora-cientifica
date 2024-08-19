#ifndef FUNCIONESCALCULADORA_H
#define FUNCIONESCALCULADORA_H
#include <windows.h>
#define color SetConsoleTextAttribute
using namespace std;

extern HANDLE hConsole;

extern int numerocolorletra;
extern int numerocolores;
void informacion();
void menu();
void simplificar();
void mcm();
void mcd();
void valorabsoluto();
void seno();
void coseno();
void tangente();
void hipotenusa();
#endif
