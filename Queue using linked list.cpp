#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node *front = NULL, *rear = NULL;

void enqueue() {
    node* newnode = new node;
    cout << "Enter data: ";
    cin >> newnode->data;
    newnode->next = NULL;

    if (rear == NULL)
        front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Underflow\n";
    } else {
        node* temp = front;
        cout << "Deleted: " << temp->data << endl;
        front = front->next;
        delete temp;
        if (front == NULL) rear = NULL;
    }
}

void peek() {
    if (front == NULL)
        cout << "Empty\n";
    else
        cout << "Front: " << front->data << endl;
}

void display() {
    node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch;
    while (1) {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}
