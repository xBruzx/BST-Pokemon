#include "BinaryTree.h"

class Pokemon {
    private:
    int id;
    string name;

    public:
    //Constructor setters and getters.
    Pokemon() {
        setID(id);
    }
    int setID(int id) {
        this->id = id;
        return this->id;
    }

    string setName(string name) {
        this->name = name;
        return this->name;
    }

    int getID(int id) {
        return this->id;
    }

    string getName(string name) {
        return this->name;
    }

    //overloaded operatiors.
    bool operator==(const Pokemon& pokemon) const {
            return this->id == pokemon.id;
        }

    bool operator<(const Pokemon& pokemon) const {
        return this->id < pokemon.id;
    }

    friend ostream& operator<<(ostream& os, const Pokemon& pokemon) {
        os << "Pokemon Index Number: " << pokemon.id << "\t Name: " << pokemon.name;
        return os;
    }

};