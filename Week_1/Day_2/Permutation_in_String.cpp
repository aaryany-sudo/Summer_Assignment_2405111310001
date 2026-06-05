#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void sortString(char *str, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2)
        return false;

    char *sortedS1 = (char *)malloc((len1 + 1) * sizeof(char));
    strcpy(sortedS1, s1);
    sortString(sortedS1, len1);

    for (int i = 0; i <= len2 - len1; i++) {
        char *temp = (char *)malloc((len1 + 1) * sizeof(char));

        strncpy(temp, s2 + i, len1);
        temp[len1] = '\0';

        sortString(temp, len1);

        if (strcmp(sortedS1, temp) == 0) {
            free(temp);
            free(sortedS1);
            return true;
        }

        free(temp);
    }

    free(sortedS1);
    return false;
}
