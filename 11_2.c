#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int* numbers;
    int size;
} Stack;

Stack* buildStack(int capacity) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->size = 0;
    s->numbers = (int*) malloc(sizeof(int) * capacity);
    return s;
}

void push(Stack *s, int x) {
    *(s->numbers + s->size) = x;
    s->size++;
}

int pop(Stack *s) {
    s->size--;
    return *(s->numbers + s->size);
}

int main() {
    int capacity;
    scanf("%d", &capacity);

    Stack* stack = buildStack(capacity);

    for (int i = 0; i < capacity; i++) {
        char command[50];
        scanf("%s", command);
        if (strstr(command, "add")) {
            int num;
            sscanf(command, "add(%d)", &num);
            push(stack, num);
        } else if (strcmp(command, "remove()") == 0) {
            pop(stack);
        }
    }

    while(stack->size > 0) {
        printf("%d\n", pop(stack));
    }

    return 0;
}
