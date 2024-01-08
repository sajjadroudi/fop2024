#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {

        if (i == 1) {
            for (int k = 1; k <= n; k++) printf("#");
            printf("\n");
        }

        else if (i == n) {
            for (int k = 1; k <= n; k++) printf("#");
        }

        else {
            for (int j = 1; j <= n; j++) {
                if (j == 1) printf("#");
                else if ((i == j) || (i + j == n + 1)) printf("#");
                else if ((i + j > n) && (j > i) && (j != n)) printf("#");
                else if (j == n) printf("#\n");
                else printf(" ");
            }
        }

    }
    return 0;
}
