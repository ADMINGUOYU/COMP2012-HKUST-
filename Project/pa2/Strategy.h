#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include "Market.h"

using namespace std;

const int EVALUATION_WINDOW = 100;
class Strategy
{
private:
    string name;
    // TODO: fill out this part if needed

protected:
    // TODO: fill out this part if needed

public:
    // TODO: fill out this part if needed
};

enum Action
{
    BUY,
    SELL,
    HOLD
};

#endif