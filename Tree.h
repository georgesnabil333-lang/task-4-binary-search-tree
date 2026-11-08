#pragma once
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() { root = nullptr; }

    ~Tree() { destroy(root); }                  // free all nodes

    Node* insert(Node* n, int v) {
        if (n == nullptr) return new Node(v);
        if (v < n->data)      n->left  = insert(n->left, v);
        else if (v > n->data) n->right = insert(n->right, v);
        return n;                               // duplicates are ignored
    }

    bool search(Node* n, int v) {
        if (n == nullptr) return false;
        if (v == n->data) return true;
        if (v < n->data) return search(n->left, v);
        return search(n->right, v);
    }

    Node* findMin(Node* n) {
        while (n != nullptr && n->left != nullptr) n = n->left;
        return n;
    }

    Node* deleteNode(Node* n, int v) {
        if (n == nullptr) return nullptr;       // value not found
        if (v < n->data) {
            n->left = deleteNode(n->left, v);
        } else if (v > n->data) {
            n->right = deleteNode(n->right, v);
        } else {
            if (n->left == nullptr) {           // leaf or only right child
                Node* temp = n->right;
                delete n;
                return temp;
            }
            if (n->right == nullptr) {          // only left child
                Node* temp = n->left;
                delete n;
                return temp;
            }
            Node* successor = findMin(n->right); // two children
            n->data = successor->data;
            n->right = deleteNode(n->right, successor->data);
        }
        return n;
    }

    void inOrder(Node* n) {
        if (n == nullptr) return;
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

    void preOrder(Node* n) {
        if (n == nullptr) return;
        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }

    int height(Node* n) {                       // empty tree = -1, leaf = 0
        if (n == nullptr) return -1;
        return 1 + max(height(n->left), height(n->right));
    }

    void levelOrder() {
        if (root == nullptr) { cout << endl; return; }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }

    // Extra credit: sideways ASCII tree (root on the left, right subtree on top)
    void printTree(Node* n, int depth = 0) {
        if (n == nullptr) return;
        printTree(n->right, depth + 1);
        cout << string(depth * 4, ' ') << n->data << endl;
        printTree(n->left, depth + 1);
    }

private:
    void destroy(Node* n) {
        if (n == nullptr) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
};
