#Variable objetos
OBJECTS = main.o machineRAM.o inputTape.o instruction.o outputTape.o registers.o tag.o tagRegister.o i_add.o i_div.o i_halt.o i_jgtz.o i_jump.o i_jzero.o i_load.o i_mult.o i_read.o i_store.o i_write.o i_sub.o
#Flags de compilacion
CFLAGS = -c -std=c++17

ram_sim: $(OBJECTS)
	g++  $(OBJECTS) -o ram_sim
	mv *.o ../objects
	mv ram_sim ../bin


main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

machineRAM.o: ../src/machineRAM.cpp ../include/machineRAM.hpp
	g++ $(CFLAGS) ../src/machineRAM.cpp

inputTape.o: ../src/inputTape.cpp ../include/inputTape.hpp
	g++ $(CFLAGS) ../src/inputTape.cpp

instruction.o: ../src/instruction.cpp ../include/instruction.hpp
	g++ $(CFLAGS) ../src/instruction.cpp

outputTape.o: ../src/outputTape.cpp ../include/outputTape.hpp
	g++ $(CFLAGS) ../src/outputTape.cpp

registers.o: ../src/registers.cpp ../include/registers.hpp
	g++ $(CFLAGS) ../src/registers.cpp

tag.o: ../src/tag.cpp ../include/tag.hpp
	g++ $(CFLAGS) ../src/tag.cpp

tagRegister.o: ../src/tagRegister.cpp ../include/tagRegister.hpp
	g++ $(CFLAGS) ../src/tagRegister.cpp

i_load.o: ../src/i_load.cpp ../include/i_load.hpp
	g++ $(CFLAGS) ../src/i_load.cpp

i_store.o: ../src/i_store.cpp ../include/i_store.hpp
	g++ $(CFLAGS) ../src/i_store.cpp

i_add.o: ../src/i_add.cpp ../include/i_add.hpp
	g++ $(CFLAGS) ../src/i_add.cpp

i_div.o: ../src/i_div.cpp ../include/i_div.hpp
	g++ $(CFLAGS) ../src/i_div.cpp

i_halt.o: ../src/i_halt.cpp ../include/i_halt.hpp
	g++ $(CFLAGS) ../src/i_halt.cpp

i_jgtz.o: ../src/i_jgtz.cpp ../include/i_jgtz.hpp
	g++ $(CFLAGS) ../src/i_jgtz.cpp

i_jump.o: ../src/i_jump.cpp ../include/i_jump.hpp
	g++ $(CFLAGS) ../src/i_jump.cpp

i_jzero.o: ../src/i_jzero.cpp ../include/i_jzero.hpp
	g++ $(CFLAGS) ../src/i_jzero.cpp

i_mult.o: ../src/i_mult.cpp ../include/i_mult.hpp
	g++ $(CFLAGS) ../src/i_mult.cpp

i_read.o: ../src/i_read.cpp ../include/i_read.hpp
	g++ $(CFLAGS) ../src/i_read.cpp

i_sub.o: ../src/i_sub.cpp ../include/i_sub.hpp
	g++ $(CFLAGS) ../src/i_sub.cpp

i_write.o: ../src/i_write.cpp ../include/i_write.hpp
	g++ $(CFLAGS) ../src/i_write.cpp


.PHONY: clean
clean:
	rm -rf ../objects/*.o
	rm -rf ../bin/*

run1:
	../bin/ram_sim ../inputs/ram_program.ram ../inputs/input_tape.in ../inputs/output_tape.out 1

run0:
	../bin/ram_sim ../inputs/ram_program.ram ../inputs/input_tape.in ../inputs/output_tape.out 0
