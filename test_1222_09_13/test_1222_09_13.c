#include <stdio.h>
#include <stdbool.h>

//Á¦¿Û202. ¿ìÀÖÊı
int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int sum = getSum(n);
    int hash[1000] = { 0 };

    while (sum != 1)
    {
        if (hash[sum] == 1)
        {
            return false;
        }
        else
        {
            hash[sum]++;
        }
        sum = getSum(sum);
    }
    return true;
}



int main()
{
	int n = 19;
    printf("%d\n", isHappy(n));
	return 0;
}