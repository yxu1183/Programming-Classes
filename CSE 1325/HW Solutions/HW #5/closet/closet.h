//Name: Yunika Upadhayaya   Student ID:1001631183

#ifndef CLOSET_H
#define CLOSET_H

#include <gtkmm.h>
#include <string>

using namespace std;

class Main_Window:public Gtk::Window
{
public:
  Main_Window();

  Gtk::VBox box;
  Gtk::Button Seller;
  Gtk::Button Buyer;
  Gtk::Button exit;
  Gtk::Button Total;

  void on_seller_button();
  void on_buyer_button();
  void total_sales_button();
  void close();
};

class Seller_Window:public Gtk::Window
{
public:
  Seller_Window();
  Gtk::Box box;
  Gtk::Label label;
  Gtk::Label label1;
  Gtk::Entry Name;
  Gtk::Entry Item;
  Gtk::Box textbox;
  Gtk::Button continueButton;

  void continue_button();
};

class Add_window:public Gtk::Window
{
public:
  Add_window();
  Gtk::Box box;
  Gtk::Box textbox;
  Gtk::Label label;
  Gtk::Entry Item_Price;
  Gtk::Button DoneButton;

  void Done_button();
};

class Buyer_Window:public Gtk::Window
{
public:
  Buyer_Window();
  Gtk::Box box;
  Gtk::Box textbox;
  Gtk::Label label;
  Gtk::Entry Item;
  Gtk::Button SearchButton;

  void Search_button();
};
#endif
