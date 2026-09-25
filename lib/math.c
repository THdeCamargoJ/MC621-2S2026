#include <math.h>

#define llint long long int

#define MOD 123


llint power(llint base, llint exponent) {
    llint aux ;

    if (exponent == 0) return 1;
    else if (exponent % 2 == 0) {
        aux = power(base , exponent/2);
        return aux * aux;
    } else {
        aux = power(base, (exponent-1)/2 );
        return (base * aux) * aux;
    }
}


llint modular_inverse(llint a) {
    a = a % MOD;
    return power(a, MOD - 2);
}

int is_prime(llint number) {
    llint sqrt_number, i;
    
    if (number == 2) return 1; 
    
    if (number % 2 == 0) return 0;

    sqrt_number = sqrt(number) + 1;

    for (i = 3; i < sqrt_number; i += 2) if (number % i == 0) return 0;

    return 1;
}

//calculates x^y % n
int exponentMod(int x, int y, int n) {
    // base cases
    if ( y == 0 ) return 1;
    if ( x == 0 ) return 0;

    // y is even
    long v ;
    if (y % 2 == 0 ) {
        v = exponentMod (x, y/2, n);
        v = (v * v) % n;
    }

    // y is odd
    else {
        v = x % n ;
        v = (v * exponentMod ( x, y-1, n)) % n;
    }
    return (int) ((v + n) % n);
}