#include "WeightedTrendFollowingStrategy.h"
#include "Utils.h"
#include <cmath>

WeightedTrendFollowingStrategy::WeightedTrendFollowingStrategy()
{
}

WeightedTrendFollowingStrategy::WeightedTrendFollowingStrategy(const string &name, int shortWindow, int longWindow)
{
}

double WeightedTrendFollowingStrategy::calculateExponentialWeight(int index) const
{
}

double WeightedTrendFollowingStrategy::calculateMovingAverage(Market *market, int index, int window) const
{
}

WeightedTrendFollowingStrategy **WeightedTrendFollowingStrategy::generateStrategySet(const string &baseName, int minShortWindow, int maxShortWindow, int stepShortWindow, int minLongWindow, int maxLongWindow, int stepLongWindow)
{
}
