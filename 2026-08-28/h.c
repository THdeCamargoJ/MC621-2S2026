#include <stdio.h>

int has_more_uppercase(const char *word) {
    int uppercase_count = 0,
        lowercase_count = 0;
        
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] <= 'Z') {
            uppercase_count++;
        } else {
            lowercase_count++;
        }
    }

    return uppercase_count > lowercase_count;
}

void to_uppercase(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'a') {
            word[i] -= 32;
        }
    }
}

void to_lowercase(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] <= 'Z') {
            word[i] += 32;
        }
    }
}

int main() {
    char word[101];

    scanf("%s", word);

    if (has_more_uppercase(word)) {
        to_uppercase(word);
    } else {
        to_lowercase(word);
    }

    printf("%s\n", word);

    return 0;
}