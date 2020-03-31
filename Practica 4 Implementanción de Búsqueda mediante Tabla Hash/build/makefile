#Variable objetos
OBJECTS = main.o cell.o table.o DNI.o explorationBase.o dispersionBase.o
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

explorationBase.o: ../src/explorationBase.cpp ../include/explorationBase.hpp
	g++ $(CFLAGS) ../src/explorationBase.cpp

dispersionBase.o: ../src/dispersionBase.cpp ../include/dispersionBase.hpp
	g++ $(CFLAGS) ../src/dispersionBase.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/hash


