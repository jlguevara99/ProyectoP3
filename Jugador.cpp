#include "Jugador.h"
#include <string>
#include <iostream>

using namespace std;

Jugador::Jugador(){

}

void Jugador::incrementarHP(){
	vida = 0;
}

int Jugador::attack(){
	return 2;
}

int Jugador::heal(int pvida){
	return 0;
}

Jugador::Jugador(string pNombre,Arma* pArma, int pVida){
	nombre = pNombre;
	arma = pArma;
	vida = pVida;
}

string Jugador::getNombre(){
	return nombre;
}

int Jugador::getVida(){
	return vida;
}

Arma* Jugador::getArma(){
	return arma;
}

void Jugador::setNombre(string pNombre){
	nombre = pNombre;
}

void Jugador::setVida(int pVida){
	vida = pVida;
}

void Jugador::setArma(Arma* pArma){
	arma = pArma;
}
