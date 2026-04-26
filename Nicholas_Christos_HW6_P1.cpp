#include <iostream>
#include <vector>

using namespace std;

//Function gathers the list of numbers from the user
void getList(vector<int>& list)
{
    int holder;

    cout << "Enter your list of numbers:\n";
    cin >> holder;

    while(holder >= 0)
    {
        list.push_back(holder);
        cin >> holder;
    }
    
}

//Function returns the index for the bin of the inputted number
int binSort(int num, int binSize)
{
    return (num / binSize);
}

//Function goes through the user provided list and adds a tally to the bin that each number belongs in
void histogram(vector<int>& list, int bins[], int binSize)
{
    int j;
    int size = list.size();
    
    for(int i = 0; i < size; i++)
    {
        j = binSort(list[i], binSize);
        bins[j] += 1;
    }
}

//Function returns the max value in the list
int listMax(vector<int>& list)
{
    int size = list.size();
    
    int max = list[0];

    for(int i = 1; i < size; i++)
    {
        if(list[i] > max)
            max = list[i];
    }

    return max;
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

//Function initializes an array full of zeros
void zeros(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        a[i] = 0;
    }
}

int main()
{
    //Declare variables
    int size, max, histogramSize;
    vector<int> list;
    //Initializes variables
    int binSize = 10;

    getList(list);

    max = listMax(list);
    histogramSize = binSort(max, binSize) + 1;
    int bins[histogramSize];

    zeros(bins, histogramSize);
    histogram(list, bins, binSize);
    displayHistogram(bins, histogramSize);

    return 0;
}