#include <stdio.h>

int main() {
    int m,n;
    scanf("%d", &m);
    scanf("%d", &n);

    int matrix[m][n];
    

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);        
        }
    }
    
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%d ", matrix[i][j]);        
    //     }
    // }
    
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Print rightmost column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Print leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}
