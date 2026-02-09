//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

int main() {
    char s[200];
    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;

    while(i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    printf("%s", s);
    return 0;
}
