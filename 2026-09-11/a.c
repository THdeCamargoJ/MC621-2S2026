#include <stdio.h>

#define llint long long int
#define DENOMINATOR 1000000007


llint potencia2 (llint x, llint p) {
    llint aux ;

    if (p == 0) return 1;
    else if (p % 2 == 0) {
        aux = potencia2( x , p / 2 ) % DENOMINATOR ;
        return aux * aux % DENOMINATOR ;
    } else {
        aux = potencia2( x, (p-1) / 2 ) % DENOMINATOR ;
        return (x * aux % DENOMINATOR) * aux % DENOMINATOR ;
    }
}

llint inversomod(llint a) {
    a = a % DENOMINATOR;
    return potencia2(a, DENOMINATOR - 2);
}

int main() {
    llint letters[26], i, j, element_repetition, n_possible_strings, string_size, numerator, denominator;
    char string[1000001];

    for (i = 0; i < 26; i++) {
        letters[i] = 0;
    }

    scanf("%s", string);

    string_size = 0;
    for (i = 0; string[i] != '\0'; i++) {
        letters[string[i] - 'a']++;
        string_size++;
    }

    numerator = string_size;
    for (i = 1; i < string_size; i++) {
        numerator = numerator * (string_size - i) % DENOMINATOR;
    }

    denominator = 1;
    for (i = 0; i < 26; i++) {
        if (letters[i] > 0) {
            element_repetition = letters[i];
            for (j = 1; j < letters[i]; j++) {
                element_repetition = element_repetition * (letters[i] - j) % DENOMINATOR;
            }
            denominator = (denominator * element_repetition) % DENOMINATOR;
        }
    }

    n_possible_strings = (llint) (numerator * inversomod(denominator)) % DENOMINATOR;

    printf("%lld\n", n_possible_strings);
}
