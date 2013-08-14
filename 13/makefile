CXX = g++
CC = g++

all:		13-2 13-6

Core.o:	Core.cc Core.h

Grad.o:	Grad.cc Core.h

Student_info.o:	Student_info.cc median.h Student_info.h Core.h

grade.o:	grade.cc median.h Student_info.h

read_hw.o:	read_hw.cc median.h Student_info.h

main_core.o:	main_core.cc Core.h median.h

main_grad.o:	main_grad.cc Core.h median.h

main_orig.o:	main_orig.cc Core.h median.h Student_info.h

main_core_ptrs.o:	main_core_ptrs.cc Core.h median.h

main_orig:	main_orig.o grade.o Student_info.o read_hw.o Core.o

main_core:	main_core.o grade.o  read_hw.o Core.o

main_grad:	main_grad.o grade.o  read_hw.o Core.o

main_core_ptrs:	main_core_ptrs.o grade.o  read_hw.o Core.o

13-2.o:	13-2.cpp Core.h median.h

13-6.o:	13-2.cpp Core.h median.h

13-2:	Core.o grade.o read_hw.o

13-6:	Core.o grade.o read_hw.o

test:		all
	./main_core <../data/grades_core
	./main_grad <../data/grades_grad
	./main_orig <../data/mixed_grades
	./main_core_ptrs <../data/mixed_grades

clobber:
	rm -f *.o *.exe core main_core main_grad main_orig main_core_ptrs
