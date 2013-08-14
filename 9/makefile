CXX = g++
CC = g++
CXXFLAGS = -I. -I../chapter08

all:		9-5

Student_info.o:	Student_info.cc Student_info.h

grade.o:	grade.cc ../chapter08/  Student_info.h

9-5.o:	9-5.cpp grade.h ../chapter08/median.h Student_info.h

9-5:	9-5.o grade.o Student_info.o

test:		all
	./9-5 <../data/grades

clobber:
	rm -f *.o *.exe core 9-5
