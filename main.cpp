#include "Jugador.h"
#include "Arma.h"
#include "Mago.h"
#include "Titan.h"
#include "Cazador.h"
#include "Chancla.h"
#include "Espada.h"
#include "Baston.h"
#include "Juego.h"
#include <ncurses.h>

#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;
int main(){
	
	initscr();
//		noecho();
		
	//	Jugador* m = new Cazador();
	//	getch();
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

	Juego* juego = new Juego();
	juego->init();
	
		getch();
		move(1,1);
		printw("si");
		getch();
	endwin();
	delete juego;

	return 0;
}
