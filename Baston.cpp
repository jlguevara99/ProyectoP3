#include "Baston.h"
#include <string>
using namespace std;

Baston::Baston(string pNombre,string pElemento){
	nombre = pNombre;
	poder = 130;
	elemento = pElemento;
}

//incrementar poder
int Baston::incrementarPoder(){
	poder += 20;
}
