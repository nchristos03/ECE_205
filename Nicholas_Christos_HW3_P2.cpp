#include <iostream>
#include <cmath>

using namespace std;

//Function gathers the length of the sides of the triangle from the user
void getInfo(double& a, double& b, double& c)
{
    cout << "Enter the length of side a: ";
    cin >> a;

    cout << "Enter the length of side b: ";
    cin >> b;

    cout << "Enter the length of side c: ";
    cin >> c;
}

/* Function checks wether the give lengths create a triangle,
if yes the function calculates the area and perimeter
if no the function sets the area and the perimeter to 0 */
void findArea(double a, double b, double c, double& area, double& perimeter)
{
    double holder = pow(a,2) + pow(b,2);

    //Checks whether given info makes a triangle
    if(holder == (pow(c,2)))
    {
        perimeter = a + b + c;

        holder = perimeter / 2;
        area = holder * (holder - a) * (holder - b) * (holder - c);
        area = sqrt(area);
    }
    else
    {
        area = 0;
        perimeter = 0;
    }
}

int main()
{
    //Initialiazes variables
    double a, b, c, area, perimeter;
    char again;

    do
    {
        getInfo(a, b, c);
        findArea(a, b, c, area, perimeter);

        //Outputs results
        cout << "The area of the triangle is " << area << endl;
        cout << "The perimeter of the triangle is " << perimeter << endl;

        //Gathers whether user would like to try another triangle
        cout << "Would you like to try another triangle?(y/n) ";
        cin >> again;

    }while(again == 'y'); // Loops while user still wants to input more traingles

    return 0;
}