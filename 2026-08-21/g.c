#include <stdio.h>

#define llint long long int


llint max_books(llint *reading_times, llint n_books, llint free_time) {
    llint l = 0, r = 0, sum = 0, max = 0;

    for (r; r < n_books; r++) {
        sum += reading_times[r];
        
        while (sum > free_time) sum -= reading_times[l++];

        if (r - l + 1 > max) max = r - l + 1;
    }

    return max;
}

int main() {
    llint n_books, free_minutes;

    scanf("%lld %lld", &n_books, &free_minutes);

    llint book_reading_times[n_books];

    for (llint i = 0; i < n_books; i++) {
        scanf("%lld", &book_reading_times[i]);
    }

    printf("%lld\n", max_books(book_reading_times, n_books, free_minutes));

    return 0;
}