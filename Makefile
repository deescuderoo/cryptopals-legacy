CXX = g++
PROGNAME = prog
OBJS = tools.o xor_tools.o
HDRS = tools.hpp xor_tools.hpp

clean:
	rm -f $(OBJS)
	rm -f "$(PROGNAME)"

set11: $(OBJS) 
	$(CXX) set11.cpp $^ -o $(PROGNAME)

set12: $(OBJS) 
	$(CXX) set12.cpp $^ -o $(PROGNAME)

set13: $(OBJS) 
	$(CXX) set13.cpp $^ -o $(PROGNAME)

set14: $(OBJS) 
	$(CXX) set14.cpp $^ -o $(PROGNAME)

set15: $(OBJS) 
	$(CXX) set15.cpp $^ -o $(PROGNAME)

set16: $(OBJS) 
	$(CXX) set16.cpp $^ -o $(PROGNAME)

.PHONY: clean
