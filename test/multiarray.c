#include <stdio.h>

const int n = 3;

int a[3][3];
int i, j;


int main() {
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            scanf("%d", &a[i - 1][j - 1]);
        }
    }
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            printf("%d", a[j - 1][i - 1]);
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}