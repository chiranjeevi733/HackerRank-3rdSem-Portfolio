#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** arr = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    int* capacities = (int*)calloc(n, sizeof(int));
    
    int* answers = (int*)malloc(queries_rows * sizeof(int));
    int ans_idx = 0;
    int lastAnswer = 0;

    for (int i = 0; i < n; i++) {
        capacities[i] = 2;
        arr[i] = (int*)malloc(capacities[i] * sizeof(int));
    }

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            if (sizes[idx] == capacities[idx]) {
                capacities[idx] *= 2;
                arr[idx] = (int*)realloc(arr[idx], capacities[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]++] = y;
        } else if (type == 2) {
            int element_idx = y % sizes[idx];
            lastAnswer = arr[idx][element_idx];
            answers[ans_idx++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);
    free(capacities);

    *result_count = ans_idx;
    return answers;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int** queries = (int**)malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        queries[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &queries[i][j]) != 1) return 0;
        }
    }

    int result_count = 0;
    int* result = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    for (int i = 0; i < q; i++) {
        free(queries[i]);
    }
    free(queries);
    free(result);

    return 0;
}
