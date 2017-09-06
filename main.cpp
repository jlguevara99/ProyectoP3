#include "Jugador.h"
#include "Arma.h"
#include "Mago.h"
#include "Titan.h"
#include "Cazador.h"
#include "Chancla.h"
#include "Espada.h"
#include "Baston.h"
#include "typeinfo"
#include "ncurses.h"

#include <string>
#include <iostream>

using namespace std;
int main(){
	
	initscr();
		Jugador* m = new Titan();
		getch();
		move(1,1);
		printw("si");
		getch();
	endwin();
	delete m;

	return 0;
}
