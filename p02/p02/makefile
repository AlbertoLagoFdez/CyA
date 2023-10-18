CC = g++
CFLAGS = -Wall -g

p02_string: Clientp02_string.cc Chain.cc Alphabet.cc tools.cc
		$(CC) $(CFLAGS) Chain.cc Alphabet.cc Clientp02_string.cc -o p02_string

.PHONY: clean

clean:
		rm -rf p02_string
		rm -rf *.o
