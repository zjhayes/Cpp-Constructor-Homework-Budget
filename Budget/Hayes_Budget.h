// Header file for Budget app.

// Zachary Hayes - zjhayes@dmacc.edu - July 8th, 2019
#include <iostream>
using namespace std;

class Budget
{
private:
    int rent;
    double gas;
    double water;
    int garbage;
    string donation;
    
public:
    
    // Constructors
    Budget();
    
    // Helper methods
    double getTotal();
    void addRent(int moreRent);
    void addGas(int moreGas);
    void addWater(double moreWater);
    void addGarbage(int moreGarbage);
    void addDonation(string moreDonation);
    
    // Accessors and mutators
    void setRent(int rentIn);
    int getRent();
    void setGas(double gasIn);
    double getGas();
    void setWater(double waterIn);
    double getWater();
    void setGarbage(int garbageIn);
    int getGarbage();
    void setDonation(string donationIn);
    string getDonation();
};
