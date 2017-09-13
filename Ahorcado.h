#ifndef AHORCADO_H
#define AHORCADO_H

#include "Minijuego.h"
#include <string>
using namespace std;

class Ahorcado : public Minijuego{
		private:
			string nombre;
			int tipo;
		public:
			Ahorcado();
			string getNombre();
			int getCodigo();
			int run();
};

#endif
