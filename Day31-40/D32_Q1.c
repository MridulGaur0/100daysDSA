#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int main() {
    int n, op, value;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {
            int popped = pop();
            if (popped != -1) {
                printf("%d\n", popped);
            } else {
                printf("Stack is empty\n");
            }
        }
    }
    
    return 0;
}