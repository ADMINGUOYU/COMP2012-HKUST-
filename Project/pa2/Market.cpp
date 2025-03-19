#include "Market.h"
#include "Utils.h"

/*
The parameterized constructor for the Market class. All prices should be initilaized to 0.0.
*/
Market::Market(double initialPrice, double volatility, double expectedYearlyReturn, int numTradingDays, int seed)
    :
    initialPrice(initialPrice),
    volatility(volatility),
    expectedYearlyReturn(expectedYearlyReturn),
    numTradingDays(numTradingDays),
    prices(nullptr),
    seed(seed)
{
    // allocate memory for the dynamic array of pointers to double
    this->prices = new double* [this->numTradingDays];
    // allocate memory for every double and init to 0.0
    for (int i = 0; i < this->numTradingDays; i++) this->prices[i] = new double {0.0};

    return;
}

/*
The constructor for the Market class that reads market parameters and price data from a file.
*/
Market::Market(const string &filename)
    :
    initialPrice(0.0),
    volatility(0.0),
    expectedYearlyReturn(0.0),
    numTradingDays(0),
    prices(nullptr),
    seed(-1)
{

    /* 
    partially copied code from the member function 
    we don't want to delete the thing that does not exist
    */

    string filePath = "data/" + filename;
    ifstream inFile(filePath);
    if (!inFile)
    {
        cerr << "Error opening file for reading: " << filePath << endl;
        return;
    }

    inFile >> initialPrice >> volatility >> expectedYearlyReturn >> numTradingDays >> seed;

    // Count number of prices first
    ifstream countFile(filePath);
    string line;
    int count = 0;
    double dummy;
    countFile >> dummy >> dummy >> dummy >> dummy >> dummy; // Skip parameters
    while (countFile >> dummy)
        count++;
    countFile.close();

    // Allocate new array
    prices = new double *[count];
    for (int i = 0; i < count; i++)
    {
        prices[i] = new double(0.0);
    }

    // Read prices
    int pricesSize = 0;
    double price;
    while (inFile >> price)
    {
        *prices[pricesSize++] = price;
    }

    inFile.close();
    cout << "Loaded parameters from file: " << filePath << endl;
    cout << "Initial Price: " << initialPrice << ", Volatility: " << volatility
         << ", Expected Yearly Return: " << expectedYearlyReturn
         << ", Num of Trading Days: " << numTradingDays << ", Seed: " << seed << endl;
    cout << "Loaded " << pricesSize << " price entries." << endl;

    return;
}

/*
The destructor of the Market class.
*/
Market::~Market()
{
    // first delete the allocated double(s)
    for (int i = 0; i < this->numTradingDays; i++) delete (this->prices[i]);
    // delete the pointer to pointer array
    delete [] this->prices;

    return;
}

// ===== Don't modify below this line =====
// Helper function to generate a random number from a normal distribution
double Market::generateZ(int seed)
{
    static std::mt19937 gen(seed == -1 ? std::random_device{}() : seed);
    static std::normal_distribution<> d(0, 1);
    return d(gen);
}
// ===== Don't modify above this line =====

/*
The function to simulate price movements for numTradingDays based on a geometric Brownian motion model 
and stored simulated prices in prices. 
Please start with initialPrice and iteratively apply GBM formula to the previous prices. 
-> initialPrice should be the first element in the prices array. 
Remember to use roundToDecimals to round the prices up to 3 decimal places.
*/
void Market::simulate() 
{
    
    
    // set the first item
    (*this->prices[0]) = roundToDecimals(this->initialPrice, 3);

    // loop through
    for (int i = 1; i < this->numTradingDays; i++)
    {
        // generate seed if necessary
        // note that whether to generate ?= -1 is compared in the helper function
        // not sure the seed needs to be calculated everytime, so~
        double seedToUse = this->generateZ(this->seed);

        // calculate the coefficient to work with
        double coefficient = std::exp
        (
            (this->expectedYearlyReturn - (0.5 * std::pow(this->volatility, 2.0))) * (1.0 / TRADING_DAYS_PER_YEAR)
            +
            this->volatility * std::sqrt((1.0 / TRADING_DAYS_PER_YEAR)) * seedToUse
        );

        // calculate the next day
        (*this->prices[i]) = roundToDecimals(((*this->prices[i - 1]) * coefficient), 3);
        }

    // return
    return;
}

/*
The function to return the volatility of the stock.
*/
double Market::getVolatility() const
{ return (this->volatility); }

/*
The function to return the ExpectedYearlyReturn of the stock.
*/
double Market::getExpectedYearlyReturn() const
{ return (this->expectedYearlyReturn); }

/*
The function to return the array of prices.
*/
double **Market::getPrices() const
{ return (this->prices); }

/*
The function to retrieve the price at a specific index in the prices array.
*/
double Market::getPrice(int index) const
{ return (*this->prices[index]); }

/*
The function to return the last price in the prices array.
*/
double Market::getLastPrice() const
{ return (*this->prices[this->numTradingDays - 1]); }

/*
The function to return the size of the prices array (pricesSize).
*/
int Market::getNumTradingDays() const
{ return (this->numTradingDays); }

// ===== Don't modify below this line =====
void Market::createDirectory(const string &folder)
{
#ifdef _WIN32
    _mkdir(folder.c_str());
#else
    mkdir(folder.c_str(), 0777);
#endif
}

/*
This function saves the market parameters and generated prices to a specified file.
*/
void Market::writeToFile(const string &filename)
{
    string folder = "data";
    string filePath = folder + "/" + filename;

    createDirectory(folder);

    ofstream outFile(filePath);
    if (!outFile)
    {
        cerr << "Error opening file for writing: " << filePath << endl;
        return;
    }

    outFile << initialPrice << " " << volatility << " "
            << expectedYearlyReturn << " " << numTradingDays << " " << seed << endl;

    for (int i = 0; i < numTradingDays; ++i)
    {
        outFile << *prices[i] << endl;
    }

    outFile.close();
    cout << "Market parameters and prices written to file: " << filePath << endl;
}

/*
This function reads market parameters and price data from a file, loading them into the class.
*/
void Market::loadFromFile(const string &filename)
{
    string filePath = "data/" + filename;
    ifstream inFile(filePath);
    if (!inFile)
    {
        cerr << "Error opening file for reading: " << filePath << endl;
        return;
    }

    inFile >> initialPrice >> volatility >> expectedYearlyReturn >> numTradingDays >> seed;

    // Clear existing prices
    if (prices)
    {
        for (int i = 0; i < numTradingDays; i++)
        {
            delete prices[i];
        }
        delete[] prices;
    }

    // Count number of prices first
    ifstream countFile(filePath);
    string line;
    int count = 0;
    double dummy;
    countFile >> dummy >> dummy >> dummy >> dummy >> dummy; // Skip parameters
    while (countFile >> dummy)
        count++;
    countFile.close();

    // Allocate new array
    prices = new double *[count];
    for (int i = 0; i < count; i++)
    {
        prices[i] = new double(0.0);
    }

    // Read prices
    int pricesSize = 0;
    double price;
    while (inFile >> price)
    {
        *prices[pricesSize++] = price;
    }

    inFile.close();
    cout << "Loaded parameters from file: " << filePath << endl;
    cout << "Initial Price: " << initialPrice << ", Volatility: " << volatility
         << ", Expected Yearly Return: " << expectedYearlyReturn
         << ", Num of Trading Days: " << numTradingDays << ", Seed: " << seed << endl;
    cout << "Loaded " << pricesSize << " price entries." << endl;
}
// ===== Don't modify above this line =====

// TODO: Implement the member functions of the Market class
