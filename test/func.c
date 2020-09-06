#include <stdio.h>


int i;

void drawaline(int n) {
    int j;
    for (j = 1; j <= n; j++) 
        printf("* ");
    printf("\n");
}

int main() {
    for (i = 1; i <= 6; i++) 
        drawaline(i);
    return 0;
}