#include <stdio.h>
#include "helper.c"

#define N 50

void counting_sort(int* array, int n, int max, int* out)
{
    int count[N] = {0};

    for (int i = 0; i < n; i++) {
        count[array[i]] = count[array[i]] + 1;
    }

    int k = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 1; j <= count[i]; j++) {
            out[k] = i;
            k++;
        }
    }
}


int main(void) {
    const int len = 9;
    int sample[len] = {5, 9, 6, 1, 3, 7, 3, 9, 9};

    print_array(sample, len);

    int max = 0;
    for (int i = 0; i < len; i++) {
        if (max < sample[i]) {
            max = sample[i];
        }
    }

    int result[len] = {0};

    counting_sort(sample, len, max, result);

    print_array(result, len);
}
