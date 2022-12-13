// jajanoseprogramar.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std; 
void intento(int* putero, vector<int> &si, int* puntero2);
int divisiondeunidades(int i);
int main()
{
	
	int option;	
	int nuevopuntero;
	vector<int> mientenme;
	int* puntero;
	int* puntero2;

	for (int i=0; i < 8; i++) {

		cout << "deme el numero " << i + 1 << endl;
		cin >> option;
		mientenme.push_back(option);
	}
	puntero = &mientenme[0];
	intento(puntero, mientenme);
	cout <<" La posicion de memoria es: " << puntero<<"pocision del vector:"<< *puntero2 << endl;
	
}

void intento(int* puntero, vector <int>& si, int *puntero2) {
	puntero= &si[0];
	int azul = si[0];
	
	for (int i = 0; i < si.size(); i++) {
		
		
	
		
		if (divisiondeunidades(si[i]) <= divisiondeunidades(*puntero)) {
			puntero= &si[i];
			*puntero2 = i;
		}

	}
	

}
int divisiondeunidades(int i) {
	int unidad = 0;
	int decena = 0;
	int centena = 0;
	int milesima = 0;
	int contador = 0;
	unidad = (i % 10) / 1;
	decena = (i % 100) / 10;
	centena = (i % 1000) / 100;
	milesima = (i % 10000) / 1000;
	if ((unidad % 2) == 0) {
		contador++;
	}
	if ((decena % 2) == 0) {
		contador++;
	}
	if ((centena % 2) == 0) {
		contador++;
	}
	if ((milesima % 2) == 0) {
		contador++;
	}
	
	return contador;
}