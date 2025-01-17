#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* queue[100];
int f = -1;
int r = -1;

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

int isEmpty() {
    return f == r;
}

void push(struct Node* node) {
    queue[++r] = node;
}

struct Node* pop() {
    return queue[++f];
}
void BFS(struct Node* root) {
    struct Node* temp = root;
    push(temp);
    while(!isEmpty()) {
        temp = pop();
        printf("%d ", temp->data);
        if(temp->left != NULL) {
            push(temp->left);
        }
        if(temp->right != NULL) {
            push(temp->right);
        }
    }
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    CreationNR(root);
    BFS(root);
}