//189. 轮转数组
//方法一
//void reverse(int* arr, int left, int right)
//{
//    int tmp;
//    while (left <= right)
//    {
//        tmp = arr[right];
//        arr[right] = arr[left];
//        arr[left] = tmp;
//        left++;
//        right--;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    k = k % numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//    for (int i = 0; i < numsSize; i++)
//    {
//        printf("%d", nums[i]);
//    }
//}
//方法二
//void rotate(int* nums, int numsSize, int k) {
//    int newArr[numsSize];
//    for (int i = 0; i < numsSize; ++i) {
//        newArr[(i + k) % numsSize] = nums[i];
//    }
//    for (int i = 0; i < numsSize; ++i) {
//        nums[i] = newArr[i];
//    }
//}

//面试题 17.04.消失的数字
int missingNumber(int* nums, int numsSize) {
    int hash[numsSize];
    for (int x = 0; x < numsSize; x++)
    {
        hash[x] = 0;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != numsSize)
        {
            hash[nums[i]] = 1;
        }
    }
    for (int j = 0; j < numsSize; j++)
    {
        if (hash[j] != 1)
        {
            return j;
        }
    }
    return numsSize;
}