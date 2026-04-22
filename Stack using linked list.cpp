#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* top = NULL;

void push() {
    node* newnode = new node;
    cout << "Enter data: ";
    cin >> newnode->data;

    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        cout << "Underflow\n";
    } else {
        node* temp = top;
        cout << "Deleted: " << temp->data << endl;
        top = top->next;
        delete temp;
    }
}

void peek() {
    if (top == NULL)
        cout << "Empty\n";
    else
        cout << "Top: " << top->data << endl;
}

void display() {
    node* temp = top;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int ch;
    while (1) {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}
