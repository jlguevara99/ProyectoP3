#ifndef ESPADA_H
#define ESPADA_H
#include <string>
#include "Arma.h"
using namespace std;

class Espada : public Arma{
	public:
		Espada(string,string);

		//funciones de arma
		int incrementarPoder();
};

#endif
