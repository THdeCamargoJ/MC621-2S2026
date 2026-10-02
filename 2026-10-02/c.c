#include <stdio.h>
#include <stdlib.h>

#define llint long long int


llint *minimum_divisors;

llint f(llint n) {
    llint i;

    if (n % 2 == 0) return 2;

    if (minimum_divisors[n] != 0) return minimum_divisors[n];

    for (i = 3; i <= (llint) n / 2; i += 1) {
        if (n % i == 0) {
            minimum_divisors[n] = i;
            return i;
        }
    }
    minimum_divisors[n] = n;
    return n;
}



int main() {
    llint n_tests, t, n, k, i;

    minimum_divisors = (llint *) calloc(sizeof(llint), 1000001);

    scanf("%lld", &n_tests);
    for (t = 0; t < n_tests; t++) {
        scanf("%lld %lld", &n, &k);

        for (i = 0; i < k; i++) {
            n += f(n);

            if (n % 2 == 0) {
                n += 2 * (k - i - 1);
                break;
            } else if (n % 3 == 0) {
                n += 3 * (k - i - 1);
                break;
            } 
        }

        printf("%lld\n", n);
    }

    free(minimum_divisors);
    return 0;
}