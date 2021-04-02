#include "room.h"

Room::Room(size_t _id, double _temperature, double _humidity)
    : id{_id}, temperature{_temperature}, humidity{_humidity}, dht{new DHT11{0, 0, this}} {}

double Room::getTemperature() const
{
    return temperature;
}
double Room::getHumidity() const
{
    return humidity;
}
void Room::changeTemperatureStdev(double stdev) const
{
    dht->setTemp_stdev(stdev);
}
void Room::changeHumidityStdev(double stdev) const
{
    dht->setHum_stdev(stdev);
}
void Room::set_id(size_t _id)
{
    id = _id;
}
size_t Room::get_id() const
{
    return id;
}
