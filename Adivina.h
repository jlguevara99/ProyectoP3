#ifndef ADIVINA_H
#define ADIVINA_H

#include <time.h>
#include <stdlib.h>
#include "Minijuego.h"
#include <string>

using namespace std;

class Adivina : public Minijuego{
	private:
		string nombre;
		int tipo;
	public:
		Adivina();
		string getNombre();
		int getCodigo();
		int run();


};

#endif
