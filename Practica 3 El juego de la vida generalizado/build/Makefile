#Variable objetos
OBJECTS = main.o celula.o celula1.o celula2.o celula3.o tablero.o
#Flags de compilacion
CFLAGS = -c -std=c++17

game: $(OBJECTS)
	g++  $(OBJECTS) -o game
	mv *.o ../objects
	mv game ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

celula.o: ../src/celula.cpp ../include/celula.hpp
	g++ $(CFLAGS) ../src/celula.cpp

celula1.o: ../src/celula1.cpp ../include/celula1.hpp
	g++ $(CFLAGS) ../src/celula1.cpp

celula2.o: ../src/celula2.cpp ../include/celula2.hpp
	g++ $(CFLAGS) ../src/celula2.cpp


celula3.o: ../src/celula3.cpp ../include/celula3.hpp
	g++ $(CFLAGS) ../src/celula3.cpp

tablero.o: ../src/tablero.cpp ../include/tablero.hpp
	g++ $(CFLAGS) ../src/tablero.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/game


