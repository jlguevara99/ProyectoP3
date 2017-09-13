#include "Batalla.h"

Batalla::Batalla(Jugador* jug1, Jugador* jug2){
	jugador1 = jug1;
	jugador2 = jug2;
	nombre = "Batalla";
	tipo = 5;
}

int Batalla::getCodigo(){
	return tipo;
}

string Batalla::getNombre(){
	return nombre;
}

int Batalla::run(){
	//batalla ente ambos jugadores
	clear();
	WINDOW* ventana = newwin(20,35,20,50);
	refresh();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_WHITE,COLOR_RED);
	//valores de jugadores
	string nombre1 = jugador1->getNombre();
	string nombre2 = jugador2->getNombre();
	int vida1 = jugador1->getVida();
	int vida2 = jugador2->getVida();
	int turnos = 1;
	bool gana1 = true, gana2 = true;
	move(10,10);
	getch();
	do {
		if(turnos == 1){
			clear();
			wbkgd(ventana,COLOR_PAIR(1));
			move(19,50);
			printw("Turno de: %s",nombre1.c_str());
			refresh();
			box(ventana,0,0);
			wrefresh(ventana);
			mvwprintw(ventana,2,2,"%s -> %d",nombre1.c_str(),vida1);
			mvwprintw(ventana,3,2,"%s -> %d",nombre2.c_str(),vida2);
			
			mvwprintw(ventana,7,2,"Ingrese la opcion, %s: ",nombre1.c_str());
			mvwprintw(ventana,8,2,"1. Atacar");
			mvwprintw(ventana,9,2,"2. Regenerar Salud ");
			wrefresh(ventana);
			char opci[2];
			wgetstr(ventana,opci);
			int opcion;
			opcion = atoi(opci);
			//cambiar por enteros
			if(opcion == 1){
				vida2 -= jugador1->attack();
			}else if(opcion == 2){
				vida1 = jugador1->heal(vida1);
			}

			if(vida2 <= 0){
				gana1 = false;
				break;
			}
			turnos = 2;
			wclear(ventana);
			clear();
			wrefresh(ventana);
		}else if(turnos == 2){
			clear();
			wbkgd(ventana,COLOR_PAIR(2));
			move(19,50);
			printw("Turno de: %s",nombre2.c_str());
			refresh();
			box(ventana,0,0);
			wrefresh(ventana);
			mvwprintw(ventana,2,2,"%s -> %d",nombre1.c_str(),vida1);
			mvwprintw(ventana,3,2,"%s -> %d",nombre2.c_str(),vida2);
			
			mvwprintw(ventana,7,2,"Ingrese la opcion, %s: ",nombre2.c_str());
			mvwprintw(ventana,8,2,"1. Atacar");
			mvwprintw(ventana,9,2,"2. Regenerar Salud ");
			wrefresh(ventana);
			char opci2[2];
			wgetstr(ventana,opci2);
			int opcion2 = atoi(opci2);
			if(opcion2 == 1){
				vida1 -= jugador2->attack();
			}else if(opcion2 == 2){
				vida2 = jugador1->heal(vida2);
			}
			if(vida1 <= 0){
				gana2 = false;
			}
			turnos = 1;
			wclear(ventana);
			clear();
			wrefresh(ventana);
		}
	} while (gana1 && gana2);

	//verificar ganador
	if(gana1 == false){
		return 1;
	}else if(gana2 == false){
		return 2;
	}else{
		return 0;
	}
}
