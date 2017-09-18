#include "Juego.h"

Juego::Juego(int pn){
	jugadores = new Jugador*[2];
	numeroJugadores = 0;
	posicion1 = 0;
	posicion2 = 0;
	numeroJugadores = pn;
}

Juego::Juego(int p1, int p2,Jugador* jj, Jugador* jj2){
	posicion1 = p1;
	posicion2 = p2;
	jugadores = new Jugador*[2];
	jugadores[0] = jj;
	jugadores[1] = jj2;
}

//menu para correr el juego
int Juego::RUN(){
	int opcion;
	Juego* jj = new Juego(2);
	do {
		WINDOW* menu = newwin(20,20,10,50);
		refresh();
		box(menu,0,0);
		wrefresh(menu);
		mvwprintw(menu,1,6,"Density");
		mvwprintw(menu,2,3,"1. New Game");
		mvwprintw(menu,3,3,"2. Continue");
		mvwprintw(menu,4,3,"3. Exit");
		mvwprintw(menu,5,3,"");
		char opi[2];
		wgetstr(menu,opi);
		opcion = atoi(opi);
		clear();
		if(opcion == 1){
			jj->init(1);
			jj->play();
		}else if(opcion == 2){
			jj->init(2);
		}else if(opcion == 3){
			clear();
			move(5,30);
			printw(" ___    ___   _   _    ___    ___    ___    _   _");
			move(6,30);
			printw("|   )   |__   | \\ |   |___     |      |     |___|");
			move(7,30);
			printw("|___)   |__   |  \\|    ___|   _|_     |       |");
			getch();
		}
	
		}while(opcion != 3);
		delete jj;
		return 0;
}



//inicializa el tablero
void Juego::init(int opcionn){
	
	jugadores = new Jugador*[2];
	
	if(opcionn == 1){
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

		//escribe los datos al archivo
		ofstream salida("juego.txt");
		Juego game(posicion1,posicion2,jugadores[0],jugadores[1]);
		salida<<game;
		salida.close();
	}else if(opcionn == 2){
		//carga los datos y empieza el juego
		ifstream entrada("juego.txt");
		Juego jug(2);
		Arma* arm = new Baston(" "," ");
		jug.jugadores[0] = new Cazador("Jug-1",arm);
		jug.jugadores[1] = new Mago("Jug-2",arm);
		entrada>>jug;
		jug.play();
		
	}else if(opcionn == 3){

	}
	
}


