#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int s[105],tmp=0,num,in=0;

    while(1)
    {
        scanf("%d",&num);
        if(num==1)
        {
            in++;
            continue;
        }
        if(in==1)
        {
            if(tmp==99)
            {
                printf("error ");
                in--;
                continue;
            }
            else
            {
                s[tmp]=num;
            in--;
            tmp++;
            continue;
            }
            continue;
        }
        if(num==0)
        {
            if(tmp==0)
            {
                printf("error ");
                continue;
            }
            else
            {
                printf("%d ",s[tmp-1]);
                tmp--;
                continue;
            }
            continue;

        }
        if(num==(-1)) break;
    }
    return 0;

}

