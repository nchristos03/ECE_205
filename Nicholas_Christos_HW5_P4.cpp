#include <iostream>
using namespace std;

class PrimeNumber
{
    public:
        PrimeNumber();
        PrimeNumber(int num);
        int getNumber();
        int prevPrime(int num);
        int nextPrime(int num);
        bool prime(int num);

        PrimeNumber& operator++()
        {
            number = nextPrime(number);
            return *this;
        }

        PrimeNumber& operator--()
        {
            number = prevPrime(number);
            return *this;
        }

        PrimeNumber operator++(int)
        {
            PrimeNumber temp(number);
            number = nextPrime(number);

            return temp;
        }

        PrimeNumber operator--(int)
        {
            PrimeNumber temp(number);
            number = prevPrime(number);

            return temp;
        }

    private:
        int number;
};

PrimeNumber::PrimeNumber()
{
    number = 1;
}

PrimeNumber::PrimeNumber(int num)
{
    number = num;
}

int PrimeNumber::getNumber()
{
    return number;
}

int PrimeNumber::prevPrime(int num)
{
    num--;

    while(!prime(num))
        num--;
    
    return num;
}

int PrimeNumber::nextPrime(int num)
{
    num++;

    while(!prime(num))
        num++;
    
    return num;
}

bool PrimeNumber::prime(int num)
{
    for(int i = 2; i < num; i++)
    {
        if((num % i) == 0)
            return false;
    }

    return true;
}

int main()
{
    PrimeNumber p1;
    PrimeNumber p(13);

    cout << p1.getNumber() << endl;
    cout << "Initial: " << p.getNumber() << endl;

    cout << "Prefix ++: " << (++p).getNumber() << endl;
    cout << "After prefix: " << p.getNumber() << endl;

    p = PrimeNumber(13);

    cout << "Postfix ++: " << (p++).getNumber() << endl;
    cout << "After postfix: " << p.getNumber() << endl;

    cout << "Prefix --: " << (--p).getNumber() << endl;
    cout << "After prefix --: " << p.getNumber() << endl;

    p = PrimeNumber(13);

    cout << "Postfix --: " << (p--).getNumber() << endl;
    cout << "After postfix --: " << p.getNumber() << endl;

    return 0;
}