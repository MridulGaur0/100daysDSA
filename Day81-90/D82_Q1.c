#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int l = 0, r = n, ans = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int l = 0, r = n, ans = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] > x) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d", lb, ub);

    return 0;
}