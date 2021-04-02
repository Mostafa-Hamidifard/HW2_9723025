#include "dht11.h"
#include <random>
#include <chrono>
#include "room.h"
#include <iostream>
DHT11::DHT11(double _temp_stdev, double _hum_stdev) : DHT11(_temp_stdev, _hum_stdev, nullptr) {}
DHT11::DHT11(double _temp_stdev, double _hum_stdev, Room *_proom)
    : temp_stdev{_temp_stdev}, hum_stdev{_hum_stdev}, proom{_proom}
{
}

void DHT11::setHum_stdev(double stdev)
{
    hum_stdev = stdev;
}
void DHT11::setTemp_stdev(double stdev)
{
    temp_stdev = stdev;
}
double DHT11::getTemperature() const
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(proom->getTemperature(), temp_stdev);
    return distribution(generator);
}
double DHT11::getHumidity() const
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(proom->getHumidity(), temp_stdev);
    return distribution(generator);
}
std::pair<double, double> DHT11::getStdevs()
{
    return std::pair<double, double>{temp_stdev, hum_stdev};
}