//Aqui está todo el desarrollo del juego
int Juego::play(){
	clear();
	char* tablero;
	tablero = new char[100];
	for(int i = 0; i < 100; i++) {//llenar el tablero
		tablero[i] = ' ';
	}
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_WHITE,COLOR_RED);
	

	WINDOW* gameplay = newwin(30,70,10,30);
	refresh();
	srand(time(NULL));
	int turno = 0;
	bool gana1 = true, gana2 = true, salir = true;
	do {
		clear();
		if(turno == 0){
			wbkgd(gameplay,COLOR_PAIR(1));
		}else{//cambiarle el color al tablero, dependiendo del jugador
			wbkgd(gameplay,COLOR_PAIR(2));
		}
		refresh();
		box(gameplay,0,0);
		wrefresh(gameplay);

		mvwprintw(gameplay,3,4,"start");
		mvwprintw(gameplay,13,61, "end");
		int x = 4, y=2;
		for(int i = 0; i < 100; i++) {
			//mvwprintw(gameplay,y,x,"[%c]",tablero[i]);
			
			if(i%20 == 0){
				x = 4;
				y+=2;
			}else{
				x+=3;
			}
			mvwprintw(gameplay,y,x,"[%c]",tablero[i]);
		}
		mvwprintw(gameplay,16,50,"%s",jugadores[0]->getNombre().c_str());
		mvwprintw(gameplay,16,61,"%s",jugadores[1]->getNombre().c_str());
		mvwprintw(gameplay,17,42,"Posicion->%d",posicion1);
		mvwprintw(gameplay,17,61,"%d",posicion2);
		wrefresh(gameplay);
		refresh();
		getch();

		//jugar

		mvwprintw(gameplay,15,3,"Turno de %s", jugadores[turno]->getNombre().c_str());
		mvwprintw(gameplay,16,3,"1. Lanzar dados: ");
		mvwprintw(gameplay,17,3,"2. Guardar y salir del Juego");
		mvwprintw(gameplay,18,3,"");
		char eleccion[2];
		wgetstr(gameplay,eleccion);
		int opcion = atoi(eleccion);
		while(opcion!=1 && opcion!=2){
			wgetstr(gameplay,eleccion);
			opcion = atoi(eleccion);
		}
		
		if(opcion == 1){
			int lanzar = rand() % 6+1;
			if(turno == 0){
				if(posicion1<=99){				
					tablero[posicion1] = ' ';
				}
				posicion1 += lanzar;
			}else{
				if(posicion2 <= 99){
					tablero[posicion2] = ' ';
				}
				posicion2 += lanzar;
			}
			int minigame =rand() & 10+1;
			int ganador;

			//elige un minijuego aleatorio
			if(minigame == 1){
				clear();
				move(20,20);
				printw("Minigame: Adivina");
				wrefresh(gameplay);
				getch();
				Minijuego* mini = new Adivina();
				ganador = mini->run();
				delete mini;
			}else if(minigame == 2){
				clear();
				move(20,20);
				printw("Minigame: TicTac");
				wrefresh(gameplay);
				getch();
				Minijuego* mini = new TicTac();
				ganador = mini->run();
				delete mini;
			}else if(minigame == 3){
				clear();
				move(20,20);
				printw("Minigame: Busca");
				wrefresh(gameplay);
				getch();
				Minijuego* mini = new Busca();
				ganador = mini->run();
				delete mini;
			}else if(minigame == 4){
				clear();
				move(20,20);
				printw("Minigame: Ahorcado");
				wrefresh(gameplay);
				getch();
				Minijuego* mini = new Ahorcado();
				ganador = mini->run();
				delete mini;
			}else if(minigame == 9){
				clear();
				move(20,20);

				printw("Minigame: Batalla");
				getch();
				Minijuego* mini = new Batalla(jugadores[0],jugadores[1]);
				ganador = mini->run();
				delete mini;
			}
		
			if(ganador == 1){
				mvwprintw(gameplay,20,3,"Ha ganado %s",jugadores[0]->getNombre().c_str());
				jugadores[0]->incrementarHP();
				posicion1 += 3;
			}else if(ganador == 2){
				mvwprintw(gameplay,20,3,"Ha ganado %s",jugadores[1]->getNombre().c_str());
				jugadores[1]->incrementarHP();
				posicion2 += 3;
			}
			wrefresh(gameplay);
			getch();

			//verificar si hay ganador
			if(posicion1 >= 100){
				mvwprintw(gameplay,22,3,"Ha ganado el juego %s",jugadores[0]->getNombre().c_str());
				gana1 = false;
			}else{
				tablero[posicion1] = '1';
			}

			if(posicion2 >= 100){
				mvwprintw(gameplay,23,3,"Ha ganado el juego%s",jugadores[1]->getNombre().c_str());
				gana2 = false;
			}else{
				tablero[posicion2] = '2';
			}
			if(turno == 0){
				turno = 1;
			}else if(turno == 1){
				turno = 0;
			}
			for(int i = 0; i < 100; i++) {
				if(i != posicion1 && i != posicion2){
					tablero[i] = ' ';
				}
			}
			wrefresh(gameplay);
			refresh();
			getch();

		}else if(opcion == 2){
			salir = false;

			//guardar archivo
			ofstream salida("juego.txt");
			Juego game(posicion1,posicion2,jugadores[0],jugadores[1]);
			salida<<game;
			salida.close();
			clear();
		}

	} while (gana1 && gana2 && salir);
	clear();
	delete[] tablero;
	if(gana1 == false){
		return 1;
	}else if(gana2 == false){
		return 2;
	}else{
		return 0;
	}
	//retornar jugador
}



//salida (escribir a un archivo de texto)
ostream& operator << (ostream& out,const Juego& game){
	Jugador* j1 = game.jugadores[0];
	Jugador* j2 = game.jugadores[1];

	string tipo1,tipo2;
	if(typeid(*j1) == typeid(Cazador)){
		tipo1 = "c";
	}else if(typeid(*j1) == typeid(Mago)){
		tipo1 = "m";
	}else{
		tipo1 = "t";
	}

	if(typeid(*j2)==typeid(Cazador)){
		tipo2 = "c";
	}else if(typeid(*j2)==typeid(Mago)){
		tipo2 = "m";
	}else{
		tipo2 = "t";
	}
	string nom1 = j1->getNombre();
	string nom2 = j2->getNombre();


	out<<game.posicion1<<","<<game.posicion2<<","<<nom1<<","<<tipo1<<","<<nom2<<","<<tipo2<<endl;
	//out<<game.posicion1<<","<<game.posicion2<<endl;
	return out;
}

//entrada (recuperar datos de un archivo de texto)
istream& operator >> (istream& in, Juego& game){
	string buffer;
	in>>buffer;
	
	//printw("%s",buffer.c_str());
	int contador = 0;
	string palabra = "";
	string nom1,nom2,tipo1,tipo2;
		
	for(int i = 0; i < buffer.size(); i++) {
		if(buffer[i] == ',' || i+1 == buffer.size()){
			contador++;
			
			if(contador==1){
				int numero = atoi(palabra.c_str());
				game.posicion1 = numero;
				/*move(2,2);
				printw("aqui %d",game.posicion1);
				getch();*/
			}else if(contador==2){
				int num = atoi(palabra.c_str());
				game.posicion2 = num;
			}else if(contador==3){
				nom1 = palabra.c_str();
			}else if(contador==4){
				tipo1 = palabra;
			}else if(contador==5){
				nom2 = palabra.c_str();
			}else if(contador==6){
				tipo2 = palabra.c_str();
			}
			palabra = "";
		}else{
			palabra += buffer[i];
		}
	}
	getch();
	
	
	return in;	
}
