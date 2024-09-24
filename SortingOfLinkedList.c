#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

//Function for creating a linked list
void Creation(struct node* head, int size) {
    struct node* temp = head;
    for(int i = size; i >= 1; i--) {
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

int Length(struct node* ptr) {
    int len = 0;
    while(ptr->next != NULL) {
        len++;
        ptr = ptr->next;
    }
    return len;
}
void Sort(struct node* head, int n) {
    struct node* temp;
    for(int i = 1; i < n; i++) {
        struct node* prev = head;
        struct node* curr = head->next;
        for(int j = 0; j < n - i; j++) {
            temp = curr->next;
            if(curr->data > temp->data) {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                prev = temp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 69;
    head->next = NULL;
    
    Creation(head, 5);
    printf("Original List:-\n");
    Display(head);

    int len = Length(head);
    Sort(head, len);
    printf("After Sorting:-\n");
    Display(head);

    return 0;
}