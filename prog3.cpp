#include "Pokemon.h"
#include "BinaryTree.h"

/*
Author: Alec Szczechowicz
Program Name: Program 3 Pokedex BST
Date: 11/21/2024
Description: This program reads in a text file and then adds it to a BST. For every pokemon added is a new tree node and is sorted by its ID.
*/

int main() {
    //Variables that create a new Pokemon and Tree object.
    Pokemon pokemon;
    Tree<Pokemon> pokemonTree;
    fstream file("pokemon.txt");
    int id, counter = 0; 
    string name, line;

    //if the file cannot be opened then show an error message and return 1. Else read through the file and set the id and names, and add them to the tree.
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }else {
        //While loop that reads through the file and sets the id and names.
        while (getline(file, line, ',')) {
            id = stoi(line);
            pokemon.setID(id);
            getline(file, name, ',');
            pokemon.setName(name);
            pokemonTree.insertNode(pokemon);
            cout << "instering Pokemon with index " << id << " to the Pokedex." << endl;
            counter++;
        }

        cout << counter << " pokemon have been added to the Pokedex!" << "\n" << endl;
        
        pokemonTree.displayTreeInOrder();

    }


    return 0;

}