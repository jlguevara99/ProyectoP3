main:	main.o Jugador.o Arma.o Cazador.o Titan.o Mago.o Espada.o Baston.o Chancla.o Juego.o
	g++ main.o Jugador.o Arma.o Cazador.o Titan.o Mago.o Espada.o Baston.o Chancla.o Juego.o -lncurses -o main

main.o:	main.cpp Arma.h Cazador.h Titan.h Jugador.h Mago.h
	g++ -c main.cpp

Jugador.o:	Jugador.h Jugador.cpp
	g++ -c Jugador.cpp

Mago.o:	Mago.h Mago.cpp
	g++ -c Mago.cpp

Cazador.o:	Cazador.h Cazador.cpp
	g++ -c Cazador.cpp

Titan.o:	Titan.h Titan.cpp
	g++ -c Titan.cpp

Arma.o:	Arma.h Arma.cpp
	g++ -c Arma.cpp

Espada.o:	Espada.h Espada.cpp
	g++ -c Espada.cpp

Baston.o:	Baston.h Baston.cpp
	g++ -c Baston.cpp

Chancla.o:	Chancla.h Chancla.cpp
	g++ -c Chancla.cpp

Juego.o:	Juego.h Juego.cpp
	g++ -c Juego.cpp

clean:
	rm -f *.o main