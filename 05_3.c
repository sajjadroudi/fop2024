#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int max = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        sum = arr[i];
        if (sum >= max) max = sum;
        for (int j = i + 1; j < n; j++) {
            sum += arr[j];
            if (sum >= max) max = sum;
        }
    }
    if (max > 0) printf("%d\n", max);
    else printf("0\n");
    return 0;
}

