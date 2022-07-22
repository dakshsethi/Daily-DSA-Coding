#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
};

void inOrder(struct TreeNode* root) {
    if(root ==  NULL) return ;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(struct TreeNode* root) {
    if(root ==  NULL) return ;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode* root) {
    if(root ==  NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int heightOfTree(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

int main() {
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout<<"InOrder Traversal of Tree: ";
    inOrder(root);

    cout<<"\nPreOrder Traversal of Tree: ";
    preOrder(root);

    cout<<"\nPostOrder Traversal of Tree: ";
    postOrder(root);

    cout<<"\nHeight of Tree: "<<heightOfTree(root);
    return 0;
}