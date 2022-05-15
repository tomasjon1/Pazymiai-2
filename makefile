main: main.o
	g++ -o main *.o -O3
main.o :
	g++ -c *.cpp 
clean :
	del main.exe *.o