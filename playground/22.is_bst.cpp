#include <iostream>

struct Node {
    int data; 
    Node* left; 
    Node* right; 
};

Node* root = nullptr;

Node* GetNewNode(int data) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 
    temp1 -> left = temp1 -> right = nullptr; 
    return temp1;
}

Node* Insert(Node* root, int data) {
    if (root == nullptr) {
        root = GetNewNode(data);
    }
    else if (data <= root -> data) {
        root -> left = (Insert(root -> left, data));
    }
    else if (data > root -> data) {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

void InOrderTraversal(Node* root) {
    if (root) {
        InOrderTraversal(root-> left);
        std::cout << root -> data << " ";
        InOrderTraversal(root -> right);
    }
}

bool IsBstUtil(Node* root, int minValue, int maxValue) {
    if (root == nullptr) return true; 
    if (root -> data > minValue && root -> data <= maxValue
        && IsBstUtil(root -> left, minValue, root -> data)
        && IsBstUtil(root -> right, root-> data, maxValue)) return true; 
    else return false;
}

bool IsBst(Node* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main() {
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 3);
    root = Insert(root, 6);
    root = Insert(root, 4);
    InOrderTraversal(root);
    std::cout << std::boolalpha << IsBst(root) << std::endl; 
}