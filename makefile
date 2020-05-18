main:main.o Polynomial.h Polynomial.o
	g++  main.o Polynomial.h Polynomial.o -g -o main
main.o:main.cpp
	g++ -c main.cpp -g -o main.o
Polynomial.o:Polynomial.cpp
	g++ -c Polynomial.cpp -g -o Polynomial.o
clean:
	rm *.o
	rm main