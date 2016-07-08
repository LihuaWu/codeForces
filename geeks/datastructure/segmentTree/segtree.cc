#include <iostream>

using namespace std;

struct Node {
    int  left, right;
    Node *leftchild;
    Node * rightchild;
    int cover;
};

Node * build(int l, int r) {
    Node * root = new Node;
    root->left = l;
    root->right = r;
    root->cover = 0;
    root->leftchild = NULL;
    root->rightchild = NULL;

    if (l + 1 < r) {
        int mid = l+(r-l)/2;
        root->leftchild = build(l, mid);
        root->rightchild = build(mid, r);
    }
    return root;
}


void Insert(Node* root, int a, int b) {
    int m;
    if (root->cover == 0) {
        m = root->left + (root->right - root->left) / 2;
        if (a == root->left && b == root->right) {
            root->cover = 1;
        }
        else if (b <= m) Insert(root->leftchild, a, b);
        else if (a >= m) Insert(root->rightchild, a, b);
        else {
            Insert(root->leftchild, a, m);
            Insert(root->rightchild, m, b);
        }
    }
}

int Count(Node* root) {
    int m, n;
    if (root->cover == 1) {
        return root->right - root->left;
    } else if (root->right - root->left == 1) return 0;
    m = Count(root->leftchild);
    n = Count(root->rightchild);
    return m + n;
}

int main() {
    Node* root = build(10000, 60000);
    Insert(root, 10000, 22000);
    Insert(root, 30300, 55000);
    Insert(root, 44000, 60000);
    Insert(root, 55000, 60000);
    cout << Count(root) << "\n";

    return 0 ;
}
