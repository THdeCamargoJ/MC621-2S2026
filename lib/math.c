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