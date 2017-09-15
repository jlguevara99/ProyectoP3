#ifndef JUGADOR_H
#define JUGADOR_H

#include <stdlib.h>
#include <time.h>
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

		//hacer puro
		virtual int getVida()=0;
		//
		Arma* getArma();

		//setters
		void setNombre(string);
		void setVida(int);
		void setArma(Arma*);

		//funciones de jugador
		virtual int attack();
		virtual int heal(int);	
		virtual void incrementarHP();
		
};





#endif
