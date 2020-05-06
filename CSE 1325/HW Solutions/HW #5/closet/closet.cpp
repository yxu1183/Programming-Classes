//Name: Yunika Upadhayaya     Student ID:1001631183

#include <iostream>
#include "closet.h"
#include <gtkmm.h>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

float total_sales = 0.00 ;
vector <string> all_item_name;
vector <float> all_item_price;
string ownername;

Main_Window::Main_Window():box(Gtk::ORIENTATION_VERTICAL),exit("Exit"),Seller("Sell Item"),Buyer("Buy Item"),Total("Check Balance")
{
  add(box);
  set_size_request(600,400);
	set_title("***Marko's closet***");

  Seller.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::on_seller_button));
  box.pack_start(Seller);

  Buyer.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::on_buyer_button));
  box.pack_start(Buyer);

  Total.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::total_sales_button));
  box.pack_start(Total);

	exit.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::close));
  box.pack_start(exit);
  box.show_all();
}

Seller_Window::Seller_Window():box(Gtk::ORIENTATION_VERTICAL),continueButton("Continue")
{
  add(box);
  set_size_request(400,200);
  set_title("Sell Items");

  label.set_text("Hello closet cleaner! Enter your name:");
  box.pack_start(label);

  Name.set_max_length(75);
  Name.set_text("Name");
  Name.select_region(0,Name.get_text_length());
  box.pack_start(Name);

  label1.set_text("How many items do you want to sell?");
  box.pack_start(label1);

  Item.set_max_length(75);
  Item.set_text("Number");
  Item.select_region(0,Item.get_text_length());
  box.pack_start(Item);

  box.pack_start(textbox);

  continueButton.signal_clicked().connect(sigc::mem_fun(*this,&Seller_Window::continue_button));
  box.pack_start(continueButton);

  show_all_children();
}

Add_window::Add_window():box(Gtk::ORIENTATION_VERTICAL),DoneButton("Add to Closet!")
{
  add(box);
  set_size_request(300,200);
  set_title("Add Items");

  label.set_text("Enter item and price:");
  box.pack_start(label);

  Item_Price.set_max_length(75);
  Item_Price.set_text("Item and price:");
  Item_Price.select_region(0,Item_Price.get_text_length());
  box.pack_start(Item_Price);

  box.pack_start(textbox);

  DoneButton.signal_clicked().connect(sigc::mem_fun(*this,&Add_window::Done_button));
  box.pack_start(DoneButton);
  show_all_children();
}

Buyer_Window::Buyer_Window():box(Gtk::ORIENTATION_VERTICAL),SearchButton("Search")
{
  add(box);
  set_size_request(400,200);
  set_title("Buy Items");

  label.set_text("Hello shopper! What items are you looking for?");
  box.pack_start(label);

  Item.set_max_length(75);
  Item.set_text("Items");
  Item.select_region(0,Item.get_text_length());
  box.pack_start(Item);

  box.pack_start(textbox);

  SearchButton.signal_clicked().connect(sigc::mem_fun(*this,&Buyer_Window::Search_button));
  box.pack_start(SearchButton);
  show_all_children();
}

void Main_Window::on_seller_button()
{
  Seller_Window s;
  Gtk::Main::run(s);
}

void Main_Window::on_buyer_button()
{
  Buyer_Window b;
  Gtk::Main::run(b);
}

void Main_Window::total_sales_button()
{
  ostringstream ss;
  ss<<"Hello "<<ownername<<"! So far you have made $"<<total_sales<<".";
  string line = ss.str();
  Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_INFO);
  dialog.run();
}

void Main_Window::close()
{
  string line = "Bye!";
  Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_INFO);
  //set_secondary_text("See you again!!");
  dialog.run();
  hide();
}

void Seller_Window::continue_button()
{
  string ownername = Name.get_text();
  string name = Item.get_text();
  int number = stof(name);

  for(int i = 0; i<number; i++)
  {
    Add_window a;
    Gtk::Main::run(a);
  }
  Gtk::MessageDialog show(*this,"Done adding items to the closet!",false,Gtk::MESSAGE_INFO);
  show.run();
  hide();
}

void Add_window::Done_button()
{
  string item = Item_Price.get_text();
  stringstream ss(item);
  string item_name;
  float item_price;
  ss>>item_name>>item_price;
  all_item_name.push_back(item_name);
  all_item_price.push_back(item_price);
  hide();
}

void Buyer_Window::Search_button()
{
  int tracker = 0;
  string buyer_item = Item.get_text();
  stringstream ss(buyer_item);
  string item_name;
  float item_price;
  ss>>item_name>>item_price;

  for(int i = 0; i<all_item_name.size();i++)
  {
    int j =0;
    if(all_item_name[i] == item_name)
    {
      ostringstream ss;
      ss<<"We have "<<all_item_name[i]<<" for $"<<fixed<<setprecision(2)<<all_item_price[j]<<". Would you like to buy them?";
      string line = ss.str();
      Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
      int run = dialog.run();

      if(run == Gtk::RESPONSE_YES)
      {
        all_item_name.erase(all_item_name.begin()+i);
        all_item_price.erase(all_item_price.begin()+j);
        total_sales = total_sales + all_item_price[j];
        tracker = 1;
      }
    }
    j++;
  }

  if(tracker == 1)
  {
    string line = "Ok, Your item has been purchased.";
    Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_INFO);
    dialog.run();
  }
  else
  {
    string line = "Sorry! We don't have that.";
    Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_INFO);
    dialog.run();
  }
  hide();
}
