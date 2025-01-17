#include <stdio.h>
#include <stdlib.h>
#define size 100

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* stack[size];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    if(isEmpty()) {
        return NULL;
    }
    struct Node* node = stack[top--];
    return node;

}
void CreationNR(struct Node* root) {
    char start = 'Y';
    do {
        struct Node* temp = root;
        struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
        int new;
        printf("Enter the data:");
        scanf("%d", &new);
        curr->data = new;
        curr->left = NULL;
        curr->right = NULL;
        int flag = 0;
        while(flag == 0) {
            char ch;
            printf("Enter 'l' for left or 'r' for right or 'q' to exit: ");
            scanf(" %c", &ch);
            if(ch == 'l') {
                if(temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else {
                if(ch == 'r') {
                    if(temp->right == NULL) {
                        temp->right = curr;
                        flag = 1;
                    }
                temp = temp->right;
                }
            }
        }
        printf("Do you want to continue? (Y/N):");
        scanf(" %c", &start);
    } while(start == 'Y');
    
}

void inorderNR(struct Node* root) {
    struct Node* temp = root;
    while(1) {
        while(temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        if(isEmpty()) {
            break;
        }
        temp = pop();
        printf("%d", temp->data);
        temp = temp->right;
    }
}

void preorderNR(struct Node* root) {
    struct Node* temp = root;
    while(1) {
        while(temp != NULL) {
            printf("%d", temp->data); 
            push(temp);
            temp = temp->left;
        }
        if (isEmpty()) {
            break;
        }
        temp = pop();
        temp = temp->right;
    }
}

void postorderNR(struct Node* root) {
    struct Node* temp = root;
    while(1) {
        while(temp != NULL) {
            push(temp);
            temp = temp->left;
        }
        if (isEmpty()) {
            break;
        }
        temp = pop();
        temp = temp->right;
        printf("%d", temp->data); 
    }
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    CreationNR(root);
    inorderNR(root);
}