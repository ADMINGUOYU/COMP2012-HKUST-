#include "WeightedTrendFollowingStrategy.h"
#include "Utils.h"
#include <cmath>

/*
Default constructor for the WeightedTrendFollowingStrategy class.
*/
WeightedTrendFollowingStrategy::WeightedTrendFollowingStrategy()
    :
    TrendFollowingStrategy()    // initialize its parent
{ return; }

/*
The constructor initializes the strategy with a specified name and the short and long moving average windows, leveraging the base class TrendFollowingStrategy.
*/
WeightedTrendFollowingStrategy::WeightedTrendFollowingStrategy(const string &name, int shortWindow, int longWindow)
    :
    TrendFollowingStrategy(name, shortWindow, longWindow)
{ return; }

/*
This function calculates the exponential weight for a given index, 
allowing more recent prices to have a greater influence on the moving average. 
Compute an exponential weight for a given index by initializing a growth factor to 1.1 (+10%), 
starting with a weight of 1.0, and iteratively multiplying the weight by the growth factor for each index up to the specified one, 
ensuring that more recent prices have a greater influence on the moving average.
*/
double WeightedTrendFollowingStrategy::calculateExponentialWeight(int index) const
{ return (1.0 * std::pow(1.1, index)); }

/*
The `WeightedTrendFollowingStrategy` class overrides this function from the base Strategy class. 
This function calculates a weighted moving average WMA of stock prices, using the exponential weights determined by calculateExponentialWeight. 
It sums the weighted prices and divides by the total weight.
*/
double WeightedTrendFollowingStrategy::calculateMovingAverage(Market *market, int index, int window) const
{
    //!!! not sure of the behaviour if available number is smaller than window
    
    double valueToReturn = 0.0;
    double weightSumed = 0.0;

    // set the first index to sum
    int startingIndex = index + 1 - window;
    startingIndex = (startingIndex < 0) ? 0 : startingIndex;

    // sum up the value
    for (int i = startingIndex; i <= index; i++) 
    {
        double weight = this->calculateExponentialWeight(i);
        valueToReturn += (market->getPrice(i) * weight);
        weightSumed += weight;
    }
    // find the average
    valueToReturn /= weightSumed;
    // return the value
    return valueToReturn;
}

/*
The static function generates a dynamic array of WeightedTrendFollowingStrategy objects. 
It iterates over the range of window sizes for the short and long windows, 
creating a new strategy for each combination. Minimum and maximum values are inclusive. 
Each strategy is named using this code snippet: 
baseName + "_" + to_string(shortWindow) + "_" + to_string(longWindow). 
For example, the baseName is "WeightedTrendFollowing", shortWindow is 10, and longWindow is 25, the strategy name would be "WeightedTrendFollowing_10_25".
*/
WeightedTrendFollowingStrategy **WeightedTrendFollowingStrategy::generateStrategySet(const string &baseName, int minShortWindow, int maxShortWindow, int stepShortWindow, int minLongWindow, int maxLongWindow, int stepLongWindow)
{
    // calculate total number to create
    int totalNum = ((maxShortWindow - minShortWindow) / stepShortWindow + 1) * ((maxLongWindow - minLongWindow) / stepLongWindow + 1);
    // allocate memory
    WeightedTrendFollowingStrategy** toReturn = new WeightedTrendFollowingStrategy*[totalNum];

    for (int wndSrt = minShortWindow, i = 0; wndSrt <= maxShortWindow; wndSrt += stepShortWindow)
    {
        // we assume it is dividable (i is the counter)
        for (int wndLng = minLongWindow; wndLng <= maxLongWindow; wndLng += stepLongWindow)
            toReturn[i++] = new WeightedTrendFollowingStrategy(baseName + "_" + std::to_string(wndSrt) + "_" + std::to_string(wndLng), wndSrt, wndLng);
    }
    
    // return the pointer
    return toReturn;
}
