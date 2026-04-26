#include <iostream>
#include <vector>

using namespace std;

//Function gather a list of characters from the user
void getList(vector<char>& list)
{
    char holder;

    cout << "Enter your list of characters:\n";
    cin >> holder;

    while(holder != '0')
    {
        list.push_back(holder);
        cin >> holder;
    }
    
}

//Function deletes any repeated characters in a list
void deleteRepeatedChars(vector<char>& list)
{
    char holder;

    for(int i = 0; i < list.size(); i++)
    {
        holder = list[i];

        for(int j = 0; j < list.size(); j++)
        {
            if((holder == list[j]) && (i != j))
            {  
                list.erase(list.begin() + j);
                j--;
            }
        }
    }
}

//Function returns the max value in the list
char listMax(vector<char>& list)
{
    int size = list.size();
    
    char max = list[0];

    for(int i = 1; i < size; i++)
    {
        if(list[i] > max)
            max = list[i];
    }

    return max;
}

//Function sorts a list of characters decrementing order
void selectionSort(vector<char>& list)
{
    vector<char> holder;
    char max;

    while(list.size() > 0)
    {
        max = listMax(list);
        holder.push_back(max);

        for(int i = 0; i < list.size(); i++)
        {
            if(max == list[i])
                list.erase(list.begin() + i);
        }
    }

    list = holder;
}

//Function output a list to the console
void display(vector<char> list)
{
    int size = list.size();

    for(int i = 0; i < size; i++)
    {
        cout << "List[" << i << "] = " << list[i] << endl;
    }
}

int main()
{
    vector<char> list;

    getList(list);
    deleteRepeatedChars(list);
    selectionSort(list);
    display(list);

    return 0;
}