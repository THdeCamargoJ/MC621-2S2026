#include <stdio.h>
#include <string.h>

/******************************************************************************
 *                                 Definitions                                *
 ******************************************************************************/

#define MAX_INPUT_DIGITS 100
#define MAX_DIGITS (MAX_INPUT_DIGITS * 2)
#define PLUS         1
#define MINUS       -1

#define llint long long int

typedef struct {
    int digits[MAX_DIGITS];
    int sign;
    int last_digit_index;
} BigInt;

void init_bigint(BigInt *num);

void print_bigint(BigInt num);

void scanf_bigint(BigInt *num);

int compare_bigint(BigInt *a, BigInt *b);

void add_bigint(BigInt *a, BigInt *b, BigInt *result);

void sub_bigint(BigInt *a, BigInt *b, BigInt *result);

/******************************************************************************
 *                             Auxiliary functions                            *
 ******************************************************************************/

void digit_shift(BigInt *num, int shift) {
    int i;

    if ((num->last_digit_index == 0) && (num->digits[0] == 0)) {
        return;
    }

    for (i = num->last_digit_index; i >= 0; i--) {
        num->digits[i + shift] = num->digits[i];
    }

    for (i = 0; i < shift; i++) {
        num->digits[i] = 0;
    }

    num->last_digit_index += shift;
}

void zero_justify(BigInt *num) {
    while ((num->last_digit_index > 0) && (num->digits[num->last_digit_index] == 0)) {
        num->last_digit_index--;
    }

    if ((num->last_digit_index == 0) && (num->digits[0] == 0)) {
        num->sign = PLUS; // Avoid negative zero
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

/******************************************************************************
 *                               MAIN FUNCTIONS                               *
 ******************************************************************************/

void init_bigint(BigInt *num) {
    int i;
    for (i = 0; i < MAX_DIGITS; i++) {
        num->digits[i] = 0;
    }
    num->sign = PLUS;
    num->last_digit_index = 0;
}

void print_bigint(BigInt num) {
    int i;
    
    if (num.sign == MINUS) {
        printf("-");
    }

    for (i = num.last_digit_index; i >= 0; i--) {
        printf("%d", num.digits[i]);
    }
    printf("\n");
}

void scanf_bigint(BigInt *num) {
    char input[MAX_INPUT_DIGITS + 2]; /* +2 for '-' and \0 */
    int i;

    scanf("%s", input);

    init_bigint(num);
    
    for (i = strlen(input) - 1; i >= 0; i--) {
        if (i == 0 && input[0] == '-') {
            num->sign = MINUS;
        } else {
            num->digits[num->last_digit_index++] = input[i] - '0';
        }
    }
    num->last_digit_index--;
}

int compare_bigint(BigInt *a, BigInt *b) {
    int i;

    if ((a->sign == MINUS) && (b->sign == PLUS)) {
        return MINUS; /* b is greater than a */
    }

    if ((a->sign == PLUS) && (b->sign == MINUS)) {
        return PLUS; /* a is greater than b */
    }

    if (a->last_digit_index > b->last_digit_index) {
        /* a is greater than b (if positive) or 
           b is greater than a (if negative) */
        return PLUS * a->sign;
    }
    
    if (a->last_digit_index < b->last_digit_index) {
        /* b is greater than a (if positive) or 
           a is greater than b (if negative) */
        return MINUS * a->sign;
    }

    for (i = a->last_digit_index; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) {
            /* a is greater than b (if positive) or 
               b is greater than a (if negative) */
            return PLUS * a->sign;
        }
        if (b->digits[i] > a->digits[i]) {
            /* b is greater than a (if positive) or 
               a is greater than b (if negative) */
            return MINUS * a->sign;
        }
    }

    return 0; /* a and b are equal */
}

void add_bigint(BigInt *a, BigInt *b, BigInt *result) {
    int i, value, carry = 0;

    init_bigint(result);

    if (a->sign == b->sign) {
        result->sign = a->sign;
    } else {
        if (a->sign == MINUS) {
            a->sign = PLUS;
            sub_bigint(b, a, result);
            a->sign = MINUS;
        } else {
            b->sign = PLUS;
            sub_bigint(a, b, result);
            b->sign = MINUS;
        }
        return;
    }

    result->last_digit_index = max(a->last_digit_index, b->last_digit_index) + 1;

    for (i = 0; i <= result->last_digit_index; i++) {
        value = carry + a->digits[i] + b->digits[i] ;
        result->digits[i] = value % 10;
        carry = value / 10;
    }

    zero_justify(result);
}

void sub_bigint(BigInt *a, BigInt *b, BigInt *result) {
    int i, value, borrow = 0;

    init_bigint(result);

    if ((a->sign == MINUS) || (b->sign == MINUS)) {
        b->sign *= -1;
        add_bigint(a, b, result);
        b->sign *= -1;
        return;
    }

    if (compare_bigint(a, b) == MINUS) {
        sub_bigint(b, a, result);
        result->sign = MINUS;
        return;
    }

    result->last_digit_index = max(a->last_digit_index, b->last_digit_index);

    for (i = 0; i <= result->last_digit_index; i++) {
        value = a->digits[i] - b->digits[i] - borrow;
        
        if (a->digits[i] > 0) {
            borrow = 0;
        }
        
        if (value < 0) {
            value += 10;
            borrow = 1;
        }

        result->digits[i] = value;
    }

    zero_justify(result);
}

int main() {
    llint t, t_num;
    BigInt a, b, balance;

    scanf("%lld", &t_num);

    for (t = 0; t < t_num; t++){
        scanf_bigint(&a);
        scanf_bigint(&b);
        sub_bigint(&a, &b, &balance);
        print_bigint(balance);
    }

    return 0;
}