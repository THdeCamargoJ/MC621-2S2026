#include <stdio.h>
#include <string.h>

#define llint long long int
#define MAX_LEN 381 // lcm(19, 20)



int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;

    return a / gcd(a, b) * b;
}

void str_multiply(char *str_in, int a, char *str_out) {
    int i, len_str_in;

    len_str_in = strlen(str_in);
    for (i = 0; i < len_str_in * a; i++) {
        str_out[i] = str_in[i % len_str_in];
    }
    str_out[i] = '\0';
}

void solve_for(char *a, char *b) {
    char sim_a[MAX_LEN], sim_b[MAX_LEN];
    int len_a, len_b, len_answer;
    
    len_a = strlen(a);
    len_b = strlen(b);
    len_answer = lcm(len_a, len_b);

    str_multiply(a, len_answer / len_a, sim_a);
    str_multiply(b, len_answer / len_b, sim_b);
    
    if (strcmp(sim_a, sim_b) == 0) {
        printf("%s\n", sim_a);
        return;
    }

    printf("-1\n");
}


int main() {
    llint n_tests, t;
    char str_a[MAX_LEN], str_b[MAX_LEN];

    scanf("%lld", &n_tests);

    for (t = 0; t < n_tests; t++) {
        scanf("%s", str_a);
        scanf("%s", str_b);
        
        solve_for(str_a, str_b);
    }

return 0;
}