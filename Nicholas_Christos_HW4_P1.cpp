#include <iostream>
using namespace std;

//Function returns the list size gathered from the user
int listSize()
{
    int size;
    
    cout << "Enter the size of your list: ";
    cin >> size;
    
    return size;
}

//Function gathers the list of numbers from the user
void getList(int list[], int size)
{
    cout << "Enter your list of numbers:\n";

    for(int i = 0; i < size; i++)
    {
        cin >> list[i];
    }
}

//Function returns the index for the bin of the inputted number
int binSort(int num, int binSize)
{
    return (num / binSize);
}

//Function goes through the user provided list and adds a tally to the bin that each number belongs in
void histogram(int list[], int size, int bins[], int binSize)
{
    int j;
    
    for(int i = 0; i < size; i++)
    {
        j = binSort(list[i], binSize);
        bins[j] += 1;
    }
}

//Function returns the max value in the list
int listMax(int list[], int size)
{
    int max = list[0];

    for(int i = 1; i < size; i++)
    {
        if(list[i] > max)
            max = list[i];
    }

    return max;
}

//Function initializes an array full of zeros
void zeros(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        a[i] = 0;
    }
}

//Function displays the histogram
void displayHistogram(int bins[], int size)
{
    cout << "Histogram:\n";

    for(int i = 0; i < size; i++)
    {
        cout << "Bin " << (i + 1) << ": " << bins[i] << endl;
    }
}

int main()
{
    //Declare variables
    int size, max, histogramSize;
    //Initializes variables
    int binSize = 10;

    size = listSize();
    int list[size];
    getList(list, size);

    max = listMax(list, size);
    histogramSize = binSort(max, binSize) + 1;
    int bins[histogramSize];

    zeros(bins, histogramSize);
    histogram(list, size, bins, binSize);
    displayHistogram(bins, histogramSize);

    return 0;
}