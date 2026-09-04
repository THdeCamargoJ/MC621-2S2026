#include <stdio.h>

#define llint long long int

int main() {
    llint n_books, free_minutes, books_read;

    scanf("%lld %lld", &n_books, &free_minutes);

    llint book_reading_times[n_books];
    llint total_reading_time = 0;

    for (llint i = 0; i < n_books; i++) {
        scanf("%lld", &book_reading_times[i]);
        total_reading_time += book_reading_times[i];
    }


    books_read = n_books;

    llint i = 0, j = n_books - 1;

    while (total_reading_time > free_minutes) {
        if (book_reading_times[i] > book_reading_times[j]) {
            total_reading_time -= book_reading_times[i];
            i++;
        } else {
            total_reading_time -= book_reading_times[j];
            j--;
        }
        books_read--;
    }

    printf("%lld\n", books_read);

    return 0;
}