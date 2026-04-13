#include <iostream>
using namespace std;

//Class that contains the info of a pizza
class Pizza
{
    public:
        string getType();
        string getSize();
        int getToppings();
        void setType(string inType);
        void setSize(string inSize);
        void setToppings(int inToppings);
        double computePrice();
        void outputDescription(double price);
    private:
        string type;
        string size;
        int toppings;
};

string Pizza::getType()
{
    return type;
}

string Pizza::getSize()
{
    return size;
}

int Pizza::getToppings()
{
    return toppings;
}

void Pizza::setType(string inType)
{
    type = inType;
}

void Pizza::setSize(string inSize)
{
    size = inSize;
}

void Pizza::setToppings(int inToppings)
{
    toppings = inToppings;
}

//Function return the price of a pizza
double Pizza::computePrice()
{
    double price;

    if(size == "small")
        price = 10.0;
    else if(size == "medium")
        price = 14.0;
    else
        price = 17.0;
    
    price = price + (2 * toppings);

    return price;
}

//Function output the description of a pizza which include the type, size, number of toppings, and price
void Pizza::outputDescription(double price)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "For a " << size << " " << type << " pizza with " << toppings << " it costs: $" << price << endl;
}

int main()
{
    //Declare variables
    Pizza order;
    string inSize, inType;
    char again;
    int inToppings;
    double price;

    do
    {
        //Gather piza info from user
        cout << "What type of pizza would you like? ";
        getline(cin, inType);
        order.setType(inType);

        cout << "What size pizza would you like? ";
        cin >> inSize;
        order.setSize(inSize);

        cout << "How many toppings would you like? ";
        cin >> inToppings;
        order.setToppings(inToppings);

        price = order.computePrice();

        order.outputDescription(price);

        //Gather whether user wants to enter another pizza
        cout << "Would you like to enter another order?(y/n) ";
        cin >> again;
        cin.ignore();
    }while(again == 'y'); //Loop again if user wants to


    return 0;
}