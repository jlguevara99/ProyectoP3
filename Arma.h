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
	
	string getNombre();
	int getPoder();
	virtual string getElemento();

	void setNombre(string);
	void setPoder(int);
	void setElemento(string);


	virtual int incrementarPoder();

};
#endif
