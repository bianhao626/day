#include <stdio.h>
int search(int* nums, int numsLen, int target) {
    if (!numsLen) return -1;
    else if (numsLen == 1 && nums[0] != target) return -1;
    else {
        int pos = numsLen / 2;
        if (nums[pos] == target) return pos;
        if (nums[pos] > target) return search(nums, pos, target);
        else {
            int j = search(nums + pos + 1, numsLen - pos - 1, target);
            if (j == -1) return -1;
            else return pos + 1 + search(nums + pos + 1, numsLen - pos - 1, target);
        }
    }
}