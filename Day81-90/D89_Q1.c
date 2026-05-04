#include <stdio.h>

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int l = max, r = sum, ans = sum;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}