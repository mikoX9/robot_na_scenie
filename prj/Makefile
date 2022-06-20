#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: Robot_na_scenie
	./Robot_na_scenie

Robot_na_scenie: obj obj/main.o obj/Macierz2D.o obj/Obiekt_graficzny.o obj/lacze_do_gnuplota.o\
		obj/Robot.o obj/Sciezka.o obj/Zbior_wierzcholkow.o obj/Wektor2D.o obj/Scena.o obj/Przeszkoda.o
	g++ -Wall -pedantic -std=c++0x -o Robot_na_scenie obj/main.o obj/Macierz2D.o obj/Obiekt_graficzny.o\
		obj/lacze_do_gnuplota.o	obj/Robot.o obj/Sciezka.o obj/Zbior_wierzcholkow.o obj/Wektor2D.o obj/Scena.o obj/Przeszkoda.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp 
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/Macierz2D.o: src/Macierz2D.cpp 
	g++ -c ${CXXFLAGS} -o obj/Macierz2D.o src/Macierz2D.cpp

obj/Obiekt_graficzny.o: src/Obiekt_graficzny.cpp 
	g++ -c ${CXXFLAGS} -o obj/Obiekt_graficzny.o src/Obiekt_graficzny.cpp

obj/Robot.o: src/Robot.cpp 
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Sciezka.o: src/Sciezka.cpp 
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Wektor2D.o: src/Wektor2D.cpp 
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

obj/Zbior_wierzcholkow.o: src/Zbior_wierzcholkow.cpp 
	g++ -c ${CXXFLAGS} -o obj/Zbior_wierzcholkow.o src/Zbior_wierzcholkow.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp 
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

obj/Scena.o: src/Scena.cpp 
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


