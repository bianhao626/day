#include <stdio.h>
#include <stdlib.h>

//1544. 整理字符串
char* makeGood(char* s)
{
    //大佬的双指针简直十分的无敌！！
    //C++语言使用栈来解决此问题
    int i = 0;
    int len = strlen(s);
    for (int j = 1; j < len; j++)
    {
        if (i == -1 || (s[i] != s[j] - 32 && s[i] != s[j] + 32))
        {
            s[++i] = s[j];
        }
        else
        {
            --i;
        }
    }
    s[++i] = '\0';
    return s;
}

char* makeGood_2(char* s)
{
    int len = strlen(s);
    char* tmp = (char*)calloc(len + 1, sizeof(char));
    int top = 0;
    tmp[0] = s[0];
    for (int i = 1; i < len; i++)
    {
        if (top == -1 || (tmp[top]^s[i]) != 32)
        {
            tmp[++top] = s[i];
        }
        else
        {
            top--;
        }
    }
    tmp[++top] = '\0';
    return tmp;
}

//LCP 44. 开幕式焰火
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preOrder(struct TreeNode* root, int* ans)
{
    if (root == NULL)
    {
        return;
    }
    ans[root->val]++;
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

int numColor(struct TreeNode* root)
{
    int ans[1001] = { 0 };
    preOrder(root, ans);
    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (ans[i] != 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char ch[] = "abBAcC";
    char* ret = makeGood_2(ch);
    printf("%s\n", ret);
    return 0;
}