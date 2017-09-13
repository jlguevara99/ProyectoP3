#ifndef MINIJUEGO_H
#define MINIJUEGO_H

#include <stdlib.h>
#include <ncurses.h>
#include <string>
#include <typeinfo>
using namespace std;
class Minijuego{

	public:
		virtual string getNombre() =0;
		virtual int getCodigo() =0;
		virtual int run() =0;
};

#endif
