CC = g++
CFLAGS = -Wall -g

p05_automata_simulator: Clientp05_automata_simulator.cc Simbol.cc Alphabet.cc Chain.cc Estado.cc Transition.cc
		$(CC) $(CFLAGS) Clientp05_automata_simulator.cc Simbol.cc Alphabet.cc Chain.cc Estado.cc Transition.cc -o p05_automata_simulator
 
.PHONY: clean

clean:
		rm -rf p05_automata_simulator
		rm -rf *.o
