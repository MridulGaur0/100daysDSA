#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int count[26] = {0};

    for (int i = 0; s[i]; i++) {
        int idx = s[i] - 'a';
        count[idx]++;
        if (count[idx] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}