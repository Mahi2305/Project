#include <iostream>
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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    void inorder(TreeNode* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void preorder(TreeNode* node) {
        if (node == NULL) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

private:
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) current = current->left;
        return current;
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

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}

