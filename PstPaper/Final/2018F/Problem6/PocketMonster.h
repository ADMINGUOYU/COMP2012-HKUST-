#ifndef POCKETMONSTER_H /* File: PocketMonster.h */
#define POCKETMONSTER_H
#include <iostream>
using namespace std;
class PocketMonster
{
private:
    string name;         // Name of the pocket monster
    int hp;              // Health point
    int attack;          // Attack stat
    int defense;         // Defense stat
    int speed;           // Speed
    int exp;             // Experience value
    string beforeEvolve; // Species before evolution
    string afterEvolve;  // Species after evolution
public:
    // Construct a pocket monster with the given name, health point, attack stat,
    // defense stat, speed, experience value, and species before & after evolution
    PocketMonster(string name = "", int hp = 0, int attack = 0,
                  int defense = 0, int speed = 0, int exp = 0,
                  string beforeEvolve = "", string afterEvolve = "")
        : name(name), hp(hp), attack(attack), defense(defense), speed(speed),
          exp(exp), beforeEvolve(beforeEvolve), afterEvolve(afterEvolve) {}
    // Print all the data of pocket monster
    virtual void print() const
    {
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << ", ATT: " << attack << ", DEF: " << defense
             << ", SPD: " << speed << ", EXP: " << exp << endl;
        cout << beforeEvolve << " -> " << name << " -> " << afterEvolve << endl;
    }
    // Accessor functions of all the data members
    string getName() const { return name; }
    double getHP() const { return hp; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getSpeed() const { return speed; }
    int getExp() const { return exp; }
    string regress() const { return beforeEvolve; }
    string evolve() const { return afterEvolve; }
    /* ----- Function to implement ----- */
    // Battle with the enemy by updating the enemy's hp and increase the
    // experience value of the pocket monster according to the following:
    // [ Update the enemy's hp ]
    // - Compute the amount of damage
    // = attack value of the pocket monster - defense stat of the enemy
    // - If the computed damage is greater than 0, compute the enemy's new hp
    // = current hp of the enemy - computed damage
    // - If the new hp is greater than 0, update the enemy's hp value
    // with the new hp, otherwise set enemy's hp to 0.
    // [ Increase the experience value of the pocket monster ]
    // - If the amount of damage is greater than 0, increase the experience value
    // of the pocket monster by the amount = computed damage + 5,
    // otherwise only increase the experience value by 5
    virtual void battle(PocketMonster &enemy);
    /*
    -> must be added
    */
    virtual ~PocketMonster() = default;
};
#endif /* POCKETMONSTER_H */
