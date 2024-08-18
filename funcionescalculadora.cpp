#include "funcionescalculadora.h"
#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int numerocolor=7;

void informacion(){
	
	cout << "\tInformacion de la calculadora:" << endl << endl;
	cout << "\tModelo: CASIO 2024." << endl;
	cout << "\tAño: 2024." << endl;
	cout << "\tCreador: Jhonel Gerson Apaza Pacompia." << endl << endl;
	cout << "\tDerechos reservados UNJBG-TACNA.";
}

void menu(){
	
	string respuesta;
	int tamanorespuesta;
	int numero;
	bool salir=false;
	bool valido=true;
	do{
		system("cls");
		cout << endl << endl;
		cout << "\t\t\tMenu de la calculadora" << endl << endl;
		cout << "          Color pantalla          Color letra          Idioma          Salir" << endl << endl;
		cin.ignore();
		getline(cin, respuesta);
		
		tamanorespuesta=respuesta.length();
		
		system("cls");
		cout << endl << endl<< endl;
		cout << "\t\t";
		if(tamanorespuesta<=10){
			valido = false;
		} else if (tamanorespuesta<=24){
			cout << "Elija el color del fondo de pantalla" << endl << endl;
			for(int i=numerocolor; i<242; i+=16){
				color(hConsole, i);
				cout << "\tColor " << i;
				color(hConsole, 7);
				cout << endl << endl;
			}
			color(hConsole, 7);
			cout << endl << endl << "\t=";
			cin >> numero;
			// simplificacion de N*n + (15-N+1)(n-1) = numerocolor*numero+(15-numerocolor+1)(numero-1)
			// N+16(n-1)
			numerocolor=numerocolor+16*(numero-1);
			color(hConsole, numerocolor);
		} else if (tamanorespuesta<=34){
			valido = false;
		} else if (tamanorespuesta<=45){
			cout << "Elija el color de letra" << endl;
		} else if (tamanorespuesta<=55){
			valido = false;
		} else if (tamanorespuesta<=61){
			cout << "Elija el idioma" << endl;
		} else if (tamanorespuesta<=71){
			valido = false;
		} else if (tamanorespuesta<=76){
			cout << "Saliendo del programa" << endl;
			salir = true;
		}
		
		color(hConsole, 7);
		
		cout << endl << endl<< endl << endl;
		if(!valido){
			cout << "Indique una opcion valida." << endl;
		}
		if(!salir){
			system("pause");
		}
	} while(!salir);
}
