#include <iostream>

using namespace std;

int main()
{
    // Variable declarations
    int inTime;
    int hours, minutes, seconds;
    float totalHours, totalMinutes;

    // User prompt and input in total seconds
    cout << "Enter a time in seconds: ";
    cin >> inTime;

    // Time conversions
    hours = inTime / 3600;
    minutes = (inTime % 3600) / 60;
    seconds = inTime % 60;

    // Total time calculations
    totalHours = inTime / 3600.0;
    totalMinutes = inTime / 60.0;

    // Formatting the float outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    // Output results
    cout << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.\n";
    cout << totalHours << " hours.\n";
    cout << totalMinutes << " minutes.\n";

    return 0;
}