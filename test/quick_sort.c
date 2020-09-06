#include <stdio.h>


int i, n, temp;
int a[100];

void initialize(int n) {
    int i;
    for (i = 1; i <= n; i++) 
        scanf("%d", &a[i - 1]);
}
void swap(int i, int j) {
    temp = a[j - 1];
    a[j - 1] = a[i - 1];
    a[i - 1] = temp;
}
void quicksort(int l, int r) {
    int p, m, tmp, ind;
    if (l < r) 
    {
        p = a[l - 1];
        m = l;
        for (ind = (l + 1); ind <= r; ind++) 
            if (a[ind - 1] < p) 
            {
                m = (m + 1);
                tmp = a[m - 1];
                a[m - 1] = a[ind - 1];
                a[ind - 1] = tmp;
            }
        a[l - 1] = a[m - 1];
        a[m - 1] = p;
        quicksort(l, m - 1);
        quicksort(m + 1, r);
    }
}

int main() {
    scanf("%d", &n);
    if (n <= 100) 
    {
        initialize(n);
        quicksort(1, n);
        for (i = 1; i <= n; i++) 
            printf("%d", a[i - 1]);
    }
    return 0;
}