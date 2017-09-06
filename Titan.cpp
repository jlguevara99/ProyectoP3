#include "Titan.h"

#include <string>
using namespace std;

Titan::Titan(){
	getch();
	move(20, 50);
	printw("Creando Su Personaje");
	move(21, 50);
	printw("---------------------");
	move(22, 50);
	printw("Ingrese su nombre:  ");
	char nom[25];
	getstr(nom);
	clear();
	
	move(20, 50);
	printw("Creando su Personaje");
	move(21, 50);
	printw("---------------------");
	move(22, 50);
	printw("Elija su tipo de Arma");
	move(23, 50);
	printw("a. Espada");
	move(24, 50);
	printw("b. Baston");
	move(25, 50);
	printw("c. Chancla");
	char opcion = getch();
	while(opcion!='a' && opcion !='b' && opcion!='c'){
		clear();
		move(20,50);
		printw("Ha ingresado una opcion invalida, pulse para continuar");
		getch();
		clear();
		move(20,50);
		printw("Creando su Personaje");
		move(21,50);
		printw("---------------------");
		move(22,50);
		printw("Elija su tipo de Arma:  ");
		move(23,50);
		printw("a. Espada");
		move(24,50);
		printw("b. Baston");
		move(25,50);
		printw("c. Chancla");
		opcion = getch();
	}
	clear();
	move(20,50);
	printw("Ingrese el nombre de su arma:  ");
	char arm[40];
	getstr(arm);
	clear();
	move(20,50);
	printw("Ingrese el elemento de su arma:  ");
	char elem[40];
	getstr(elem);

	if(opcion=='a'){
		Arma* nueva = new Espada(arm,elem);
		arma = nueva;
		delete nueva;
	}else if(opcion=='b'){
		Arma* nueva = new Baston(arm,elem);
		arma = nueva;
		delete nueva;
	}else if(opcion=='c'){
		Arma* nueva = new Chancla(arm,elem);
		arma = nueva;
		delete nueva;
	}
	clear();
	move(20,50);
	printw("Ingrese la fuerza del Titan:  ");
	char fuerz[10];
	getstr(fuerz);

	//inicializar
	nombre = nom;
	vida = 1350;
	fuerza = fuerz;
	clear();
	

}
	
string Titan::getFuerza(){
	return fuerza;
}

void Titan::setFuerza(string pFuerza){
	fuerza = pFuerza;
}
