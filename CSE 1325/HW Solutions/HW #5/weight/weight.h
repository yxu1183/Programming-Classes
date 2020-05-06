//Name: Yunika Upadhayaya           Student ID:1001631183

#ifndef WEIGHT_H
#define WEIGHT_H

#include <gtkmm.h>

class Weightwindow:public Gtk::Window
{
public:
    Weightwindow();
    virtual ~Weightwindow();
protected:
	void button_1();
	void button_2();
	void button_close();

	Gtk::Button lbButton;
	Gtk::Button KgButton;
  Gtk::Button close;
  Gtk::Box textbox;
  Gtk::Box box;
  Gtk::Label label;
	Gtk::Entry weight;
	Gtk::Entry Name;
};

#endif
