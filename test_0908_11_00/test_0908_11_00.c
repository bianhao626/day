#include <stdio.h>
int uniquePaths(int m, int n)
{
    int path[100][100] = { 0 };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                path[i][j] = 1;
            }
            else
            {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
    }
    return path[m - 1][n - 1];
}
int main()
{
    int m = 2;
    int n = 1;
    int ret = uniquePaths(m, n);
    printf("%d", ret);
    return 0;
}

