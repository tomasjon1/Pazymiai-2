main: main.o
	g++ -o main v0.3.cpp *.o -O3
main.o :
	g++ -c cpp/*.cpp 
clean :
	del main.exe *.o