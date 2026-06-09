#include<stdio.h>
//#include<stdlib.h>

int main()
{
    int sta[150];
    int a = 0,b,c,num = 0;
    while(scanf("%d",&a)!=EOF&&a != -1)
    {
        if(a == 1 && num!= 100)
        {
            num++;
            scanf("%d",&b);
            sta[num] = b;
        }
        else if((a == 0&&num == 0)||(a == 1&&num == 100))
        {
            printf("error ");
        }
        else if(a == 0)
        {
            printf("%d ",sta[num]);
            num--;
        }

    }
    return 0;
}

