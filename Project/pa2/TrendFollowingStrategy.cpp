#include "TrendFollowingStrategy.h"
#include "Utils.h"
#include <iostream>

/*
Default constructor for the TrendFollowingStrategy class
*/
TrendFollowingStrategy::TrendFollowingStrategy()
:
    Strategy(),  //use the default as well
    shortMovingAverageWindow(),
    longMovingAverageWindow()
{ return; }

/*
The constructor initializes the strategy with a specified name and the short and long moving average windows.
*/
TrendFollowingStrategy::TrendFollowingStrategy(const std::string &name, int shortWindow, int longWindow)
    :
    Strategy(name),
    shortMovingAverageWindow(shortWindow),
    longMovingAverageWindow(longWindow)
{ return; }

/*
The TrendFollowingStrategy class overrides this function from the base Strategy class. 
It determines the action to take (buy, sell, or hold) based on the relationship between 
the short and long moving averages. 
If the short-term moving average (MAshort) crosses above the long-term moving average (MAlong), 
the strategy will execute a buy order. 
This indicates a potential upward trend, suggesting it may be a good time to enter a 
long position. 
Conversely, if the short-term moving average crosses below the long-term moving average, 
the strategy will execute a sell order. 
If neither condition is met, the strategy will hold the current position. 
The moving averages are calculated using the calculateMovingAverage function with given market data, 
period of evaluation (short or long window), and starting day (index). 

Note: You cannot buy the stock if you already have one (currentHolding is 1). 
Similarly, you cannot sell the stock if you do not have one (currentHolding is 0).
*/
Action TrendFollowingStrategy::decideAction(Market *market, int index, double currentHolding) const
{
    Action action = Action::HOLD;

    // calculate moving average
    double MaShort = this->calculateMovingAverage(market, index, this->shortMovingAverageWindow);
    double MaLong = this->calculateMovingAverage(market, index, this->longMovingAverageWindow);

    if ((MaShort > MaLong) && (false == static_cast<bool>(currentHolding)))
        action = Action::BUY;

    if ((MaShort < MaLong) && (true == static_cast<bool>(currentHolding)))
        action = Action::SELL;

    return action;
}

/*
The static function generates a dynamic array of TrendFollowingStrategy objects. 
It iterates over the range of window sizes for the short and long windows, 
creating a new strategy for each combination. Minimum and maximum values are inclusive. 
Each strategy is named using this code snippet: 
baseName + "_" + to_string(shortWindow) + "_" + to_string(longWindow). 
For example, the baseName is "TrendFollowing", shortWindow is 10, and longWindow is 25, the strategy name would be "TrendFollowing_10_25".
*/
TrendFollowingStrategy **TrendFollowingStrategy::generateStrategySet(const string &baseName, int minShortWindow, int maxShortWindow, int stepShortWindow, int minLongWindow, int maxLongWindow, int stepLongWindow)
{
    // calculate total number to create
    int totalNum = ((maxShortWindow - minShortWindow) / stepShortWindow + 1) * ((maxLongWindow - minLongWindow) / stepLongWindow + 1);
    // allocate memory
    TrendFollowingStrategy** toReturn = new TrendFollowingStrategy*[totalNum];

    for (int wndSrt = minShortWindow, i = 0; wndSrt <= maxShortWindow; wndSrt += stepShortWindow)
    {
        // we assume it is dividable (i is the counter)
        for (int wndLng = minLongWindow; wndLng <= maxLongWindow; wndLng += stepLongWindow)
            toReturn[i++] = new TrendFollowingStrategy(baseName + "_" + to_string(wndSrt) + "_" + to_string(wndLng), wndSrt, wndLng);
    }
    
    // return the pointer
    return toReturn;
}
