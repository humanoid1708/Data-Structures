#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* stack[100];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(struct node* node) {
    stack[++top] = node;
}

struct node* pop() {
    if(isEmpty()) {
        return NULL;
    }
    struct node* node = stack[top--];
    return node;

}

void create(struct node* root) {
    int choice = 1;
    do {
        struct node* temp = root;
        struct node* curr = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &curr->data);
        curr->left = NULL;
        curr->right = NULL;
        int flag = 0;
        while(flag == 0) {
            if(curr->data < temp->data) {
                if(temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else {
                if(temp->right == NULL) {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }
        printf("Do you wan to continue? (1/0): ");
        scanf("%d", &choice);
    }while(choice == 1);
}

void inorder(struct node* root) {
    struct node* temp = root;
    while(1) {
        while(temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        if(isEmpty()) {
            break;
        }
        temp = pop();
        printf("%d ", temp->data);
        temp = temp->right;

    }
}


int main() {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for root: ");
    scanf("%d", &root->data);
    root->left = NULL;
    root->right = NULL;
    create(root);
    inorder(root);
}