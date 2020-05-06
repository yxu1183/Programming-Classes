//Name: Yunika Upadhayaya     Student ID:1001631183

#include <iostream>
#include "choice.h"
#include <gtkmm.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

float delivery_fee = 3.49;
string burrito_bowl;
string pick1 = "";
string pick2 = "";
string pick3 = "";
vector<string> all_persons;
int delivery_index = 0;
float burrito_bowl_price = 0.00;
float total_made = 0.00;

void ReadFile()
{
  ifstream inFile;
  string line;

  inFile.open("deliveries.txt");

  if(!inFile.is_open())
  {
    cout<<"Sorry, unable to open the file.\nExiting...";
    exit(1);
  }

  while(!inFile.eof())
  {
    string intermediate;

    string whole_line;
    string firstname;
    string lastname;

    getline(inFile,whole_line);
    stringstream separate_line(whole_line);

    getline(separate_line,intermediate,' ');
    firstname = intermediate;

    getline(separate_line,intermediate,' ');
    lastname = intermediate;

    all_persons.push_back(firstname);
  }
  inFile.close();
}

void WriteFile()
{
  ofstream Ofile;
  Ofile.open("total.txt");
  if(!Ofile.is_open())
  {
    cout<<"Cannot open the file!"<<endl;
    exit(1);
  }
  Ofile<<"Total made :$"<<total_made;
}

Main_Window::Main_Window():box(Gtk::ORIENTATION_VERTICAL),exit("Exit"),Customer("Customer"),Apply("Apply")
{
  add(box);
  set_size_request(500,200);
  set_border_width(25);
	set_title("***RONNIE'S DELIVERY SERVICE***");

  Customer.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::on_Customer_button));
  box.pack_start(Customer);

  Apply.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::on_Apply_button));
  box.pack_start(Apply);

	exit.signal_clicked().connect(sigc::mem_fun(*this,&Main_Window::close));
  box.pack_start(exit);
  box.show_all();
}

CustomerWindow::CustomerWindow():box(Gtk::ORIENTATION_VERTICAL)
{
  add(box);
  set_size_request(500,100);
  set_border_width(25);
  set_title("Place your order");

  label.set_text("Burrito or Bowl? Select one:");
  box.pack_start(label);

  Burrito.add_label("Burrito");
  Bowl.add_label("Bowl");

  Bowl.join_group(Burrito);

  box.pack_start(Burrito);
  box.pack_start(Bowl);

  Burrito.signal_clicked().connect(sigc::mem_fun(*this,&CustomerWindow::on_burrito_button));
  Bowl.signal_clicked().connect(sigc::mem_fun(*this,&CustomerWindow::on_bowl_button));

  Bowl.set_active();

  box.pack_start(separator);
  label1.set_text("Click below to continue with the order or exit:");
  box.pack_start(label1);

  continuebutton.add_label("Continue");
  continuebutton.signal_clicked().connect(sigc::mem_fun(*this,&CustomerWindow::on_continue_button));
  box.pack_start(continuebutton);

  exit.add_label("Exit");
  exit.signal_clicked().connect(sigc::mem_fun(*this,&CustomerWindow::close));
  box.pack_start(exit);
  show_all_children();
}

PickWindow::PickWindow()
{
  set_size_request(500,400);
  set_border_width(25);
  set_title("Pick your stuffings");

  add(box1);
  box1.pack_start(box2);
  box1.pack_start(separtor1);
  box1.pack_start(box3);
  box1.pack_start(separtor2);
  box1.pack_start(box4);
  box1.pack_start(separtor3);
  box1.pack_start(box5);
  box1.pack_start(separtor4);
  box1.pack_start(box6);

  label.set_text("You can choose more than one stuffing in one pick!");
  box2.pack_start(label);

  label1.set_text("First Pick:");
  box3.pack_start(label1);

  radiobutton_1.add_label("Tofu");
  radiobutton_2.add_label("Steak");
  radiobutton_3.add_label("Chicken");

  radiobutton_1.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton1));
  radiobutton_2.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton2));
  radiobutton_3.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton3));

  box3.pack_start(radiobutton_1);
  box3.pack_start(radiobutton_2);
  box3.pack_start(radiobutton_3);

  label2.set_text("Second Pick:");
  box4.pack_start(label2);

  radiobutton_4.add_label("Cilantro-Lime Brown");
  radiobutton_5.add_label("Cilanto-Lime White");

  radiobutton_4.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton4));
  radiobutton_5.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton5));

  box4.pack_start(radiobutton_4);
  box4.pack_start(radiobutton_5);

  label3.set_text("Third Pick:");
  box5.pack_start(label3);

  radiobutton_6.add_label("Queso");
  radiobutton_7.add_label("Sour Cream");
  radiobutton_8.add_label("Fresh Tomoato Salse");

  radiobutton_6.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton6));
  radiobutton_7.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton7));
  radiobutton_8.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_radiobutton8));

  box5.pack_start(radiobutton_6);
  box5.pack_start(radiobutton_7);
  box5.pack_start(radiobutton_8);

  newContinue.add_label("Continue with the order");
  newContinue.signal_clicked().connect(sigc::mem_fun(*this,&PickWindow::on_order_button));
  box6.pack_start(newContinue);

  show_all_children();
}

