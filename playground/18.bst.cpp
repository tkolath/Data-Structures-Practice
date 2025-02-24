#include <iostream>

struct BstNode {
    int data;
    BstNode* left; 
    BstNode* right;
};

BstNode* root = nullptr;

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data; 
    newNode -> left = nullptr; 
    newNode -> right = nullptr;
    return newNode;
}

void Insert(int data) {
    if (root == nullptr) {
        root = GetNewNode(data);
        return;
    }

};

int main() {
    Insert(15);
    Insert(10);
    Insert(20);
}