//Name: Yunika Uapdhayaya     Student ID: 1001631183

#include <iostream>
#include <sstream>
#include <string>
#include "shapes.h"

using namespace std;
int tracker = 0;

Shapeswindow:: Shapeswindow()
{
  set_title("Shapes!");
  set_border_width(12);
  set_default_size(500,450);

  TrButton.add_label("Triangle");
  TrButton.signal_clicked().connect(sigc::mem_fun(*this,&Shapeswindow::button_1));
  layout.pack_start(TrButton);

  SqButton.add_label("Square");
	SqButton.signal_clicked().connect(sigc::mem_fun(*this,&Shapeswindow::button_2));
  layout.pack_start(SqButton);

  RecButton.add_label("Rectangle");
  RecButton.signal_clicked().connect(sigc::mem_fun(*this,&Shapeswindow::button_3));
  layout.pack_start(RecButton);

  CirButton.add_label("Circle");
  CirButton.signal_clicked().connect(sigc::mem_fun(*this,&Shapeswindow::button_4));
  layout.pack_start(CirButton);

  QuadButton.add_label("Quadilateral");
  QuadButton.signal_clicked().connect(sigc::mem_fun(*this,&Shapeswindow::button_5));
  layout.pack_start(QuadButton);

  close.add_label("Exit");
  close.signal_clicked().connect(sigc::mem_fun(*this,&Shapeswindow::button_close));
  layout.pack_start(close);

  layout.show_all();
  add(layout);
}

Shapeswindow:: ~Shapeswindow()
{

}

void Shapeswindow::button_1()
{
  Gtk::MessageDialog show(*this,"Area = (Base*Height)/2\nPerimeter = Sum of length of all sides",false,Gtk::MESSAGE_INFO);
  tracker++;
  show.run();
}

void Shapeswindow::button_2()
{
  Gtk::MessageDialog show(*this,"Area = Length*Length\nPerimeter = 4*Length",false,Gtk::MESSAGE_INFO);
  show.run();
  tracker++;
}

void Shapeswindow::button_3()
{
  Gtk::MessageDialog show(*this,"Area = Length*Breadth\nPerimeter = 2(Length+Breadth)",false,Gtk::MESSAGE_INFO);
  show.run();
  tracker++;
}

void Shapeswindow::button_4()
{
  Gtk::MessageDialog show(*this,"Area = Pi*Radius*Radius\nPerimeter = 2*Pi*Radius",false,Gtk::MESSAGE_INFO);
  show.run();
  tracker++;
}

void Shapeswindow::button_5()
{
  Gtk::MessageDialog show(*this,"Perimeter = Sum of all sides",false,Gtk::MESSAGE_INFO);
  show.run();
  tracker++;
}

void Shapeswindow::button_close()
{
  ostringstream line;
  line<<"You looked for "<<tracker<<" different shapes in this session!\n";
  string word = line.str();
  Gtk::MessageDialog show(*this,word,false,Gtk::MESSAGE_INFO);
  show.run();
  hide();
}
