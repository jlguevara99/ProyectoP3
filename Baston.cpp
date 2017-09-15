#include "Baston.h"
#include <string>
using namespace std;

Baston::Baston(string pNombre,string pElemento){
	nombre = pNombre;
	poder = 130;
	elemento = pElemento;
}

string Baston::getNombre(){
	return getNombre();
}

//incrementar poder
int Baston::incrementarPoder(){
	poder += 20;
}

int Baston::getPoder(){
	return poder;
}

string Baston::getElemento(){
	return elemento;
}
