#include "Espada.h"
#include<string>
using namespace std;

Espada::Espada(string pNombre, string pElemento){
	nombre = pNombre;
	poder = 100;
	elemento = pElemento;
}

//incrementar poder
int Espada::incrementarPoder(){
	poder += 25;
}
