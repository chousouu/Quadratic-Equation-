CC=g++
CFLAGS= -Wall

all: quadr.exe

quadr.exe: main.cpp SolveQE.cpp inout.cpp
	   	   $(CC) main.cpp SolveQE.cpp inout.cpp -o quadr.exe
		   

clean:
	   del *.o *.exe