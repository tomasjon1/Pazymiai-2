main: main.o
	g++ -o main v0.3.cpp calculations.o generation.o InputAndOutput.o validation.o
main.o :
	g++ -c cpp/*.cpp 
clean :
	del main.exe *.o