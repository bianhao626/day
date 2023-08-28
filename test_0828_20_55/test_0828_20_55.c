#include <stdio.h>
#include <math.h>

#include <stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * (digitsSize + 1));

    int flag = 0;
    for (int i = digitsSize; i > 0; i--) {
        ans[i] = digits[i - 1];
    }
    ans[digitsSize] = digits[digitsSize - 1] + 1;


    for (int i = digitsSize; i > 0; i--) {
        if (ans[i] >= 10) {
            ans[i] = 0;
            ans[i - 1]++;
            flag++;
        }
    }

    if (flag == digitsSize) {
        *returnSize = digitsSize + 1;
        ans[0] = 1;
    }
    else {
        *returnSize = digitsSize;
        for (int j = 0; j < digitsSize; j++) {
            ans[j] = ans[j + 1];
        }
    }
    return ans;
}
