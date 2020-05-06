//Name: Yunika Upadhayaya   Student ID: 1001631183

#ifndef MONEY_H
#define MONEY_H

#include <gtkmm.h>
#include <string>

using namespace std;

class Moneywindow:public Gtk::Window
{
public:
   Moneywindow();
   virtual ~Moneywindow();
 protected:
   void button_1();
   void button_2();
   void button_3();
   void button_4();
	 void button_close1();

   Gtk::Box textbox;
   Gtk::Box box;
   Gtk::Label label1;
   Gtk::Label label2;
   Gtk::Button Nbutton;
   Gtk::Button Wbutton;
   Gtk::Button Sbutton;
   Gtk::Button Ebutton;
   Gtk::Button close1;
   Gtk::Entry Name1;
   Gtk::Entry Name2;
   Gtk::Entry Manager1;
   Gtk::Entry Manager2;
};

class Secondwindow:public Gtk::Window
{
public:
   Secondwindow(string office1, string manager_name1);
   virtual ~Secondwindow();
protected:
   void button_5();
   void button_6();
   void button_7();
   void button_8();

   Gtk::Box box1;
   Gtk::Box textbox1;
   Gtk::Label label3;
   Gtk::Label label4;
   Gtk::Label label5;
   Gtk::Button RupButton;
   Gtk::Button YenButton;
   Gtk::Button PesoButton;
   Gtk::Button EuroButton;
   Gtk::Entry Currency;
};

class Thirdwindow:public Gtk::Window
{
public:
   Thirdwindow(string office2, string manager_name2);
   virtual ~Thirdwindow();
protected:
   void button_9();
   void button_10();
   void button_11();
   void button_12();
   Gtk::Box box1;
   Gtk::Box textbox1;
   Gtk::Label label3;
   Gtk::Label label4;
   Gtk::Label label5;
   Gtk::Button RupButton;
   Gtk::Button YenButton;
   Gtk::Button PesoButton;
   Gtk::Button EuroButton;
   Gtk::Entry Currency;
};

#endif
