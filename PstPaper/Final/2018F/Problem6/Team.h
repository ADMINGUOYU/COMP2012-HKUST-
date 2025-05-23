#ifndef TEAM_H /* File: Team.h */
#define TEAM_H
#include "ElectricPocketMonster.h"
class Team
{
private:
    // A pointer which points to an array of pointers in PocketMonster type
    PocketMonster **members;
    // The size of the pointer array
    int numMembers;

public:
    // Default constructor
    // Construct a team by initializing members to NULL and numMembers to 0
    Team() : members(NULL), numMembers(0) {}
    /* ----- Functions to implement ----- */
    // Copy constructor which performs deep copy
    // Note:
    // - Two different types of objects will be pointed by the array of pointers
    // - Dynamically create PocketMonster object when the object to be copied
    // is in PocketMonster type
    // - Dynamically create ElectricPocketMonster object when the object to be
    // copied is in ElectricPocketMonster type
    // Hint:
    // - Use typeid(<expression>) to identify the type of the object
    Team(const Team &t);
    // Destructor which deallocates all the dynamically-allocated memory
    ~Team();
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
    void addMember(PocketMonster *pm);
    // Print team information on screen according to the sample output
    void print() const;
};
#endif /* TEAM_H */