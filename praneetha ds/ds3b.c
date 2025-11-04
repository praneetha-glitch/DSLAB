#include <stdio.h>
#define size 6

int queue[size];
int front = -1;
int rear = -1;

void enqueue() {
    int item;
    if ((rear+1)%size==front) {
        printf("Overflow condition\n");
    } else {
        printf("Enter value to be inserted: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear=(rear+1)%size;
        queue[rear] = item;
    }
}

void dequeue() {
    if (front == -1 ) {
        printf("Underflow condition\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front=(front+1)%size;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}


int main() {
    int choice;
    while (1) {
        printf("1. Insert 2. Delete 3. Display 4. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}





