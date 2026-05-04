#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    qsort(arr, n, sizeof(arr[0]), cmp);

    int start = arr[0][0], end = arr[0][1];

    for (int i = 1; i < n; i++) {
        if (arr[i][0] <= end) {
            if (arr[i][1] > end)
                end = arr[i][1];
        } else {
            printf("%d %d\n", start, end);
            start = arr[i][0];
            end = arr[i][1];
        }
    }

    printf("%d %d", start, end);

    return 0;
}