#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Character{
    private:
        int health;
        int mana;
    protected:
        void setHealth(int health){
            if(health>0 && health<=1000){
                this->health = health;
            }
            else{
                cout<<"Enter a valid health value";
                this->health = 0;
            }
        }
        void setMana(int mana){
            if(mana>0 && mana<=1000){
                this->mana = mana;
            }
            else{
                cout<<"Enter a valid mana value";
                this->mana=0;
            }
        }
    public:
        Character(int health, int mana) {
        setHealth(health);
        setMana(mana);
    }
        virtual void attack() = 0;
        int getHealth(){
            return health;
        }
        int getMana(){
            return mana;
        }
        virtual ~Character() = default;
};


//   Derived Class: Warrior
class Warrior : public Character {
public:
    Warrior(int health, int mana)
        : Character(health, mana) {}

    void attack() override {
        if (getHealth() > 0) {
            cout << "Warrior swings a mighty sword! ⚔️" << endl;
        } else {
            cout << "Warrior is too weak to attack." << endl;
        }
    }
};

/* =========================
   Derived Class: Mage
   ========================= */
class Mage : public Character {
public:
    Mage(int health, int mana)
        : Character(health, mana) {}

    void attack() override {
        if (getMana() > 0) {
            cout << "Mage casts a powerful fireball!" << endl;
        } else {
            cout << "Mage is out of mana!" << endl;
        }
    }
};

/* =========
   Main
   ========= */
int main() {
    vector<Character*> party;

    party.push_back(new Warrior(120, 30));   // health capped at 100
    party.push_back(new Mage(80, 150));      // mana capped at 100
    party.push_back(new Mage(-10, 40));      // health corrected to 0

    cout << "=== Party Attacks ===\n";
    for (Character* c : party) {
        c->attack();   // Polymorphic call
        cout << "Health: " << c->getHealth()
             << ", Mana: " << c->getMana() << "\n\n";
    }

    // Clean up
    for (Character* c : party)
        delete c;

    return 0;
}