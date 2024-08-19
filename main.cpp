#include <iostream>
#include "funcionescalculadora.h"
using namespace std;

int main(){
	
	char opcion;
	do{
		system("cls");
		color(hConsole, 7);
		cout << endl << endl;
		color(hConsole, numerocolores); 
		cout << "\t******************************" << endl;
		cout << "\t   CALCULADORA CIENTIFICA" << endl;
		cout << "\t******************************" << endl << endl;
		cout << "\t X"   << "\t I" << "\t M" << "\t T" << endl;
		cout << "\tSALIR"<< "\tINFO" << "\tMENU" << "\tHIST" << endl << endl;
		cout << "\t l"   << "\t q" << "\t p" << "\t v" << endl;
		cout << "\tsimp"<< "\tmcm" << "\tmcd" << "\t|x|" << endl << endl;
		cout << "\t s"   << "\t c" << "\t t" << "\t h" << endl;
		cout << "\tsen"<< "\tcos" << "\ttan" << "\thipo" << endl << endl;
		cout << "\t z"   << "\t k" << "\t n" << "\t r" << endl;
		cout << "\tr2(x)"<< "\tr3(x)" << "\tx^n" << "\trad" << endl << endl;
		cout << "\t g"   << "\t j " << "\t b" << "\t o" << endl;
		cout << "\tlog10"<< "\tlog2" << "\tnotC" << "\t %" << endl << endl;
		cout << endl;
		color(hConsole, 7);
		cout << "\t=  ";
		cin >> opcion;
		
		system("cls");
		cout << endl << endl;
		switch(opcion){
			case 'X':
				cout << "\tSaliendo de la calculadora...";
				break;
			case 'I':
				informacion();
				break;
			case 'M':
				menu();
				break;
			case 'T':
			 	
				break;
			case 'l':
				simplificar();
				break;
			case 'q':
				mcm();
				break;
			case 'p':
				mcd();
				break;
			case 'v':
				valorabsoluto();
				break;
			case 's':
				seno();
				break;
			case 'c':
				coseno();
				break;
			case 't':
				tangente();
				break;
			case 'h':
				hipotenusa();
				break;
			case 'z':
				raizcuadrada();
				break;
			case 'k':
				
				break;
			case 'n':
				
				break;
			case 'r':
				
				break;
			case 'g':
				break;
			case 'j':
				break;
			case 'b':
				break;
			case 'o':
				break;
		}
		cout << endl << endl << endl << endl << endl << endl << endl << "\t" << endl;
		system("pause");
		cout << endl << endl << endl;
		
	} while(opcion != 'X');
	return 0;
}
