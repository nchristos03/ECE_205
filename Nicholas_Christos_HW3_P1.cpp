#include <iostream>

using namespace std;

//Function that gathers the desired time from the user
void getInfo(int& hours, int& minutes)
{
    cout << "What is the hour? ";
    cin >> hours;

    cout << "What is the minutes? ";
    cin >> minutes;
}

//Function that converts time from a 24 clock to a 12 hour clock and returns A for AM and P for PM
char convert(int& hours, int& minutes)
{
    char identifier;

    //Checks whether the hour is in the am or pm or special case of hour = 0 and converts accordingly
    if(hours == 0)
    {
        identifier = 'A';
        hours = 12;
    }
    else if(hours < 12)
    {
        identifier = 'A';
    }
    else
    {
        identifier = 'P';
        hours -= 12;
    }

    return identifier;
}

int main()
{
    //Initialize variables
    int hour, minutes;
    char identifier, again;

    do
    {
        getInfo(hour, minutes);
        identifier = convert(hour, minutes);

        //Outputs the result of the conversion
        if(minutes == 0)
            cout << "The time is: " << hour << ":00 " << identifier << "M\n";
        else
            cout << "The time is: " << hour << ":" << minutes << " " << identifier << "M\n";
        
        //Gathers whether the user would like to enter another time
        cout << "Would you like to enter a new time?(y/n) ";
        cin >> again;

    } while (again == 'y'); //Loops while the user wants to input a new time
    

    return 0;
}