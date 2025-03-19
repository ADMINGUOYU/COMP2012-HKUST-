#include "Strategy.h"
#include <iostream>

/*
Default constructor which initializes the strategy with an empty name.
*/
Strategy::Strategy()
    :name() { return; }

/*
Initializes the strategy with a specified name.
*/
Strategy::Strategy(const string &name)
    :name(name) { return; }

/*
The function to compute the moving average of stock prices over a specified window. 
This function computes the moving average MA of stock prices starting from a given index 
in the price array. 
It calculates the average of the most recent prices within the defined window, 
summing those prices and dividing by the number of prices considered to obtain the average.
*/
double Strategy::calculateMovingAverage(Market *market, int index, int window) const
{
    //!!! not sure of the behaviour if available number is smaller than window
    
    double valueToReturn = 0.0;
    int numberSumed = 0;
    // sum up the value
    for (int i = 0; i < window; i++) 
    {
        // stops summing when reaches index 0
        if (0 > (index - i)) break;
        // sum up the values
        valueToReturn += market->getPrice(index - i);
        ++numberSumed;  // keep track of how much we have summed
    }
    // find the average
    valueToReturn /= static_cast<double>(numberSumed);
    // return the value
    return valueToReturn;
}

/*
The function to return the name of the strategy.
*/
string Strategy::getName() const
{ return this->name; }
