#Variable objetos
EXPLORATIONS = explorationBase.o explorationQuadratic.o explorationLinear.o explorationDouble.o explorationReDispersion.o
DISPERSIONS = dispersionBase.o dispersionSum.o dispersionModule.o dispersionPseudoRandom.o
OBJECTS = main.o cell.o table.o DNI.o experiment.o $(EXPLORATIONS) $(DISPERSIONS)
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

experiment.o: ../src/experiment.cpp ../include/experiment.hpp
	g++ $(CFLAGS) ../src/experiment.cpp

explorationBase.o: ../src/explorationBase.cpp ../include/explorationBase.hpp
	g++ $(CFLAGS) ../src/explorationBase.cpp

explorationQuadratic.o: ../src/explorationQuadratic.cpp ../include/explorationQuadratic.hpp
	g++ $(CFLAGS) ../src/explorationQuadratic.cpp

explorationLinear.o: ../src/explorationLinear.cpp ../include/explorationLinear.hpp
	g++ $(CFLAGS) ../src/explorationLinear.cpp

explorationDouble.o: ../src/explorationDouble.cpp ../include/explorationDouble.hpp
	g++ $(CFLAGS) ../src/explorationDouble.cpp

explorationReDispersion.o: ../src/explorationReDispersion.cpp ../include/explorationReDispersion.hpp
	g++ $(CFLAGS) ../src/explorationReDispersion.cpp

dispersionBase.o: ../src/dispersionBase.cpp ../include/dispersionBase.hpp
	g++ $(CFLAGS) ../src/dispersionBase.cpp

dispersionSum.o: ../src/dispersionSum.cpp ../include/dispersionSum.hpp
	g++ $(CFLAGS) ../src/dispersionSum.cpp

dispersionModule.o: ../src/dispersionModule.cpp ../include/dispersionModule.hpp
	g++ $(CFLAGS) ../src/dispersionModule.cpp

dispersionPseudoRandom.o: ../src/dispersionPseudoRandom.cpp ../include/dispersionPseudoRandom.hpp
	g++ $(CFLAGS) ../src/dispersionPseudoRandom.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/hash


