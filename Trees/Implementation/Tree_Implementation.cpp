#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree() {
    struct TreeNode* new_node = NULL;
    int data;
    cout<<"Enter Data for Node: ";
    cin>>data;

    if(data == -1) return NULL;

    new_node = new TreeNode(data);
    
    cout<<"Enter Left Node Value for "<<data<<": ";
    new_node->left = createTree();

    cout<<"Enter Right Node Value for "<<data<<": ";
    new_node->right = createTree();

    return new_node;
}

int main() {
    createTree();
    return 0;
}