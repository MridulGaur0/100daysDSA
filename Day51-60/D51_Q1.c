#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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

struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->data && q < root->data) {
        return findLCA(root->left, p, q);
    }

    if (p > root->data && q > root->data) {
        return findLCA(root->right, p, q);
    }

    return root;
}

int main() {
    int N;
    scanf("%d", &N);

    int values[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, values[i]);
    }

    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->data);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}