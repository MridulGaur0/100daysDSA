#include <stdio.h>

long long merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long inv = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            inv += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return inv;
}

long long mergeSort(int arr[], int l, int r) {
    long long inv = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv += mergeSort(arr, l, m);
        inv += mergeSort(arr, m + 1, r);
        inv += merge(arr, l, m, r);
    }
    return inv;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long result = mergeSort(arr, 0, n - 1);

    printf("%lld", result);

    return 0;
}