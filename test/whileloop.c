#include <stdio.h>

int m, n, a, b, r;

int main() {
    printf("Input m,n:");
    scanf("%d %d", &m, &n);
    a = m;
    b = n;
    r = a % b;
    while (r != 0) 
    {
        a = b;
        b = r;
        r = a % b;
    }
    printf("The greatest common divide is : ");
    printf("%d", b);
    return 0;
}