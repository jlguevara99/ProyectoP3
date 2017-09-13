#ifndef BATALLA_H
#define BATALLA_H

#include "Minijuego.h"
#include "Jugador.h"
#include "Arma.h"
#include "Cazador.h"
#include "Titan.h"
#include "Mago.h"
#include "Espada.h"
#include "Chancla.h"
#include "Baston.h"
#include <string>

using namespace std;

class Batalla : public Minijuego{
	private:
		string nombre;
		int tipo;
		Jugador* jugador1;
		Jugador* jugador2;
	public:
		Batalla(Jugador*,Jugador*);
		int getCodigo();
		string getNombre();
		int run();

};


#endif
