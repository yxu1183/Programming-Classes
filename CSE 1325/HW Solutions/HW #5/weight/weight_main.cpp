//Name: Yunika Upadhayaya     Student ID: 1001631183

#include <iostream>
#include <gtkmm.h>
#include "weight.h"

using namespace std;

int main(int argc,char** argv)
{
    Gtk::Main app(argc,argv);
    Weightwindow w;
    Gtk::Main::run(w);
    return 0;
}
