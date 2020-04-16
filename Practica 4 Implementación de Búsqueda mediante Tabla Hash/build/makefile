#Variable objetos
OBJECTS = main.o  DNI.o experiment.o $(EXPLORATIONS) 
#Flags de compilacion
CFLAGS = -c -std=c++17

hash: $(OBJECTS)
	g++  $(OBJECTS) -o hash
	mv *.o ../objects
	mv hash ../bin

main.o: ../src/main.cpp ../include/cell.hpp ../include/table.hpp ../include/dispersionBase.hpp ../include/dispersionSum.hpp ../include/dispersionModule.hpp ../include/dispersionPseudoRandom.hpp ../include/explorationQuadratic.hpp ../include/explorationDouble.hpp ../include/explorationReDispersion.hpp ../include/explorationLinear.hpp ../include/explorationBase.hpp ../include/dispersionSum2.hpp
	g++ $(CFLAGS) ../src/main.cpp


DNI.o: ../src/DNI.cpp ../include/DNI.hpp
	g++ $(CFLAGS) ../src/DNI.cpp

experiment.o: ../src/experiment.cpp ../include/experiment.hpp
	g++ $(CFLAGS) ../src/experiment.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/hash


