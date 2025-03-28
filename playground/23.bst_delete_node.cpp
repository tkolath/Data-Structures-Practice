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
        root -> left = Insert(root -> left, data);
    }
    else {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

void InOrder(Node* root) {
    if (root) {
        InOrder(root -> left);
        std::cout << root -> data << " ";
        InOrder(root -> right);
    }
}

Node* FindMin(Node* root) {
    if (root == nullptr) {
        std::cout << "Error: Tree is empty\n";
        return nullptr; 
    }
    while(root -> left != nullptr) {
        root = root -> left;
    }
    return root; 
}

Node* Delete(Node* root, int data) {
    if (root == nullptr) return root; 
    else if (data < root -> data) root -> left = Delete(root -> left, data);
    else if (data > root -> data) root -> right = Delete(root -> right, data);
    else {
        //case 1: no child
        if (root -> left == nullptr && root -> right == nullptr) {
            delete root;
            root = nullptr; 
        }
        //case 2: one child
        else if (root -> left == nullptr) {
            Node* temp1 = root; 
            root = root -> right; 
            delete temp1;
            temp1 = nullptr; 
        }
        else if(root -> right == nullptr) {
            Node* temp1 = root;
            root = root -> left; 
            delete temp1;
            temp1 = nullptr; 
        }
        //case 3: two children
        else {
            Node* temp1 = FindMin(root->right);
            root -> data = temp1 -> data;
            root -> right = Delete(root -> right, temp1 -> data);
        }
    }
    return root; 
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
    InOrder(root);
    Delete(root, 4);
    std::cout << "\n";
    InOrder(root);
}