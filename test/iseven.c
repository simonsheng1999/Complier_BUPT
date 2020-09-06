#include <stdio.h>


int a;


int main() {
    printf("a=");
    scanf("%d", &a);
    if (((a % 2) == 0)) 
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}