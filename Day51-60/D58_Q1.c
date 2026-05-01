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

struct Node* build(int pre[], int in[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) return root;

    int inIndex = search(in, inStart, inEnd, root->data);

    root->left = build(pre, in, inStart, inIndex - 1, preIndex);
    root->right = build(pre, in, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int pre[n], in[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    int preIndex = 0;

    struct Node* root = build(pre, in, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}