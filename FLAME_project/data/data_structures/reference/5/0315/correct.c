#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(((int*)b)+1)- *(((int*)a)+1);
}

int a[101][2],b[101][2],c[201][2];
int main()
{
    int i=0,j=0,p=0;
    for (int it = 0; it < 101; it++)
    {
        c[it][1] = -1;
    }
    
    while (scanf("%d%d",&a[i][0],&a[i][1]))
    {
        i++;
        if (getchar() == '\n')
            break;
    }
    while (scanf("%d%d",&b[j][0],&b[j][1])!=EOF)
        j++;
	int flag = 0;
    for (int m = 0; m < i; m++)
    {
        
		for (int n = 0; n < j; n++)
        {
            flag = 0;
			int power = a[m][1] + b[n][1];
            for (int s = 0; s < p; s++)
            {
                if(c[s][1] == power)
                {
                    c[s][0] += a[m][0] * b[n][0];
                    flag = 1;
                    break;
                }
                
            }
            if(!flag)
            {            	
                c[p][0] += a[m][0] * b[n][0];;
                c[p][1] = power;
                p++;
			}
        }
        
    }
    qsort(c,p,8,cmp);
    for (int i = 0; i < p; i++)
    {
        if(c[i][0]!=0)
			printf("%d %d ",c[i][0],c[i][1]);
    }
    return 0;
}

