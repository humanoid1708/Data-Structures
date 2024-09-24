#include<stdio.h>
#include<stdlib.h>

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
        while(ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

/*struct node* InsertAtBegining(struct node* head, int data) {
    struct node* info;
    info = (struct node*)malloc(sizeof(struct node));
    info->data = data;
    info->next = head;
    return info;
    //Its time complexity is O(1).
}*/

void InsertInBetween(struct node* head, int data, int index) {
    struct node* info = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;    //Always try to allocate a new temp variable
                                //to the head node before doing any operation.
    int count = 0;
    info->data = data;          
    while(count != index-1) {
        count++;
        ptr = ptr->next;
    }
    info->next = ptr->next;     //Order of these 2 statemenst should be kept
    ptr->next = info;           //in mind cautiously to avoid infinite loop.
}
int main() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    head->data =0;
    head->next = NULL;

    Creation(head, 5);
    printf("Original List:-\n");
    Display(head);

    /*head = InsertAtBegining(head, 69);
    printf("List after insertion at begining:-\n");
    Display(head);*/

    InsertInBetween(head, 91, 3);
    printf("List after insertion at a position:-\n");
    Display(head);
    return 0;
}