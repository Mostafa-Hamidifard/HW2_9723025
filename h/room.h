#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <memory>
#include "dht11.h"
class Room
{
private:
    size_t id;
    double temperature{28};
    double humidity{25}; //  Make this as last 2 digits of your student no

public:
    Room(size_t id, double temperature, double humidity); //ok
    double getTemperature() const;                        //ok
    double getHumidity() const;                           //ok
    void changeTemperatureStdev(double stdev) const;      //ok
    void changeHumidityStdev(double stdev) const;         //ok
    size_t get_id() const;                                //added by ME //not used in this Homework
    void set_id(size_t _id);                              //added by ME //not used in this Homework
    std::unique_ptr<DHT11> dht;
};
#endif