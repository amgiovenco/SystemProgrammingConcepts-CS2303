race: animals.o race.o
	gcc -g -Wall race.o animals.o -lm -o theRace 

animals.o: animals.h animals.c
	gcc -g -Wall -c animals.c

race.o: animals.h race.c
	gcc -g -Wall -c race.c

clean:
	del -f race.o animals.o theRace

all: race
