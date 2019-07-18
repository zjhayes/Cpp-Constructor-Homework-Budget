// Main Budget app program

// Zachary Hayes - zjhayes@dmacc.edu - July 8th, 2019

#include "Hayes_Budget.cpp"
#include <iostream>
using namespace std;

void getInput(Budget*);
Budget getInputForMonth();
Budget calculateTotals(Budget*);
void outputTotal(double);
Budget calculateAverages(Budget);
void outputAverages(Budget);
void outputDonations(string);
Budget invalidInput();

const int MONTHS_PER_QUARTER = 4;

int main()
{
    // Take input..
    Budget quarterlyBudget[MONTHS_PER_QUARTER];
    getInput(quarterlyBudget);
    
    // Process..
    Budget totals = calculateTotals(quarterlyBudget);
    Budget averages = calculateAverages(totals);
    
    // Output..
    outputTotal(totals.getTotal());
    outputAverages(averages);
    outputDonations(totals.getDonation());
    
    return 0;
}

void getInput(Budget* budget)
{
    for(int i = 0; i < MONTHS_PER_QUARTER; i++) // For each month..
    {
        cout << "Enter spendings for month " << i + 1 << "/" << MONTHS_PER_QUARTER << endl;
        budget[i] = getInputForMonth(); // Get input for this month.
    }
}

Budget getInputForMonth()
{
    Budget currentBudget; // Get user input for one month's spendings.
    
    int rentIn;
    cout << "Rent: $";
    cin >> rentIn;
    currentBudget.setRent(rentIn);
    
    double gasIn;
    cout << "Gas: $";
    cin >> gasIn;
    currentBudget.setGas(gasIn);
    
    double waterIn;
    cout << "Water: $";
    cin >> waterIn;
    currentBudget.setWater(waterIn);
    
    int garbageIn;
    cout << "Garbage: $";
    cin >> garbageIn;
    currentBudget.setGarbage(garbageIn);
    
    if(cin.fail()) // Validates input.
    {
        return invalidInput();
    }
    
    cin.ignore();
    
    string donationIn;
    cout << "Donations? (Summarize): ";
    getline(cin, donationIn);
    currentBudget.setDonation(donationIn);
    
    return currentBudget;
}

Budget invalidInput()
{
    cout << endl << endl << "You've entered an invalid value, " << endl;
    cout << "and unfortunately you'll have to start " << endl;
    cout << "this month's budget over..." << endl << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return getInputForMonth(); // Prompt for new data.
}

Budget calculateTotals(Budget* quarterBudgets)
{
    Budget quarterlyAverages;
    
    for(int i = 0; i < MONTHS_PER_QUARTER; i++) // Sum totals into new Budget struct.
    {
        quarterlyAverages.addRent(quarterBudgets[i].getRent());
        quarterlyAverages.addGas(quarterBudgets[i].getGas());
        quarterlyAverages.addWater(quarterBudgets[i].getWater());
        quarterlyAverages.addGarbage(quarterBudgets[i].getGarbage());
        quarterlyAverages.addDonation(quarterBudgets[i].getDonation());
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
    averages.setGas(totals.getGas() / MONTHS_PER_QUARTER);
    averages.setWater(totals.getWater() / MONTHS_PER_QUARTER);
    averages.setGarbage(totals.getGarbage() / MONTHS_PER_QUARTER);
    
    return averages;
}

void outputAverages(Budget averages)
{
    cout << endl << "AVERAGES..." << endl;
    cout << "Rent $" << averages.getRent() << endl;
    cout << "Gas $" << averages.getGas() << endl;
    cout << "Water $" << averages.getWater() << endl;
    cout << "Garbage $" << averages.getGarbage() << endl;
}

void outputDonations(string donations)
{
    cout << endl << "DONATIONS.." << endl;
    cout << donations << endl;
}



/*
    For the budget class from last week, separate out the class from the main program into two separate files - (main file and .h file).
    One can also do three files including an implementation file but that does not work with Dev-C.
 */
