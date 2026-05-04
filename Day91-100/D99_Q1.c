#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    int speed;
};

int cmp(const void *a, const void *b) {
    return ((struct Car*)b)->pos - ((struct Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    struct Car cars[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].pos);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    qsort(cars, n, sizeof(struct Car), cmp);

    double lastTime = -1;
    int fleets = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d", fleets);

    return 0;
}