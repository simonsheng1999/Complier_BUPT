#include <stdio.h>


int year;


int main() {
    printf("Input year:");
    scanf("%d", &year);
    printf("%d", year);
    printf("\n");
    if (((year % 400) == 0)) 
        printf("is a leap year.");
    else
        if (((year % 4) == 0) && (year % 100 != 0)) 
        {
            printf("is a leap year.");
        }
        else
            printf("is not a leap year.");
    return 0;
}