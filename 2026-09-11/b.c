#include <stdio.h>

#define llint long long int

int main() {
    llint a, b, c, d;
    double p_hit_smallR, p_hit_zanoes, p_miss_smallR, p_miss_zanoes, result;

    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    p_hit_smallR = (double) a / b;
    p_hit_zanoes = (double) c / d;

    p_miss_smallR = 1 - p_hit_smallR;
    p_miss_zanoes = 1 - p_hit_zanoes;

    // SmallR always shoots first, and the shooting takes place in turns.
    // First hit wins

    // p_smallR_win = p_hit_smallR + (p_miss_smallR * p_miss_zanoes * p_hit_smallR) + (p_miss_smallR * p_miss_zanoes * p_miss_smallR * p_miss_zanoes * p_hit_smallR) + ...
    // p_smallR_win = p_hit_smallR + (p_hit_smallR * (p_miss_smallR * p_miss_zanoes)) + (p_hit_smallR * (p_miss_smallR * p_miss_zanoes)^2) + (p_hit_smallR * (p_miss_smallR * p_miss_zanoes)^3) + ...
    // p_smallR_win = p_hit_smallR * (1 + (p_miss_smallR * p_miss_zanoes) + (p_miss_smallR * p_miss_zanoes)^2 + (p_miss_smallR * p_miss_zanoes)^3 + ...)

    result = (p_hit_smallR / (1 - p_miss_smallR * p_miss_zanoes));

    printf("%.12lf\n", result);

    return 0;
}