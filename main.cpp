#include <iostream> // Include the iostream library for input and output operations

// Define the structure for a node in the binary tree
struct Node {
    int data; // Data stored in the node
    Node *left; // Pointer to the left child node
    Node *right; // Pointer to the right child node

    // Constructor to initialize a node with given data
    Node(int value) {
        data = value; // Set the node's data
        left = right = nullptr; // Initialize child pointers to NULL (nullptr in modern C++)
    }
};

// Function for Preorder Traversal of the binary tree
void preOrderTraversal(Node* node) {
    if (node == nullptr) { // Base case: if the node is NULL, return
        return;
    }
    std::cout << node->data << " "; // Print the data of the current node
    preOrderTraversal(node->left); // Recursively traverse the left subtree
    preOrderTraversal(node->right); // Recursively traverse the right subtree
}

// Function for Inorder Traversal of the binary tree
void inOrderTraversal(Node* node) {
    if (node == nullptr) { // Base case: if the node is NULL, return
        return;
    }
    inOrderTraversal(node->left); // Recursively traverse the left subtree
    std::cout << node->data << " "; // Print the data of the current node
    inOrderTraversal(node->right); // Recursively traverse the right subtree
}

// Function for Postorder Traversal of the binary tree
void postOrderTraversal(Node* node) {
    if (node == nullptr) { // Base case: if the node is NULL, return
        return;
    }
    postOrderTraversal(node->left); // Recursively traverse the left subtree
    postOrderTraversal(node->right); // Recursively traverse the right subtree
    std::cout << node->data << " "; // Print the data of the current node
}

int main() {
    // Create the root node and initialize its children
    Node* root = new Node(1); // Create the root node with data 1
    root->left = new Node(2); // Create left child of root with data 2
    root->right = new Node(3); // Create right child of root with data 3
    root->left->left = new Node(4); // Create left child of node 2 with data 4
    root->left->right = new Node(5); // Create right child of node 2 with data 5
    root->right->left = new Node(6); // Create left child of node 3 with data 6
    root->right->right = new Node(7); // Create right child of node 3 with data 7

    std::cout << "Preorder Traversal: ";
    preOrderTraversal(root); // Output: 1 2 4 5 3 6 7 
    std::cout << std::endl;

    std::cout << "Inorder Traversal: ";
    inOrderTraversal(root); // Output: 4 2 5 1 6 3 7
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postOrderTraversal(root); // Output: 4 5 2 6 7 3 1
    std::cout << std::endl;

    // Cleanup memory (optional but recommended)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0; // Return 0 to indicate successful program execution
}
/*
  Explanation
Structure Definition (Node):

Node represents a single node in the binary tree. It has:

data: An integer value stored in the node.
left and right: Pointers to the left and right child nodes.
Constructor (Node(int value)):

Initializes the data with the provided value.
Sets both child pointers (left and right) to nullptr.
Traversal Functions:

Preorder Traversal (preOrderTraversal):
Visit the root node first.
Recursively traverse the left subtree.
Recursively traverse the right subtree.
Prints nodes in the order: Root -> Left Subtree -> Right Subtree.
Inorder Traversal (inOrderTraversal):
Recursively traverse the left subtree.
Visit the root node.
Recursively traverse the right subtree.
Prints nodes in the order: Left Subtree -> Root -> Right Subtree.
Postorder Traversal (postOrderTraversal):
Recursively traverse the left subtree.
Recursively traverse the right subtree.
Visit the root node.
Prints nodes in the order: Left Subtree -> Right Subtree -> Root.
Main Function:

Creates a binary tree with the following structure:
markdown
Copy code
    1
   / \
  2   3
 / \ / \
4  5 6  7
Calls each traversal function to display the order in which nodes are visited.
Memory Cleanup: Deletes dynamically allocated nodes to prevent memory leaks (important in real applications).
Summary
This code demonstrates how to create a simple binary tree and perform different types of depth-first traversals. 
It helps you understand how nodes are linked and visited in different orders.
*/
