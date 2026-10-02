#include <stdio.h>
#include <stdlib.h>

#define llint long long int
#define MAX_DIGITS 6
#define MAX_NUM 1000000


llint gcd(llint a, llint b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

void llint_to_string(llint n, char *buffer) { sprintf(buffer, "%lld", n); }

int main() {
    llint a, b, c, _gcd, *reminders, reminder, i, digit;
    bool found = false;
    
    scanf("%lld %lld %lld", &a, &b, &c);

    
    // Simplify a/b
    _gcd = gcd(a, b);
    
    a /= _gcd;
    b /= _gcd;
    
    if (a % b == 0) {
        if (c != 0) printf("-1\n"); else printf("1\n");
    }

    reminders = (llint *) calloc(sizeof(llint), MAX_NUM);

    reminder = a % b;
    while (reminder > b) reminder %= b;

    i = 1;
    while (!found && !reminders[reminder]) {
        reminders[reminder] = true;
        reminder *= 10;
        digit = reminder / b;
        if (reminder < b) {
            if (digit == c) {
                found = true;
                break;
            }
            i++;
            continue;
        }

        if (digit == c) {
            found = true;
            break;
        }
        
        reminder %= b;
        i++;
    }


    if (!found) printf("-1\n");
    else printf("%lld\n", i);

    free(reminders);
    return 0;
}