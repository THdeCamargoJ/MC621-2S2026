#include <stdio.h>


#define llint long long int
#define MAX_N 100001LL


llint gcd(llint a, llint b) {
    return b == 0? a : gcd(b, a % b); 
}

llint max_gcd(llint *vec, llint vec_size) {
    llint prefix[MAX_N], sufix[MAX_N], i, max_gcd, curr_gcd;

    prefix[0] = 0;
    for (i = 0; i <= vec_size; i++) prefix[i + 1] = gcd(prefix[i], vec[i]);

    sufix[vec_size] = 0;
    for (i = vec_size-1; i >= 0; i--) sufix[i]= gcd(sufix[i + 1], vec[i]);

    max_gcd = 0;
    for (i = 0; i < vec_size; i++) {
        curr_gcd = gcd(prefix[i], sufix[i + 1]);
        if (curr_gcd > max_gcd) max_gcd = curr_gcd;
    }

    return max_gcd;
}

int main() {
    llint ints[100000], n, i;

    scanf("%lld", &n);

    for (i = 0; i < n; i++) scanf("%lld", &ints[i]);

    printf("%lld\n", max_gcd(ints, n));

    return 0;
}