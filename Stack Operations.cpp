#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Function to check stack is full
int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

// Function to check stack is empty
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Push operation
void push(int value) {
    if (isFull()) {
        printf("Stack is FULL! Cannot Push.\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack is EMPTY! Cannot Pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Peep operation (Top element)
void peep() {
    if (isEmpty()) {
        printf("Stack is EMPTY! No top element.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main menu driven program
int main() {
    int choice, value;

    while (1) {
        printf("\n====== STACK MENU ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep (Top Element)\n");
        printf("4. Display\n");
        printf("5. isEmpty\n");
        printf("6. isFull\n");
        printf("7. Exit\n");
        printf("========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                display();
                break;

            case 5:
                if (isEmpty())
                    printf("Stack is EMPTY.\n");
                else
                    printf("Stack is NOT empty.\n");
                break;

            case 6:
                if (isFull())
                    printf("Stack is FULL.\n");
                else
                    printf("Stack is NOT full.\n");
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
