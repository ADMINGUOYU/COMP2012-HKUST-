#include "PocketMonster.h"

/* ----- Function to implement ----- */
    // Battle with the enemy by updating the enemy's hp and increase the
    // experience value of the pocket monster according to the following:
    // [ Update the enemy's hp ]
    // - Compute the amount of damage
    //   = attack value of the pocket monster - defense stat of the enemy
    // - If the computed damage is greater than 0, compute the enemy's new hp
    //    = current hp of the enemy - computed damage
    // - If the new hp is greater than 0, update the enemy's hp value
    //    with the new hp, otherwise set enemy's hp to 0.
    // [ Increase the experience value of the pocket monster ]
    // - If the amount of damage is greater than 0, increase the experience value
    //    of the pocket monster by the amount = computed damage + 5,
    //    otherwise only increase the experience value by 5
void PocketMonster::battle(PocketMonster &enemy)
{
    int amount_of_damage = this->attack - enemy.defense;
    if (amount_of_damage > 0)
    {
        enemy.hp = (enemy.hp - amount_of_damage > 0) ? enemy.hp - amount_of_damage : 0;
        this->exp += (amount_of_damage + 5);
    }
    else
        this->exp += 5;
    return;
}