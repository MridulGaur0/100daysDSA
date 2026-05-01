#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

struct QNode {
    struct Node* node;
    int hd;
};

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (!root) return 0;

    struct QNode q[1000];
    int front = 0, rear = 0;

    int cols[200][200];
    int count[200] = {0};

    int offset = 100;

    q[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = q[front++];
        struct Node* node = temp.node;
        int hd = temp.hd + offset;

        cols[hd][count[hd]++] = node->data;

        if (node->left)
            q[rear++] = (struct QNode){node->left, temp.hd - 1};
        if (node->right)
            q[rear++] = (struct QNode){node->right, temp.hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", cols[i][j]);
            printf("\n");
        }
    }

    return 0;
}