#include "Titan.h"

#include <string>
using namespace std;

int Titan::super(){
	return 400;
}


Titan::Titan(){
/*	WINDOW* win = newwin(10,10,10,10);
	refresh();
	box(win,0,0);
	mvwprintw(win,1,1,"hallo");
	wrefresh(win);*/
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
		
	}else if(opcion=='b'){
		Arma* nueva = new Baston(arm,elem);
		arma = nueva;
		
	}else if(opcion=='c'){
		Arma* nueva = new Chancla(arm,elem);
		arma = nueva;
	
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

Titan::Titan(string pNombre, Arma* pArma){
	nombre = pNombre;
	vida = 1350;
	fuerza = ".";
	arma = pArma;
}


int Titan::getVida(){
	return vida;
}
//atacar
int Titan::attack(){

	srand(time(NULL));
	int numero = rand() % 8+1;
	int golpe = arma->getPoder();
	if(numero == 6){
		golpe += golpe*0.13; 
	}else if(numero == 4){
		golpe += golpe*0.16;
	}else if(numero == 1){
		golpe += golpe*0.8;
	}
	return golpe;
}

//sanar
int Titan::heal(int pVida){
	int nueva = pVida +25;
	return nueva;
}

//incrementar vida
void Titan::incrementarHP(){
	vida += 125;
}

string Titan::getFuerza(){
	return fuerza;
}

void Titan::setFuerza(string pFuerza){
	fuerza = pFuerza;
}
