    #include <stdio.h>
    #include <string.h>

    #define llint long long int
    #define MAX_LEN 100001 // lcm(19, 20)



    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }

    int is_generator(char *prefix, char *string) {
        int i, len_prefix, len_string;

        len_prefix = strlen(prefix);
        len_string = strlen(string);

        for (i = 0; i < len_string; i++) {
            if (prefix[i % len_prefix] != string[i]) return 0;
        }

        return 1;
    }

    void solve_for(char *a, char *b) {
        char prefix[MAX_LEN];
        int len_a, len_b, gcd_ab, i, j, missmatch, divisors;
        
        len_a = strlen(a);
        len_b = strlen(b);
        gcd_ab = gcd(len_a, len_b);

        divisors = 0;
        for (i = 1; i <= gcd_ab; i++) {
            if (gcd_ab % i != 0) continue;

            missmatch = 0;
            for (j = 0; j < i; j++) {
                if (a[j] != b[j]) {
                    missmatch = 1;
                    break;
                }
                prefix[j] = a[j];
            }

            prefix[j] = '\0';
            if (!missmatch && is_generator(prefix, a) && is_generator(prefix, b)) {
                divisors++;
            }
        }

        printf("%d\n", divisors);
    }


    int main() {
        char str_a[MAX_LEN], str_b[MAX_LEN];
        scanf("%s", str_a);
        scanf("%s", str_b);
            
        solve_for(str_a, str_b);
        
        return 0;
    }