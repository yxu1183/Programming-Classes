CXXFLAGS = -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

all: money_main.o money.o
		$(CXX) $(CXXFLAGS) -o money money_main.o money.o $(GTKFLAGS)
money_main.o: money_main.cpp
		$(CXX) $(CXXFLAGS) -c money_main.cpp $(GTKFLAGS)
money.o:money.cpp
		$(CXX) $(CXXFLAGS) -c money.cpp $(GTKFLAGS)
clean:
	rm -f *.o
	rm -f out
