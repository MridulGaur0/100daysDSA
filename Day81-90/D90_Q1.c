#include <stdio.h>

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) return 0;

        if (time + arr[i] > maxTime) {
            painters++;
            time = arr[i];
        } else {
            time += arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}