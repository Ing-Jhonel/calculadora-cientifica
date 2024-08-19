#include "funcionescalculadora.h"
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int numerocolorletra=7;
int numerocolores=7;

void informacion(){
	
	cout << "\tInformacion de la calculadora:" << endl << endl;
	cout << "\tModelo: CASIO 2024." << endl;
	cout << "\tAño: 2024." << endl;
	cout << "\tCreador: Jhonel Gerson Apaza Pacompia." << endl << endl;
	cout << "\tDerechos reservados UNJBG-TACNA." << endl << endl;
	cout << "\tOperadores matematicos:" << endl << endl;
	cout << "\t+ = suma" << endl << "\t- = resta" << endl << "\t* = multiplicacion" << endl << "\t/ = division";
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
		if(0<=0) cin.ignore();
		getline(cin, respuesta);
		
		tamanorespuesta=respuesta.length();
		
		system("cls");
		cout << endl << endl<< endl;
		cout << "\t\t";
		if(tamanorespuesta<=10){
			valido = false;
		} else if (tamanorespuesta<=24){
			cout << "Elija el color del fondo de pantalla" << endl << endl;
			int j=1;
			for(int i=numerocolorletra; i<242; i+=16){
				color(hConsole, i);
				cout << "\tColor " << j;
				color(hConsole, 7);
				cout << endl << endl;
				j++;
			}
			
			do{
				color(hConsole, 7);
				cout << endl << endl << "\t=";
				cin >> numero;
				if(numero <=15 && numero > 0){
						// simplificacion de N*n + (15-N+1)(n-1) = numerocolor*numero+(15-numerocolor+1)(numero-1)
					// N+16(n-1)
					numerocolores=numerocolorletra+16*(numero-1);
					color(hConsole, numerocolores);
				} else {
					color(hConsole, 4);
					cout << endl << "\tIngrese un numero valido." << endl << endl;
				}
			} while(numero >15 || numero <= 0);
			
		} else if (tamanorespuesta<=34){
			valido = false;
		} else if (tamanorespuesta<=45){
			cout << "Elija el color de letra" << endl << endl;
			for(int i=1; i<=15; i++){
				color(hConsole, i);
				cout << "\tColor " << i;
				color(hConsole, 7);
				cout << endl << endl;
			}
			
			do{
				
				int aux=numerocolorletra;
				
				cout << endl << endl << "\t=";
				cin >> numerocolorletra;
				
				int diferencia=numerocolorletra-aux;
				numerocolores=numerocolores+diferencia;
				
				if(numerocolorletra <= 15  && numerocolorletra > 0){
					color(hConsole, numerocolores);
				}else{
					color(hConsole, 4);
					cout << endl << "\tIngrese un numero valido." << endl << endl;
				}
			} while (numerocolorletra > 15  && numerocolorletra <= 0);
		
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
		
		if(!valido){
			cout << "Indique una opcion valida." << endl;
		}
		
		cout << endl << endl<< endl << endl;
		if(!salir){
			system("pause");
		}
	} while(!salir);
}

void simplificar(){
	
	string expresion;
	int numerador;
	int denominador;
	int mcd;
	cout << endl << "\t\tSIMPLIFICACION DE FRACCIONES" << endl;
	cout << 				"\t\t____________________________" << endl << endl;
	cout << "\tIndique su fraccion" << endl << endl;
	cout << "    Nominador ->  ";
	cin >> numerador;
	cout << "                 ------";
	cout << endl;
	cout << "  Denominador ->  ";
	cin >> denominador;
	
	while (denominador == 0) {
		color(hConsole, 4);
        cout << endl << "\tEl denominador no puede ser 0. Por favor, ingrese un denominador valido." << endl << endl;
        color(hConsole, 6);
        cout << "\tCorrija su fraccion" << endl << endl;
        cout << "    Numerador ->  " << numerador << endl;
        cout << "                 ------" << endl;
        cout << "  Denominador ->  ";
        cin >> denominador;
    }
	color(hConsole, 7);
    // Guardar los valores originales para la simplificación
    int numOriginal = numerador;
    int denOriginal = denominador;

    // Calcular el MCD usando el algoritmo de Euclides
    while (denominador != 0) {
        int aux = denominador;
        denominador = numerador % denominador;
        numerador = aux;
    }

    // El MCD es ahora el valor de numerador
    mcd = numerador;

    // Simplificar la fracción dividiendo por el MCD
    numOriginal = numOriginal/mcd;
    denOriginal = denOriginal/mcd;
    
    cout << endl << endl << endl << "\tFraccion final:" << endl << endl << endl;
    cout << "\t\t    " << numOriginal << endl;
    cout << "\t\t  " << "------" << endl;
    cout << "\t\t    " << denOriginal << endl << endl;
	
}

void mcm(){
	int numero1, numero2;
	cout << "\tIndique el primer numero: ";
	cin >> numero1;
	cout << endl;
	cout << "\tIndique el segundo numero: ";
	cin >> numero2;
	
	int a=numero1;
	int b=numero2;
	
	while(b!=0){
		int aux=b;
		b=a%b;
		a=aux;
	}
	
	int mcd=a;
	
	int mcm=(numero1*numero2)/mcd;
	
	cout << endl << endl << endl << "\tEl minimo comun multiplo (mcm) de " << numero1 << " y " << numero2 << " es --> " << mcm;
}

