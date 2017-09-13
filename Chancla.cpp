#include "Chancla.h"
#include <string>

using namespace std;

Chancla::Chancla(string pNombre, string pElemento){
	nombre = pNombre;
	poder = 180;
	elemento = pElemento;
}

//incrementar poder

int Chancla::incrementarPoder(){
	poder += 15;
}

string Chancla::getElemento(){
	return elemento;
}
