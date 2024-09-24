#include <stdio.h>
#include <stdlib.h>

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

void Reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head->next;

    while(curr!= NULL) {
        struct node* futu = curr->next;
        curr->next = prev;
        prev = curr;
        curr = futu;
    }
    head->next =  prev; 
}

int main() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data =0;
    head->next = NULL;

    Creation(head, 20);
    printf("Original List:-\n");
    Display(head);

    Reverse(head);
    printf("Revrsed List:-\n");
    Display(head);
    return 0;
}