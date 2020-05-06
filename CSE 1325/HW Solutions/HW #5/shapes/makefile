CXXFLAGS = -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

all: shapes_main.o shapes.o
		$(CXX) $(CXXFLAGS) -o shapes shapes_main.o shapes.o $(GTKFLAGS)
shapes_main.o: shapes_main.cpp
		$(CXX) $(CXXFLAGS) -c shapes_main.cpp $(GTKFLAGS)
shapes.o:shapes.cpp
		$(CXX) $(CXXFLAGS) -c shapes.cpp $(GTKFLAGS)
clean:
	rm -f *.o
	rm -f out
