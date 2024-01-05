#include <stdio.h>
#define maxElement 100

int a[maxElement][maxElement] = {};
int setNumber(int x, int y);
int n;
int m;

int main()
{
    int i;
    int j;
    int k;
    int kNumber;

    scanf("%d %d", &n, &m);
    scanf("%d", &kNumber);

    for (k = 0; k < kNumber; k++)
    {
        scanf("%d", &i);
        scanf("%d", &j);
        a[i-1][j-1] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m;  j++)
        {
            if (a[i][j] != -1){
                setNumber(i, j);
                printf("%d ", a[i][j]);
            }else printf("* ");
        }
        printf("\n");
    }

    return 0;
}

int setNumber(int x, int y)
{
    int i;
    int j;
    for (i = x - 1;  i < x + 2; i++)
    {
        for (j = y - 1; j < y + 2; j++)
        {
            if (a[i][j] == -1 && -1 < i && i < n && -1 < j && j < m)
                a[x][y]++;
        }
    }
    return 0;
}
