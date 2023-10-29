CTDS = g++
CFLAGS = -Wall -g

Grammar2CNF: Grammar2CNF.cc alphabet.cc symbol.cc grammar.cc
	$(CTDS) $(CFLAGS) Grammar2CNF.cc alphabet.cc symbol.cc grammar.cc -o Grammar2CNF 

.PHONY: clean

clean:
	rm -rf Grammar2CNF
	rm -rf *.o