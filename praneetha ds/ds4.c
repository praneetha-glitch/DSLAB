#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void createList(int n);
void insertAtBeginning(int data);
void insertAtPosition(int data, int position);
void insertAtEnd(int data);
void display();

int main() {
    int choice, data, n, position;

    do {
        printf("\n1. Create List");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at Position");
        printf("\n4. Insert at End");
        printf("\n5. Display List");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes to create: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position (starting from 1): ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
void createList(int n) {
    if (n <= 0) {
        printf("List size must be greater than 0.\n");
        return;
    }

    struct Node *newNode, *temp;
    head = NULL;
    int i, data;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("List of %d nodes created successfully.\n", n);
}



void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at the beginning.\n");

}


void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    struct Node *temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of list range.\n", position);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);

}
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
