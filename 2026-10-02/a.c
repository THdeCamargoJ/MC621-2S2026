#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define llint long long int
#define MAX_SIZE 200000


void apply_operation(llint *number) { *number = *number + *number % 10; }

llint last_digit(llint number) { return number % 10; }

bool all_equal(llint *array, llint size) {
    llint i;
    for (i = 1; i < size; i++) if (array[i] != array[0]) return false;
    return true;
}

void make_all_end_in_two(llint *array, llint size) {
    llint i;
    for (i = 0; i < size; i++) {
        if (last_digit(array[i]) == 0) continue;
        while (last_digit(array[i]) != 2) apply_operation(&array[i]);
    }
}

bool has_solution(llint *array, llint size) {
    llint i, mod_20 = array[0] % 20;

    // Two numbers that end in 2 can be made equal if their difference is
    // a multiple of 20, so check if the mod 20 of all numbers are equal.
    for (i = 1; i < size; i++) if (array[i] % 20 != mod_20) return false;
    
    return true;
}


int main() {
    llint n_tests, t, array_size, a, array[MAX_SIZE];
    bool all_zeroes;

    scanf("%lld", &n_tests);
    for (t = 0; t < n_tests; t++) {
        scanf("%lld", &array_size);

        if (array_size == 1) {
            scanf("%lld", &a);
            printf("Yes\n");
            continue;
        }

        all_zeroes = true;
        for (llint i = 0; i < array_size; i++) {
            scanf("%lld", &a);
            if (last_digit(a) == 5 || last_digit(a) == 0) {
                apply_operation(&a);
                array[i] = a;
            } else {
                array[i] = a;
                all_zeroes = false;
            }
        }

        if (all_zeroes) {
            if (all_equal(array, array_size)) printf("Yes\n");
            else printf("No\n");
            continue;
        }

        make_all_end_in_two(array, array_size);

        if (has_solution(array, array_size)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}