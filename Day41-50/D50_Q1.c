#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0; 
    }

    if (root->data == data) {
        return 1;  
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    int n, value, query;
    struct Node* root = NULL;
    
    scanf("%d", &n);  
    
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    
    scanf("%d", &query);

    if (search(root, query)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}