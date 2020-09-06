#include <stdio.h>


int n, i, s;


int main() {
    printf("Enter n = ");
    scanf("%d", &n);
    s = 1;
    for (i = 2; i <= n; i++) 
    {
        s = s * i;
    }
    printf("%d", n);
    printf(" != ");
    printf("%d", s);
    return 0;
}