// Budget class for Budget app.

// Zachary Hayes - zjhayes@dmacc.edu - July 8th, 2019

#include "Hayes_Budget.h"
#include <iostream>
using namespace std;

Budget::Budget()
{
    rent = 0;
    gas = 0;
    water = 0;
    garbage = 0;
    donation = "";
}
    
double Budget::getTotal()
{
    return rent + gas + water + garbage;
}
    
void Budget::addRent(int moreRent)
{
    rent += moreRent;
}
    
void Budget::addGas(int moreGas)
{
    gas += moreGas;
}
    
void Budget::addWater(double moreWater)
{
    water += moreWater;
}
    
void Budget::addGarbage(int moreGarbage)
{
    garbage += moreGarbage;
}
    
void Budget::addDonation(string moreDonation)
{
    donation += moreDonation + "\n";
}
    
    // Accessors and mutators
    
void Budget::setRent(int rentIn)
{
    rent = rentIn;
}
int Budget::getRent()
{
    return rent;
}
void Budget::setGas(double gasIn)
{
    gas = gasIn;
}
double Budget::getGas()
{
    return gas;
}
void Budget::setWater(double waterIn)
{
    water = waterIn;
}
double Budget::getWater()
{
    return water;
}
void Budget::setGarbage(int garbageIn)
{
    garbage = garbageIn;
}
int Budget::getGarbage()
{
    return garbage;
}
void Budget::setDonation(string donationIn)
{
    donation = donationIn;
}
string Budget::getDonation()
{
    return donation;
}
