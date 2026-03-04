#include <iostream>

using namespace std;

//Function that returns the difference in minutes between two times within 24 hours
int difference(int startHour, int startMin, int endHour, int endMin)
{
    int difMin;
    int difHour;

    if(startHour == endHour)
    {
        if(startMin == endMin)
        {
            difMin = 24 * 60;
        }
        else if(startMin < endMin)
        {
            difMin = endMin - startMin;
        }
        else
        {
            difMin = (24 * 60) - (startMin - endMin);
        }
    }
    else if(startHour < endHour)
    {
        difHour = endHour - startHour;
        difMin = (difHour * 60) + (endMin - startMin);
    }
    else
    {
        difHour = (24 - startHour) + endHour;
        difMin = (difHour * 60) + (endMin - startMin);
    }

    return difMin;
}

//Function that gathers a start and end time from the user
void setup(int& startTime, int& endTime)
{
    cout << "Start time: ";
    cin >> startTime;

    cout << "End time: ";
    cin >> endTime;
}

//Function that seperates the hours and mins from a given time
void seperate(int time, int& hour, int& min)
{
    hour = time / 100;
    min = time % 100;
}

int main()
{
    //Initialize variables
    int startTime, endTime, startHour, endHour, startMin, endMin, difMin;
    char again;

    do
    {    
        setup(startTime, endTime);
        seperate(startTime, startHour, startMin);
        seperate(endTime, endHour, endMin);
        
        difMin = difference(startHour, startMin, endHour, endMin);

        //Outputs the data
        cout << "Difference in minutes = " << difMin << " minutes\n";

        //Gathers whether the user would like to run the program again
        cout << "Would you like to enter different times?(y/n) ";
        cin >> again;

    }while(again == 'y'); //Loops while the user wants to continue using the program

    return 0;
}