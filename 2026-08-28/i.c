#include <stdio.h>

#define llint long long int
#define denominator 1000000007LL

void mult_even_matrices(llint a[2][2], llint b[2][2], llint result[2][2]) {
    result[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % denominator;
    result[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % denominator;
    result[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % denominator;
    result[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % denominator;
}

void matrix_power(llint matrix[2][2], llint n, llint result[2][2]) {
    if (n == 0) {
        result[0][0] = 1;
        result[0][1] = 0;
        result[1][0] = 0;
        result[1][1] = 1;
        return;
    }

    if (n == 1) {
        result[0][0] = matrix[0][0];
        result[0][1] = matrix[0][1];
        result[1][0] = matrix[1][0];
        result[1][1] = matrix[1][1];
        return;
    }
    
    if (n % 2 == 0) {
        llint half_power[2][2];
        matrix_power(matrix, n / 2, half_power);
        mult_even_matrices(half_power, half_power, result);
    } else {
        llint half_power[2][2];
        matrix_power(matrix, n - 1, half_power);
        mult_even_matrices(half_power, matrix, result);
    }
}

llint fibonacci(llint n) {
    llint matrix[2][2] = {{1, 1}, {1, 0}},
          fib_0_1[2][1] = {{1}, {0}};
    if (n <= 1) {
        return n;
    }
    
    llint power_matrix[2][2], fib[2];
    matrix_power(matrix, n - 1, power_matrix);

    return (power_matrix[0][0] * fib_0_1[0][0] + power_matrix[0][1] * fib_0_1[1][0]) % denominator;
}

int main() {
    llint nth_fib, n;

    scanf("%lld", &n);

    nth_fib = fibonacci(n);

    printf("%lld\n", nth_fib);
    return 0;
}