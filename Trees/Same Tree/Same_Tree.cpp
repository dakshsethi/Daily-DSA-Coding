#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    TreeNode(): data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): data(x), left(nullptr), right(nullptr) {}
};

bool isSameTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if(root1 == NULL || root2 == NULL) return root1 == root2;

    return ((root1->data == root2->data) && isSameTrees(root1->left, root2->left) && isSameTrees(root1->right, root2->right));
}

int main() {
    struct TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(4);

    struct TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);

    cout<<"Are the 2 trees same? ";
    if(isSameTrees(root1, root2))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}