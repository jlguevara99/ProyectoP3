#include "Jugador.h"
#include "Arma.h"
#include "Mago.h"
#include "Titan.h"
#include "Cazador.h"
#include "Chancla.h"
#include "Espada.h"
#include "Baston.h"
#include "Juego.h"
#include "Minijuego.h"
#include "Adivina.h"
#include "Busca.h"
#include "TicTac.h"
#include "Ahorcado.h"
#include "Batalla.h"

#include <stdlib.h>
#include <ncurses.h>
#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;
int main(){
//wbkgd(ventana,colorpair);	
	initscr();
	start_color();
//		noecho();
		
		Jugador* m = new Titan();
		getch();
		Jugador* x = new Mago();
		getch();
		/*WINDOW* win = newwin(10,10,20,20);
		refresh();
		char c = '*';
		int i = (int)c;
		box(win,i,i);
		mvwprintw(win,1,1,"this is my box");
		wrefresh(win);*/
		
		
		//cosa para castear
		/*if(typeid(*m)==typeid(Cazador)){
			
			Cazador* ca = dynamic_cast<Cazador*>(m);
			printw("%d",ca->attack());
		}*/
	//	printw("%d",m->attack());

	//Juego* juego = new Juego();
	//juego->init();
		//int asa = x->attack();
//		int xx = m->attack();

		
		Minijuego* juego = new Batalla(m,x);
		clear();
		int a = juego->run();
		move(2,2);
		printw("%d",a);

		getch();
		move(1,1);
		printw("si");
		getch();
	endwin();
	delete juego;
	delete m;
	delete x;
	return 0;
}
