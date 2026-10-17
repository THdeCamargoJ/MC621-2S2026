#include <stdio.h>
#include <string.h>

#define MAX_LEN 3001



void solve_for(char *p, char *q) {
    static int table[MAX_LEN][MAX_LEN];
    int len_p = strlen(p), len_q = strlen(q), len_ans;
    int i, j;
    char ans[MAX_LEN];

    memset(table, 0, sizeof(table));

    for (i = 1; i <= len_p; i++) {
        for (j = 1; j <= len_q; j++) {
            if (p[i - 1] == q[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = (table[i - 1][j] > table[i][j - 1])? table[i - 1][j] : table[i][j - 1];
        }
    }

    len_ans = table[len_p][len_q];
    ans[len_ans] = '\0';

    i = len_p;
    j = len_q;
    while (i > 0 && j > 0) {
        if (p[i - 1] == q[j - 1]) {
            ans[--len_ans] = p[i - 1];
            i--;
            j--;
        }
        else if (table[i - 1][j] >= table[i][j - 1]) i--;
        else j--;
    }
    
    printf("%s\n", ans);
}



int main() {
    char s[MAX_LEN], t[MAX_LEN];
    
    scanf("%s %s", s, t);

    solve_for(s, t);

    return 0;
}