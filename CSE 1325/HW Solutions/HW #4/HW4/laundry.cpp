//Name: Yunika Upadhayaya      Student ID: 1001631183

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Laundromat
{
protected:
  vector <int> available_machines;
  vector <string> name_machines;
  vector <string> all_name;
  vector <string> all_id;
  vector <float> all_balance;
  vector <float> all_detergent_amount;
public:
  void ReadFile1()
  {
    ifstream inputFile;
    inputFile.open("machines.txt");

    if(!inputFile.is_open())
    {
      cout<<"Sorry, unable to open the file.\nExiting...";
      exit(0);
    }
    while(!inputFile.eof())
    {
      string intermediate;
      string whole_line;
      string machines;
      int num_machines;

      getline(inputFile,whole_line);
      stringstream separate_line(whole_line);

      getline(separate_line,intermediate,',');
      machines = intermediate;

      getline(separate_line,intermediate,',');
      num_machines = stoi(intermediate);

      available_machines.push_back(num_machines);
      name_machines.push_back(machines);
    }
    cout<<"***AVAILABLE***"<<endl;
    int j =0;
    for(int i = 0 ;i <name_machines.size();i++)
    {
      cout<<name_machines[i]<<" Machines: "<<available_machines[j]<<endl;
      j++;
    }
  }

  void ReadFile2()
  {
    ifstream inputFile;
    inputFile.open("users.txt");

    if(!inputFile.is_open())
    {
      cout<<"Sorry, unable to open the file.\nExiting...";
      exit(0);
    }

    while(!inputFile.eof())
    {
      string intermediate;
      string whole_line;
      string name;
      string id;
      float balance;
      int detergent_amount;

      getline(inputFile,whole_line);
      stringstream separate_line(whole_line);

      getline(separate_line,intermediate,',');
      name = intermediate;
      all_name.push_back(name);

      getline(separate_line,intermediate,',');
      id = intermediate;
      all_id.push_back(id);

      getline(separate_line, intermediate,',');
      balance = stof(intermediate);
      all_balance.push_back(balance);

      getline(separate_line,intermediate);
      detergent_amount = stoi(intermediate);
      all_detergent_amount.push_back(detergent_amount);
    }
    cout<<"\nAll Registered Users info read in.\n"<<endl;
  }
  void display_discount()
  {
    cout<<"\n***AVAILABLE***"<<endl;
    int j = 1;
    for(int i = 1; i<name_machines.size();i++)
    {
      cout<<name_machines[i]<<" Machines: "<<available_machines[j]<<endl;
      j++;
    }
  }
  void display_regular()
  {
    cout<<"\n***AVAILABLE***"<<endl;
    int j = 0;
    for(int i = 0; i<name_machines.size()-1;i++)
    {
      cout<<name_machines[i]<<" Machines: "<<available_machines[j]<<endl;
      j++;
    }
  }
  void display_elite()
  {
    cout<<"\n***AVAILABLE***"<<endl;
    int j = 0;
    for(int i = 0; i<name_machines.size();i++)
    {
      cout<<name_machines[i]<<" Machines: "<<available_machines[j]<<endl;
      j++;
    }
  }
};

class Machine
{
protected:
  float price;
  float detergent_amount ;
  vector <string> members_type = {"Discount","Regular","Elite"};

  string machine;
};

class Display
{
protected:
  string machine;
  vector <string> machines_type = {"Fast","Slow","Very Slow"};
public:
  void check_machine()
  {
    int price = 50;
    int  detergent_amount = 2;
    cout<<"~Which machine would you like to use?"<<endl;
    cin>>machine;

    if(machine == machines_type[0])
    {
      cout<<"~Ok, using "<<price<<" centa and putting "<<detergent_amount<<" oz of the detergent."<<endl;
      cout<<"~Loading machines..\n"<<endl;
    }

    price = 35;
    detergent_amount = 1.5;
    if(machine == machines_type[1])
    {
      cout<<"~Ok, using "<<price<<" centa and putting "<<detergent_amount<<" oz of the detergent."<<endl;
      cout<<"~Loading machines..\n"<<endl;
    }

    price = 25;
    detergent_amount = 1;
    if(machine == machines_type[2])
    {
      cout<<"~Ok, using "<<price<<" cents and putting "<<detergent_amount<<" oz of the detergent."<<endl;
      cout<<"~Loading machines..\n"<<endl;
    }
  }
};

class Person: public Display,public Machine,public Laundromat
{
protected:
  string input_ID;
  string sub_id;
  int id;
  string laundry;
public:
  void input_user()
  {
      cout<<"~Please enter your ID:"<<endl;
      cin >> input_ID;

      while(input_ID != "exit")
      {
        sub_id = input_ID.substr(1,3);
        id = stoi(sub_id);
        if(find(all_id.begin(), all_id.end(), input_ID) != all_id.end())
        {

          if(id>=100 && id<=500)
          {
            cout<<"\n~Welcome "<<members_type[0]<<" member."<<endl;
          }
          else if(id>=501 && id<=900)
          {
            cout<<"\n~Welcome "<<members_type[1]<<" member."<<endl;
          }
          else if(id>=901 && id<=999)
          {
            cout<<"\n~Welcome "<<members_type[2]<<" member."<<endl;
          }
          else
          {
            cout<<"\n~Sorry, you do not match our member types."<<endl;
            cout<<"-----------"<<endl;
          }
        }
        else
        {
          cout<<"\nSorry, we do not have this ID registered."<<endl;
          cout<<"-----------"<<endl;
        }

        cout<<"1) Start a laundry load:"<<endl;
        cout<<"2)Finish a laundry load:"<<endl;
        cin>>laundry;

        if(laundry == "start")
        {
          if(id>=100 && id<=500)
          {
            display_discount();
            check_machine();
          }
          if(id>=501 && id<=900)
          {
            display_regular();
            check_machine();
          }
          if(id>=901 && id<=999)
          {
            display_elite();
            check_machine();
          }
        }
        else
        {
          cout<<"You currently have"<<endl;
        }
        cout<<"~Please enter your ID:"<<endl;
        cin >> input_ID;
      }
    }
  };

int main(int argc, char **argv)
{
  Laundromat L;
  Person P;
  cout<<"\nWELCOME!"<<endl;
  cout<<"Laundromat info read in:\n"<<endl;
  P.ReadFile1();
  P.ReadFile2();
  P.input_user();
}
