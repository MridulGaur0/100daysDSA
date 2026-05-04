#include <stdio.h>

struct Node {
    int val, idx;
};

void merge(struct Node arr[], int l, int m, int r, int count[]) {
    int n1 = m - l + 1, n2 = r - m;
    struct Node L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l, rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(struct Node arr[], int l, int r, int count[]) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}