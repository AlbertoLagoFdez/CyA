CC = g++
CFLAGS = -Wall -g

p05_automata_simulator: Clientp05_automata_simulator.cc Alphabet.cc Estado.cc Automata.cc Transicion.cc
		$(CC) $(CFLAGS) Clientp05_automata_simulator.cc Alphabet.cc Estado.cc Automata.cc Transicion.cc -o p05_automata_simulator
 
.PHONY: clean

clean:
		rm -rf p05_automata_simulator
		rm -rf *.o
