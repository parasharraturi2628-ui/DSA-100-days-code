//Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix[1000];
    int freq[1000];
    int size = 0;

    int sum = 0;
    int count = 0;

    prefix[size] = 0;
    freq[size] = 1;
    size++;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int found = -1;
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count += freq[found];
            freq[found]++;
        } else {
            prefix[size] = sum;
            freq[size] = 1;
            size++;
        }
    }

    printf("%d", count);
    return 0;
}
