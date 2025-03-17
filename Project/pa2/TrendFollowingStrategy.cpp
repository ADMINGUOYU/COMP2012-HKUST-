#include "TrendFollowingStrategy.h"
#include "Utils.h"
#include <iostream>

TrendFollowingStrategy::TrendFollowingStrategy()
{
}

TrendFollowingStrategy::TrendFollowingStrategy(const std::string &name, int shortWindow, int longWindow)
{
}

Action TrendFollowingStrategy::decideAction(Market *market, int index, double currentHolding) const
{
}

TrendFollowingStrategy **TrendFollowingStrategy::generateStrategySet(const string &baseName, int minShortWindow, int maxShortWindow, int stepShortWindow, int minLongWindow, int maxLongWindow, int stepLongWindow)
{
}
