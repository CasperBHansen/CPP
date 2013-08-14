CXX = g++
CC = g++

all:		9-5

Student_info.o:	Student_info.cc Student_info.h

grade.o:	grade.cc Student_info.h

9-5.o:	9-5.cpp grade.h median.h Student_info.h

9-5:	9-5.o grade.o Student_info.o

test:		all
	./9-5 <../data/grades

clobber:
	rm -f *.o *.exe core 9-5
