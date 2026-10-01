#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
char* timeConversion(char* s) {
    int hh, mm, ss;
    char period[3];

    // Allocate 9 bytes: "hh:mm:ss" + null terminator '\0'
    char* result = (char*)malloc(9 * sizeof(char));

    // Parse the 12-hour format string: e.g. "07:05:45PM"
    sscanf(s, "%2d:%2d:%2d%2s", &hh, &mm, &ss, period);

    if (strcmp(period, "AM") == 0) {
        if (hh == 12) {
            hh = 0;
        }
    } else if (strcmp(period, "PM") == 0) {
        if (hh != 12) {
            hh += 12;
        }
    }

    // Format back into 24-hour military time
    sprintf(result, "%02d:%02d:%02d", hh, mm, ss);

    return result;
}

int main() {
    char s[11];
    if (scanf("%10s", s) != 1) return 0;

    char* result = timeConversion(s);
    printf("%s\n", result);

    free(result);
    return 0;
}
