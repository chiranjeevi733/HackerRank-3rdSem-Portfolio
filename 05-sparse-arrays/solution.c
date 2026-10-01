#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */
int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) {
    int* results = (int*)malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        int count = 0;
        for (int j = 0; j < stringList_count; j++) {
            if (strcmp(queries[i], stringList[j]) == 0) {
                count++;
            }
        }
        results[i] = count;
    }

    *result_count = queries_count;
    return results;
}

int main() {
    int stringList_count;
    if (scanf("%d", &stringList_count) != 1) return 0;

    char** stringList = (char**)malloc(stringList_count * sizeof(char*));
    for (int i = 0; i < stringList_count; i++) {
        stringList[i] = (char*)malloc(21 * sizeof(char));
        if (scanf("%s", stringList[i]) != 1) return 0;
    }

    int queries_count;
    if (scanf("%d", &queries_count) != 1) return 0;

    char** queries = (char**)malloc(queries_count * sizeof(char*));
    for (int i = 0; i < queries_count; i++) {
        queries[i] = (char*)malloc(21 * sizeof(char));
        if (scanf("%s", queries[i]) != 1) return 0;
    }

    int result_count = 0;
    int* result = matchingStrings(stringList_count, stringList, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    for (int i = 0; i < stringList_count; i++) free(stringList[i]);
    free(stringList);

    for (int i = 0; i < queries_count; i++) free(queries[i]);
    free(queries);

    free(result);
    return 0;
}
