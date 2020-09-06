#include <stdio.h>


float a, b, h, s;


int main() {
    printf("Input a,b,h:");
    scanf("%f %f %f", &a, &b, &h);
    s = (a + b) * h / 2;
    printf("s = ");
    printf("%f", s);
    return 0;
}