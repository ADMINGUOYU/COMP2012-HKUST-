#ifndef ELECTRICPOCKETMONSTER_H /* File: ElectricPocketMonster.h */
#define ELECTRICPOCKETMONSTER_H
#include <iostream>
#include <typeinfo>
#include <cmath>
#include "PocketMonster.h"
class ElectricPocketMonster : public PocketMonster
{
private:
    int electricPower; // Electric power stat of the electric pocket monster
public:
    // Accessor function of electric power
    int getEP() const { return electricPower; }
    /* ----- Functions to implement ----- */
    // Construct an electric pocket monster with the given name, health point,
    // attack stat, defense stat, speed, experience value, species before &
    // after evolution and electric power stat
    ElectricPocketMonster(string name = "", int hp = 0, int attack = 0,
                          int defense = 0, int speed = 0, int exp = 0,
                          string bEvolve = "", string aEvolve = "",
                          int electricPower = 0);
    // Battle with the enemy by updating the enemy's hp and increase the experience
    // value of the electric pocket monster according to the following:
    // [ Update the enemy's hp ]
    // - The rules for updating the enemy's hp are SAME AS the battle function in
    // PocketMonster class EXCEPT on the computation of damage
    // - The amount of damage is calculated according to the rules below:
    // * If the enemy is of ElectricPocketMonster type, the damage is
    // = attack value of the electric pocket monster - defense stat of the enemy
    // * If the enemy is of PocketMonster type, electric pocket monster takes
    // advantage of its electric power and the damage is
    // = attack value of the electric pocket monster -
    // defense stat of the enemy + floor(0.5 * electricPower)
    // Hint: You may find the function: double floor(double x) in cmath library
    // useful for this computation.
    // [ Increase the experience value of the ElectricPocketMonster ]
    // - SAME AS the battle function in PocketMonster
    void battle(PocketMonster &enemy) override;
    // Print all the data of electric pocket monster according to the sample output
    void print() const override;
};
#endif /* ELECTRICPOCKETMOSTER_H */
