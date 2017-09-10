#include "Cazador.h"
#include <string>
using namespace std;

Cazador::Cazador(){
	move(20,50);
	printw("Creando su Personaje");
	move(21,50);
	printw("---------------------");
	getch();
	move(22,50);
	printw("Ingrese su nombre:  ");
	char nom[25];
	getstr(nom);
	getch();
	clear();

	move(20,50);
	printw("Creando su Personaje");
	move(21,50);
	printw("--------------------");
	move(22,50);
	printw("Elija su tipo de Arma");
	move(23,50);
	printw("a. Espada");
	move(24,50);
	printw("b. Baston");
	move(25,50);
	printw("c. Chancla");
	char opcion = getch();
	while(opcion!='a' && opcion !='b' && opcion!='c'){
		clear();
		move(20,50);
		printw("Ha Ingresado una opcion invalida, pulse para continuar");
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
	printw("Ingrese la agilidad de su cazador:  ");
	char otroelem[10];
	getstr(otroelem);

	//inicializar personaje
	nombre = nom;
	vida =1100;
	agilidad = otroelem;
	clear();

}

//atacar
int Cazador::attack(){
	int numero;
	srand (time(NULL));
	numero = rand() % 6+1;
	int golpe = arma->getPoder();
	if(numero==1){
		golpe += golpe*0.5;
	}else if(numero==2){
		golpe += golpe*0.10;
	}else if(numero==3){
		golpe += golpe*0.15;
	}
	return golpe;
}

//sanar
int Cazador::heal(int pVida){
	int nueva = pVida+275;
	return nueva;	
}

//incrementar la vida
void Cazador::incrementarHP(){
	vida += 140;
}


string Cazador::getAgilidad(){
	return agilidad;
}


void Cazador::setAgilidad(string agility){
	agilidad = agility;
}