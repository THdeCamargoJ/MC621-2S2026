#include <stdio.h>
#include <math.h>


#define llint long long int
#define MAX_NUMBER_OF_JEWLERY 100000LL


int is_prime(llint number) {
    llint sqrt_number, i;
    
    if (number == 2) return 1; 
    
    if (number % 2 == 0) return 0;

    sqrt_number = sqrt(number) + 1;

    for (i = 3; i < sqrt_number; i += 2) if (number % i == 0) return 0;

    return 1;
}


int main() {
    llint number_of_jewlery, i;

    scanf("%lld", &number_of_jewlery);

    if (number_of_jewlery < 3) printf("%d\n", 1);
    else printf("%d\n", 2);

    for (i = 1; i <= number_of_jewlery; i++) {
        if (is_prime(i+1)) printf("1 ");
        else printf("2 ");
    }

    return 0;
}