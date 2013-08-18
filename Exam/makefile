CXX=g++
CFLAGS=-std=c++11 -c -Wall
LDFLAGS=
SOURCES=main.cpp Shape.cpp Line.cpp Circle.cpp Triangle.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Shapes

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o Shapes
