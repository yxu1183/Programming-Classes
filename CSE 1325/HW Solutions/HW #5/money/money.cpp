//Name: Yunika Upadhayaya   Student ID:1001631183

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "money.h"

using namespace std;

long double total_made = 0;

Moneywindow:: Moneywindow():box(Gtk::ORIENTATION_VERTICAL),close1("Exit"),Nbutton("North"),Sbutton("South"),Ebutton("East"),Wbutton("West")
{
  set_size_request(500,300);
  set_title("Money Converter!");
  add(box);

  label1.set_text("Enter the name of two exchange offices and two managers:");
  box.pack_start(label1);

  Name1.set_max_length(75);
  Name1.set_text("ABC Conversions");
  Name1.select_region(0,Name1.get_text_length());
  box.pack_start(Name1);

  Name2.set_max_length(75);
  Name2.set_text("DEF Conversions");
  Name2.select_region(0,Name2.get_text_length());
  box.pack_start(Name2);

  Manager1.set_max_length(75);
  Manager1.set_text("Armin");
  Manager1.select_region(0,Manager1.get_text_length());
  box.pack_start(Manager1);

  Manager2.set_max_length(75);
  Manager2.set_text("Jep");
  Manager2.select_region(0,Manager2.get_text_length());
  box.pack_start(Manager2);

  box.pack_start(textbox);

  label2.set_text("Hello traveller! Where are you in the airport?");
  box.pack_start(label2);

  Nbutton.signal_clicked().connect(sigc::mem_fun(*this,&Moneywindow::button_1));
  box.pack_start(Nbutton);

  Wbutton.signal_clicked().connect(sigc::mem_fun(*this,&Moneywindow::button_2));
  box.pack_start(Wbutton);

  Sbutton.signal_clicked().connect(sigc::mem_fun(*this,&Moneywindow::button_3));
  box.pack_start(Sbutton);

  Ebutton.signal_clicked().connect(sigc::mem_fun(*this,&Moneywindow::button_4));
  box.pack_start(Ebutton);

  close1.signal_clicked().connect(sigc::mem_fun(*this,&Moneywindow::button_close1));
  box.pack_start(close1);

  show_all_children();
}

Moneywindow::~Moneywindow()
{

}

Secondwindow:: Secondwindow(string office1, string manager_name1):box1(Gtk::ORIENTATION_VERTICAL),RupButton("Rupee"),YenButton("Yen"),PesoButton("Peso"),EuroButton("Euro")//if users selects north or east
{
  add(box1);
  set_size_request(500,300);
  set_title("Currencies");
  set_position(Gtk::WIN_POS_CENTER_ALWAYS);

  label3.set_text("Welcome to "+office1+" department.\n Please contact the manager "+manager_name1+" if you have any complaints.");
  box1.pack_start(label3);

  label4.set_text("How much money would you like to convert?\n");
  box1.pack_start(label4);

  Currency.set_max_length(75);
  Currency.set_text("Amount Value");
  Currency.select_region(0,Currency.get_text_length());
  box1.pack_start(Currency);

  box1.pack_start(textbox1);

  label5.set_text("Select the currency below that you want to convert to dollars:");
  box1.pack_start(label5);

  RupButton.signal_clicked().connect(sigc::mem_fun(*this,&Secondwindow::button_5));
  box1.pack_start(RupButton);

  YenButton.signal_clicked().connect(sigc::mem_fun(*this,&Secondwindow::button_6));
  box1.pack_start(YenButton);

  PesoButton.signal_clicked().connect(sigc::mem_fun(*this,&Secondwindow::button_7));
  box1.pack_start(PesoButton);

  EuroButton.signal_clicked().connect(sigc::mem_fun(*this,&Secondwindow::button_8));
  box1.pack_start(EuroButton);

  show_all_children();
}

Secondwindow::~Secondwindow()
{

}

Thirdwindow:: Thirdwindow(string office2, string manager_name2):box1(Gtk::ORIENTATION_VERTICAL),RupButton("Rupee"),YenButton("Yen"),PesoButton("Peso"),EuroButton("Euro")//if users selects north or east
{
  add(box1);
  set_size_request(500,300);
  set_title("Currencies");
  set_position(Gtk::WIN_POS_CENTER_ALWAYS);

  label3.set_text("Welcome to "+office2+" department.\n Please contact the manager "+manager_name2+" if you have any complaints.");
  box1.pack_start(label3);

  label4.set_text("How much money would you like to convert to dollars?\n");
  box1.pack_start(label4);

  Currency.set_max_length(75);
  Currency.set_text("Amount Value");
  Currency.select_region(0,Currency.get_text_length());
  box1.pack_start(Currency);

  box1.pack_start(textbox1);

  label5.set_text("Select the currency below that you want to convert to dollars:");
  box1.pack_start(label5);

  RupButton.signal_clicked().connect(sigc::mem_fun(*this,&Thirdwindow::button_9));
  box1.pack_start(RupButton);

  YenButton.signal_clicked().connect(sigc::mem_fun(*this,&Thirdwindow::button_10));
  box1.pack_start(YenButton);

  PesoButton.signal_clicked().connect(sigc::mem_fun(*this,&Thirdwindow::button_11));
  box1.pack_start(PesoButton);

  EuroButton.signal_clicked().connect(sigc::mem_fun(*this,&Thirdwindow::button_12));
  box1.pack_start(EuroButton);

  show_all_children();
}

