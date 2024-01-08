#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b + c && b < a + c && c < a + b) {
        printf("YES\n");
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) printf("1");
        else if (a == b && b == c) printf("2");
        else if (a == b || a == c || b == c) printf("3");
        else printf("4");
    } else printf("NO");
    return 0;
}
