#include<stdio.h>
#include<stdlib.h>

//Creation of structure node
struct node {
    int data;
    struct node* next;
};

//Function for creating a linked list
void Creation(struct node* head, int size) {
    struct node* temp = head;
    for(int i = 1; i <= size; i++) {
        struct node* curr;
        curr  = (struct node*)malloc(sizeof(struct node));
        curr->data = i;
        curr->next =  NULL;
        temp->next = curr;
        temp = temp->next;
    }
}
//Function for traversal and display of the linked list
void Display(struct node* ptr) {
    if(ptr->next == NULL) {
        printf("Empty List");
    }

    else {
        ptr = ptr->next;
        while(ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void Length(struct node* ptr) {
    int len = 0;
    while(ptr->next != NULL) {
        len++;
        ptr = ptr->next;
    }
    printf("The length of the list is %d\n", len);
}

int main() {
    //Creating head node
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 101;
    head->next = NULL;
    
    Creation(head, 10);
    Display(head);
    Length(head);

    return 0;
}