#include "MeanReversionStrategy.h"
#include "Utils.h"
#include <cmath>
#include <iostream>

/*
Default constructor of MeanReversionStrategy class.
*/
MeanReversionStrategy::MeanReversionStrategy()
    :
    Strategy(),  //use the default as well
    window(),
    threshold()
{ return; }

/*
This constructor initializes the strategy with a specified name, window size, and threshold.
*/
MeanReversionStrategy::MeanReversionStrategy(const string &name, int window, int threshold)
    :
    Strategy(name),
    window(window),
    threshold(threshold)
{ return; }

/*
The MeanReversionStrategy class overrides this function from the base Strategy class. 
It determines the action to take (buy, sell, or hold) based on the current stock price 
relative to the moving average. 
The moving average is calculated using the calculateMovingAverage function with given market data, 
period of evaluation (window), and starting day (index). 
The mean reversion logic dictates that if the price is above the moving average (MA) by the threshold amount, 
the strategy will sell; 
if it is below the threshold amount, it will buy. 
If neither condition is met, it will hold. 
For example, if MA is 200 and threshold is 20 percent you should buy only if the price is below 160 and sell if the price is above 240. 
You cannot buy the stock if you already have one (currentHolding is true). 
Similarly, you cannot sell the stock if you do not have one (currentHolding is false).
*/
Action MeanReversionStrategy::decideAction(Market *market, int index, double currentHolding) const
{
    Action action = Action::HOLD;

    // calculate moving average
    double ma = this->calculateMovingAverage(market, index, this->window);

    if (
        ((market->getPrice(index) - ma) > (ma * this->threshold / 100.0))
        &&
        (true == static_cast<bool>(currentHolding))
    ) action = Action::SELL;            

    if (
        (ma - (market->getPrice(index)) > (ma * this->threshold / 100.0))
        &&
        (false == static_cast<bool>(currentHolding))
    ) action = Action::BUY;

    // return
    return action;
}

/*
The static function generates a dynamic array of MeanReversionStrategy objects. 
It iterates over the range of window sizes and thresholds, 
creating a new strategy for each combination. 
Minimum and maximum values are inclusive. 
Each strategy is named using this code snippet: 
baseName + "_" + 
to_string(window) + "_" + 
to_string(threshold). 
For example, the baseName is "MeanReversion", window is 10, and threshold is 5, the strategy name would be "MeanReversion_10_5".
*/
MeanReversionStrategy **MeanReversionStrategy::generateStrategySet(const string &baseName, int minWindow, int maxWindow, int windowStep, int minThreshold, int maxThreshold, int thresholdStep)
{
    // calculate total number to create
    int totalNum = ((maxWindow - minWindow) / windowStep + 1) * ((maxThreshold - minThreshold) / thresholdStep + 1);
    // allocate memory
    MeanReversionStrategy** toReturn = new MeanReversionStrategy*[totalNum];

    for (int wnd = minWindow, i = 0; wnd <= maxWindow; wnd += windowStep)
    {
        // we assume it is dividable (i is the counter)
        for (int thres = minThreshold; thres <= maxThreshold; thres += thresholdStep)
            toReturn[i++] = new MeanReversionStrategy(baseName + "_" + to_string(wnd) + "_" + to_string(thres), wnd, thres);
    }
    
    // return the pointer
    return toReturn;
}