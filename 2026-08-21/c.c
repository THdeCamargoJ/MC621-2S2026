#include <stdio.h>

#define llint long long int

typedef struct {
    llint strength;
    llint prize_bonus;
} Dragon;

int compare_dragons(Dragon dragon_a, Dragon dragon_b) {
    return dragon_a.strength - dragon_b.strength;
}

void merge(Dragon * arr, llint left, llint mid, llint right) {
    llint L_size = mid - left + 1;
    llint R_size = right - mid;

    Dragon L[L_size], R[R_size];

    for (llint i = 0; i < L_size; i++)
        L[i] = arr[left + i];
    for (llint j = 0; j < R_size; j++)
        R[j] = arr[mid + 1 + j];

    llint i = 0, j = 0, k = left;

    while (i < L_size && j < R_size) {
        if (compare_dragons(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < L_size) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < R_size) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(Dragon * arr, llint left, llint right) {
    if (left < right) {
        llint mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    llint kirito_strength, n_dragons, defeated_dragons = 0;

    scanf("%lld %lld", &kirito_strength, &n_dragons);

    Dragon dragons[n_dragons];

    for (llint i = 0; i < n_dragons; i++) {
        scanf("%lld %lld", &dragons[i].strength, &dragons[i].prize_bonus);
    }

    merge_sort(dragons, 0, n_dragons - 1);

    while(defeated_dragons < n_dragons) {
        llint strongest_defeatable_dragon = -1;
        
        for (llint i = defeated_dragons; i < n_dragons; i++) {
            if (dragons[i].strength < kirito_strength) {
                strongest_defeatable_dragon = i;
            } else {
                break;
            }
        }

        if (strongest_defeatable_dragon < 0) {
            printf("NO\n");
            return 0;
        }
        
        for (llint i = defeated_dragons; i <= strongest_defeatable_dragon; i++) {
            kirito_strength += dragons[i].prize_bonus;
        }

        defeated_dragons = strongest_defeatable_dragon + 1;
    }

    printf("YES\n");
    return 0;
}