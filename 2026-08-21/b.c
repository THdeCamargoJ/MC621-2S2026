#include <stdio.h>

#define llint long long int
#define MAX_FIGHTERS 200000


llint sum(llint *terms, llint n) {
    llint i, sum = 0;
    for (i = 0; i < n; i++) sum += terms[i];
    return sum;
}

llint max_score(llint *fighters, llint n_fighters) {
    return fighters[n_fighters - 1] - (fighters[n_fighters - 2] - sum(fighters, n_fighters - 2));
}


void solve() {
    llint fighters[MAX_FIGHTERS], n_fighters, i;

    scanf("%lld", &n_fighters);

    for (i = 0; i < n_fighters; i++) scanf("%lld", fighters + i);

    printf("%lld\n", max_score(fighters, n_fighters));
}


int main() {
    int n_tests, t;
    scanf("%d", &n_tests);

    for (t = 0; t < n_tests; t++) solve();

    return 0;
}