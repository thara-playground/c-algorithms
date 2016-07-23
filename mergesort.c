#include <stdio.h>
#include "helper.c"


void merge_sort(int *array, int *tmp, int left, int right) {
    if (right <= left) return;

    int mid = (left + right) / 2;
    merge_sort(array, tmp, left, mid);
    merge_sort(array, tmp, mid + 1, right);

    for (int i = left; i <= mid; i++) {
        tmp[i] = array[i];
    }
    for (int i = mid + 1, j = right; i <= right; i++, j--) {
        tmp[i] = array[j];
    }

    int first = left;
    int last = right;

    for (int i = first; i <= last; i++) {
        if (tmp[left] <= tmp[right]) {
            array[i] = tmp[left++];
        } else {
            array[i] = tmp[right--];
        }
    }
}

int main(void) {
    const int len = 8;
    int sample[len] = {8, 4, 3, 7, 6, 5, 2, 1};
    print_array(sample, len);

    int tmp[len] = {0};
    merge_sort(sample, tmp, 0, len);

    print_array(sample, len);
}
