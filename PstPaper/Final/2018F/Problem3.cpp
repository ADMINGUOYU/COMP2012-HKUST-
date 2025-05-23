#include <iostream>
#include <typeinfo>

using namespace std;
class Weapon
{
};
class Sword : public Weapon
{
public:
    Sword(int n = 1) { cout << n << " x S" << endl; }
    ~Sword() { cout << "~S" << endl; }
};
class Hero
{
    Weapon *w;

public:
    Hero()
    {
        cout << "H" << endl;
        w = new Weapon;
    }
    ~Hero()
    {
        cout << "~H" << endl;
        delete w;
    }
    virtual const Hero &operator=(const Hero &h) { cout << "H=" << endl; return (*this); }
};
class SpiderMan : public Hero
{
    Weapon *w;

public:
    SpiderMan()
    {
        cout << "SM" << endl;
        w = new Weapon;
    }
    SpiderMan(const SpiderMan &s)
    {
        cout << "Copy SM" << endl;
        w = new Weapon;
    }
    virtual ~SpiderMan()
    {
        cout << "~SM" << endl;
        delete w;
    }
    const SpiderMan &operator=(const SpiderMan &s) { cout << "SM=" << endl; return (*this); }
};
class DeadPool : public SpiderMan
{
    Sword sword;

public:
    DeadPool() : sword(2) { cout << "DP" << endl; }
    DeadPool(const DeadPool &d) : SpiderMan(d) { cout << "Copy DP" << endl; }
    ~DeadPool() { cout << "~DP" << endl; }
    const DeadPool &operator=(const DeadPool &d) override { cout << "DP=" << endl; return (*this); }
};

int main()
{
    cout << "--- Block 1 ---" << endl;
    Hero *hero = new DeadPool;
    cout << "--- Block 2 ---" << endl;
    SpiderMan *spiderman = new DeadPool;
    cout << "--- Block 3 ---" << endl;
    DeadPool deadpool(*dynamic_cast<DeadPool *>(spiderman));
    cout << "--- Block 4 ---" << endl;
    std::cout << typeid(*hero).name() << std::endl; // 8DeadPool
    *hero = *spiderman;
    cout << "--- Block 5 ---" << endl;
    delete hero;
    cout << "--- Block 6 ---" << endl;
    delete spiderman;
}

/*
compile command: g++ -fsanitize=address,undefined,leak -fno-elide-constructors Problem3.cpp

output:
--- Block 1 ---
H
SM
2 x S
DP
--- Block 2 ---
H
SM
2 x S
DP
--- Block 3 ---
H
Copy SM
1 x S
Copy DP
--- Block 4 ---
H=                          <- WHY? 
                                const DeadPool &operator=(const DeadPool &d) override { cout << "DP=" << endl; return (*this); }
                                ERROR -> member function declared with 'override' does not override a base class memberC/C++(1455)
                                Change to ->
                                const Hero &operator=(const Hero &d) override { cout << "DP=" << endl; return (*this); }
                                Signature has to be the same
--- Block 5 ---
~H
=================================================================
==69823==ERROR: AddressSanitizer: new-delete-type-mismatch on 0x603000000010 in thread T0:
  object passed to delete has wrong type:
  size of the allocated type:   32 bytes;
  size of the deallocated type: 16 bytes.
    #0 0x76cd4ff3ac65 in operator delete(void*, unsigned long) ../../../../src/libsanitizer/asan/asan_new_delete.cc:177
    #1 0x652e6f3b2e0d in main (/workspaces/COMP2012-HKUST-/PstPaper/Final/2018F/a.out+0x7e0d)
    #2 0x76cd4efa3082 in __libc_start_main ../csu/libc-start.c:308
    #3 0x652e6f3b234d in _start (/workspaces/COMP2012-HKUST-/PstPaper/Final/2018F/a.out+0x734d)

0x603000000010 is located 0 bytes inside of 32-byte region [0x603000000010,0x603000000030)
allocated by thread T0 here:
    #0 0x76cd4ff39587 in operator new(unsigned long) ../../../../src/libsanitizer/asan/asan_new_delete.cc:104
    #1 0x652e6f3b25c0 in main (/workspaces/COMP2012-HKUST-/PstPaper/Final/2018F/a.out+0x75c0)
    #2 0x76cd4efa3082 in __libc_start_main ../csu/libc-start.c:308

SUMMARY: AddressSanitizer: new-delete-type-mismatch ../../../../src/libsanitizer/asan/asan_new_delete.cc:177 in operator delete(void*, unsigned long)
==69823==HINT: if you don't care about these errors you may set ASAN_OPTIONS=new_delete_type_mismatch=0
==69823==ABORTING
*/