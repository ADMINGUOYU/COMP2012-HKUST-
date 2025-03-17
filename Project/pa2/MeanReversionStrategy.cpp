#include "MeanReversionStrategy.h"
#include "Utils.h"
#include <cmath>
#include <iostream>

MeanReversionStrategy::MeanReversionStrategy()
{
}

MeanReversionStrategy::MeanReversionStrategy(const string &name, int window, int threshold)
{
}

Action MeanReversionStrategy::decideAction(Market *market, int index, double currentHolding) const
{
}

MeanReversionStrategy **MeanReversionStrategy::generateStrategySet(const string &baseName, int minWindow, int maxWindow, int windowStep, int minThreshold, int maxThreshold, int thresholdStep)
{
}