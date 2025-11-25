#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node *head;

void insetatstart(int ele);
void deletebyvalue(int value);
void display();

int main() {
    head = NULL;
    int choice, k = 1, ele, val;

    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");

    while (k) {
        printf("enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter ele:");
                scanf("%d", &ele);
                insetatstart(ele);
                break;

            case 2:
                printf("enter val:");
                scanf("%d", &val);
                deletebyvalue(val);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("exit\n");
                k = 0;
                break;
        }
    }
}

void insetatstart(int ele) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void deletebyvalue(int val) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (temp->prev == NULL && temp->next == NULL) {
        head = NULL;
    } else if (temp->prev == NULL) {
        head = temp->next;
        head->prev = NULL;
    } else if (temp->next == NULL) {
        temp->prev->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted.\n");
}

void display() {
    if (head == NULL) {
        printf("list is empty\n");
    } else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}
