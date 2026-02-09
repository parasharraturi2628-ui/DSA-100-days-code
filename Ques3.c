Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int n, i, k;
    int a[100];
    int comparisons = 0;
    int found = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(a[i] == k) {
            found = i;
            break;
        }
    }

    if(found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}
