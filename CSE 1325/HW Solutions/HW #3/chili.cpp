//Name: Yunika Upadhayaya  Student ID:1001631183

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Cup
{
  string name;
  int cup_size;
public:
  Cup(){}
  Cup(string name, int cup_size)
  {
    this->name = name;
    this->cup_size = cup_size;
  }

  string get_name()
  {
    return name;
  }
  int get_cupsize()
  {
    return cup_size;
  }
};

class Customers
{
  string name;
  Cup drink_size;
public:
  Customers(){}
  Customers(string name,Cup drink_size)
  {
    this->name = name;
    this->drink_size = drink_size;
  }
  string get_name()
  {
    return name;
  }
  Cup get_drinksize()
  {
    return drink_size;
  }
};

vector<Customers> Read_file(vector<Cup> catalog)
{
  vector<Customers> name_list;
  string intermediate;
  string drink_name;
  string whole_line;
  Cup drink;
  ifstream ifile;
  ifile.open("info.txt");
  if(!ifile.is_open())
  {
    cout<<"Sorry, the file could not be opened\nExiting..."<<endl;
    exit(0);
  }
  else
  {
    while(!ifile.eof())
    {
      getline(ifile,whole_line);

      stringstream delimeter(whole_line);
      getline(delimeter,intermediate,',');
      delimeter >> drink_name;

      for(int j =0; j<catalog.size(); j++)
      {
        if(drink_name == catalog.at(j).get_name())
        {
          drink = catalog.at(j);
          Customers put(intermediate,drink);
          name_list.push_back(put);
          break;
        }
      }
    }
  }
  return name_list;
}

bool print_chili(int &left_chili, int size)
{
  string ask;
  left_chili = left_chili - size;

  if(left_chili<0)
  {
    cout<<"Sorry, not enough Chili left. ";
    return true;
  }
  if (left_chili<2)
  {
    cout<<"Order Served. Not much Chili left!\n"<<endl;
  }
  else
  {
    cout<<"Order served. Still got lots of Chili!\n"<<endl;
  }
  while(ask != "continue" && ask != "break")
  {
    cout<<"Continue with orders or take a break?"<<endl;
    cin>>ask;
    if(ask == "break")
    {
      cout<<"\nOk. Press enter to continue when you are finished with your break."<<endl;
      cin.ignore();
      cin.get();
    }
    else if(ask!="continue")
    {
      cout<<"Invalid input. Please re-enter."<<endl;
    }
  }
  return false;
}

void size_cups(vector<Cup> &catalog)
{
  Cup s1("Venti",2);
  Cup s2("Grande",2);
  Cup s3("Tall",1);
  Cup s4("Short",1);

  catalog.push_back(s1);
  catalog.push_back(s2);
  catalog.push_back(s3);
  catalog.push_back(s4);
}

int main(int argc, char** argv)
{
  int num = 0;
  int batches = 0;
  bool check = false;
  bool answer = true;
  string new_batch;
  int  i =0;
  cout<<"--Welcome Louise--\n"<<endl;
  cout<<"Checking today's Customers...done!"<<endl;
  cout<<"How many batches of your famous chili are you making?"<<endl;
  cin>>num;
  batches = 4*num; //total cups
  cout<<"\nStarting orders..."<<endl;

  vector <Cup> drink_list;
  size_cups(drink_list);
  vector <Customers> new_list = Read_file(drink_list);

  for(int i = 0; i<new_list.size();i++)
  {
    cout<<"\nCustomer "<<(i+1)<<": "<<new_list.at(i).get_name()<< "'s order is " <<new_list.at(i).get_drinksize().get_name()<<endl;
    check = print_chili(batches,new_list.at(i).get_drinksize().get_cupsize());
    if(check)
    {
      while(answer)
      {
        cout<<"Would you like to continue with another batch or quit? (Enter Yes or Quit)"<<endl;
        cin>>new_batch;

        if(new_batch == "Quit")
        {
          answer = false;
          exit(1);
        }
        else if(new_batch == "Yes")
        {
          batches = batches + 4;
          i--;
          answer = false;
        }
        else
        {
          cout<<"Invalid choice.Please re-enter:"<<endl;
          answer = true;
        }
      }
      answer=true;
    }
    if(new_batch== "Quit")
    {
      break;
    }
 }
cout<<"\nNo more customers. All customers served!!"<<endl;
}
