#include "Espada.h"
#include<string>
using namespace std;

Espada::Espada(string pNombre, string pElemento){
	nombre = pNombre;
	poder = 100;
	elemento = pElemento;
}

string Espada::getNombre(){
	return nombre;
}

//incrementar poder
int Espada::incrementarPoder(){
	poder += 25;
}

int Espada::getPoder(){
	return poder;
}

string Espada::getElemento(){
	return elemento;
}
