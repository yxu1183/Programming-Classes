//Name: Yunika Upadhayaya    Student ID: 1001631183

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void convert (string &word) //"convert" function converts the entered word into lowercase
{
    int w_length = word.length();
    for(int i = 0; i < w_length; i++)
    {
        word[i] = tolower(word[i]);
    }
}

void convert_weight(string name, string weight_type, double weight_num) //"convert_weight" function converts the given weight
{                                                                      // from kilos to pounds and viceversa

    name[0] = toupper(name[0]);//converts first letter of the name to uppercase
    if(weight_type == "pounds")
    {
        weight_num = weight_num/2.205;
        cout<<"Hi "<<name<<"- you weigh "<<fixed<<setprecision(1)<<weight_num<<" kilos.\n"<<endl;
    }
    else if (weight_type == "kilos")
    {
        weight_num = weight_num*2.205;
        cout<<"Hi "<<name<<"- you weigh "<<fixed<<setprecision(1)<<weight_num<<" pounds.\n"<<endl;
    }
    else
    {
        cout<<"Not enough info to convert.\n"<<endl;
    }
}

int main(int argc, char**argv)
{
    string name_weight;

    cout<<"Please enter your name and weight."<<endl;//Output to screen
    getline(cin,name_weight); //takes input from the user
    convert(name_weight);

    while (name_weight != "exit")
    {
        string Name, weightNum, weightType;

        stringstream ss(name_weight); //separates the name and weight by space
        ss>>Name>>weightNum>>weightType;

        double weightToNum = 0;
        stringstream geek(weightNum); //converts string into integer(double)
        geek >> weightToNum;

        convert_weight (Name,weightType,weightToNum);

        cout<<"Please enter your name and weight."<<endl;
        getline(cin,name_weight);
        convert(name_weight);
    }
    cout<<"Exiting...\n"<<endl;
}
