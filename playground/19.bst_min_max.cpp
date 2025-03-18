#include <iostream>

struct Node {
    int data; 
    Node* left;
    Node* right;
};

//Find Min Iteratively
int FindMin(Node* root) {
    if (root == nullptr) {
        std::cout << "Error: Tree is empty\n";
        return -1; 
    }
    while(root -> left != nullptr) {
        root = root -> left;
    }
    return root -> data; 
}

//Find Min Recursively
int FindMinRecursively(Node* root) {
    if (root == nullptr) {
        std::cout << "Error: Tree is empty\n";
        return -1; 
    }
    else if (root -> left == nullptr) {
        return root->data; 
    }
    return FindMinRecursively(root->left);
}

//Find Max Iteratively
int FindMax(Node* root) {
    if (root == nullptr) {
        std::cout << "Error: Tree is empty\n" << std::endl; 
        return -1;
    }
    while(root -> right != nullptr) {
        root = root -> right; 
    }
    return root -> data; 
}

//Find Max Recursively
int FindMaxRecursively(Node* root){
    if (root == nullptr) {
        std::cout << "Error: Tree is empty\n";
        return -1; 
    }
    else if (root -> right == nullptr) {
        return root -> data; 
    }
    return FindMaxRecursively(root->right);
}

Node* GetNewNode(int data) {
    Node* temp1 = new Node(); 
    temp1 -> left = temp1 -> right = nullptr ;
    temp1 -> data = data; 
    return temp1; 
}

Node* Insert(Node* root, int data) {
    if (root == nullptr) {
        root = GetNewNode(data);
    }
    else if (data <= root -> data) {
        root -> left = Insert(root-> left, data);
    }
    else if (data > root -> data) {
        root -> right = Insert(root->right, data);
    }
    return root;
}

Node* root = nullptr; 

void Print(Node* root) {
    if (root) {
        Print(root -> left);
        std::cout << root -> data << " ";
        Print(root -> right);
    }
}

int main() {
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 8);
    std::cout << "Current List: ";
    Print(root); std::cout << "\n";
    std::cout << "Iterative Min: ";
    std::cout << FindMin(root) << std::endl;
    std::cout << "Recursive Min: ";
    std::cout << FindMinRecursively(root) << std::endl; 
    std::cout << "Iterative Max: ";
    std::cout << FindMax(root) << std::endl;
    std::cout << "Recursive Max: ";
    std::cout << FindMaxRecursively(root) << std::endl;    
}
