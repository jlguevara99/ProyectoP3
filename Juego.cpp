#include "Juego.h"

Juego::Juego(){
	jugadores = NULL;
	numeroJugadores = 0;
	
}

//inicializa el tablero
void Juego::init(){
	jugadores = new Jugador*[2];
	/*WINDOW* menu =newwin(20,20,20,50);
	box(menu,0,0);
	refresh();
	keypad(menu,true);
	wrefresh(menu);
	string clases[3] = {"Cazador","Mago","Titan"};
	int eleccion=0;
	int opcion;*/
	for(int j = 0; j < 2; j++) {
		move(19,50);
		printw("Jugador %d",j+1);
		WINDOW* menu = newwin(20,20,20,50);
		box(menu,0,0);
		refresh();
		keypad(menu,true);
		wrefresh(menu);
		int eleccion=0;
		int opcion;
		string clases[3] = {"Cazador","Mago","Titan"};
		while(1){
			for(int i = 0; i < 3; i++) {
				if(i == eleccion)
					wattron(menu, A_REVERSE);
	
					mvwprintw(menu,i+1,1,clases[i].c_str());
					wattroff(menu, A_REVERSE);
				
			}
			opcion = wgetch(menu);
	
			switch(opcion){
				case KEY_UP:
					eleccion--;
					if(eleccion == -1){
						eleccion = 0;
					}
					break;
				case KEY_DOWN:
					eleccion++;
					if(eleccion == 3){
						eleccion = 2;
					}
					break;
				default:
					break;
			}
			if(opcion == 10)
				break;
		}
		clear();	
		//inicilizar cada jugador
		if(eleccion == 0){
			jugadores[j] = new Cazador();
		}else if(eleccion == 1){
			jugadores[j] = new Mago();
		}else{
			jugadores[j] = new Titan();
		}


	}//fin del for principal
	
}

int Juego::play(){




	return 0;
}

