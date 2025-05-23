#include "ElectricPocketMonster.h"
#include <typeinfo>
#include <cmath>

ElectricPocketMonster::ElectricPocketMonster(string name, int hp, int attack, int defense, int speed, int exp, string bEvolve, string aEvolve, int electricPower)
    :
    PocketMonster{ name, hp, attack, defense, speed, exp, bEvolve, aEvolve},
    electricPower(electricPower)
{ return; }

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
void ElectricPocketMonster::battle(PocketMonster &enemy)
{
    int amount_of_damage = this->getAttack() - enemy.getDefense();                     
    if (typeid(enemy) == typeid(PocketMonster)) amount_of_damage += std::floor(0.5 * this->electricPower);

    int new_exp { };
    if (amount_of_damage > 0)
    {
        int new_hp = (enemy.getHP() - amount_of_damage > 0) ? enemy.getHP() - amount_of_damage : 0;
        if (typeid(enemy) == typeid(PocketMonster))
        {
            enemy = PocketMonster {enemy.getName(), new_hp,
                                   enemy.getAttack(), enemy.getDefense(),
                                   enemy.getSpeed(), enemy.getExp(),
                                   enemy.regress(), enemy.evolve() };
            
        }
        else
        {
            ElectricPocketMonster& e = dynamic_cast<ElectricPocketMonster&>(enemy);
            enemy = ElectricPocketMonster(e.getName(), new_hp,
                                          e.getAttack(), e.getDefense(),
                                          e.getSpeed(), e.getExp(),
                                          e.regress(), e.evolve(),
                                          e.electricPower);
        }
        new_exp = this->getExp() + (amount_of_damage + 5);
    }
    else
        new_exp = this->getExp() + 5;

    (*this) = ElectricPocketMonster(this->getName(), this->getHP(),
                                          this->getAttack(), this->getDefense(),
                                          this->getSpeed(), new_exp,
                                          this->regress(), this->evolve(),
                                          this->electricPower);

    return;
}

void ElectricPocketMonster::print() const
{
    this->PocketMonster::print();
    std::cout << "Electric Power: " << this->electricPower << std::endl;
}