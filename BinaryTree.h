#ifndef BINARYTREE_H 
#define BINARYTREE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



template<typename T>
class Tree {
    private:
    struct TreeNode {
        T value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }

    };
    

    TreeNode* insert(TreeNode* node, T value) {
        //if node is equal to nodeptr then we make a new tree node.
        if (node == nullptr) {
            return new TreeNode(value);
        }
        //if value is less than node's value, go to the left.
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        //if value is greater than node's value, go to the right.
        else {
            node->right = insert(node->right, value);
        }
        
        return node;
    }

    void destroySubtree(TreeNode* node) {
        //If node does not equal nodeptr then we want to go left to right and delete the node.
        if (node != nullptr) {
            destroySubtree(node->left); //Traverse left.
            destroySubtree(node->right); //Traverse right.
            delete node;
        }
    }

    void displayInOrder(TreeNode* node) {
        //base case to stop the recursion
        if (node == nullptr) {
            return;
        }
        displayInOrder(node->left); //Traverse left
        cout << node->value << endl; //Display current node's value
        displayInOrder(node->right); //Traverse right

    }

    public:
    TreeNode* root;
    Tree() {
        //Constructor will set root to nullptr.
        root = nullptr;
    };
    //call destroySubtree recursively starting at the root.
    ~Tree() {
        destroySubtree(root);
    };

    //Inserts a node at the start of the tree
    void insertNode(T value) {
        root = insert(root, value);
    }

    void displayTreeInOrder() {
        //Call displayInOrder proviate function to start at the root node and recusively call until node points to nullptr.
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
        }
        else {
            cout << "**********Pokemon**********" << endl;
            displayInOrder(root);
        }

    }

    bool searchNode(TreeNode* node, int value) {
        bool found = false;
        
        //If node value is equal to value then return true
        if (node->value == value) {
            found = true;
        }
        //If the value is less than the node we search left.
        else if (value < node->value) {
            searchNode(node->left, value);
        }
        //Else we go right.
        else {
            searchNode(node->right, value);
        }

        return found;

    }
};

#endif