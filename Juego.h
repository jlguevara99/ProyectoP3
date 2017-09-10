#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Arma.h"
#include "Cazador.h"
#include "Mago.h"
#include "Titan.h"
#include "Chancla.h"
#include "Espada.h"
#include "Baston.h"
#include <string>
#include <ncurses.h>
#include <stdlib.h> 

using namespace std;

class Juego{
	private:
		int numeroJugadores;
		Jugador** jugadores;
		int tablero[100];
	public:
		Juego();
		void init();
		int play();
		
};

#endif
