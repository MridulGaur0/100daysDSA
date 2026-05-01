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

int search(int in[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (in[i] == val) return i;
    return -1;
}

struct Node* build(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(post[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) return root;

    int inIndex = search(in, inStart, inEnd, root->data);

    root->right = build(in, post, inIndex + 1, inEnd, postIndex);
    root->left = build(in, post, inStart, inIndex - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[n], post[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    int postIndex = n - 1;

    struct Node* root = build(in, post, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}