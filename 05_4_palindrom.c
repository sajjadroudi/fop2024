#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int subs[1024];

bool isPalindrome(int arr[], int start, int end) {
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int result[n];
    result[0] = arr[0];

    int j = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            result[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        arr[i] = result[i];
    }

    return j; 
}


void decode(int i){
    int code = subs[i];
    while(true){
        printf("%d ", (code%10));
        code = code/10;
        if(code==0){
            break;
        }
    }
}

int findPalindromeSubarrays(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(arr, i, j)) {
     
                int code = 0;
                for (int k = i; k <= j; k++) {
                    code = (code*10)+ arr[k];
                }
                subs[count] = code;
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);        
    }
    

    int count = findPalindromeSubarrays(arr, n);


   for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (subs[j] > subs[j + 1]) {
                int temp = subs[j];
                subs[j] = subs[j + 1];
                subs[j + 1] = temp;
            }
        }
    }

    int newSize = removeDuplicates(subs, count);

    for (int i = 0; i < newSize; i++) {
         decode(i);
        printf("\n");
    }
}
