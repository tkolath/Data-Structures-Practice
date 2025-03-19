#include <iostream>
#include <queue>

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
    else if (data > root -> data) {
        root -> right = Insert(root -> right, data);
    }
    return root; 
}

void LevelOrder(Node* root) {
    if(root == nullptr) {
        return; 
    }
    std::queue <Node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        Node* current = Q.front(); 
        std::cout << current -> data << " ";
        if (current -> left != nullptr) Q.push(current -> left);
        if (current -> right != nullptr) Q.push(current->right);
        Q.pop(); 
    }
}

void PreOrder(Node* root) {
    if(root) {
        std::cout << root -> data << " ";
        PreOrder(root -> left);
        PreOrder(root -> right);
    }
}

void InOrder(Node* root) {
    if(root) {
        InOrder(root -> left);
        std::cout << root -> data << " "; 
        InOrder(root -> right);
    }
}

void PostOrder(Node* root) {
    if (root) {
        PostOrder(root -> left);
        PostOrder(root -> right);
        std::cout << root -> data << " ";
    }
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
    root = Insert(root, 4); std::cout << std::endl; 
    std::cout << "InOrder: ";
    InOrder(root);
    std::cout << "\nPreOrder: ";
    PreOrder(root);
    std::cout << "\nPostOrder: ";
    PostOrder(root);
}