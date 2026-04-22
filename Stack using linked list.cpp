#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push Operation
void push() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;
}

// Pop Operation
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek Operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Display Stack
void display() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("\n--- Stack using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
