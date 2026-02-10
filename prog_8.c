#include <stdio.h>
#include <stdlib.h>

int comp = 0, swap = 0;

void bubble(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            comp++;
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap++;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("Before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    bubble(a, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nComparisons = %d", comp);
    printf("\nSwaps = %d", swap);

    return 0;
}