ApplyWindow::ApplyWindow():box(Gtk::ORIENTATION_VERTICAL),continueButton("Continue")
{
  add(box);
  set_size_request(500,200);
  set_title("Apply");

  label.set_text("Enter your full name:");
  box.pack_start(label);

  Name.set_max_length(75);
  Name.set_text("Name");
  Name.select_region(0,Name.get_text_length());
  box.pack_start(Name);

  box.pack_start(textbox);

  continueButton.signal_clicked().connect(sigc::mem_fun(*this,&ApplyWindow::continue_button));
  box.pack_start(continueButton);

  show_all_children();
}

void ApplyWindow::continue_button()
{
  string full_name = Name.get_text();
  string firstname;
  string lastname;
  stringstream ss(full_name);
  ss>>firstname>>lastname;

  string::iterator it(firstname.begin());
  if(it!=firstname.end())
  {
    firstname[0]=toupper(firstname[0]);
  }
  while(++it!=firstname.end())
  {
    *it = tolower(*it);
  }
  Gtk::MessageDialog dialog(*this,"Newest delivery person: "+firstname+".",false,Gtk::MESSAGE_INFO);
  dialog.run();
  hide();
}

void Main_Window::on_Customer_button()
{
  CustomerWindow c;
  Gtk::Main::run(c);
}

void Main_Window::on_Apply_button()
{
  ApplyWindow a;
  Gtk::Main::run(a);
}

void CustomerWindow::close()
{
  hide();
}

void CustomerWindow::on_burrito_button()
{
  burrito_bowl_price = 6.99;
  if(Burrito.get_active())
  {
    burrito_bowl = "Burrito";
  }
}

void CustomerWindow::on_bowl_button()
{
  burrito_bowl_price = 8.99;
  if(Bowl.get_active())
  {
    burrito_bowl = "Bowl";
  }
}

void CustomerWindow::on_continue_button()
{
  PickWindow P;
  Gtk::Main::run(P);
  hide();
}

void Main_Window::close()
{
  ostringstream ss;
  ss<<"You made a total of $"<<fixed<<setprecision(2)<<total_made<<" in this session!";
  string line = ss.str();
  Gtk::MessageDialog dialog(*this,line,false,Gtk::MESSAGE_INFO);
  dialog.set_secondary_text("Thank you for using our delivering service.");
  dialog.run();
  hide();
}

void PickWindow::on_radiobutton1()
{
  if(radiobutton_1.get_active())
  {
    pick1 = pick1 + "\nTofu";
  }
}

void PickWindow::on_radiobutton2()
{
  if(radiobutton_2.get_active())
  {
    pick1 = pick1 + "\nSteak";
  }
}

void PickWindow::on_radiobutton3()
{
  if(radiobutton_3.get_active())
  {
    pick1 = pick1 + "\nChicken";
  }
}

void PickWindow::on_radiobutton4()
{
  if(radiobutton_4.get_active())
  {
    pick2 = pick2 + "\nCilantro-Lime Brown";
  }
}

void PickWindow::on_radiobutton5()
{
  if(radiobutton_5.get_active())
  {
    pick2 = pick2 + "\nCilantro-Lime White";
  }
}

void PickWindow::on_radiobutton6()
{
  if(radiobutton_6.get_active())
  {
    pick3 = pick3 + "\nQueso";
  }
}

void PickWindow::on_radiobutton7()
{
  if(radiobutton_7.get_active())
  {
    pick3 = pick3 + "\nSour Cream";
  }
}

void PickWindow::on_radiobutton8()
{
  if(radiobutton_8.get_active())
  {
    pick3 = pick3 + "\nFresh Tomato Salse";
  }
}

void PickWindow::on_order_button()
{
    ostringstream ss;
    ss<<burrito_bowl<<": "<<pick1<<pick2<<pick3<<"";
    pick1 ="";
    pick2 ="";
    pick3 ="";
    string line = ss.str();
    Gtk::MessageDialog dialog(*this,line,false,Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
    dialog.set_secondary_text("Confirm with the order?");
    int run = dialog.run();

    if(run == Gtk::RESPONSE_YES)
    {
      ostringstream ss;
      ReadFile();
      ss<<"Your price will be $"<<fixed<<setprecision(2)<<burrito_bowl_price<<" with a delivery fee of $"<<delivery_fee<<".\nAnd, "<<all_persons[delivery_index]<<" will be delivering your order!";
      string line = ss.str();
      Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_INFO);
      dialog.set_secondary_text("Thank you! See you soon:)");
      delivery_index++;
      dialog.run();
      total_made = total_made + burrito_bowl_price + delivery_fee;
      WriteFile();
      hide();
    }
    else
    {
      ostringstream ss;
      ss<<"Sorry to see you go:(";
      string line = ss.str();
      Gtk::MessageDialog dialog(*this, line, false, Gtk::MESSAGE_INFO);
      dialog.set_secondary_text("Hope to see you soon..");
      dialog.run();
      hide();
    }
}
