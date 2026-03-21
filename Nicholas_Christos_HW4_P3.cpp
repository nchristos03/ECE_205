#include <iostream>
using namespace std;

//Struct that contains the row number, column letter, and whther it has been taken
struct seat
{
    int row;
    char column;
    bool available;
};

//Function displays the seating chart of the airplane
void display(seat seats[], int rowSize, int colSize)
{
    cout << "Please select one of the following seats:\n";
    
    for(int i = 0; i < rowSize; i++)
    {
        cout << i + 1 << "\t";

        for(int j = 0; j < colSize; j++)
        {
            if(seats[(i * colSize) + j].available)
                cout << seats[(i * colSize) + j].column << " ";
            else
                cout << "X ";
        }

        cout << endl;
    }
}

//Function returns true if the seat the user chose is available and false if it is not available or does not exist
bool availability(seat seats[], seat choice, int rowSize, int colSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            if(seats[(i * colSize) + j].row == choice.row)
            {
                if(seats[(i * colSize) + j].column == choice.column)
                {
                    if(seats[(i * colSize) + j].available)
                    {
                        seats[(i * colSize) + j].available = false;
                        return true;
                    }
                    else
                    {
                        cout << "Seat unavailable\n";
                        return false;
                    }
                }
            }
        }
    }

    cout << "Seat not found.\n";
    return false;
}

//Function returns a seat gathered from the user
seat getChoice()
{
    seat choice;

    cout << "Enter seat row: ";
    cin >> choice.row;
    cout << "Enter seat column: ";
    cin >> choice.column;

    return choice;
}

//Function initializes all the seats on the airplane
void fillSeats(seat seats[], int rowSize, int colSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            seats[(i * colSize) + j].row = i + 1;
            seats[(i * colSize) + j].available = true;
            
            if(j == 0)
                seats[(i * colSize) + j].column = 'A';
            else if(j == 1)
                seats[(i * colSize) + j].column = 'B';
            else if(j == 2)
                seats[(i * colSize) + j].column = 'C';
            else
                seats[(i * colSize) + j].column = 'D';
        }
    }
}

int main()
{
    //Declaring and initializing variables
    int rowSize = 10, colSize = 4, size;
    size = rowSize * colSize;

    seat seats[size], choice;
    char again = 'y';
    bool isAvailable;

    fillSeats(seats, rowSize, colSize);
    
    do
    {
        
        display(seats, rowSize, colSize);
        choice = getChoice();
        isAvailable = availability(seats, choice, rowSize, colSize);

        if(isAvailable)
        {    
            size--;
            cout << "Would you like to pick another seat?(y/n) ";
            cin >> again;
        }


    }while((again == 'y') && (size > 0)); //Loop while user wants to or there are seats remaining

    //Output if all seats have been taken
    if(size == 0)
        cout << "All seats taken.";

    return 0;
}