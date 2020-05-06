//Name: Yunika Upadhayaya           Student ID:1001631183

#ifndef SHAPE_H
#define SHAPE_H

#include <gtkmm.h>

class Shapeswindow:public Gtk::Window
{
public:
    Shapeswindow();
    virtual ~Shapeswindow();
protected:
	void button_1();
	void button_2();
  void button_3();
  void button_4();
  void button_5();
  void button_close();

	Gtk::Button TrButton;
  Gtk::Button SqButton;
  Gtk::Button RecButton;
  Gtk::Button CirButton;
	Gtk::Button QuadButton;
  Gtk::Button close;
  Gtk::VBox layout;
};

#endif
