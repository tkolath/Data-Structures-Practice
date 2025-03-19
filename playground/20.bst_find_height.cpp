#include <iostream>
#include <algorithm>

struct Node {
    int data; 
    Node* right; 
    Node* left;
};

Node* root = nullptr;

Node* GetNewNode(int data) {
    Node* temp1 = new Node();
    temp1 -> left = temp1 -> right = nullptr; 
    temp1 -> data = data; 
    return temp1; 
}

Node* Insert(Node* root, int data) {
    if (root == nullptr) {
        root = GetNewNode(data);
    }
    else if (data <= root -> data) {
        root -> left= Insert(root -> left, data);
    }
    else if (data > root -> data) {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

void Print(Node* root) {
    if (root) {
        Print(root -> left);
        std::cout << root -> data << " ";
        Print(root -> right);
    }
}

// int FindHeight(Node* root) {
//     if (root == nullptr) {
//         return -1;         
//     }
//     return std::max(FindHeight(root -> left), FindHeight(root -> right)) + 1;
// }


int FindHeight(Node* root) {
    if(root == nullptr) {
        return -1; 
    }
    return std::max(FindHeight(root-> left), FindHeight(root -> right)) +1;
}

int main() {
    root = Insert(root, 1);
    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 8);
    Print(root);
    std::cout << std::endl; 
    std::cout << "Max Height: " << FindHeight(root) << "\n";
     


}