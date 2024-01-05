#include <stdio.h>

const double INFINITY = 1.7976931348623157E+308;

double fabs(double d){
    if( d < 0 )
      return -d;
    return d;
}

double fmin(double a, double b) {
    return (a < b) ? a : b;
}

double newtonsMethodSquareRoot(double num) {
    const double epsilon = 1e-6;
    double guess = num;

    while (fabs(guess * guess - num) > epsilon) {
        guess = 0.5 * (guess + num / guess);
    }

    return guess;
}

double euclidean_distance(double point1[], double point2[], int m) {
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
        sum += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return newtonsMethodSquareRoot(sum);
}

double min_euclidean_distance(double points[][100], int n, int m) {
    double min_distance = INFINITY;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = euclidean_distance(points[i], points[j], m);
            min_distance = fmin(min_distance, distance);
        }
    }

    return min_distance;
}

int main() {
    
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    double points[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &points[i][j]);
        }
    }

    double result = min_euclidean_distance(points, n, m);
    printf("%.2lf\n", result);

    return 0;
}
