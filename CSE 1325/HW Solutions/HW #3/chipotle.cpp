//Name: Yunika Upadhayaya   Student ID: 1001631183

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

string convert_lower(string name)
{
  int name_length = name.length();
  for(int i = 0; i < name_length; i++)
  {
    name[i] = tolower(name[i]);
  }
  return name;
}

class Customer
{
public:
  vector<string> all_persons;
  float total =0.00;
  int delivery_index = 0;
  Customer()
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
    //cout<<"Second member: "<<all_persons.at(1)<<endl;
    inFile.close();
  }

  void orders()
  {
    float delivery = 3.49;
    float price = 0.00;
    vector<string>all_orders;

    string order;
    string pick1;
    string pick2;
    string pick3;
    string ask;

    cout<<"\n***Please place your order***"<<endl;
    cout<<"Burrito or Bowl?"<<endl;
    cin>>order;
    cout<<"\n";
    string lower_order = convert_lower(order);
    while((lower_order!="burrito")&&(lower_order!="bowl"))
    {
      cout<<"Invalid Input."<<endl;
      cout<<"Please enter Burrito or Bowl:"<<endl;
      cin>>order;
      lower_order = convert_lower(order);
    }

    string::iterator it(order.begin());

    if(it!= order.end())
    {
      order[0] = toupper(order[0]);
    }
    while(++it!= order.end())
    {
      *it = tolower(*it);
    }

    all_orders.push_back(order);

    if(lower_order == "burrito")
    {
      price = 6.99;
    }
    if(lower_order =="bowl")
    {
      price = 8.50;
    }
    cout<<"Your price will be $"<<price<<" with the delivery fee of $"<<delivery<<"."<<endl;
    total = total + price + delivery;

    vector<string> topping{"Tofu", "Steak", "Chicken"};
    cout << "\n-Pick: ";
    for(int i = 0; i < topping.size(); i++)
    {
      if (i == topping.size() - 1) {
        cout << topping.at(i);
      } else {
        cout << topping.at(i) + ", ";
      }
    }
    cout << endl;
    cin.ignore();
    getline(cin,pick1);
    if(pick1 != "none"&&pick1 != "None")
    {
      all_orders.push_back(pick1);
    }

    cout<<"\n-Pick: Cilantro-Lime Brown,Cilantro-Lime White"<<endl;
    getline(cin,pick2);
    if(pick2 != "none"&& pick2 != "None")
    {
      all_orders.push_back(pick2);
    }

    cout<<"\n-Pick: Queso,Sour Cream,Fresh Tomato Salsa"<<endl;
    getline(cin,pick3);
    if(pick3 != "none"&& pick3 !="None")
    {
      all_orders.push_back(pick3);
    }
    cout<<"\nConfirm order(yes or no):"<<endl;
    cout<<all_orders[0]<<": ";
  	for(int i=1;i<all_orders.size()-1;i++)
  	{
  		cout<<all_orders[i]<<",";
  	}
  	cout<<all_orders.back()<<endl;
    cin>>ask;
    cout<<"\n";
    string new_lower = convert_lower(ask);

    while((new_lower!= "no")&&(new_lower!="yes"))
    {
      cout<<"Invalid instrcution."<<endl;
      cout<<"Please enter yes or no:"<<endl;
      cin>>ask;
      cout<<"\n";
      new_lower = convert_lower(ask);
    }

    if(new_lower== "yes")
    {
      cout<<"Ok. "<<all_persons[delivery_index]<<" will be delivering your order.Thank you!\n"<<endl;
      delivery_index++;
    }

    ofstream Ofile;
    Ofile.open("total.txt");
    if(!Ofile.is_open())
    {
      cout<<"Cannot open the file!"<<endl;
      exit(1);
    }
    Ofile<<"Total made :$"<<total;
  }

  double get_total()
  {
    return total;
  }

};

class Apply
{
public:
  Apply()
  {}
    void new_delivery()
    {
      ofstream outputfile;
      outputfile.open("new_delivery.txt");
      if(!outputfile.is_open())
      {
        cout<<"Cannot open the file";
        exit(1);
      }
      else
      {
        string fname;
        string lname;
        cout<<"Enter your full name: ";
        cin>>fname>>lname;
        cout<<"Newest delivery person: "<<fname<<"\n"<<endl;
        outputfile<<fname<<" "<<lname;
        outputfile.close();
      }
    }
  };

  int main(int argc,char **argv)
  {
    Customer c;
    Apply a;
    int chose = 0;
    cout<<"\n~~Ronnie's Delivery Service~~\n"<<endl;

do
{
    cout<<"-----------------------------------\n"<<endl;
    cout<<"Pick from the following menu:"<<endl;
    cout<<"1.Customer"<<endl;
    cout<<"2.Apply"<<endl;
    cout<<"3.Exit"<<endl;
    cin>>chose;

    if(chose==1)
    {
      c.orders();

    }
    else if(chose==2)
    {
      a.new_delivery();
    }
    else if(chose==3)
    {
      cout<<"Exiting..."<<endl;
      cout<<"Total made:$"<<c.get_total()<<endl;
      exit(1);
    }
    else
    {
      cout<<"Value out of range";
    }
 }
 while(chose!=3);
}
