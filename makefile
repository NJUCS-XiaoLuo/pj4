main:main.o
	g++  main.o -g -o main
main.o:main.cpp
	g++ -c main.cpp -g -o main.o
clean:
	rm *.o
	rm main