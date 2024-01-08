#include <stdio.h>

int sum_up_to_n(int n) {
    return n * (n + 1) / 2;
}

int count(int n) {
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) counter++;
    }
    return counter;
}

int main() {
    int k;
    scanf("%d", &k);
    int i;
    for (i = 1; count(sum_up_to_n(i)) < k; i++);
    printf("%d", sum_up_to_n(i));
    return 0;
}