Thirdwindow::~Thirdwindow()
{

}

void Moneywindow::button_1()
{
  string office1 = Name1.get_text();
  for(int i = 0; i< office1.length();i++)
  {
    office1[i] = toupper(office1[i]);
  }
  string manager_name1 = Manager1.get_text();
  string::iterator it(manager_name1.begin());
  if(it!= manager_name1.end())
  {
    manager_name1[0] = toupper(manager_name1[0]);
  }
  while(++it!= manager_name1.end())
  {
    *it = tolower(*it);
  }
  Secondwindow t(office1,manager_name1);
  Gtk::Main::run(t);
}

void Moneywindow::button_2()
{
  string office2 = Name2.get_text();
  for(int i = 0; i< office2.length();i++)
  {
    office2[i] = toupper(office2[i]);
  }
  string manager_name2 = Manager2.get_text();
  string::iterator it(manager_name2.begin());
  if(it!= manager_name2.end())
  {
    manager_name2[0] = toupper(manager_name2[0]);
  }
  while(++it!= manager_name2.end())
  {
    *it = tolower(*it);
  }
  Thirdwindow s(office2,manager_name2);
  Gtk::Main::run(s);
}

void Moneywindow::button_3()
{
  string office2 = Name2.get_text();
  for(int i = 0; i< office2.length();i++)
  {
    office2[i] = toupper(office2[i]);
  }
  string manager_name2 = Manager2.get_text();
  string::iterator it(manager_name2.begin());
  if(it!= manager_name2.end())
  {
    manager_name2[0] = toupper(manager_name2[0]);
  }
  while(++it!= manager_name2.end())
  {
    *it = tolower(*it);
  }
  Thirdwindow s(office2,manager_name2);
  Gtk::Main::run(s);
}

void Moneywindow::button_4()
{
  string office1 = Name1.get_text();
  for(int i = 0; i< office1.length();i++)
  {
    office1[i] = toupper(office1[i]);
  }
  string manager_name1 = Manager1.get_text();
  string::iterator it(manager_name1.begin());
  if(it!= manager_name1.end())
  {
    manager_name1[0] = toupper(manager_name1[0]);
  }
  while(++it!= manager_name1.end())
  {
    *it = tolower(*it);
  }
  Secondwindow t(office1,manager_name1);
  Gtk::Main::run(t);
}

void Secondwindow::button_5()
{
  double convert = stof(Currency.get_text());
  convert = convert*0.0088;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Secondwindow::button_6()
{
  double convert = stof(Currency.get_text());
  convert = convert*0.0093;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Secondwindow::button_7()
{
  double convert = stof(Currency.get_text());
  convert = convert*0.0051;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Secondwindow::button_8()
{
  double convert = stof(Currency.get_text());
  convert = convert*1.10;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Thirdwindow::button_9()
{
  double convert = stof(Currency.get_text());
  convert = convert*0.0088;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Thirdwindow::button_10()
{
  double convert = stof(Currency.get_text());
  convert = convert*0.0093;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Thirdwindow::button_11()
{
  double convert = stof(Currency.get_text());
  convert = convert*0.0051;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Thirdwindow::button_12()
{
  double convert = stof(Currency.get_text());
  convert = convert*1.10;
  total_made = total_made + convert;
  stringstream newline;
  newline<<"$"<<fixed<<setprecision(2)<<convert<<".";
  string word = newline.str();
  Gtk::MessageDialog show(*this,"Here you go: "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("Thanks for using Money Converter!");
  show.run();
  hide();
}

void Moneywindow::button_close1()
{
  stringstream new_line;
  new_line<<"dollars given out in this session: $"<<fixed<<setprecision(2)<<total_made<<".";
  string word = new_line.str();
  Gtk::MessageDialog show(*this,"$$$Total "+word,false,Gtk::MESSAGE_INFO);
  show.set_secondary_text("See you again:)");
  show.run();
  hide();
}
