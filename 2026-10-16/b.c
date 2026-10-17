#include <stdio.h>
#include <string.h>

#define llint long long int

#define MAX_LEN 1000005LL



void solve_for(char *string) {
    llint len_string = strlen(string);
    llint accounted_ws, ws_count, wow_factor;
    llint i;

    ws_count = 0;
    for (i = 0; i < len_string - 1; i++) {
        if (string[i] == 'v' && string[i + 1] == 'v') ws_count++;
    }

    i = 0;
    wow_factor = 0;
    accounted_ws = 0;
    while (i < len_string - 1) {
        if (string[i] == 'v' && string[i + 1] == 'v') {
            accounted_ws++;
        } else if (string[i] == 'o')
            wow_factor += accounted_ws * (ws_count - accounted_ws);
        i++;
    }
    
    printf("%lld\n", wow_factor);
}



int main() {
    char string[MAX_LEN];
    
    scanf("%s", string);

    solve_for(string);

    return 0;
}