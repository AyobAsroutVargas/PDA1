CXX=g++
CXXFLAGS = -std=c++2a -g -Wall

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = pda_stack.hpp in_tape.hpp pda.hpp helpers.hpp
DEPS = $(patsubst %,$(LDIR)/%,$(_DEPS))

_OBJ = pda_stack.o in_tape.o pda.o helpers.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o main 