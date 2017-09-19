#include "Ahorcado.h"

Ahorcado::Ahorcado(){
	nombre = "Ahorcado";
	tipo = 4;
}

string Ahorcado::getNombre(){
	return nombre;
}

int Ahorcado::getCodigo(){
	return tipo;
}
//desarrollo del juego
int Ahorcado::run(){
	clear();
	init_pair(1,COLOR_WHITE, COLOR_BLUE);
	init_pair(2,COLOR_WHITE, COLOR_RED);
	WINDOW* ventana = newwin(20,35,20,50);
	bool gana1 = true, gana2 = true, empate = true;
	int contador = 0;
	
	string palabras[10] = {"arbol","camion","camisa","hola","libro","lentes","destruir","construir","variar","carne"};
	
	srand(time(NULL));
	int numero;
	numero = rand() % 10+1;
	string palabra1 = palabras[numero];
	string referencia;
	for(int i = 0; i < palabra1.size(); i++) {
		referencia+="_";
	}
	//turno 1
	do {
		clear();
		wbkgd(ventana,COLOR_PAIR(1));
		refresh();
		box(ventana,0,0);
		wrefresh(ventana);
		int x = 3;
		for(int i = 0; i < palabra1.size(); i++) {
			mvwprintw(ventana,4,x,"%c",referencia.at(i));
			x+=3;
		}
		wrefresh(ventana);
		mvwprintw(ventana,10,2,"Ingrese una letra: ");
		char letra[2];
		wgetstr(ventana,letra);
		string l = letra;
		if(l.size() == 0){
			continue;
		}
		bool NOesta = true;
		for(int i = 0; i < palabra1.size(); i++) {//verificar coincidencia
			if(palabra1.at(i)==l.at(0)){
				referencia.replace(i,1,l);
				NOesta = false;
			}
		}
		if(NOesta){
			contador++;
		}
		int ganar = palabra1.size();
		for(int i = 0; i < palabra1.size(); i++) {
			if(referencia.at(i) != '_' ){
				ganar--;
			}
		}
		if(ganar == 0){
			gana1 = false;
		}

	} while (contador<6 && gana1);//tienen 6 oportunidades


	string referencia2;
	srand(time(NULL));
	int numero2 = rand() % 10+1;
	string palabra2 = palabras[numero2];
	for(int i = 0; i < palabra2.size(); i++) {
		referencia2 += "_";
	}
	wclear(ventana);
	wrefresh(ventana);
	clear();
	getch();
	int contador2 = 0;

	//turno 2
	do {
		clear();
		wrefresh(ventana);
		wbkgd(ventana,COLOR_PAIR(2));
		refresh();
		box(ventana,0,0);
		int x = 3;
		for(int i = 0; i < palabra2.size(); i++) {
			mvwprintw(ventana,4,x,"%c",referencia2.at(i));
			x+=3;
		}

		wrefresh(ventana);
		mvwprintw(ventana,10,2,"Ingrese una letra: ");
		char letra2[2];
		wgetstr(ventana,letra2);
		string l2 = letra2;
		if(l2.size() == 0){
			continue;
		}
		bool noE = true;
		for(int i = 0; i < palabra2.size(); i++) {
			if(palabra2.at(i) == l2.at(0)){
				referencia2.replace(i,1,l2);
				noE = false;
			}
		}
		if(noE){
			contador2++;
		}
		int ganar = palabra2.size();
		for(int i = 0; i < palabra2.size(); i++) {
			if(referencia2.at(i) != '_'){
				ganar--;
			}
		}
		if(ganar == 0){
			gana2 = false;
		}

	} while (contador2<6 && gana2);


	//retorna ganadorta
	if(gana1 == false && gana2 == false){
		return 0;
	}else if(gana1 == true && gana2 == true){
		return 0;
	}else if(gana1 == false){
		return 1;
	}else if(gana2 == false){
		return 2;
	}
}


