#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int space = 0; space < (n + 1) / 2 - i; space++) printf(" ");
        for (int star = 1; star <= 2 * i - 1; star++) printf("*");
        for (int space = 0; space < (n + 1) / 2 - i; space++) printf(" ");
        for (int space = 0; space < (n + 1) / 2 - i; space++) printf(" ");
        for (int star = 1; star <= 2 * i - 1; star++) printf("*");
        printf("\n");
    }

    int spaceCount = 1;

    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        for (int space = 0; space < spaceCount; space++) printf(" ");
        for (int star = 1; star <= 2 * (n - i) + 1; star++) printf("*");
        for (int space = 0; space < spaceCount; space++) printf(" ");
        for (int space = 0; space < spaceCount; space++) printf(" ");
        for (int star = 1; star <= 2 * (n - i) + 1; star++) printf("*");
        spaceCount++;
        printf("\n");
    }
    
}