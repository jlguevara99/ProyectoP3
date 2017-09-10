#ifndef MAGO_H
#define MAGO_H
#include<string>
#include "ncurses.h"
#include"Jugador.h"
#include"Arma.h"
#include"Espada.h"
#include"Baston.h"
#include"Chancla.h"

using namespace std;
//Clase mago hereda de jugador
class Mago : public Jugador{
	private:
		string element;				
	public:
		Mago();
		string getElement();
		void setElement(string);

		//funciones de personaje
		int attack();
		int heal(int);
		void incrementarHP();
};

#endif
