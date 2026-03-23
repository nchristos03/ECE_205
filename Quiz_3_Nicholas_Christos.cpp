#include <iostream>
#include <cmath>
using namespace std;

const int maxSize = 99;

int getScores(int scores[])
{
    int holder;
    int size = 0;

    cout << "Enter a list of exam scores:\n";

    for(int i = 0; i < maxSize; i++)
    {
        cin >> holder;

        if(holder > 100)
            i--;
        else if(holder >= 0)
        {
            scores[i] = holder;
            size++;
        }
        else
            return size;
    }

    return size;
}

int maxVal(int scores[], int size)
{
    int max = scores[0];

    for(int i = 1; i < size; i++)
    {
        if(scores[i] > max)
            max = scores[i];
    }

    return max;
}

int minVal(int scores[], int size)
{
    int min = scores[0];

    for(int i = 1; i < size; i++)
    {
        if(scores[i] < min)
            min = scores[i];
    }

    return min;
}

int getAvg(int scores[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += scores [i];
    }

    return (sum / size);
}

double stad(int scores[], int avg, int size)
{
    double sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += pow((scores[i] - avg), 2);
    }

    sum = sum / size;
    sum = sqrt(sum);

    return sum;
}

int main()
{
    int scores[maxSize], size, avg, min, max;
    double standard;

    size = getScores(scores);
    min = minVal(scores, size);
    max = maxVal(scores, size);
    avg = getAvg(scores, size);
    standard = stad(scores, avg, size);

    cout << "Min: " << min << " Max: " << max << " Average: " << avg << " Standard deviation: " << standard;
}