CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test logicsim-hi

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.cpp llrec.h
	g++ -std=c++11 -g -Wall llrec-test.cpp llrec.cpp -o llrec-test

logicsim-hi: logicsim/logicsim.cpp logicsim/circuit.cpp logicsim/gate.cpp logicsim/wire.cpp heap.h
	$(CXX) $(CXXFLAGS) -o logicsim-hi logicsim/logicsim.cpp logicsim/circuit.cpp logicsim/gate.cpp logicsim/wire.cpp
clean:
	rm -f *.o rh llrec-test logicsim-hi *~

.PHONY: clean 