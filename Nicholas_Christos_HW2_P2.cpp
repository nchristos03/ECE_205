#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;

    //Initializing variables
    double score1, score2, score3, score4, score5;
    double avg, sd, holder;

    //Connecting to txt file
    in.open("scores.txt");

    //Reading in values from the txt file
    in >> score1;
    in >> score2;
    in >> score3;
    in >> score4;
    in >> score5;

    //Calculating the average
    avg = (score1 + score2 + score3 + score4 + score5) / 5.0;

    //Calculating the standard deviation
    holder = pow((score1 - avg), 2) + pow((score2 - avg), 2) + pow((score3 - avg), 2) + pow((score4 - avg), 2) + pow((score5 - avg), 2);
    holder /= 5;
    sd = sqrt(holder);

    //Formatting output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Outputting results
    cout << "The average score is: " << avg << endl;
    cout << "The standard deviation is: " << sd;

    //Connecting to output txt file
    out.open("output.txt");
    
    //Outputting data to txt file
    out << avg << endl;
    out << sd;

    //Closing connections
    in.close();
    out.close();

    return 0;
}