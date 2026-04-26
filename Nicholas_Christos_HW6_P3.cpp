#include <iostream>
#include <vector>

using namespace std;

void createList(vector<int>& primes, int N)
{
    for(int i = 2; i < N; i++)
    {
        primes.push_back(i);
    }
}

void findPrimes(vector<int>& primes)
{
    int holder;
    
    for(int i = 0; i < primes.size(); i++)
    {
        holder = primes[i];

        for(int j = 0; j < primes.size(); j++)
        {
            if(((primes[j] % holder) == 0) && (primes[j] != holder))
            {
                primes.erase(primes.begin() + j);
                j--;
            }
        }
    }
}

void display(vector<int> primes, int N)
{
    if(primes.size() > 0)
    {
        cout << "All the prime numbers before " << N << ":\n";

        for(int i = 0; i < primes.size(); i++)
        {
            cout << primes[i] << endl;
        }
    }
    else
    {    
        cout << "There are no prime number smaller than " << N;
    }
}

int main()
{
    int N;
    vector<int> primes;

    cout << "Enter a number: ";
    cin >> N;

    createList(primes, N);
    findPrimes(primes);
    display(primes, N);

    return 0;
}