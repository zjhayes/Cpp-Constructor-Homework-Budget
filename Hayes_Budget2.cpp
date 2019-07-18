// Budget app altered to use classes.

// Zachary Hayes - zjhayes@dmacc.edu - July 8th, 2019

#include <iostream>
using namespace std;

enum Bills {RENT, WATER, GARBAGE};

class Bill                              // This allows for a more dynamic Budget constructor.
{
private:
    
    Bills billType;
    double value;
    
public:
    
    Bill(Bills billTypeIn, double valueIn)
    {
        billType = billTypeIn;
        value = valueIn;
    }
    Bills getBillType()
    {
        return billType;
    }
    double getValue()
    {
        return value;
    }
};

class Budget
{
private:
    
    int rent;
    double water;
    int garbage;
    
public:
    
    Budget() // Default constructor.
    {
        reset();
    }
    
    Budget(int rentIn, double waterIn, int garbageIn)
    {
        rent = rentIn;
        water = waterIn;
        garbage = garbageIn;
    }
    
    Budget(Bill bill)               // Set one or two bills using Bill class,
    {                               // For example, to set rent and garbage you
        reset();                    // don't have to set water.
        setDynamicBill(bill);
    }
    
    Budget(Bill bill1, Bill bill2)
    {
        reset();
        setDynamicBill(bill1);
        setDynamicBill(bill2);      // If same billType as bill1, bill1 will be overridden.
    }
    
    // Helper methods
    
    double getTotal()
    {
        return rent + water + garbage;
    }
    
    void addRent(int moreRent)
    {
        rent += moreRent;
    }
    
    void addWater(double moreWater)
    {
        water += moreWater;
    }
    
    void addGarbage(int moreGarbage)
    {
        garbage += moreGarbage;
    }
    
    void reset()        // Call before setDynamicBill() so the values not set dynamically will be 0.
    {
        rent = 0;
        water = 0;
        garbage = 0;
    }
    
    void setDynamicBill(Bill bill)  // Set bill based on enum, so constructor isnt' dependent
    {                               // on the order bills are given, and any number can be set.
        if(bill.getBillType() == RENT)
        {
            rent = bill.getValue();
        }
        else if(bill.getBillType() == WATER)
        {
            water = bill.getBillType();
        }
        else if(bill.getBillType() == GARBAGE)
        {
            garbage = bill.getBillType();
        }
        else
        {
            cout << " There was an issue processing this bill. ";
        }
    }
    
    // Accessors and mutators
    
    void setRent(int rentIn)
    {
        rent = rentIn;
    }
    int getRent()
    {
        return rent;
    }
    void setWater(double waterIn)
    {
        water = waterIn;
    }
    double getWater()
    {
        return water;
    }
    void setGarbage(int garbageIn)
    {
        garbage = garbageIn;
    }
    int getGarbage()
    {
        return garbage;
    }
};

Budget calculateTotals(Budget*);
void outputTotal(double);
Budget calculateAverages(Budget);
void outputAverages(Budget);

const int MONTHS_PER_QUARTER = 4;

int main()
{
    // Set up budget..
    Budget quarterlyBudget[MONTHS_PER_QUARTER];
    
    Budget defaultBudget;               // Uses default constructor.
    defaultBudget.setRent(800);
    defaultBudget.setWater(68);
    defaultBudget.setGarbage(50);
    
    Budget normalBudget(650, 75, 30);   // Set properties in constructor.
    
    Bill waterBill(WATER, 40);          // Set one property dynamic constructor.
    Budget dynamicBudget(waterBill);
    dynamicBudget.setRent(400);
    dynamicBudget.setGarbage(65);
    
    Bill rentBill(RENT, 500);           // Set two properties dynamic constructor.
    Bill garbageBill(GARBAGE, 35);
    Budget doubleDynamicBudget(rentBill, garbageBill);
    doubleDynamicBudget.setWater(85);
    
    quarterlyBudget[0] = defaultBudget;
    quarterlyBudget[1] = normalBudget;  // Add to monthly budget.
    quarterlyBudget[2] = dynamicBudget;
    quarterlyBudget[3] = doubleDynamicBudget;
    
    // Process..
    Budget totals = calculateTotals(quarterlyBudget);
    Budget averages = calculateAverages(totals);
    
    // Output..
    outputTotal(totals.getTotal());
    outputAverages(averages);
    
    return 0;
}

Budget calculateTotals(Budget* quarterBudgets)
{
    Budget quarterlyAverages;
    
    for(int i = 0; i < MONTHS_PER_QUARTER; i++) // Sum totals into new Budget struct.
    {
        quarterlyAverages.addRent(quarterBudgets[i].getRent());
        quarterlyAverages.addWater(quarterBudgets[i].getWater());
        quarterlyAverages.addGarbage(quarterBudgets[i].getGarbage());
    }
    
    return quarterlyAverages;
}

void outputTotal(double total)
{
    cout << endl << "-----------------------" << endl << endl;
    cout << "QUARTER TOTAL: $" << total << endl;
}

Budget calculateAverages(Budget totals)
{
    Budget averages;
    
    averages.setRent(totals.getRent() / MONTHS_PER_QUARTER); // Calculate averages into new structure.
    averages.setWater(totals.getWater() / MONTHS_PER_QUARTER);
    averages.setGarbage(totals.getGarbage() / MONTHS_PER_QUARTER);
    
    return averages;
}

void outputAverages(Budget averages)
{
    cout << endl << "AVERAGES..." << endl;
    cout << "Rent $" << averages.getRent() << endl;
    cout << "Water $" << averages.getWater() << endl;
    cout << "Garbage $" << averages.getGarbage() << endl;
}



/*
 Create a class based on the monthly budget structure from last week but only include member items: rent, water and garbage.
 Include an accessor and a mutator (getter and setter) for each item, setup a default constructor (with some default values) and include a total function that is not stored as a member item but just is calculated when requested.
 
 Once you are done, create three objects as part of your program that demonstrate your class including one that uses the default constructor.
 */
