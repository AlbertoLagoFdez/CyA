CTDS = g++
CFLAGS = -Wall -g

TMsimulator: TMsimulator.cc alphabet.cc symbol.cc state.cc turingmachine.cc
	$(CTDS) $(CFLAGS) TMsimulator.cc alphabet.cc symbol.cc state.cc turingmachine.cc -o TMsimulator 

.PHONY: clean

clean:
	rm -rf TMsimulator
	rm -rf *.o