void mcd(){
	
	int numero1, numero2;
	cout << "\tIndique el primer numero: ";
	cin >> numero1;
	cout << endl;
	cout << "\tIndique el segundo numero: ";
	cin >> numero2;
	
	int a=numero1;
	int b=numero2;
	
	while(b!=0){
		int aux=b;
		b=a%b;
		a=aux;
	}
	
	int mcd=a;
	
	cout << endl << endl << endl << "\tEl maximo comun divisor (mcd) de " << numero1 << " y " << numero2 << " es --> " << mcd;
}

void valorabsoluto(){
	
	int numero;
	cout << "\tIndique un numero: ";
	cin >> numero;
	cout << endl;
	
	cout << "\tEl valor absoluto de " << numero << " es --> ";
	if(numero >= 0){
		cout << numero;
	} else {
		cout << -numero;
	}
	
}

void seno(){
	
	double anguloGrados;
	double anguloRadianes;
	double seno;
	
	cout << "\tIndique su angulo en grados: ";
	cin >> anguloGrados;
	
	anguloRadianes= anguloGrados*(M_PI/180.0);
	seno = sin(anguloRadianes);
	cout << endl << endl;
	cout << "\tSeno(" << anguloGrados << ") = " << seno;
	
}

void coseno(){
	
	double anguloGrados;
	double anguloRadianes;
	double coseno;
	
	cout << "\tIndique su angulo en grados: ";
	cin >> anguloGrados;
	
	anguloRadianes= anguloGrados*(M_PI/180.0);
	coseno = cos(anguloRadianes);
	cout << endl << endl;
	cout << "\tCoseno(" << anguloGrados << ") = " << coseno;
}

void tangente(){
	
	double anguloGrados;
	double anguloRadianes;
	double tangente;
	
	cout << "\tIndique su angulo en grados: ";
	cin >> anguloGrados;
	
	anguloRadianes= anguloGrados*(M_PI/180.0);
	tangente = tan(anguloRadianes);
	cout << endl << endl;
	cout << "\tTangente(" << anguloGrados << ") = " << tangente;
}

void hipotenusa(){
	cout << "          *" << endl;;
	cout << "          **" << endl;
	cout << "          *  *" << endl;
	cout << "      CA1 *    *" << endl;
	cout << "          *      *" << endl;
	cout << "          *        *" << endl;
	cout << "          * * * * *  *" << endl;
	cout << "               CA2" << endl << endl;
	
	char respuesta;
	cout << "\t¿Su triangulo es un triangulo rectangulo?(s/n): ";
	cin >> respuesta;
	
	cout << endl << endl;
	int cateto1;
	int cateto2;
	int hipotenusa;
	switch(respuesta){
		case 's':
			cout << "\tCateto 1: ";
			cin >> cateto1;
			cout << endl;
			cout << "\tCateto 2: ";
			cin >> cateto2;
			
			hipotenusa = sqrt((cateto1*cateto1)+(cateto2*cateto2));
			
			cout << endl << endl << "\tHipotenusa --> " << hipotenusa;
			break;
		case 'n':
			cout << "\tLa hipotenusa solo aplica a triangulos rectangulos."	;
			break;
	}

}

void raizcuadrada(){
	
	double numero;
	cout << "\tIndique un numero: ";
	cin >> numero;
	cout << endl << endl << endl;
	cout << "\tLa raiz cuadrada de " << numero << " es --> " << sqrt(numero);
}


void raizcubica(){
	
	double numero;
	cout << "\tIndique un numero: ";
	cin >> numero;
	cout << endl << endl << endl;
	cout << "\tLa raiz cubica de " << numero << " es --> " << cbrt(numero);
}

void exponenciacion(){
	
	double numero;
	double exponente;
	cout << "\tIndique un numero: ";
	cin >> numero;
	cout << endl << endl;
	cout << "\tIndique el exponente: ";
	cin >> exponente;
	cout << endl << endl << endl;
	cout << "\t" << numero << " elevado a la " << exponente << " es --> " << pow(numero, exponente);
}

void radianes(){
	
	double anguloGrados;
	double anguloRadianes;
	cout << "\tIndique el angulo en grados: ";
	cin >> anguloGrados;
	anguloRadianes = anguloGrados*(M_PI/180.0);
	cout << endl << endl;
	cout << "\tEl angulo " << anguloGrados << " en radiantes es --> " << anguloRadianes;
	
}

void logaritmo10(){
	
	double numero;
    double logBase10;
    cout << "\tIngrese un numero: ";
    cin >> numero;
    logBase10 = log10(numero);
    cout << endl << endl << endl;
    cout << "\tEl logaritmo base 10 de " << numero << " es --> " << logBase10 << endl;
	
}

void logaritmo2(){
	
	double numero;
    double logBase2 ;
    cout << "\tIngrese un numero: ";
    cin >> numero;
    logBase2  = log2(numero);
    cout << endl << endl << endl;
    cout << "\tEl logaritmo base 2 de " << numero << " es --> " << logBase2 << endl;
	
}

