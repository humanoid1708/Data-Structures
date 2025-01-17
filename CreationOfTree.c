#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void CreationR(struct Node* root){
    struct Node* temp = root;
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    int new;
    printf("Enter data: ");
    scanf("%d", &new);
    curr->data = new;
    curr->left = NULL;
    curr->right = NULL;
    char choice;
    printf("Press 'l' for left or 'r' for right\n");
    scanf(" %c", &choice);
    if(choice == 'l'){
        temp->left = curr;
        CreationR(curr);
    }
    else if(choice == 'r'){
        temp->right = curr;
        CreationR(curr);
    }
    else{
        printf("Invalid Choice");
    }

}

void CreationNR(struct Node* root){
    int cont = 1;
    do {
        struct Node* temp = root;
        struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
        int new;
        printf("Enter data: ");
        scanf("%d", &new);
        curr->data = new;
        curr->left = NULL;
        curr->right = NULL;
        int flag = 0;
        while(flag == 0) {
            char choice;
            printf("Press 'l' for left or 'r' for right: ");
            scanf(" %c", &choice);
            if(choice == 'l'){
                if(temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                }
                else{
                    temp = temp->left;
                }
            }
            else if(choice == 'r'){
                if(temp->right == NULL){
                    temp->right = curr;
                    flag = 1;
                }
                else{
                    temp = temp->right;
                }
            }
            else {
                printf("Invalid Choice\n");
            }
        }
        printf("Press 1 to continue or 0 to exit: ");
        scanf("%d", &cont);
    }
    while(cont == 1);
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    CreationR(root);
    return 0;
}

