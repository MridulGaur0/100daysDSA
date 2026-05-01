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
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = node;
    newQueueNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
        return;
    }

    q->rear->next = newQueueNode;
    q->rear = newQueueNode;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }

    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return node;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(q, current->left);
        }

        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int data;
    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}