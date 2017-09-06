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
using namespace std;

class Juego{
	private:
		int numeroJugadores;
		Jugador** jugadores;
		
	public:
		void init();
		int play();

};

#endif
