#include <iostream>

struct Node {
    int data; 
    Node* left; 
    Node* right; 
};

Node* GetNewNode(int data) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 
    temp1 -> left = temp1 -> right = nullptr; 
    return temp1;
}

Node* Insert(Node* root, int data) {
    if(root == nullptr) {
        root = GetNewNode(data);
    }
    else if (data <= root -> data) {
        root -> left = Insert(root -> left, data);
    }
    else if (data > root -> data) {
        root -> right = Insert(root -> right, data);
    }
    return root; 
}

void print(Node* root) {
    if (root) {
        print(root -> left);
        std::cout << root -> data << " ";
        print(root -> right);
    }
}

int main() {
    Node* root = nullptr; 
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 8);
    print(root);
}