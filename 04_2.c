#include <stdio.h>

int main() {
    int n, max = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);
        if (number % 2 == 0 && number > max) max = number;
    }
    printf("%d", max);
}