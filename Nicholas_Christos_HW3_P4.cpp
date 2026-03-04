#include <iostream>

using namespace std;

//Function that returns the the number of lbs from the input of oz
double convertOZtoLB(int oz)
{
    return (oz / 16.0);
}

//Function that returns the number of kg from the input of lb
double convertLBtoKG(double lb)
{
    return (lb / 2.2046);   
}

//Function that returns the the decimal value of kg as g
double convertKGtoG(double kg)
{
    double holder = kg * 1000;

    return (static_cast<int>(holder) % 1000);
}

//Gather the oz and lb from the user
void setup(int& oz, double& lb)
{
    cout << "Enter the number of lb: ";
    cin >> lb;
    cout << "Enter the number of oz: ";
    cin >> oz;
}

int main()
{
    //Initialize variables
    int oz, g;
    double kg, lb;
    char again;

    do
    {
        setup(oz, lb);
        lb = lb + convertOZtoLB(oz);
        kg = convertLBtoKG(lb);
        g = convertKGtoG(kg);

        //Output results
        cout << static_cast<int>(kg) << "kg " << static_cast<int>(g) << "g\n";

        //Gather whether wants to enter another weight
        cout << "Would you like to enter another weight?(y/n) ";
        cin >> again;

    } while (again == 'y'); //Loop while the user wants to continue
    

    return 0;
}