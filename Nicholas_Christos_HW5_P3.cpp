#include <iostream>
using namespace std;

//Class that holds info about a pizza
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

//Class that contains info about a order of pizzas
class Order
{
    public:
        void setOrder(int inSize);
        void outputOrder();
        void addPizza(int count, string inType, string inSize, int inToppings);
    private:
        int orderSize;
        Pizza pies[100];
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

//Function return the cost of the pizza
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

void Order::setOrder(int inSize)
{
    orderSize = inSize;
}

//Function outputs the cost of each pizza along with the cost of the order
void Order::outputOrder()
{
    double piePrice, cost = 0;
    
    for(int i = 0; i < orderSize; i++)
    {
        piePrice = pies[i].computePrice();
        pies[i].outputDescription(piePrice);
        cost += piePrice;
    }

    cout << "The total cost of the order is $" << cost << endl;
}

void Order::addPizza(int count, string inType, string inSize, int inToppings)
{
    pies[count].setType(inType);
    pies[count].setSize(inSize);
    pies[count].setToppings(inToppings);
}

int main()
{
    //Declare variables
    Order order1;
    string inSize, inType;
    int inToppings, count;
    double price;

    //Gather order size
    cout << "How many pies would you like to order? ";
    cin >> count;
    cin.ignore();

    order1.setOrder(count);

    //Gather the input of each pizza and add to order
    for(int j = 0; j < count; j++)
    {
        cout << "What type of pizza would you like? ";
        getline(cin, inType);

        cout << "What size pizza would you like? ";
        cin >> inSize;

        cout << "How many toppings would you like? ";
        cin >> inToppings;
        cin.ignore();

        order1.addPizza(j, inType, inSize, inToppings);
    }

    //Output order
    order1.outputOrder();

    return 0;
}