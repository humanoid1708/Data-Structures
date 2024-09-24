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

void DeletionOfNode(struct node* head, int pos) {
    struct node* prev = head;
    struct node* curr = head->next;
    int count = 1;

    while(count<pos) {
        count++;
        prev = curr;
        curr =  curr->next;
    }
    struct node* temp = curr;
    prev->next = curr->next;
    curr->next = NULL;
    free(temp);
}

int main() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data =0;
    head->next = NULL;

    Creation(head, 5);
    printf("Original List:-\n");
    Display(head);

    DeletionOfNode(head, 4);
    printf("List after deletion:-\n");
    Display(head);
    return 0;
}