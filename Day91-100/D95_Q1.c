#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

struct Node* insertSorted(struct Node* head, float val) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;

    if (!head || val < head->data) {
        t->next = head;
        return t;
    }

    struct Node* cur = head;
    while (cur->next && cur->next->data < val)
        cur = cur->next;

    t->next = cur->next;
    cur->next = t;

    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx] = insertSorted(buckets[idx], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            printf("%.2f ", temp->data);
            temp = temp->next;
        }
    }

    return 0;
}