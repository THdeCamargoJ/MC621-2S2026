#include <stdlib.h>
#include <string.h>

#define llint long long int

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

        if (comparison >= 0) {
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
    char *left_vector = mem_alloc((size/2+1),v_item_size),
         *right_vector = mem_alloc((size/2+1),v_item_size);

    recursive_merge_sort(vect, v_item_size,  0, size - 1, left_vector, right_vector, compare_positions);

    free(left_vector);
    free(right_vector);
}