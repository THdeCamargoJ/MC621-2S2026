#include <stdio.h>
#include <string.h>

#define llint long long int
#define MAX_LEN 2501

int main() {
    int len, i, j, missmatch, n, k;
    char string[MAX_LEN];

    scanf("%d %d %s", &n, &k, string);

    if (k == 1) {
        printf("%s\n", string);
        return 0;
    }

    j = 0;
    for (len = 1; len < n; len++) {
        missmatch = 0;
        for (i = 0; i < len; i++) {
            if (string[i] != string[n - len + i]) {
                missmatch = 1;
                break;
            }
        }
        if (!missmatch) j = len;
    }

    printf("%s", string);
    for (i = 1; i < k; i++) printf("%s", string + j);

    printf("\n");

    return 0;
}