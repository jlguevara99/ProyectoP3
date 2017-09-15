#include "Chancla.h"
#include <string>

using namespace std;

Chancla::Chancla(string pNombre, string pElemento){
	nombre = pNombre;
	poder = 180;
	elemento = pElemento;
}

//incrementar poder

string Chancla::getNombre(){
	return nombre;
}

int Chancla::incrementarPoder(){
	poder += 15;
}

int Chancla::getPoder(){
	return poder;
}

string Chancla::getElemento(){
	return elemento;
}
