#include "Mago.h"
#include "Arma.h"
Mago::Mago(){
	move(20,50);
	printw("Creando su Personaje: ");
	move(21,50);
	
	printw("--------------------");
	move(22,50);
	printw("Ingrese su nombre: ");
	char nom[25];
	getstr(nom);
	getch();
	clear();

	move(20,50);
	printw("Creando su Personaje");
	move(21,50);
	printw("--------------------");
	move(22,50);
	printw("Elija su tipo de Arma:  ");
	move(23,50);
	printw("a. Espada");
	move(24,50);
	printw("b. Baston");
	move(25,50);
	printw("c. Chancla");
	char opcion = getch();
	getch();
	while(opcion!='a' && opcion !='b' && opcion!='c'){
		clear();
		move(20,50);
		printw("Ha ingresado una opcion invalida, pulse para continuar");
		getch();
		move(20,50);
		printw("Creando su Personaje");
	    move(21,50);
	    printw("--------------------");
		move(22,50);
		printw("Elija su tipo de Arma: ");
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
	}else if(opcion=='b'){
		Arma* nueva = new Baston(arm,elem);
		arma = nueva;
	}else if(opcion == 'c'){
		Arma* nueva = new Chancla(arm,elem);
		arma = nueva;
	}
	clear();
	move(20,50);
	printw("Ingrese el elemento de su mago:  ");
	char otroelem[25];
	getstr(otroelem);

	//inicializar Personaje
	nombre = nom;
	
	vida = 1250;
	element = otroelem;
	clear();
}

string Mago::getElement(){
	return element;
}

void Mago::setElement(string pElement){
	element = pElement;
}
