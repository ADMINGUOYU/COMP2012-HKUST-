#include "ElectricPocketMonster.h" /* File: test-pocket-monster.cpp */
#include "Team.h"
void train_and_print(PocketMonster *pm, PocketMonster &enemy)
{
    cout << "=== Start ===" << endl;
    cout << "[ Pocket Monster ]" << endl;
    pm->print();
    cout << "[ Enemy ]" << endl;
    enemy.print();
    cout << "=== Battle ===" << endl;
    if (pm->getSpeed() > enemy.getSpeed())
    {
        pm->battle(enemy);
        enemy.battle(*pm);
    }
    else
    {
        enemy.battle(*pm);
        pm->battle(enemy);
    }
    cout << "[ Pocket Monster ]" << endl;
    pm->print();
    cout << "[ Enemy ]" << endl;
    enemy.print();
}
int main()
{
    cout << ">>> Create a Pocket Monster \"Charmeleon\" " << "and an Electric Pocket Monster \"Pikachu\" <<<" << endl;
    // The following dynamic objects will be de-allocated by the destructor
    // of the Team class.
    PocketMonster *pocketMonster[2] = {
        new PocketMonster("Charmeleon", 80, 25, 30, 8, 50, "Charmander", "Charizard"),
        new ElectricPocketMonster("Pikachu", 100, 30, 25, 10, 60, "Pichu", "Raichu", 40)};
    cout << ">>> Create Team A by adding Charmeleon and Pikachu as members <<<" << endl;
    Team teamA;
    for (int i = 0; i < sizeof(pocketMonster) / sizeof(PocketMonster *); ++i)
        teamA.addMember(pocketMonster[i]);
    cout << ">>> Create Team B as a clone of Team A using copy constructor <<<" << endl;
    Team teamB(teamA);
    cout << endl;
    PocketMonster enemy("Metapod", 40, 5, 10, 2, 50, "Caterpie", "Butterfree");
    for (int i = 0; i < sizeof(pocketMonster) / sizeof(PocketMonster *); ++i)
    {
        cout << "Train <<< "
             << ((i == 0) ? "PocketMonster" : "ElectricPocketMonster")
             << " >>>" << endl;
        train_and_print(pocketMonster[i], enemy);
        cout << endl;
    }
    cout << "[ Print Team A ]" << endl;
    teamA.print();
    cout << endl;
    cout << "[ Print Team B ]" << endl;
    teamB.print();
    return 0;
}

/*
compile command: g++ -fsanitize=address,undefined,leak PocketMonster.cpp ElectricPocketMonster.cpp Team.cpp test-pocket-monster.cpp

output:
>>> Create a Pocket Monster "Charmeleon" and an Electric Pocket Monster "Pikachu" <<<
>>> Create Team A by adding Charmeleon and Pikachu as members <<<
>>> Create Team B as a clone of Team A using copy constructor <<<

Train <<< PocketMonster >>>
=== Start ===
[ Pocket Monster ]
Name: Charmeleon
HP: 80, ATT: 25, DEF: 30, SPD: 8, EXP: 50
Charmander -> Charmeleon -> Charizard
[ Enemy ]
Name: Metapod
HP: 40, ATT: 5, DEF: 10, SPD: 2, EXP: 50
Caterpie -> Metapod -> Butterfree
=== Battle ===
[ Pocket Monster ]
Name: Charmeleon
HP: 80, ATT: 25, DEF: 30, SPD: 8, EXP: 70
Charmander -> Charmeleon -> Charizard
[ Enemy ]
Name: Metapod
HP: 25, ATT: 5, DEF: 10, SPD: 2, EXP: 55
Caterpie -> Metapod -> Butterfree

Train <<< ElectricPocketMonster >>>
=== Start ===
[ Pocket Monster ]
Name: Pikachu
HP: 100, ATT: 30, DEF: 25, SPD: 10, EXP: 60
Pichu -> Pikachu -> Raichu
Electric Power: 40
[ Enemy ]
Name: Metapod
HP: 25, ATT: 5, DEF: 10, SPD: 2, EXP: 55
Caterpie -> Metapod -> Butterfree
=== Battle ===
[ Pocket Monster ]
Name: Pikachu
HP: 100, ATT: 30, DEF: 25, SPD: 10, EXP: 105
Pichu -> Pikachu -> Raichu
Electric Power: 40
[ Enemy ]
Name: Metapod
HP: 0, ATT: 5, DEF: 10, SPD: 2, EXP: 60
Caterpie -> Metapod -> Butterfree

[ Print Team A ]
Name: Charmeleon
HP: 80, ATT: 25, DEF: 30, SPD: 8, EXP: 70
Charmander -> Charmeleon -> Charizard
Name: Pikachu
HP: 100, ATT: 30, DEF: 25, SPD: 10, EXP: 105
Pichu -> Pikachu -> Raichu
Electric Power: 40

[ Print Team B ]
Name: Charmeleon
HP: 80, ATT: 25, DEF: 30, SPD: 8, EXP: 50
Charmander -> Charmeleon -> Charizard
Name: Pikachu
HP: 100, ATT: 30, DEF: 25, SPD: 10, EXP: 60
Pichu -> Pikachu -> Raichu
Electric Power: 40
*/