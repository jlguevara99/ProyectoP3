#ifndef TICTAC_H
#define TICTAC_H

#include <string>
#include "Minijuego.h"
using namespace std;

class TicTac : public Minijuego{
	private:
		string nombre;
		int codigo;

	public:
		TicTac();
		string getNombre();
		int getCodigo();
		int run();
		

};

#endif
