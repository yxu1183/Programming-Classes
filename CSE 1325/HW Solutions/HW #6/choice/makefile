CXXFLAGS = -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

all: choice_main.o choice.o
		$(CXX) $(CXXFLAGS) -o choice choice_main.o choice.o $(GTKFLAGS)
choice_main.o: choice_main.cpp
		$(CXX) $(CXXFLAGS) -c choice_main.cpp $(GTKFLAGS)
choice.o:choice.cpp
		$(CXX) $(CXXFLAGS) -c choice.cpp $(GTKFLAGS)
clean:
	rm -f *.o
	rm -f out
