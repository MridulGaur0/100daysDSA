#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int arr[], int n, int k, int dist) {
    int count = 1, last = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
        }
        if (count >= k) return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int l = 1, r = arr[n-1] - arr[0], ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}