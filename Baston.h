#ifndef BASTON_H
#define BASTON_H
#include "Arma.h"
#include <string>
using namespace std;

class Baston : public Arma{
	public:
		Baston(string,string);

		//funciones de arma
		int getPoder();
		int incrementarPoder();
		string getElemento();
		string getNombre();

		void setPoder(int);
};

#endif
