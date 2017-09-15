#include "Juego.h"

int main(){
	initscr();
	start_color();
	Juego* game = new Juego(2);
	game->RUN();
	endwin();
	delete game;
	return 0;
}
