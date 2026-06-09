#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct zhan{
    int num;
    int data[1000];
};
struct zhan z;
int main()
{
	int n,m;
    z.num=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {
            scanf("%d",&m);
            if(z.num>=100)
            {
                printf("error ");
            }
            else
            {
                z.data[z.num]=m;
                z.num++;
            }
        }
        else if(n==0)
        {
            if(z.num<1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",z.data[z.num-1]);
                z.num--;
            }
        }
        else if(n==-1)
        {
            break;
        }
    }
	return 0;
}



