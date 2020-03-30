#Variable objetos
OBJECTS = main.o cell.o table.o DNI.o
#Flags de compilacion
CFLAGS = -c -std=c++17

hash: $(OBJECTS)
	g++  $(OBJECTS) -o hash
	mv *.o ../objects
	mv hash ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

cell.o: ../src/cell.cpp ../include/cell.hpp
	g++ $(CFLAGS) ../src/cell.cpp

table.o: ../src/table.cpp ../include/table.hpp
	g++ $(CFLAGS) ../src/table.cpp

DNI.o: ../src/DNI.cpp ../include/DNI.hpp
	g++ $(CFLAGS) ../src/DNI.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/hash


