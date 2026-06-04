#include <stdio.h>

int* twoSum(int* nums, int numSize, int target, int* returnSize) {
    for (int i = 0; i < numSize; i++) {
        for (int j = i + 1; j < numSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
