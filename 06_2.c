#include <stdio.h>

double power( double a , int b ) {  
    double res = 1.00 , i ;  
    for (i=0; i<b; i++) {  
        res = res * a ;  
    }  
    return res;  
}  

double toRad(int deg){
    return deg * (3.14/180);
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double calculate_sin(double x, int terms) {
    double result = 0.0;

    for (int i = 0; i < terms; i++) {
        double term = power(-1, i) * power(x, 2 * i + 1) / factorial(2 * i + 1);
        result += term;
    }

    return result;
}

double calculate_cos(double x, int terms) {
    double result = 0.0;

    for (int i = 0; i < terms; i++) {
        double term = power(-1, i) * power(x, 2 * i) / factorial(2 * i);
        result += term;
    }

    return result;
}

int main() {
    int angle;
    int bc;

    scanf("%d", &angle);
    scanf("%d", &bc);


    // Calculate and display the sine using the Taylor series
    double sin_value = calculate_sin(toRad(angle), 10);
    printf("%.5lf\n", sin_value);

   // Calculate and display the sine using the Taylor series
    double cos_value = calculate_cos(toRad(angle), 10);
    printf("%.5lf\n", cos_value);


    double p = (sin_value * bc) + (cos_value * bc) + bc;
    printf("%.5lf\n", p);

    return 0;
}
