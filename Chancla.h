#ifndef CHANCLA_H
#define CHANCLA_H

#include "Arma.h"

#include <string>

using namespace std;

class Chancla : public Arma{
	public:
		Chancla(string,string);

		//funciones de arma
		int incrementarPoder();
		string getElemento();
};

#endif
