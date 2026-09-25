#include <stdio.h>

#define llint long long int


llint solve_for(llint a, llint b) {
    llint k = 1, i = 0;
    if (a % b == 0) return 0;

    return b - (a % b);
}

int main() {
    llint test_cases, test_case, a, b;

    scanf("%lld", &test_cases);

    for (test_case = 0; test_case < test_cases; test_case++) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", solve_for(a, b));
    }

    return 0;
}