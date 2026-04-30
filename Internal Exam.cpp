#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insert(Node* root, int val) {
    if (root == NULL) 
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << "\nLevel Order Traversal: ";
    levelOrder(root);

    cout << endl;

    return 0;
}
