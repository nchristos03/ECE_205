#include <iostream>
using namespace std;

//Function returns the difficulty of the dive gathered from the user
double getDif()
{
    double holder;
    cout << "Enter the difficulty of the dive: ";
    cin >> holder;

    return holder;
}

//Function gather the judges scores from the user
void getScores(double scores[], int size)
{
    cout << "Enter the list of scores:\n";

    for(int i = 0; i < size; i++)
    {
        cin >> scores[i];
    }
}

//Function returns the max value in the list
double listMax(double list[], int size)
{
    double max = list[0];

    for(int i = 1; i < size; i++)
    {
        if(list[i] > max)
            max = list[i];
    }

    return max;
}

//Function returns the min value in the list
double listMin(double list[], int size)
{
    double min = list[0];

    for(int i = 1; i < size; i++)
    {
        if(list[i] < min)
            min = list[i];
    }

    return min;
}

//Function returns the final score of the dive
double score(double scores[], int size, double difficulty)
{
    double max, min, sum = 0;

    max = listMax(scores, size);
    min = listMin(scores, size);

    for(int i = 0; i < size; i++)
    {
        if((scores[i] != max) && (scores[i] != min))
            sum += scores[i];
    }

    sum = sum * difficulty * 0.6;

    return sum;
}

int main()
{
    //Initialize variables
    int size = 7;

    //Declaring variables
    double finalScore, difficulty, scores[size];

    difficulty = getDif();
    getScores(scores, size);

    finalScore = score(scores, size, difficulty);

    // Formatting the float outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //Output results
    cout << "The diver's score is " << finalScore;

    return 0;
}