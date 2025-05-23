#include "Team.h"
#include <typeinfo>

// Copy constructor which performs deep copy
// Note:
// - Two different types of objects will be pointed by the array of pointers
// - Dynamically create PocketMonster object when the object to be copied
// is in PocketMonster type
// - Dynamically create ElectricPocketMonster object when the object to be
// copied is in ElectricPocketMonster type
// Hint:
// - Use typeid(<expression>) to identify the type of the object
Team::Team(const Team &t)
    :
    members{ new PocketMonster* [t.numMembers] { } },
    numMembers{ t.numMembers }
{
    for (int i = 0; i < this->numMembers; i++)
    {
        if (typeid(*t.members[i]) == typeid(ElectricPocketMonster))
            this->members[i] = new ElectricPocketMonster { *dynamic_cast<ElectricPocketMonster*>(t.members[i]) };
        else
            this->members[i] = new PocketMonster { *t.members[i] };
    }
    return;
}

Team::~Team()
{
    for (int i = 0; i < this->numMembers; i++)
        delete this->members[i];
    delete [] this->members;
    return;
}

// Add the address of pocket monster / electric pocket monster to the pointer array
// As the size of the original pointer array is fixed once it is created, you need
// to do the following in order to store the pointer to a new pocket monster /
// electric pocket monster
// - Allocate a new array of size = original size of the array + 1
// - Copy all the pointers in the original array to the new array
// - Insert the pointer to the new pocket monster / electric pocket monster to
// the end of the new array
// - Make "members" point at the new array
// - Make sure there is NO memory leak problem after performing all the
// above operations
void Team::addMember(PocketMonster *pm)
{
    PocketMonster** new_arr = new PocketMonster* [this->numMembers + 1] { };
    for (int i = 0; i < this->numMembers; i++)
        new_arr[i] = this->members[i];
    delete [] this->members;
    this->members = new_arr;
    this->members[this->numMembers++] = pm;
    return;
}

void Team::print() const
{
    for (int i = 0; i < this->numMembers; i++)
        this->members[i]->print();
    return;
}