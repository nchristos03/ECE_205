#include <iostream>
using namespace std;

//Struct the telss whether a space has been picked, the number of the space, and which player if any has marked it.
struct space
{
    int num;
    char mark;
    bool picked;
};

//Function that displays the tic tac toe board
void display(space board[], int rowSize, int colSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            if(board[(i * colSize) + j].picked)
                cout << board[(i * colSize) + j].mark << '\t';
            else
                cout << board[(i * colSize) + j].num << '\t';
        }

        cout << endl;
    }
}

//Function returns true if the space the user chose is not taken and false if it is taken or does not exist
bool availability(space board[], space choice, int rowSize, int colSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            if(board[(i * colSize) + j].num == choice.num)
            {
                if(board[(i * colSize) + j].picked)
                {
                    cout << "Space is taken.\n";
                    return false;
                }
                else
                {
                    board[(i * colSize) + j].mark = choice.mark;
                    board[(i * colSize) + j].picked = true;
                    return true;
                }
            }
        }
    }

    cout << "Space not found.\n";
    return false;
}

//Function returns a space gathered from the user
space getChoice()
{
    space choice;

    cout << "Please pick a space: ";
    cin >> choice.num;

    return choice;
}

//Function initializes all the space on the tic tac toe board
void fillSpace(space board[], int rowSize, int colSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            board[(i * colSize) + j].num = (i * colSize) + j + 1;
            board[(i * colSize) + j].mark = (i * colSize) + j + 1;
            board[(i * colSize) + j].picked = false;
        }
    }
}

//Function returns true if the win condition is met and false if is not, it also updates the player to the winning player.
bool checkWin(space board[], char& player)
{
    if((board[0].mark == board[1].mark) && (board[0].mark == board[2].mark))
    {
        player = board[0].mark;
        return true;
    }
    else if((board[3].mark == board[4].mark) && (board[3].mark == board[5].mark))
    {
        player = board[3].mark;
        return true;
    }
    else if((board[6].mark == board[7].mark) && (board[6].mark == board[8].mark))
    {
        player = board[6].mark;
        return true;
    }
    else if((board[0].mark == board[3].mark) && (board[0].mark == board[6].mark))
    {
        player = board[0].mark;
        return true;
    }
    else if((board[1].mark == board[4].mark) && (board[1].mark == board[7].mark))
    {
        player = board[1].mark;
        return true;
    }
    else if((board[2].mark == board[5].mark) && (board[2].mark == board[8].mark))
    {
        player = board[2].mark;
        return true;
    }
    else if((board[0].mark == board[4].mark) && (board[0].mark == board[8].mark))
    {
        player = board[0].mark;
        return true;
    }
    else if((board[2].mark == board[4].mark) && (board[2].mark == board[6].mark))
    {
        player = board[2].mark;
        return true;
    }

    return false;
}

int main()
{
    //Declaring and initializing variables
    int rowSize = 3, colSize = 3, size = rowSize * colSize;
    space choice, board[size];
    bool win = false, available = false;
    char player = 'X';

    fillSpace(board, rowSize, colSize);
    display(board, rowSize, colSize);

    do
    {
        choice = getChoice();
        choice.mark = player;

        available = availability(board, choice, rowSize, colSize);

        if(available)
        {
            win = checkWin(board, player);

            if(!win)
            {
                if(player == 'X')
                    player = 'O';
                else
                    player = 'X';
                
                size--;
            }  
        }

        display(board, rowSize, colSize);
    } while ((!win) && (size > 0)); //Loop while a player has not won and there are available spaces
    
    //Output if it is a tie
    if(size == 0)
        cout << "It is a tie.";
    
    //Output the winning player
    if(win)
        cout << "Player " << player << " wins";
    
    return 0;
}