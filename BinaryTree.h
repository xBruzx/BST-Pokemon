struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

};


class Tree {
    Tree();

    ~Tree();
};

//function to add a new node to the tree with a value that also with two leaf children that have nullptr as the value.
TreeNode* NewTreeNode (int value) {
    TreeNode* node = new TreeNode;

    node->value = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;

}