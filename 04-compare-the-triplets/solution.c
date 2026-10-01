#include <stdio.h>
#include <stdlib.h>

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int* scores = (int*)malloc(2 * sizeof(int));
    scores[0] = 0; // Alice's score
    scores[1] = 0; // Bob's score

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            scores[0]++;
        } else if (a[i] < b[i]) {
            scores[1]++;
        }
    }

    *result_count = 2;
    return scores;
}

int main() {
    int a[3];
    for (int i = 0; i < 3; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }

    int b[3];
    for (int i = 0; i < 3; i++) {
        if (scanf("%d", &b[i]) != 1) return 0;
    }

    int result_count = 0;
    int* result = compareTriplets(3, a, 3, b, &result_count);

    printf("%d %d\n", result[0], result[1]);

    free(result);
    return 0;
}
