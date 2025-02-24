#include <iostream>

struct BstNode {
    int data; 
    BstNode* left; 
    BstNode* right; 
};

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = newNode -> right = nullptr; 
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
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

bool Search(BstNode* root, int data) {
    if (root == nullptr) {
        return false;
    }
    else if (root -> data == data) {
        return true; 
    }
    else if (data <= root -> data) {
        return Search(root-> left, data);
    }
    else {
        return Search(root -> right, data);
    }
}

int main() {
    BstNode* root = nullptr; 
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

    int number;
    std::cout << "Enter number to be searched\n";
    std::cin >> number; 
    if (Search(root, number) == true) std::cout << "Found\n";
    else std::cout << "Not Found\n";
}