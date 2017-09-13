#ifndef CAZADOR_H
#define CAZADOR_H
#include <string>
#include "Jugador.h"
#include "Arma.h"
#include "Baston.h"
#include "Espada.h"
#include "Chancla.h"
#include "ncurses.h"
using namespace std;

class Cazador : public Jugador{
	private:
		string agilidad;
	public:
		Cazador();
		Cazador(string,Arma*);
		string getAgilidad();
		void setAgilidad(string);

		//funcion atacar
		int attack();
		int heal(int);
		void incrementarHP();
};

#endif
