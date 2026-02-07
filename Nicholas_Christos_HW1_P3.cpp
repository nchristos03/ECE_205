#include<iostream>
#include <iomanip>

using namespace std;

//Declaring variables
double interest, principal, balance, totalInterest, totalPaid, payments, interestRate;
int month, space, numSpace;


int main()
{
    //Initializing variables
    interestRate = 0.015;
    balance = 1000.00;
    payments = 50.00;
    month = 0;
    space = 15;
    totalInterest = 0;
    totalPaid = 0;

    //Formatting double outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Outputing the table format
    cout << right << setw(space) << "Month #" << right << setw(space) << "Interest" << right << setw(space) << "Principal" << right << setw(space) << "Balance";
    cout << right << setw(space) << "Total Interest" << right << setw(space) << "Total Paid" << endl;
    

    while(balance > 0.0)
    {
        //Incrementing to the next month
        month++;
        
        //Calculating the interest
        interest = balance * interestRate;
        
        //Checking if payments do not have to be the maximum
        if((balance + interest) < payments)
            payments = balance + interest;
        
        //Calulating payment information
        principal = payments - interest;
        balance -= principal;
        totalInterest += interest;
        totalPaid += payments;

        //Outputting results
        cout << right << setw(space) << month;

        //Checking number of spaces needed for formatting
        if(interest >= 10.00)
            numSpace = 5;
        else
            numSpace = 4;
        
        cout << right << setw(space - numSpace) << "$" << setw(numSpace) << interest;

        if(principal >= 10.00)
            numSpace = 5;
        else
            numSpace = 4;
        
        cout << right << setw(space - numSpace) << "$" << setw(numSpace) << principal;

        if(balance >= 100.00)
            numSpace = 6;
        else if(balance >= 10.00)
            numSpace = 5;
        else
            numSpace = 4;
        
        cout << right << setw(space - numSpace) << "$" << setw(numSpace) << balance;

        if(totalInterest >= 100.00)
            numSpace = 6;
        else if(totalInterest >= 10.00)
            numSpace = 5;
        else
            numSpace = 4;
        
        cout << right << setw(space - numSpace) << "$" << setw(numSpace) << totalInterest;

        if(totalPaid >= 1000.00)
            numSpace = 7;
        else if(totalPaid >= 100.00)
            numSpace = 6;
        else if(totalPaid >= 10.00)
            numSpace = 5;
        else
            numSpace = 4;
        
        cout << right << setw(space - numSpace) << "$" << setw(numSpace) << totalPaid << endl;
    }
        
    return 0;
}