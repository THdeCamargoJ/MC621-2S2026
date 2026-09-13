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