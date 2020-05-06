//Name:Yunika Upadhayaya   Student ID:1001631183

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "weight.h"

using namespace std;

Weightwindow:: Weightwindow():box(Gtk::ORIENTATION_VERTICAL),close("Exit"),lbButton("~~Convert Lbs to Kg~~"),KgButton("~~Convert Lbs to Kg~~")
{
  set_size_request(500,300);
  set_title("Weight Converter!");
  add(box);

  label.set_text("Enter your name and weight in numbers:");
  box.pack_start(label);

  Name.set_max_length(75);
  Name.set_text("Name");
  Name.select_region(0,Name.get_text_length());
  box.pack_start(Name);

  weight.set_max_length(75);
  weight.set_text("Weight Value");
  weight.select_region(1,weight.get_text_length());
  box.pack_start(weight);

  box.pack_start(textbox);

  lbButton.signal_clicked().connect(sigc::mem_fun(*this,&Weightwindow::button_1));
  box.pack_start(lbButton);

	KgButton.signal_clicked().connect(sigc::mem_fun(*this,&Weightwindow::button_2));
  box.pack_start(KgButton);

  close.signal_clicked().connect(sigc::mem_fun(*this,&Weightwindow::button_close));
  box.pack_start(close);

  show_all_children();
}

Weightwindow::~Weightwindow()
{

}

void Weightwindow::button_1()
{
	double convert= stof(weight.get_text());
	convert=(convert/2.205);
	string person=Name.get_text();
  string first_name, last_name;
  stringstream delimeter(person);
  delimeter>>first_name>>last_name;

  string::iterator it(first_name.begin());
  if(it!= first_name.end())
  {
    first_name[0] = toupper(first_name[0]);
  }
  while(++it!= first_name.end())
  {
    *it = tolower(*it);
  }

	stringstream new_line;
	new_line<<" you weigh "<<fixed<<setprecision(2)<<convert<<" kilos.";
	string word=new_line.str();

	Gtk::MessageDialog show(*this,"Hi "+first_name+", "+word,false,Gtk::MESSAGE_INFO);
	show.set_secondary_text("Thanks for using Weight Converter!");
	show.run();
}

void Weightwindow::button_2()
{
	double convert= stof(weight.get_text());
	convert=(convert*2.205);
	string person=Name.get_text();
  string first_name, last_name;
  stringstream delimeter(person);
  delimeter>>first_name>>last_name;

  string::iterator it(first_name.begin());
  if(it!= first_name.end())
  {
    first_name[0] = toupper(first_name[0]);
  }
  while(++it!= first_name.end())
  {
    *it = tolower(*it);
  }

  stringstream new_line;
	new_line<<" you weigh "<<fixed<<setprecision(2)<<convert<<" pounds.";
	string word=new_line.str();

	Gtk::MessageDialog show(*this,"Hi "+first_name+", "+word,false,Gtk::MESSAGE_INFO);
	show.set_secondary_text("Thanks for using Weight Converter!");
	show.run();
}

void Weightwindow::button_close()
{
	hide();
}
