#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

int main() {
    // =========================
    // 1) CREATE ITEMS
    // =========================
    // For int
    Item<int> sword("Sword of Flames", 100, 5);
    Item<int> shield("Shield of Thunder", 80, 7);
    Item<int> potion("Healing Potion", 25, 1);

    // For double
    Item<double> gold("Gold Coin", 1.5, 0.01);
    Item<double> diamond("Shiny Diamond", 500.99, 0.2);

    cout << "\n[--- Items Created ---]\n";
    cout << "  " << sword << "\n";
    cout << "  " << shield << "\n";
    cout << "  " << potion << "\n";
    cout << "  " << gold << "\n";
    cout << "  " << diamond << "\n";

    // =========================
    // 2) TEST ITEM OPERATIONS (SAME-TYPE, CROSS-TYPE)
    // =========================
    Item<int> combined = sword + shield;
    Item<int> scaledSword = sword * 2;

    Item<double> combinedD = gold + diamond;
    Item<double> scaledGold = gold * 2.0;

    Item<double> crossSum1 = sword + gold;     // operator+<int,double>
    Item<double> crossSum2 = diamond + shield; // operator+<double,int>

    Item<double> crossScaled1 = shield * 2.5;  // operator*<int,double>
    Item<double> crossScaled2 = diamond * 3;   // operator*<double,int>

    cout << "\n[--- Item Operator Tests ---]\n";
    cout << "  Sword + Shield => " << combined << "\n";
    cout << "  Sword * 2 => " << scaledSword << "\n";
    cout << "  Gold + Diamond => " << combinedD << "\n";
    cout << "  Gold * 2.0 => " << scaledGold << "\n";
    cout << "  Sword<int> + Gold<double> => " << crossSum1 << "\n";
    cout << "  Diamond<double> + Shield<int> => " << crossSum2 << "\n";
    cout << "  Shield<int> * 2.5 => " << crossScaled1 << "\n";
    cout << "  Diamond<double> * 3 => " << crossScaled2 << "\n";

    // =======================================================
    // 3) TEST NON-TEMPLATED INVENTORY (WITH Item<int>)
    // =======================================================
    Inventory inv1;
    inv1.addItem(sword);
    inv1.addItem(shield);

    Inventory inv2;
    inv2.addItem(potion);

    Inventory inv3;
    inv3.addItem(Item<int>("Bow", 90, 4));
    inv3.addItem(Item<int>("Arrows", 1, 0));

    cout << "\n[--- Inventory Tests ---]\n";
    cout << "  inv1 => " << inv1 << "\n";
    cout << "  inv2 => " << inv2 << "\n";
    cout << "  inv3 => " << inv3 << "\n";

    // Test operator+ for Inventory (merging)
    Inventory merged = inv1 + inv2;
    cout << "  merged = inv1 + inv2 => " << merged << "\n";

    // Test the chain of merges: inv = inv1 + inv2 + inv3
    Inventory inv;
    inv = inv1 + inv2 + inv3;  // tests both operator+ and operator=
    cout << "  inv = inv1 + inv2 + inv3 => " << inv << "\n";

    // Test operator= separately
    Inventory copy;
    copy = inv1;
    cout << "  copy = inv1 => " << copy << "\n";

    cout << "\n[--- All Tests Completed ---]\n";
    return 0;
}