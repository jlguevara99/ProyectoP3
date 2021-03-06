#ifndef TITAN_H
#define TITAN_H
#include <string>
#include "Jugador.h"
#include "Arma.h"
#include "Baston.h"
#include "Espada.h"
#include "Chancla.h"
#include "ncurses.h"
using namespace std;

class Titan : public Jugador{
	private:
		string fuerza;
	public:
		Titan();
		Titan(string, Arma*);
		string getFuerza();
		void setFuerza(string);
		int getVida();
		//funciones de personaje
		int heal(int);
		int attack();
		void incrementarHP();

		int super();
};


#endif

