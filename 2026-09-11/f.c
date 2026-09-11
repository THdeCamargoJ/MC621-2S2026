#include <stdio.h>

#define llint long long int

double potencia2 (double x, llint p) {
    double aux ;

    if (p == 0) return 1;
    else if (p % 2 == 0) {
        aux = potencia2( x , p / 2 ) ;
        return aux * aux ;
    } else {
        aux = potencia2( x, (p-1) / 2 ) ;
        return (x * aux) * aux ;
    }
}

int main() {
    llint m, n, i;
    double result, prob;

    scanf("%lld %lld", &m, &n);

    prob = (double)1 / m;

    

    result = 0;
    for (i = 1; i <= m; i++) {
        result += i * (potencia2(i*prob, n) - potencia2((i - 1)*prob, n));
    }

    printf("%.12f\n", result);

    return 0;
}