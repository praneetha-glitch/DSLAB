#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertEnd(struct Node** head,int value){
    struct Node* newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void reverse(struct Node**head){
    struct Node *prev=NULL,*current=*head,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
void sortList(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node *i, *j;
    int temp;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void concatenate(struct Node** head1,struct Node** head2){
    if(*head1==NULL){
        *head1=*head2;
        return;
    }
    struct Node* temp=*head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=*head2;
}
int main(){
    struct Node *list1=NULL,*list2=NULL;
    int choice,value;
       while (1) {
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Display List1\n");
        printf("4. Display List2\n");
        printf("5. Reverse List1\n");
        printf("6. Sort List1\n");
        printf("7. Concatenate List2 to List1\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
              case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;

            case 3:
                printf("List1: ");
                display(list1);
                break;

            case 4:
                printf("List2: ");
                display(list2);
                break;

            case 5:
                reverse(&list1);
                printf("List1 Reversed.\n");
                break;

            case 6:
                sortList(&list1);
                printf("List1 Sorted.\n");
                break;

            case 7:
                concatenate(&list1, &list2);
                printf("Lists concatenated (List2 → List1).\n");
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}
        
