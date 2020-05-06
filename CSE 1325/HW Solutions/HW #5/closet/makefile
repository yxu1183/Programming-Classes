CXXFLAGS = -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

all: closet_main.o closet.o
		$(CXX) $(CXXFLAGS) -o closet closet_main.o closet.o $(GTKFLAGS)
closet_main.o: closet_main.cpp
		$(CXX) $(CXXFLAGS) -c closet_main.cpp $(GTKFLAGS)
closet.o:closet.cpp
		$(CXX) $(CXXFLAGS) -c closet.cpp $(GTKFLAGS)
clean:
	rm -f *.o
	rm -f out
