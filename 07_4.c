#include <stdio.h>
char colorchange(char pixels[][100], int x, int y, char newcolor, char oldcolor) {
    if (pixels[x][y] == newcolor) return 0;
    else if (pixels[x][y] != newcolor) pixels[x][y] = newcolor;
    if (pixels[x][y + 1] == oldcolor)   colorchange(pixels, x, y + 1, newcolor, oldcolor);
    if (pixels[x][y - 1] == oldcolor)   colorchange(pixels, x, y - 1, newcolor, oldcolor);
    if (pixels[x - 1][y] == oldcolor)   colorchange(pixels, x - 1, y, newcolor, oldcolor);
    if (pixels[x + 1][y] == oldcolor)   colorchange(pixels, x + 1, y, newcolor, oldcolor);
    if (pixels[x + 1][y + 1] == oldcolor)   colorchange(pixels, x + 1, y + 1, newcolor, oldcolor);
    if (pixels[x - 1][y - 1] == oldcolor)   colorchange(pixels, x - 1, y - 1, newcolor, oldcolor);
    if (pixels[x + 1][y - 1] == oldcolor)   colorchange(pixels, x + 1, y - 1, newcolor, oldcolor);
    if (pixels[x - 1][y + 1] == oldcolor)  colorchange(pixels, x - 1, y + 1, newcolor, oldcolor);

}
int main() {
    int m,n ,i ,j ,x ,y ,ncolor , ocolor;
    char board[100][100];
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0;j < n;j++) {
            scanf(" %c ", &board[i][j]);
        }
    }
    scanf("%d %d %c", &x, &y , &ncolor);
    ocolor = board[x - 1][y - 1];
    colorchange(board, x - 1, y - 1, ncolor, ocolor);

    for (i = 0; i < m; i++) {
        for (j = 0;j < n;j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }




}