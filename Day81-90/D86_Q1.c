#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long l = 0, r = n, ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (mid * mid <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%lld", ans);

    return 0;
}