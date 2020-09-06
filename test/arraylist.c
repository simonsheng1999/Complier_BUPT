#include <stdio.h>


int a[10];
int i;


int main() {
    printf("Enter 10 integer:");
    for (i = 1; i <= 10; i++) 
        scanf("%d", &a[i - 1]);
    for (i = 10; i >= 1; i--) 
    {
        printf("%d", a[i - 1]);
        printf(" ");
    }
    return 0;
}