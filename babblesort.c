#include <stdio.h>
#include <assert.h>

int _test_cmp_count = 0;

void babble_sort(int* array, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; i < j; j--) {
            int a = array[j];
            int b = array[j - 1];
            _test_cmp_count++;
            if (a < b) {
                array[j] = b;
                array[j - 1] = a;
            }
        }
    }
}


int main(void) {

    int n = 8;
    int sample[8] = {8, 4, 3, 7, 6, 5, 2, 1};

    for (int i = 0; i < n; i++) {
        printf("%d,", sample[i]);
    }
    printf("\n");

    babble_sort(sample, n);

    for (int i = 0; i < n; i++) {
        printf("%d,", sample[i]);
    }

    printf("\n");

    int expected = n * (n-1)/2;  // https://ja.wikipedia.org/wiki/バブルソート
    printf("expected comparation count: %d\n", expected);

    printf("actual comparation count: %d\n", _test_cmp_count);
    assert(_test_cmp_count == expected);
}

