#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Declare variables
    int winners[4], holder;

    //initializes variables
    int i = 0, finalists = 25;
    bool repeat = false;

    //Set seed
    srand(time(0));

    //Initialize winners
    for(int n = 0; n < 4; n++)
    {
        winners[n] = 0;
    }

    //Loops while a fourth winner is still not found
    while(winners[3] == 0)
    {
        //Creates a random winning number
        holder = rand() % finalists + 1;

        //Checks if the random winning number is already in the array and sets repeat to true if it is
        for(int n = 0; n < 4; n++)
        {
            if(winners[n] == holder)
                repeat = true;
        }     
        
        //Adds the random winning number to the winners if repeat is false, and resets repeat if repeat is true
        if(repeat)
            repeat = false;
        else
        {
            winners[i] = holder;
            i++;
        }
    }

    //Output the winners
    cout << "Winners: " << winners[0] << ", " << winners[1] << ", " << winners[2] << ", " << winners[3];

    return 0;
}