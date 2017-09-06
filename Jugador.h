#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>
#include "Arma.h"
using namespace std;



class Jugador{
	
	protected:
		string nombre;
		Arma* arma;
		int vida;
		
	public:
		Jugador();
		Jugador(string,Arma*,int);
		
		//getters
		string getNombre();
		int getVida();
		Arma* getArma();

		//setters
		void setNombre(string);
		void setVida(int);
		void setArma(Arma*);
};





#endif
