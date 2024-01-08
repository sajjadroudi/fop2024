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

int sum_of_digits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int nth_prime(int n) {
    if (n <= 0) {
        return -1;
    }
    int count = 0;
    int number = 2;
    while (count < n) {
        if (is_prime(number)) {
            count++;
        }
        if (count < n) {
            number++;
        }
    }
    return number;
}

int convert_base(int number, int base) {
    if (base < 2 || base > 9) {
        return -1;
    }
    int result = 0;
    int multiplier = 1;
    while (number > 0) {
        int digit = number % base;
        result += digit * multiplier;
        multiplier *= 10;
        number /= base;
    }
    return result;
}

int is_palindrome(int number) {
    int original_number = number;
    int reversed_number = 0;
    while (number > 0) {
        int digit = number % 10;
        reversed_number = reversed_number * 10 + digit;
        number /= 10;
    }
    return original_number == reversed_number ? 1 : 0;
}

int main() {
    int x, n, b;
    scanf("%d %d %d", &x, &n, &b);
    int result;
    if (!is_prime(x)) result = 0;
    else if (!is_prime(sum_of_digits(x))) result = 0;
    else if (nth_prime(n) != x) result = 0;
    else if (!is_palindrome(convert_base(x, b))) result = 0;
    else result = 1;
    if (result) printf("Adad %d vageie ast", x);
    else printf("Adad %d keyk ast", x);
    return 0;
}
