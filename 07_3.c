#include <stdio.h>
#include <string.h>
#define MAX_LEN 110

void checkPattern(char str[]) {
    int length = strlen(str);

    // Check for decreasing pattern
    int decreasing = 1;
    for (int i = 1; i < length - 1; i++) {
        if (str[i] >= str[i - 1] && str[i] > str[i + 1]) {
            for (; i < length - 1; i++) {
                if (str[i + 1] > str[i]) {
                    printf("-1\n");
                    return;
                }
            }
            decreasing = 0;
            break;
        }
    }

    // Check for increasing pattern
    int increasing = 1;
    for (int i = 1; i < length - 1; i++) {
        if (str[i] <= str[i - 1] && str[i] < str[i + 1]) {
            for (; i < length - 1; i++) {
                if (str[i + 1] < str[i]) {
                    printf("-1\n");
                    return;
                }
            }
            increasing = 0;
            break;
        }
    }

    if (increasing || decreasing) {
        printf("%s\n", str);
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        char input[MAX_LEN];
        scanf("%s", input);
        checkPattern(input);
    }

    return 0;
}
