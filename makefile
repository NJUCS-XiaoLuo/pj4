main:main.o Polynomial.h Polynomial.o Window.h Window.o CmdDeal.h CmdDeal.o
	g++  main.o Polynomial.h Polynomial.o Window.h Window.o CmdDeal.h CmdDeal.o -g -o main
main.o:main.cpp
	g++ -c main.cpp -g -o main.o
Polynomial.o:Polynomial.cpp
	g++ -c Polynomial.cpp -g -o Polynomial.o
Window.o:Window.cpp
	g++ -c Window.cpp -g -o Window.o
CmdDeal.o:CmdDeal.cpp
	g++ -c CmdDeal.cpp -g -o CmdDeal.o
clean:
	rm *.o
	rm main