#include <stdio.h>

#define llint long long int


//calculates x^y % n
llint exponentMod(llint x, llint y, llint n) {
    // base cases
    if ( y == 0 ) return 1;
    if ( x == 0 ) return 0;

    // y is even
    llint v ;
    if (y % 2 == 0 ) {
        v = exponentMod (x, y/2, n);
        v = (v * v) % n;
    }

    // y is odd
    else {
        v = x % n ;
        v = (v * exponentMod ( x, y-1, n)) % n;
    }
    return (llint) ((v + n) % n);
}

int main() {
    llint n;

    scanf("%lld", &n);

    printf("%lld\n", exponentMod(1378, n, 10));

    return 0;
}