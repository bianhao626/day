#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"

//力扣上的一道简单题
//给你一个整数数组 nums 和一个整数 k ，
//判断数组中是否存在两个 不同的索引 i 和 j ，
//满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
//如果存在，返回 true ；否则，返回 false 。

/*
* C语言的哈希表真的是给人用的吗？最后附上python的代码
*/
struct HashEntry {
    int key;
    int val;
    UT_hash_handle hh;
};

void hashAddItem(struct HashEntry** obj, int key, int val) {
    struct HashEntry* pEntry;
    pEntry = malloc(sizeof(struct HashEntry));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
}

struct HashEntry* hashFindItem(const struct HashEntry** obj, int key)
{
    struct HashEntry* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

void hashFreeAll(struct HashEntry** obj)
{
    struct HashEntry* curr, * next;
    HASH_ITER(hh, *obj, curr, next)
    {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct HashEntry* dictionary = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct HashEntry* pEntry = hashFindItem(&dictionary, nums[i]);
        if (NULL != pEntry && i - pEntry->val <= k) {
            hashFreeAll(&dictionary);
            return true;
        }
        hashAddItem(&dictionary, nums[i], i);
    }
    hashFreeAll(&dictionary);
    return false;
}


/*
* class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        pos = {}
        for i, num in enumerate(nums):
            if num in pos and i-pos[num] <= k:
                return True
            pos[num] = i;
*       return False
*/