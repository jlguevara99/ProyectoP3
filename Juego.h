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
#include "Minijuego.h"
#include "Adivina.h"
#include "Busca.h"
#include "TicTac.h"
#include "Ahorcado.h"
#include "Batalla.h"
#include <string>
#include <ncurses.h>
#include <stdlib.h> 
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <time.h>
using namespace std;

class Juego{
	public:
		int numeroJugadores;
		Jugador** jugadores;
		
		int posicion1;
		int posicion2;
	//public:
		Juego(int);
		Juego(int,int,Jugador*,Jugador*);
		void init(int);
		
		int play();
		int RUN();


		friend ostream& operator<<(ostream&,const Juego&);

		friend istream& operator>>(istream&, Juego&);
		
};

#endif
