#include <stdio.h>

int is_prime(int number) {
    if (number <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int pascals_triangle_value(int i, int j) {
    return factorial(i) / (factorial(j) * factorial(i - j));
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    int max = pascals_triangle_value(i - 1, j - 1);
    for (int k = 0; k < max; k++) {
        if (is_prime(k)) printf("%d ", k);
    }
    return 0;
}