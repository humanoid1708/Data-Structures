#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

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

void inorderR(struct Node* root) {
    if(root == NULL) {
        return;
    }
    else {
        inorderR(root->left);
        printf("%d ", root->data);
        inorderR(root->right);
    }
}

void preorderR(struct Node* root) {
    if(root!=NULL) {
        printf("%d", root->data);
        preorderR(root->left);
        preorderR(root->right);
    }
}

void postorderR(struct Node* root) {
    if(root != NULL) {
        postorderR(root->left);
        postorderR(root->right);
        printf("%d", root->data);
    }
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->right = NULL;
    root->left = NULL;
    CreationNR(root);
    preorderR(root);
    return 0;
}