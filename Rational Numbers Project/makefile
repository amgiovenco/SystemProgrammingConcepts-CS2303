rational_math: Rational.o test_rational.o
	g++ -g -Wall test_rational.o Rational.o -lm -o rational_math

Rational.o: Rational.h Rational.cpp
	g++ -g -Wall -c Rational.cpp -o Rational.o

test_rational.o: Rational.h test_rational.cpp
	g++ -g -Wall -c test_rational.cpp -o test_rational.o

clean:
	rm -f test_rational.o Rational.o rational_math

all: rational_math
