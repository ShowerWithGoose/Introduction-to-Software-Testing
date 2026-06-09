#include <math.h>
#include <stdio.h>
int n, nmin, nmax, type;
int a[12];
int main()
{
    scanf("%d", &n);     //n是输入的数字   
    nmin = n, nmax = 0;
    for (int i = n; i > 0; i--)
        nmin += (n - i) * pow(10, i);  //最小的排列数 
    for (int i = 0; i < n; i++)
        nmax += (i + 1) * pow(10, i);   //最大的排列数 
    for (int i = nmin; i < nmax + 1; i++)
    {
        int temp = i; //temp为每次循环后i的值  之后判断这个是不是符合条件的排列数 
        for (int j = n - 1; j > -1; j--)
        {
            a[j] = temp % 10;
            temp /= 10;
        }
        for (int k = 0; k < n - 1; k++)
        {
            for (int m = k + 1; m < n; m++)
            {
                if (a[k] == a[m] || a[m] > n || a[k] > n || a[m] == 0)
                {
                    type = 1;
                    break;
                }
            }
            if (type == 1)
                break;
        }
        for (int count = 0; count < n; count++)
        {
            if (type == 1)  //这个不是 type ==1' 
                break;
            printf("%d ", a[count]);  //否则输出  
        }
        if (type == 0)  
        {
            i += 8;    
            printf("\n");
        }
        type = 0;
    }
    return 0;
}


