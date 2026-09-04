#include <stdio.h>

#define llint long long int

int main() {
    llint stops, passengers, min_capacity, passengers_in, passengers_out;

    scanf("%lld", &stops);
    passengers = 0;
    min_capacity = 0;

    for (llint i = 0; i < stops; i++) {
        scanf("%lld %lld", &passengers_out, &passengers_in);
        passengers += passengers_in - passengers_out;
        if (passengers > min_capacity) {
            min_capacity = passengers;
        }
    }

    printf("%lld\n", min_capacity);
    return 0;
}