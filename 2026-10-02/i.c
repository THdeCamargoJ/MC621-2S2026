#include <stdio.h>

#define llint long long int
#define MAX_DIGITS 100

#define MAX 1
#define MIN 0

void llint_to_string(llint number, char *buffer) {
    sprintf(buffer, "%lld", number);    
}



int get_digit(llint number, int mode) {
    char target, buffer[MAX_DIGITS];
    int i;

    llint_to_string(number, buffer);

    i = 0;
    target = mode == MAX? '0' : '9';
    while (buffer[i] != '\0') {
        if (mode == MAX) {
            if (buffer[i] > target) target = buffer[i];
            if (buffer[i] == '9') return 9;
        } else {
            if (buffer[i] < target) target = buffer[i];
            if (buffer[i] == '0') return 0;
        }
        i++;
    }

    return (int)(target - '0');
}

llint get_ak(llint a1, llint k) {
    llint i, ai, max, min;

    i = 0;
    ai = a1;
    for (i = 1; i < k; i++) {
        max = get_digit(ai, MAX);
        min = get_digit(ai, MIN);
        if (min == 0) break;
        ai +=  max * min;
    }    

    return ai;
}


int main() {
    llint n_tests, t, a1, k;

    scanf("%lld", &n_tests);
    for (t = 0; t < n_tests; t++) {
        scanf("%lld %lld", &a1, &k);
        printf("%lld\n", get_ak(a1, k));
    }

    return 0;
}