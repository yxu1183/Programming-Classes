CXXFLAGS = -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

all: weight_main.o weight.o
		$(CXX) $(CXXFLAGS) -o weight weight_main.o weight.o $(GTKFLAGS)
weight_main.o: weight_main.cpp
		$(CXX) $(CXXFLAGS) -c weight_main.cpp $(GTKFLAGS)
weight.o:weight.cpp
		$(CXX) $(CXXFLAGS) -c weight.cpp $(GTKFLAGS)
clean:
	rm -f *.o
	rm -f out
