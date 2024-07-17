# Project
Sure! Here's a brief theoretical overview of the provided code:

### Overview:
1. **TreeNode Struct**:
   - Represents each node in the BST with `val`, `left`, and `right` attributes.

2. **BST Class**:
   - Manages the Binary Search Tree.
   - **insert(TreeNode* node, int key)**:
     - Recursively inserts a new node with the given key.
   - **search(TreeNode* node, int key)**:
     - Recursively searches for a node with the given key.
   - **visualize(TreeNode* node, int space, int height)**:
     - Recursively prints the tree structure as ASCII art, using spacing to represent tree levels.

3. **Main Function**:
   - Demonstrates inserting nodes into the BST.
   - Visualizes the BST structure in the console.
   - Performs a search operation and prints the result.

### Key Points:
- The tree is built recursively by comparing keys.
- The visualization function prints the tree sideways, with the root at the left and leaves to the right.
- This approach is simple and console-based, providing a textual representation of the BST structure.
