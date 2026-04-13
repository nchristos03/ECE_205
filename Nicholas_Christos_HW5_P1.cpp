#include <iostream>
using namespace std;

//Class that contains the distance travelled in a bike, the time it took, and calculates the saverage speed
class BicycleSpedometer
{
    public:
        void setDistance(double dis);
        void setTime(double time1);
        double average();
    private:
        double distance;
        double time;
        double avg;
};

//Function that sets the distance of the spedometer object
void BicycleSpedometer::setDistance(double dis)
{
    distance = dis;
}

//Function that sets the time of the spedometer object
void BicycleSpedometer::setTime(double time1)
{
    time = time1;
}

//Function that calculate the average speed
double BicycleSpedometer::average()
{
    avg = (distance / time) * 60;

    return avg;
}

int main()
{
    //Declare variables
    double dis, time1, avg;
    BicycleSpedometer bike1;

    //Gather distance and time from user
    cout << "Enter the distance biked: ";
    cin >> dis;

    cout << "Enter the time it took: ";
    cin >> time1;

    bike1.setDistance(dis);
    bike1.setTime(time1);
    avg = bike1.average();

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //Output average speed
    cout << "Your average speed was " << avg << " mph";

    return 0;
}