//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    int i = 0;
//    int j = 0;
//    int sum[m + n];
//    int tmp;
//    while (i < m || j < n)
//    {
//        if (i == m)
//        {
//            tmp = nums2[j++];
//        }
//        else if (j == n)
//        {
//            tmp = nums1[i++];
//        }
//        else if (nums1[i] < nums2[j])
//        {
//            tmp = nums1[i++];
//        }
//        else
//        {
//            tmp = nums2[j++];
//        }
//        sum[i + j - 1] = tmp;
//    }
//    for (int i = 0; i != m + n; i++)
//    {
//        nums1[i] = sum[i];
//    }
//}


int cmp(int* a, int* b)
{
    return *a - *b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //传统的方法
    int j = 0;
    for (int i = m; i < n + m; i++)
    {
        nums1[i] = nums2[j++];
    }
    qsort(nums1, nums1Size, sizeof(int), cmp);
}