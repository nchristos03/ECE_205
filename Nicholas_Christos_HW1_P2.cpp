#include <iostream>

using namespace std;

int main()
{
    //Declaring and initializing variables
    const float HOURLY = 36.75, OVERTIME_RATE = 1.5 * HOURLY;
    const float SOCIAL_RATE = 0.20, FEDERAL_RATE = 0.15, STATE_RATE = 0.04, LOCAL_RATE = 0.01;
    const int DEPENDENT_DEDUCTION = 40, UNION_DUES = 20, OT_THRESHOLD = 40, DEPENDENT_THRESHOLD = 1;
    int hoursWokered, dependents;
    int otHours;
    float grossPay, netPay, social, federalTax, stateTax, localTax;

    //Prompting and collecting the number of hours worked from user
    cout << "Please enter the number of hours worked this week: ";
    cin >> hoursWokered;

    //Prompting and collecting the number of dependents worked from user
    cout << "Please enter the number of dependents: ";
    cin >> dependents;

    //Checking if there is overtime pay and calculating the gross pay
    if (hoursWokered > OT_THRESHOLD)
    {
        otHours = hoursWokered - 40;
        grossPay = (40 * HOURLY) + (otHours * OVERTIME_RATE);
    }
    else
        grossPay = hoursWokered * HOURLY;

    //Calculating all pay withholdings and net pay except dependents
    social = grossPay * SOCIAL_RATE;
    federalTax = grossPay * FEDERAL_RATE;
    stateTax = grossPay * STATE_RATE;
    localTax = grossPay * LOCAL_RATE;
    netPay = grossPay - (social + federalTax + stateTax + localTax + UNION_DUES);

    //checking if dependent deduction is needed and calculating the net pay if so
    if(dependents > DEPENDENT_THRESHOLD)
        netPay -= DEPENDENT_DEDUCTION;
    
    //Formatting the float outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Output results
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Deductions: " << endl;
    
    cout << "\tSocial Security: $" << social << endl;
    cout << "\tFederal Income Tax: $" << federalTax << endl;
    cout << "\tState Income Tax: $" << stateTax << endl;
    cout << "\tLocal Income Tax: $" << localTax << endl;
    cout << "\tUnion Dues: $" << UNION_DUES << endl;

    if(dependents > DEPENDENT_THRESHOLD)
        cout << "\tDependent Deduction: $" << DEPENDENT_DEDUCTION << endl;
    
    cout << "\nNet Pay: $" << netPay << endl;

    return 0;
}