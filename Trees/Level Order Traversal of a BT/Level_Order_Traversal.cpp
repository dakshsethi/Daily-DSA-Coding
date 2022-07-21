#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
};

void printCurrentLevel(struct TreeNode* root, int level) {
    if(root == NULL) return ;
    if(level == 1)
        cout<<root->data<<" ";
    else {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void levelOrder(struct TreeNode* root) {
    int height = 3;
    for(int i=1; i<=height; i++)
        printCurrentLevel(root, i);
}


int main() {
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout<<"Level Order Traversal of Tree: ";
    levelOrder(root);
    return 0;
}