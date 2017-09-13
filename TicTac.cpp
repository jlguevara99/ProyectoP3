#include "TicTac.h"

TicTac::TicTac(){
	nombre = "X/0";
	codigo = 2;
}

string TicTac::getNombre(){
	return nombre;
}

int TicTac::getCodigo(){
	return codigo;
}

int TicTac::run(){
	clear();

	init_pair(1, COLOR_WHITE,COLOR_BLUE);
	init_pair(2, COLOR_WHITE,COLOR_RED);


	char** tablero;
	int turnos = 1;
	//provisionar matriz
	tablero = new char*[3];
	for(int i = 0; i < 3; i++) {
		tablero[i] = new char[3];
	}
	//llenar la matriz
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			tablero[i][j] = ' ';
		}
	}

	WINDOW* ventana = newwin(20,35,20,50);
	
	bool gana1 = true, gana2 = true, empate = true;

	do {
		if(turnos == 1){
			wbkgd(ventana,COLOR_PAIR(1));
			refresh();
			move(19,50);
			printw("Jugador 1");
			
			box(ventana,0,0);
			wrefresh(ventana);
			
			int x =7;
			int y =2;
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					mvwprintw(ventana,y,x,"[%c]",tablero[i][j]);
					x+=7;
				}
				y+=2;
				x=7;
			}
			getch();
			wrefresh(ventana);
			int j1Px;
			int j1Py;
			do{			
				mvwprintw(ventana,10,2,"Ingrese la posicion en x: ");
				char Px[2];
				wgetstr(ventana,Px);
				
				j1Px = atoi(Px);
				while(j1Px<0 || j1Px>=3){
					wgetstr(ventana,Px);
					j1Px = atoi(Px);
				}
				mvwprintw(ventana,11,2,"Ingrese la posicion en y: ");
				char Py[2];
				wgetstr(ventana,Py);
				
				j1Py = atoi(Py);
				while(j1Py<0 || j1Py>=3){
					wgetstr(ventana,Py);
					j1Py = atoi(Py);
				}
				if(tablero[j1Px][j1Py] != ' '){
					mvwprintw(ventana,12,2,"Ya hay algo en esa posicion");
				}
				wrefresh(ventana);
			}while(tablero[j1Px][j1Py] != ' ');
			
			tablero[j1Px][j1Py] = 'X';
			wrefresh(ventana);
			turnos = 2;
			clear();
			//turno del jugador 2
		}else if(turnos == 2){
			wbkgd(ventana,COLOR_PAIR(2));
			refresh();
			move(19,50);
			printw("Jugador 2");
			box(ventana,0,0);
			
			wrefresh(ventana);
			int x2 = 7;
			int y2 = 2;
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					mvwprintw(ventana,y2,x2,"[%c]",tablero[i][j]);
					x2+=7;
				}
				y2+=2;
				x2=7;
			}
			getch();		
			wrefresh(ventana);
			int j2Px;
			int j2Py;
			do {
				mvwprintw(ventana,10,2,"Ingrese la posicion en x: ");
				char Px2[2];
				wgetstr(ventana,Px2);
				j2Px = atoi(Px2);
				while(j2Px<0 || j2Px>=3){
					wgetstr(ventana,Px2);
					j2Px = atoi(Px2);
				}
				mvwprintw(ventana,11,2,"Ingrese la posicion en y: ");
				char Py2[2];
				wgetstr(ventana,Py2);
				j2Py = atoi(Py2);
				while(j2Py<0 || j2Py>=3){
					wgetstr(ventana,Py2);
					j2Py = atoi(Py2);
				}
				if(tablero[j2Px][j2Py] != ' '){
					mvwprintw(ventana,12,2,"Ya hay algo en esa posicion");
				}
				
			} while (tablero[j2Px][j2Py] != ' ');
			tablero[j2Px][j2Py] = 'O';
			wrefresh(ventana);

			turnos = 1;
			clear();


		}

		//validaciones para ganar(jugador 1)

		//verticales
		if(tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X'){
			gana1 = false;
		}
		if(tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X'){
			gana1 = false;
		}
		if(tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X'){
			gana1 = false;
		}

		//horizontales
		if(tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X'){
			gana1 = false;
		}
		if(tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X'){
			gana1 = false;
		}
		if(tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X'){
			gana1 = false;
		}

		//diagonales
		if(tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X'){
			gana1 = false;
		}
		if(tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X'){
			gana1 = false;
		}

		//validaciones para ganar(jugador 2)

		//verticales
		if(tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O'){
			gana2 = false;
		}
		if(tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O'){
			gana2 = false;
		}
		if(tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O'){
			gana2 = false;
		}

		//horizontales
		if(tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O'){
			gana2 = false;
		}
		if(tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O'){
			gana2 = false;
		}
		if(tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O'){
			gana2 = false;
		}

		//diagonales
		if(tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O'){
			gana2 = false;
		}
		if(tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O'){
			gana2 = false;
		}

		//verificar empate
		int conteo = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(tablero[i][j]==' '){
					conteo++;
				}
			}
		}

		if(conteo==0){
			empate = false;
		}
	} while (gana1 && gana2 && empate);

	
	// wdelete(ventana);

	//liberar la memoria de la matriz
	for(int i = 0; i < 3; i++) {
		delete[] tablero[i];
		tablero[i] = NULL;
	}
	delete [] tablero;

	if(gana1 == false){
		return 1;
	}else if(gana2 == false){
		return 2;
	}else if(empate == false){
		return 0;
	}
}


