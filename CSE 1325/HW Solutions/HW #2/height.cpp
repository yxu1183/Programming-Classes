//Name: Yunika Upadhayaya  Student ID:1001631183

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rider
{
      string name;
      int height;
    public:
      Rider(string name, int height)
      {
          this->name = name;
          this->height = height;
      }
      Rider(int height)
      {
          this->height = height;
      }
      int get_height()
      {
          return height;
      }
};

class Ride
{
    public:
      string name;
      int minimum_height;
      void add_line(Rider p)
      {
          if(p.get_height()>=minimum_height)
          {
              cout<<"-Adding rider to line.\n"<<endl;
          }
          else
          {
              cout<<"-Sorry can't add rider-too short.\n"<<endl;
          }
      }
};

class Amusement_park
{
    int rides;
    vector <Ride> all_rides;

    public:
      Amusement_park (int rides)
      {
          int ride_height;
          string ride_name;
          Ride new_ride;
          cout<<"\n~~~Amusement Park Info~~~"<<endl;
          for (int i=0;i<rides;i++)
          {
              cout<<"Ride" <<(i+1)<<"- Enter minimum ride height and ride name:"<<endl;
              cin>>ride_height>>ride_name;
              cout<<"\n"<<endl;
              new_ride.minimum_height = ride_height;
              new_ride.name = ride_name;
              all_rides.push_back(new_ride);
          }

      }

      Ride get_ride(int i)
      {
          return all_rides[i-1];
      }
};

int	main()
{
			Rider	r1("Yaris",	45);	//name,	height	in	inches
			Rider	r2(49);	//height	in	inches
			Amusement_park	a1(3);	//3	is	the	number	of	rides	in	the	amusement	park
			a1.get_ride(1).add_line(r1);		//add	a	rider	to	the	line	of	a	ride
			Amusement_park	a2(2);	//2	is	the	number	of	rides	in	the	amusement	park
			a2.get_ride(1).add_line(r2);	//add	a	rider	to	the	line	of	a	ride
			return	0;
}
