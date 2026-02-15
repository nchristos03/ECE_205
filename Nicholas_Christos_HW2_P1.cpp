#include <iostream>
#include <cmath>

using namespace std;

// defining gravitational constant
const double G = 6.673*pow(10.0,-8.0);

// Function that gathers the data the user wants to use for the masses of the bodies and the distance between them.
void getData(double& mass1, double& mass2, double& distance)
{
    cout << "Please enter the mass of body 1: ";
    cin >> mass1;
    
    cout << "Please enter the mass of body 2: ";
    cin >> mass2;
    
    cout << "Please enter the distance between the bodies: ";
    cin >> distance;

    //Converts kg to g for the equation
    mass1 *= 1000;
    mass2 *= 1000;
}

//Function that calculates the gravitational force of mass1 and mass2 seperated by a distance.
double gravitationalForce(double mass1, double mass2, double distance)
{
    double force = (G * mass1 * mass2) / pow(distance, 2.0);
    return force;
}

int main ()
{
    //initializing variables
    double mass1, mass2, distance, force;
    char again;

    do
    {
        getData(mass1, mass2, distance);
        force = gravitationalForce(mass1, mass2, distance);

        //Outputs the calculated force and sees if the user wants to run another calculation
        cout << "The gravitational force between the two bodies is " << force << "N.\n";
        cout << "Would you like to run another calculation?(y/n) ";
        cin >> again;

    } while (again == 'y'); //Continues to loop as long as the user want to run more calculations
    

    return 0;
}