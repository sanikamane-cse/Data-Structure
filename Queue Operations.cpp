#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int q[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
        } 
        else {
            if (front == -1)
                front = 0;

            rear++;
            q[rear] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
        } 
        else {
            cout << "Deleted: " << q[front] << endl;
            front++;

            if (front > rear) {
                front = rear = -1;
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
        } 
        else {
            cout << "Queue elements are:\n";
            for (int i = front; i <= rear; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
