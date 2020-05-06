//Name: Yunika Upadhayaya   Student ID:1001631183

#ifndef CHOICE_H
#define CHOICE_H

#include <gtkmm.h>
#include <string>

using namespace std;

void ReadFile();
void WriteFile();

class Main_Window:public Gtk::Window
{
public:
  Main_Window();

  Gtk::VBox box;
  Gtk::Button Customer;
  Gtk::Button Apply;
  Gtk::Button exit;

  void on_Customer_button();
  void on_Apply_button();
  void close();
};

class CustomerWindow:public Gtk::Window
{
public:
  CustomerWindow();

  Gtk::Label label;
  Gtk::Label label1;
  Gtk::Separator separator;
  Gtk::VBox box;
  Gtk::RadioButton Burrito;
  Gtk::RadioButton Bowl;
  Gtk::Button continuebutton;
  Gtk::Button exit;

  void close();
  void on_burrito_button();
  void on_bowl_button();
  void on_continue_button();
};

class PickWindow:public Gtk::Window
{
public:
  PickWindow();

  Gtk::Label label;
  Gtk::Label label1;
  Gtk::Label label2;
  Gtk::Label label3;
  Gtk::VBox box1;
  Gtk::VBox box2;
  Gtk::VBox box3;
  Gtk::VBox box4;
  Gtk::VBox box5;
  Gtk::VBox box6;
  Gtk::Separator separtor1;
  Gtk::Separator separtor2;
  Gtk::Separator separtor3;
  Gtk::Separator separtor4;
  Gtk::CheckButton radiobutton_1;
  Gtk::CheckButton radiobutton_2;
  Gtk::CheckButton radiobutton_3;
  Gtk::CheckButton radiobutton_4;
  Gtk::CheckButton radiobutton_5;
  Gtk::CheckButton radiobutton_6;
  Gtk::CheckButton radiobutton_7;
  Gtk::CheckButton radiobutton_8;
  Gtk::Button newContinue;

  void on_radiobutton1();
  void on_radiobutton2();
  void on_radiobutton3();
  void on_radiobutton4();
  void on_radiobutton5();
  void on_radiobutton6();
  void on_radiobutton7();
  void on_radiobutton8();
  void on_order_button();
};

class ApplyWindow:public Gtk::Window
{
public:
  ApplyWindow();

  Gtk::Entry Name;
  Gtk::Box box;
  Gtk::Label label;
  Gtk::Box textbox;
  Gtk::Button continueButton;

  void continue_button();
};

#endif
