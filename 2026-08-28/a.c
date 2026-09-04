#include <stdio.h>
#include <stdlib.h>

#define llint long long int
#define MAX 1000000000LL

int main() {
    FILE *input_file = fopen("pow.in", "r"),
         *output_file = fopen("pow.out", "w");
    llint a, b, result;

    fscanf(input_file, "%lld %lld", &a, &b);
    fclose(input_file);
    
    if (a == 1) { // b >= 1
        result = 1;
    } else {
        result = a;
        for (llint i = 1; i < b; i++) {
            result *= a;
            if (result > MAX) {
                result = -1;
                break;
            }
        }
    }

    fprintf(output_file, "%lld", result);
    fclose(output_file);

    return 0;
}