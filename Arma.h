#ifndef ARMA_H
#define ARMA_H

#include <string>
#include <iostream>
using namespace std;

class Arma{
	protected:
	string nombre;
	int poder;
	string elemento;

	public:
	Arma();
	Arma(string,int,string);
	
	//funciones de armas
	virtual string getNombre();
	virtual int getPoder();
	virtual string getElemento();

	void setNombre(string);
	void setPoder(int);
	void setElemento(string);

	//funcion de arma.. incrementa el poder del arma
	virtual int incrementarPoder();

};
#endif
