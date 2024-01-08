#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int max_of_three(int num1, int num2, int num3) {
    int max = num1;
    max = num2 > max ? num2 : max;
    max = num3 > max ? num3 : max;
    return max;
}

int min_of_three(int num1, int num2, int num3) {
    int min = num1;
    min = num2 < min ? num2 : min;
    min = num3 < min ? num3 : min;
    return min;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = max_of_three(gcd(a, b), gcd(a, c), gcd(b, c));
    int min = min_of_three(a, b, c);
    if (max % min == 0) printf("YES");
    else printf("NO");
    return 0;
}
