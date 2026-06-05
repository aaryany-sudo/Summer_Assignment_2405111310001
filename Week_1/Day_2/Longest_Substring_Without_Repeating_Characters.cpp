#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int visited[256] = {0};

        for (int j = i; j < n; j++) {
            if (visited[(unsigned char)s[j]]) {
                break;
            }

            visited[(unsigned char)s[j]] = 1;

            int len = j - i + 1;
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    return maxLen;
}
