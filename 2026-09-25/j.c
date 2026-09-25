#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define llint long long int
#define ARRAY_LEN 200000LL
#define MAX_K 1000000000LL



void combine_merge_sort(
    void *v,
    size_t v_item_size,
    llint start, llint middle, llint end,
    char *left_vector,
    char *right_vector,
    int (* compare)(const void *, const void *)
) {
    char *vect = (char *)v;
    char *left_item, *right_item;
    llint lv_i = 0, rv_i = 0, lv_size, rv_size, i;
    int comparison;

    for (i = start; i <= end; i++) {
        if (i <= middle) {
            memcpy(left_vector + (lv_i * v_item_size), vect + (i * v_item_size), v_item_size);
            lv_i++;
        } else {
            memcpy(right_vector + (rv_i * v_item_size), vect + (i * v_item_size), v_item_size);
            rv_i++;
        }
    }

    lv_size = lv_i;
    rv_size = rv_i;
    lv_i = 0;
    rv_i = 0;
    i = start;
    while (lv_i < lv_size && rv_i < rv_size) {
        left_item = left_vector + (lv_i * v_item_size);
        right_item = right_vector + (rv_i * v_item_size);

        comparison = compare(left_item, right_item);

        if (comparison <= 0) {
            memcpy(vect + (i * v_item_size), left_item, v_item_size);
            lv_i++;
        } else {
            memcpy(vect + (i * v_item_size), right_item, v_item_size);
            rv_i++;
        }
        i++;
    }

    while (lv_i < lv_size) {
        memcpy(vect + (i * v_item_size), left_vector + (lv_i * v_item_size), v_item_size);
        lv_i++;
        i++;
    }

    while (rv_i < rv_size) {
        memcpy(vect + (i * v_item_size), right_vector + (rv_i * v_item_size), v_item_size);
        rv_i++;
        i++;
    }
}

void recursive_merge_sort(
    void *vect,
    size_t v_item_size,
    llint start, llint end,
    char *left_vector,
    char *right_vector,
    int (* compare)(const void *, const void *)
) {
    llint middle = start + (end - start) / 2;
    
    if (start >= end) return; // base
    
    // Divide
    recursive_merge_sort(vect, v_item_size, start, middle, left_vector, right_vector, compare);
    recursive_merge_sort(vect, v_item_size, middle + 1, end, left_vector, right_vector, compare);

    // Conquer
    combine_merge_sort(vect, v_item_size, start, middle, end, left_vector, right_vector, compare);

}

void merge_sort(
    void *vect,
    size_t v_item_size,
    llint size,
    int (* compare_positions)(const void *, const void *)
) {
    char *left_vector = (char *) malloc(v_item_size*(size/2+1)),
         *right_vector = (char *) malloc(v_item_size*(size/2+1));

    recursive_merge_sort(vect, v_item_size,  0, size - 1, left_vector, right_vector, compare_positions);

    free(left_vector);
    free(right_vector);
}

int compare(const void *item_a, const void *item_b) {
    llint a = *(llint *) item_a, b = *(llint *) item_b;

    if (a - b < 0) return -1;
    if (a - b > 0) return 1;
    return 0;
}

void get_uniques(llint *array, llint size, llint *uniques_arr, llint *uniques_size) {
    llint i;

    merge_sort(array, sizeof(llint), size, compare);

    *uniques_size = 0;
    uniques_arr[(*uniques_size)++] = array[0];
    for (i = 1; i < size; i++) {
        if (uniques_arr[*uniques_size - 1] != array[i]) {
            uniques_arr[(*uniques_size)++] = array[i];
        }
    }
}

llint get_x_such_that_sum_of_x_a_is_divisible_by_b(llint a, llint b) {
    if (a % b == 0) return 0;
    return b - (a % b);
}


llint solve_for_array(llint *array, llint size, llint k) {
    llint i, max_x, x, *uniques, uniques_size, *freq;

    if (size == 0 || (size == 1 && array[0] == 0)) return 0;
    uniques = NULL;
    freq = NULL;

    uniques = (llint *) calloc(size, sizeof(llint));

    get_uniques(array, size, uniques, &uniques_size);

    freq = (llint *) calloc(uniques_size, sizeof(llint));

    x = 0;
    for (i = 0; i < size; i++) {
        if (array[i] == uniques[x]) freq[x]++;
        else freq[++x]++;
    }

    max_x = 0;
    for (i = 0; i < uniques_size; i++) {
        x = uniques[i] + (freq[i] - 1) * k;
        if (max_x < x) max_x = x;
    }

    free(uniques);
    free(freq);

    return max_x + 1;
}

int main() {
    llint test_cases, test_case, a, n, i, r, k, *array;

    scanf("%lld", &test_cases);

    for (test_case = 0; test_case < test_cases; test_case++) {
        scanf("%lld %lld", &n, &k);

        array = NULL;
        array = (llint *) calloc(n, sizeof(llint));

        i = 0;
        for (a = 0; a < n; a++) {
            scanf("%lld", &r);
            r = get_x_such_that_sum_of_x_a_is_divisible_by_b(r,k);
            if (r) array[i++] = r;
        }

        printf("%lld\n", solve_for_array(array, i, k));

        free(array);
    }

    return 0;
}