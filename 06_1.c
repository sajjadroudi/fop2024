#include <stdio.h>

double power( int a , int b ) {  
    double res = 1.00 , i ;  
    for (i=0; i<b; i++) {  
        res = res * a ;  
    }  
    return res;  
}  

// Function to calculate the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = countDigits(num);

    while (num != 0) {
        int digit = num % 10;
        sum += power(digit, digits);
        num /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int num;

    scanf("%d", &num);


    for(int i=num-1; i>0; i--){
        if(isArmstrong(i)){
             printf("%d", i);
             return 0; 
        }
    }

    printf("Not Exist");

    return 0;
}
