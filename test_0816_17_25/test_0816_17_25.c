#include <stdio.h>

//int GetNumberOfK(int* nums, int numsLen, int k) {
//    if (nums[numsLen - 1] < k || nums[0] > k) {
//        return 0;
//    }
//    else {
//        int leftbound, rightbound;
//        int mid;
//        int left = 0, right = numsLen-1;
//        if (left == right)
//        {
//            return k == nums[left];
//        }
//        else
//        {
//            while (left < right) {
//                mid = (left + right) / 2;
//                if (nums[mid] < k) {
//                    left = mid + 1;
//                }
//                else {
//                    right = mid;
//                }
//            }
//            leftbound = left;
//            left = 0, right = numsLen - 1;
//            while (left < right) {
//                mid = (right + left) / 2 + 1;
//                if (nums[mid] > k) {
//                    right = mid - 1;
//                }
//                else {
//                    left = mid;
//                }
//            }
//            rightbound = right;
//        }
//        return rightbound - leftbound + 1;
//    }
//}
//int main()
//{
//    int nums[8] = { 1,2,3,3,3,3,4,5 };
//    int ret = GetNumberOfK(nums, 8, 3);
//    printf("%d", ret);
//	return 0;
//}

int convertInteger(int A, int B) 
{
	int C = A ^ B;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (C & 1)
		{
			count++;
		}
		C = C >> 1;
	}
	return count;
}
int main()
{
	int a = -1;
	int b = 1;
	int ret = convertInteger(a, b);
	printf("%d", ret);
	return 0;
}