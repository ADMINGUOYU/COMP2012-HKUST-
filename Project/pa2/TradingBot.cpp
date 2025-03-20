#include "TradingBot.h"
#include <limits>

/*
The constructor for TradingBot class.
The constructor TradingBot(Market *market, int initialCapacity = 10) 
initializes the bot with a specified market and an optional initial capacity for strategies.
*/
TradingBot::TradingBot(Market *market, int initialCapacity)
    :
    market(market),
    availableStrategies(nullptr),
    strategyCount(0),
    strategyCapacity(initialCapacity)
{
    // allocate memory for the array of pointers
    this->availableStrategies = new Strategy* [this->strategyCapacity] { };

    return;
}

/*
The destructor for TradingBot class.
The destructor ~TradingBot() releases the memory allocated for the strategies 
and ensures proper cleanup to prevent memory leaks.
*/
TradingBot::~TradingBot()
{
    // we have to delete the pointer to strategies
    // even we do not create them here (delete nullptr is safe)
    for (int i = 0; i < this->strategyCount; i++) delete this->availableStrategies[i];

    // delete the dynamic allocated array of pointers
    delete [] this->availableStrategies;

    return;
}

/*
This function adds a new trading strategy to the bot. 
If the capacity is reached, 
it dynamically increases the capacity of the strategies array.
*/
void TradingBot::addStrategy(Strategy *strategy)
{
    if (this->strategyCapacity <= this->strategyCount)
    {
        // we have to add slots
        Strategy** newArr = new Strategy* [++this->strategyCapacity] { };
        // copy the old information
        for (int i = 0; i < this->strategyCount; i++) newArr[i] = this->availableStrategies[i];
        // delete the old dynamic array
        delete [] this->availableStrategies;
        // assign the new array
        this->availableStrategies = newArr;
    }
    // add the new strategy
    this->availableStrategies[this->strategyCount++] = strategy;

    return;
}

/*
This function executes the trading simulation using the available strategies. 
It returns a SimulationResult containing the best strategy and its total return. 
You should calculate return as follows:
1. Start with zero cumulative profit.
2. For each trading day, choose a strategy and decide on an action:
- BUY: You can only perform a buy action if you currently do not hold a stock.
- SELL: You can sell the stock only if you still hold one.
- HOLD: No change in your holding position.
3. Update the cumulative profit by price difference between current and previous day.
- If the bot buys stock, it records the purchase price; 
- if it sells stock, it calculates the profit (difference between current price and purchase price) 
and adds it to the cumulative profit
4. On the last trading day, if you still hold a stock, add the price difference between 
the current price and the last price you bought the stock to the cumulative profit.
*/
SimulationResult TradingBot::runSimulation()
{
    SimulationResult resultToReturn { };

    for (int i = 0; i < this->strategyCount; i++)
    {
        // set strategy to work with
        double cumulativeProfit = 0.0;
        Strategy* strategy = this->availableStrategies[i];
        double currentHolding = static_cast<double>(false);
        /* note that this is the same as remembering the last price */
        /* note that the instructions has changed to "calculate last 101 days" */
        /* this part is hard coded */
        for (int j = this->market->getNumTradingDays() - 101; j < this->market->getNumTradingDays(); j++)
        {
            // for each trading day
            switch (strategy->decideAction(this->market, j, currentHolding))
            {
            case Action::BUY:
                currentHolding = static_cast<double>(true);
                cumulativeProfit -= this->market->getPrice(j);
                break;
            case Action::SELL:
                currentHolding = static_cast<double>(false);
                cumulativeProfit += this->market->getPrice(j);
                break;
            default:    // Action::HOLD -> do nothing
                break;
            }
        }
        if (true == static_cast<bool>(currentHolding))
        {
            // if holds in the end
            cumulativeProfit += this->market->getLastPrice();
        }
        
        // compare cumulative profit
        if (cumulativeProfit > resultToReturn.totalReturn)
        {
            // we update to this strategy
            resultToReturn.totalReturn = cumulativeProfit;
            resultToReturn.bestStrategy = strategy;
        }
    }

    // return
    return resultToReturn;
}
