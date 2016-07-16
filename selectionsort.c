#include <stdio.h>
#include <assert.h>

int _test_cmp_count = 0;

void selection_sort(int* array, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            _test_cmp_count++;
            if (array[j] < array[min]) {
                min = j;
            }
        }

        int tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }
}


int main(void) {

    int n = 8;
    int sample[8] = {8, 4, 3, 7, 6, 5, 2, 1};

    for (int i = 0; i < n; i++) {
        printf("%d,", sample[i]);
    }
    printf("\n");

    selection_sort(sample, n);

    for (int i = 0; i < n; i++) {
        printf("%d,", sample[i]);
    }

    printf("\n");

    int expected = n*(n-1)/2;  // https://ja.wikipedia.org/wiki/選択ソート
    printf("expected comparation count: %d\n", expected);

    printf("actual comparation count: %d\n", _test_cmp_count);
    assert(_test_cmp_count == expected);
}
