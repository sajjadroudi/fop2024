#include <stdio.h>
#include <math.h>

double calculate_distance(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int is_fibonacci(int number) {
    int a = 0, b = 1;
    while (a <= number) {
        if (a == number) {
            return 1;
        }
        int temp = a;
        a = b;
        b = temp + b;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int points[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    int max = -1;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int distance = calculate_distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            if (distance > max && is_fibonacci(distance)) {
                max = distance;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];
            }
        }
    }
    printf("%d %d\n%d %d", x1, y1, x2, y2);
    return 0;
}
