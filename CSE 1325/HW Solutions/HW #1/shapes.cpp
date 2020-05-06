//Name: Yunika Upadhayaya   Student ID: 1001631183

#include <iostream>
#include <string>

using namespace std;

void convert (string &name) //"convert" function converts the entered word into lowercase
{
    int name_length = name.length();
    for(int i = 0; i < name_length; i++)
    {
        name[i] = tolower(name[i]);
    }
}

void check_shape(string shape) //"check_shape" fucntion checks the entered shape and displays information about calculations for the shape
{
    if(shape == "triangle")
    {
        cout<<"area = (base*height)/2"<<endl;
        cout<<"perimeter = sum of length of all sides\n"<<endl;
    }
    else if(shape == "square")
    {
          cout<<"area = length*length"<<endl;
          cout<<"perimeter = 4*length\n"<<endl;
    }
    else if(shape == "rectangle")
    {
         cout<<"area = length*breadth"<<endl;
          cout<<"perimeter = 2*(length+breadth)\n"<<endl;
    }
    else if(shape == "circle")
    {
        cout<<"area = pi*radius*radius"<<endl;
        cout<<"perimeter = 2*pi*radius\n"<<endl;
    }
    else if((shape == "pentagon")|| (shape == "hexagon")||(shape == "heptagon")||(shape == "octagon"))
    {
        cout<<"perimeter = sum of length of all sides\n"<<endl;
    }
    else if (shape != "exit")
    {
        cout<<"Sorry, information for this shape is not available.\n"<<endl;
    }
}

int main(int argc, char **argv)
{
    cout<<"\n********\n"<<endl; //output to screen
    cout<<"Shapes!\n"<<endl;
    cout<<"********\n"<<endl;

    string shape;
    int i = 0;

    while(shape!="exit")
    {
        cout<<(i+1)<<". Shape: "<<endl;
        cin>>shape;
        convert(shape);
        check_shape(shape);
        i++;
    }
    cout<<"\n-"<<(i-1)<<" shapes entered.\nExiting..."<<endl;
}
