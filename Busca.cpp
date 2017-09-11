#include "Busca.h"

Busca::Busca(){
	nombre = "Busca Exoticas";
	tipo = 3;
}

string Busca::getNombre(){
	return nombre;
}

int Busca::getCodigo(){
	return tipo;
}

int Busca::run(){
	clear();
	char** referencia;
	char** tablero;

	referencia = new char*[4];
	tablero = new char*[4];
	for(int i = 0; i < 4; i++) {
		referencia[i] = new char[4];
		tablero[i] = new char[4];
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0;j < 4; j++) {
			int numero;
			srand(time(NULL));
			numero = rand() % 3+1;
			if(numero==1 || numero ==2){
				referencia[i][j] = 'x';
			}else{
				referencia[i][j] = '.';
			}
			tablero[i][j] = '.';
		}
	}

	WINDOW* ventana = newwin(20,35,20,50);

	bool gana1 = true, gana2 = true;

	int turnos = 1;
	do {
		clear();
		if(turnos==1){
			refresh();
			move(19,50);
			printw("Jugador 1");
			box(ventana,0,0);
			wrefresh(ventana);
			
			int x = 7;
			int y = 2;
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					mvwprintw(ventana,y,x,"[%c]",tablero[i][j]);
					x+=7;
				}
				y+=2;
				x=7;
			}
			getch();
			wrefresh(ventana);

			int jx1;
			int jy1;
			
			//pedir valores
			char px1[2];
			mvwprintw(ventana,10,2,"Ingrese la posicion en x: "    );
			wgetstr(ventana,px1);

			jx1 = atoi(px1);
			while(jx1<0 || jx1>=4){
				wgetstr(ventana,px1);
				jx1 = atoi(px1);
			}

			char py1[2];
			mvwprintw(ventana,11,2,"Ingrese la posicion en y: "    );
			wgetstr(ventana,py1);
			jy1 = atoi(py1);
			while(jy1<0 || jy1 >=4){
				wgetstr(ventana,py1);
				jy1 = atoi(py1);
			}
			if(referencia[jx1][jy1] == 'x'){
				gana2 = false;
			}else{
				tablero[jx1][jy1] = 'o';
			}
			wrefresh(ventana);

			turnos = 2;
			clear();
		}else if(turnos==2){
			refresh();
			move(19,50);
			printw("Jugador 2");
			box(ventana,0,0);
			wrefresh(ventana);
			
			int x1=7;
			int y1=2;
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					mvwprintw(ventana,y1,x1,"[%c]",tablero[i][j]);
					x1+=7;
				}
				x1=7;
				y1+=2;
			}
			getch();
			wrefresh(ventana);

			int x2;
			int y2;
			
			mvwprintw(ventana,10,2,"Ingrese la posicion en x: "        );
			char xx[2];
			wgetstr(ventana,xx);

			x2 = atoi(xx);
			while(x2<0 || x2>=4){
				wgetstr(ventana,xx);
				x2 = atoi(xx);
			}

			mvwprintw(ventana,11,2,"Ingrese la posicion en y: "        );
			char yy[2];
			wgetstr(ventana,yy);

			y2 = atoi(yy);
			while(y2<0 || y2>=4){
				wgetstr(ventana,yy);
				y2 = atoi(yy);
			}

			if(referencia[x2][y2] == 'x'){
				gana1 = false;
			}else{
				tablero[x2][y2] = 'o';
			}
			wrefresh(ventana);
			turnos = 1;
			clear();
		}
	} while (gana1 && gana2);

	if(gana1 == false){
		return 1;
	}else if(gana2 == false){
		return 2;
	}
}
