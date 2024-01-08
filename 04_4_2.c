#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int x = 0, y = 0;
    int count = 0;
    while (count < n - 1) {
        if (count % 4 == 0) x = -x + 1;
        else if (count % 4 == 1) y = -y + 1;
        else if (count % 4 == 2) x = -x;
        else if (count % 4 == 3) y = -y;
        count++;
    }
    printf("%d %d", x, y);
    return 0;
}
