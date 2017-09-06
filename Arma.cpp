#include "Arma.h"
#include <string>
using namespace std;

Arma::Arma(){
	
}

Arma::Arma(string pNombre, int mPoder,string pElemento){
	nombre = pNombre;
	poder = mPoder;
	elemento = pElemento;
}

string Arma::getNombre(){
	return nombre;
}

int Arma::getPoder(){
	return poder;
}

string Arma::getElemento(){
	return elemento;
}

void Arma::setNombre(string pNombre){
	nombre = pNombre;
}

void Arma::setPoder(int mPoder){
	poder = mPoder;
}

void Arma::setElemento(string pElemento){
	elemento = pElemento;
}
