#include <iostream>

using namespace std;

//Finction that gathers the height, wieght, and age of the user
void getInfo(int& height, int& weight, int& age)
{
    cout << "What is your height? ";
    cin >> height;

    cout << "What is your weight? ";
    cin >> weight;

    cout << "What is your age? ";
    cin >> age;
}

//Function that calculates the hat size
double hatSize(int inWeight, int inHeight)
{
    double holder = 2.9 * inWeight / inHeight;
    return holder;
}

//Function that calculates the jacket size
double jacketSize(int inWeight, int inHeight, int inAge)
{
    double holder = inHeight * inWeight / 288;
    
    if(inAge > 30)
    {
        inAge = (inAge - 30) / 10;
        holder = holder + ( 1 / 8.0 * inAge);
    }

    return holder;
}

//Function that calculates the waist size
double waistSize(int inWeight, int inAge)
{
    double holder = inWeight / 5.7;

    if(inAge > 28)
    {
        inAge = (inAge - 28) / 2;
        holder = holder + ((1 / 10.0) * inAge);
    }

    return holder;
}

//Program that calculates the user's hat, jacket, and waist sizes
int main()
{
    //initialize variables
    int height, weight, age;
    double jacket, hat, waist;

    getInfo(height, weight, age);
    jacket = jacketSize(weight, height, age);
    hat = hatSize(weight, height);
    waist = waistSize(weight, age);

    //Format output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //Output the results
    cout << "Your hat size is " << hat << endl;
    cout << "Your jacket size is " << jacket << endl;
    cout << "Your waist size is " << waist;

    return 0;
}