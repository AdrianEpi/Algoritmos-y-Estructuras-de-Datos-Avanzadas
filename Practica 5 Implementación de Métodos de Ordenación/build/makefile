#Variable objetos
OBJECTS = main.o  DNI.o Counter.o experiment.o ISBN.o
METHODS = ../include/BaseSortMethod.hpp ../include/InsertionMethod.hpp ../include/BubbleSortMethod.hpp ../include/HeapSortMethod.hpp ../include/QuickSortMethod.hpp ../include/ShellSortMethod.hpp
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

ISBN.o: ../src/ISBN.cpp ../include/ISBN.hpp
	g++ $(CFLAGS) ../src/ISBN.cpp

Counter.o: ../src/Counter.cpp ../include/Counter.hpp
	g++ $(CFLAGS) ../src/Counter.cpp

experiment.o: ../src/experiment.cpp ../include/experiment.hpp
	g++ $(CFLAGS) ../src/experiment.cpp

.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run:
	../bin/ordenacion


