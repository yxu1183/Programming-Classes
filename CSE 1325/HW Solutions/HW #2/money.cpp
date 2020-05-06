//Name: Yunika Upadhayaya  Student ID:1001631183

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class convert_capital
{
	float capital;
	public:
	convert_capital(int change)
	{
		this->capital=change;
	}
	float NcToUsdollar()
	{
		capital = capital * 0.0088;
    return capital;
	}
  float yenToUsdollar()
  {
    capital = capital * 0.0093;
    return capital;
  }
  float pesoToUsdollar()
  {
    capital = capital * 0.051;
    return capital;
  }
	float euroToUsdollar()
	{
		capital = capital * 1.10;
    return capital;
	}
};

class find_currency
{
	float Changed;
	public:
	find_currency(float worth, string money)
	{
		convert_capital c(worth);
    Changed = 0.0;
    int money_length = money.length();
    for(int i = 0; i < money_length; i++)
    {
      money[i] = tolower(money[i]);
    }
    if(money == "rupee")
		{
			Changed = c.NcToUsdollar();
		}
    if(money == "yen")
    {
      Changed = c.yenToUsdollar();
    }
    if(money == "peso")
    {
      Changed = c.pesoToUsdollar();
    }
		if(money == "euro")
		{
			Changed = c. euroToUsdollar();
		}
	}
	float ChangedDollars()
	{
		return Changed;
	}
};

int main(int argc, char **argv)
{
  string first_input, second_input;
  string first_office,first_department,first_manager;
	string second_office,second_department,second_manager;
	string direction;
  string main_office, main_manager, main_department;
  float money = 0.0;
	string currency;
  float converted_total;

	cout<<"Enter name of exchange office and manager: ";
  getline(cin, first_input);
  stringstream ss(first_input);
  ss>>first_office>>first_department>>first_manager;

  cout<<"Enter name of exchange office and manager: ";
  getline(cin,second_input);
  stringstream bb(second_input);
	bb>>second_office>>second_department>>second_manager;

  cout<<endl;
  cout<<"********"<<endl;
  cout<<"Hello traveller! Where are you in the airport? ";
  cin>>direction;
  int direction_length = direction.length();
  for(int i = 0; i < direction_length; i++)
  {
    direction[i] = tolower(direction[i]);
  }
  cout<<"********"<<endl;

  while(direction!="exit")
	{
    if((direction =="north") || (direction=="east"))
		{
			main_office = first_office;
			main_department = first_department;
			main_manager = first_manager;
		}
		if((direction == "south") || (direction == "west"))
		{
      main_office = second_office;
      main_department = second_department;
      main_manager = second_manager;
		}
    cout<<"Welcome to "<<main_office<<" "<<main_department<<".";
    cout<<" Please contact the manager "<<main_manager<<" if you have any complaints."<<endl;
    cout<<"What currency are you converting to dollars and how much? ";
    cin>>money>>currency;

    find_currency find(money,currency);
		converted_total = converted_total + find.ChangedDollars();

		if(find.ChangedDollars()==0)
		{
      cout<<"We do not convert the "<<currency<<" currency here. Sorry.\n\n"<<endl;
		}
		else
		{
      cout<<"Here you go: $"<<fixed<<setprecision(2)<<find.ChangedDollars()<<endl;
			cout<<"\n\n";
    }
    cout<<"********"<<endl;
    cout<<"Hello traveller! Where are you in the airport? ";
	  cin>>direction;
	  cout<<"********"<<endl;
  }
  cout<<"$$$Total dollars given out: $"<<fixed<<setprecision(2)<<converted_total<<endl;
	cout<<"Exiting... "<<endl;
}
