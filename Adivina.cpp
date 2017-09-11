#include "Adivina.h"

Adivina::Adivina(){
	nombre = "Adivinador";
	tipo = 1;
}

string Adivina::getNombre(){
	return nombre;
}

int Adivina::getCodigo(){
	return tipo;
}

//minijuego de adivinar un numero random
int Adivina::run(){
	clear();
	
	
	bool gana1 = true, gana2 = true;
	int cont = 9;
	int turnos = 1;
	WINDOW* ventana = newwin(20,44,20,50);
	WINDOW* ventana2 = newwin(20,44,20,50);
	do {

		int numero;
		srand(time(NULL));
		numero = rand() % cont+1;
		if(turnos == 1){

		
			//WINDOW* ventana = newwin(20,40,20,50);
			refresh();
			box(ventana,0,0);
			wrefresh(ventana);
			
			
			
			mvwprintw(ventana,1,1,"Turno del jugador 1");
			mvwprintw(ventana,2,1,"Intente adivinar el numero, del 1 al %d :",cont);
			//mvwprintw(ventana,3,1,("%d",cont));
			char a[2];
			wgetstr(ventana,a);
			
			int eleccion1;
			eleccion1 = atoi(a);
			if(eleccion1 == numero){
				gana1 = false;

			}
			
			turnos = 2;
			clear();
		}else if(turnos == 2){
			//WINDOW* ventana2 = newwin(20,40,20,50);
			refresh();
			box(ventana2,0,0);
			wrefresh(ventana2);

			mvwprintw(ventana2,1,1,"Turno del jugador 2");
			mvwprintw(ventana2,2,1,"Intente adivinar el numero, del 1 al %d :",cont);
			char b[2];
			wgetstr(ventana2,b);
			int eleccion2;
			eleccion2 = atoi(b);
			if(eleccion2 == numero){
				gana2 = false;
			}
			turnos = 1;
			clear();
			
		}
		

		if(cont>3){
			cont--;
		}
	} while (gana1 && gana2);
		if(gana1 == false){
			return 1;
		}else if(gana2 == false){
			return 2;
		}else{
			return 0;
		}
	delete ventana;
	delete ventana2;
}
