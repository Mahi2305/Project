#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
    TreeNode* root;
    
    BST() : root(NULL) {}

    TreeNode* insert(TreeNode* node, int key) {
        if (node == NULL) return new TreeNode(key);
        if (key < node->val) {
            node->left = insert(node->left, key);
        } else if (key > node->val) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (node == NULL || node->val == key) return node;
        if (key < node->val) return search(node->left, key);
        return search(node->right, key);
    }

    void visualize(TreeNode* node, int space = 0, int height = 10) {
        if (node == NULL) return;
        space += height;
        visualize(node->right, space);
        cout << endl;
        for (int i = height; i < space; i++) cout << " ";
        cout << node->val << "\n";
        visualize(node->left, space);
    }
};

int main() {
    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Visualizing BST:" << endl;
    tree.visualize(tree.root);
    cout << endl;

    int searchKey = 40;
    cout << "Searching for " << searchKey << ": " << (tree.search(tree.root, searchKey) != NULL ? "Found" : "Not Found") << endl;

    return 0;
}

