#Variable objetos
OBJECTS = main.o  DNI.o Counter.o
#Flags de compilacion
CFLAGS = -c -std=c++17

ordenacion: $(OBJECTS) $(METHODS)
	g++  $(OBJECTS) -o ordenacion
	mv *.o ../objects
	mv ordenacion ../bin

main.o: ../src/main.cpp 
	g++ $(CFLAGS) ../src/main.cpp

DNI.o: ../src/DNI.cpp ../include/DNI.hpp
	g++ $(CFLAGS) ../src/DNI.cpp

Counter.o: ../src/Counter.cpp ../include/Counter.hpp
	g++ $(CFLAGS) ../src/Counter.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/ordenacion


