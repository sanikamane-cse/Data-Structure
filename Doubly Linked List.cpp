#include <iostream>
using namespace std;

struct node {
    int data;
    node *prev, *next;
};

node* head = NULL;

// Insert at Beginning
void insert_begin() {
    node* n = new node;
    cout << "Enter data: ";
    cin >> n->data;

    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

// Insert at End
void insert_end() {
    node* n = new node;
    cout << "Enter data: ";
    cin >> n->data;

    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
    } else {
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }
}

// Insert at Position
void insert_pos() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    node* n = new node;
    cout << "Enter data: ";
    cin >> n->data;

    if (pos == 1) {
        n->prev = NULL;
        n->next = head;
        if (head != NULL)
            head->prev = n;
        head = n;
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

// Delete from Beginning
void delete_begin() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    node* temp = head;
    cout << "Deleted: " << temp->data << endl;

    head = head->next;
    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete from End
void delete_end() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "Deleted: " << temp->data << endl;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    delete temp;
}

// Delete from Position
void delete_pos() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    if (pos == 1) {
        delete_begin();
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    cout << "Deleted: " << temp->data << endl;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

// Display Forward
void display_forward() {
    node* temp = head;
    if (temp == NULL) {
        cout << "List empty\n";
        return;
    }

    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display Backward
void display_backward() {
    node* temp = head;

    if (temp == NULL) {
        cout << "List empty\n";
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Main Function
int main() {
    int choice;

    while (1) {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1.Insert Begin\n2.Insert End\n3.Insert Position\n";
        cout << "4.Delete Begin\n5.Delete End\n6.Delete Position\n";
        cout << "7.Display Forward\n8.Display Backward\n9.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: display_forward(); break;
            case 8: display_backward(); break;
            case 9: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
