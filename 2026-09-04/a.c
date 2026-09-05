#include <stdio.h>
#include <string.h>

#define llint      long long int
#define MAX_DIGITS 102

int main() {
    char a[MAX_DIGITS], b[MAX_DIGITS];
    
    scanf("%s %s", a, b);

    if (strcmp(a, b) == 0) {
        printf("%s\n", a);
    } else {
        printf("%d\n", 1);
    }

    return 0;
}