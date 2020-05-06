//Name: Yunika Upadhayaya        Student ID:1001631183

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class watch
{
protected:
    float age;
    float price;
    float input_price;
    float input_age;

public:
    vector <string> all_watches = {"Designer","Non-Designer","Antique"};
    vector <string> free_repair_list = {"piaget","cartier","rolex","tag heuer","panerai","omega","chopard"};

    void set_age(float enter_age)
    {
      age = enter_age;
    }
    void set_price(float enter_price)
    {
      price = enter_price;
    }
    void take_input()
    {
      cout<<"\n~~First, let's find the type of your watch.~~\n"<<endl;
      cout<<"Enter the original price of your watch:"<<endl;
      cout<<"$";
      cin>>input_price;
      cout<<"How old is your watch?"<<endl;
      cout<<"Age: ";
      cin>>input_age;
    }
};

class Customers:public watch
{
public:
      float repair_price;
      string material;
      string brand;

      void print_price()
      {
        if(input_age>=age && input_price>=price)
        {
          cout<<"\nYou have a very unique watch. It's both "<<all_watches[0]<<" and "<<all_watches[2]<<"!"<<endl;
          cout<<"\nWe have a special discount on repair cost for your watch!"<<endl;
          repair_price = (input_price/4) - (input_age/2);
        }
        else if(input_price>price)
        {
          cout<<"\nYou have a "<<all_watches[0]<<" watch!\n"<<endl;

          cout<<"Please enter the material used in your watch (gold or silver):"<<endl;
          cin.ignore();
          getline(cin,material);
          int w_length = material.length();
          for(int i = 0; i < w_length; i++)
          {
              material[i] = tolower(material[i]);
          }

          if(material == "gold")
          {
            repair_price = input_price/4;
          }
          else if (material == "silver")
          {
            repair_price = input_price/3;
          }
          else
          {
            repair_price = input_price/2;
          }
        }
        else if(input_age>=age)
        {
            cout<<"\nYou have an "<<all_watches[2]<<" watch!"<<endl;;
            repair_price = input_age/2;
        }
        else
        {
          cout<<"\nYou have a "<<all_watches[1]<<" watch!\n"<<endl;

          cout<<"Please enter the name of the brand of your watch:"<<endl;
          cin.ignore();
          getline(cin,brand);
          int w_length = brand.length();
          for(int i = 0; i < w_length; i++)
          {
              brand[i] = tolower(brand[i]);
          }

          if(find(free_repair_list.begin(), free_repair_list.end(), brand) == free_repair_list.end())
          {
              repair_price = input_price*0.15;
          }
          else
          {
            cout<<"\nYour watch is in our special free repair list!!!"<<endl;
            repair_price = 0.00;
          }
        }
        cout<<"\n~~~The repair cost of your watch is $"<<fixed<<setprecision(2)<<repair_price<<".~~~\n"<<endl;
      }
};

int main(int argc, char **argv)
{
  int choice;
  Customers C;
  C.set_age(50);
  C.set_price(800);
  cout<<"\n~~Welcome to our Watch Repair Shop~~\n"<<endl;

do
{
  cout<<"-----------------------------------"<<endl;
  cout<<"Please choose the following options:"<<endl;
  cout<<"1. Repair Watch"<<endl;
  cout<<"2. Exit"<<endl;
  cout<<"Choice: ";
  cin>>choice;

  if(choice==1)
  {
      C.take_input();
      C.print_price();
  }
  else if(choice == 2)
  {
    cout<<"\nThank you for visiting us!"<<endl;
    cout<<"Exiting...Hope to see you soon:).\n"<<endl;
    exit(0);
  }
  else
  {
    cout<<"\nValue out of range.\n"<<endl;
  }
}
while(choice!=0);
}
