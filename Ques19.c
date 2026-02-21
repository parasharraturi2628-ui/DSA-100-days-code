//Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int abs_val(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int bestSum = arr[l] + arr[r];
    int x = arr[l], y = arr[r];

    while (l < r) {
        int s = arr[l] + arr[r];

        if (abs_val(s) < abs_val(bestSum)) {
            bestSum = s;
            x = arr[l];
            y = arr[r];
        }

        if (s < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", x, y);
    return 0;
}
