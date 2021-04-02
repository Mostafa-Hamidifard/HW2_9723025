#ifndef DHT11_H
#define DHT11_H
#include <utility>
class Room; // forward declaration for using cyclo dependant classes

class DHT11
{
private:
    double temp_stdev{1};
    double hum_stdev{1};
    Room *proom;

public:
    DHT11(double temp_stdev, double hum_stdev);              //ok
    DHT11(double temp_stdev, double hum_stdev, Room *proom); //ok

    void setTemp_stdev(double stdev); //added by ME //ok
    void setHum_stdev(double stdev);  // added by ME//ok

    double getTemperature() const;         //ok
    double getHumidity() const;            //ok
    std::pair<double, double> getStdevs(); // added by ME

};
#endif