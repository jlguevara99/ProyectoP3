#ifndef BUSCA_H
#define BUSCA_H

#include "Minijuego.h"
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Busca : public Minijuego{
	private:
		string nombre;
		int tipo;
	public:
		Busca();
		string getNombre();
		int getCodigo();
		int run();

};


#endif
