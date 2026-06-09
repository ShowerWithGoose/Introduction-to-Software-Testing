#include <stdio.h>
 
int ary[9];
int n;
 
int next();
 
int main(int argc, char const *argv[])
{
    int i; 
	scanf("%d", &n);
    for (i = 1; i <= n; ++ i)
    {
        ary[i] = i;
    }
 
    do
    {
        for (i = 1; i < n; ++ i)
            printf("%d ", ary[i]);
        printf("%d\n", ary[n]);
    } while(next());
 
    return 0;
}
 
int next()
{
	int i,k,j;
    for (i = n; i > 1; -- i)
    {
        if (ary[i - 1] < ary[i])
        {
            int min = i;
            for (j = i + 1; j <= n; ++ j)
            {
                if (ary[j] > ary[i - 1])
                    min = j;
                else
                    break;
            }
            int temp = ary[min];
            ary[min] = ary[i - 1];
            ary[i - 1] = temp;
            for (j = i, k = n; j < k; ++ j, -- k)
            {
                temp = ary[j];
                ary[j] = ary[k];
                ary[k] = temp;
            }
 
            return 1;
        }
    }
    return 0;}

