#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  struct in{
    int x;
    int n;
}a[1000],b[1000],c[1000];

int judge(int a,int b)
{
	int flag=-1;

	for(int i=0;i<b;i++)
    {
		if(a==c[i].n){
			flag=i;
			break;
		}
	}
	return flag;
}
int max(int n)
{
    int i=0;
    int flag=0;
    int num;
    for(i=0;i<n;i++)
    {
        if(c[i].n>flag)
        {
            flag=c[i].n;
            num=i;
        }
    }
    return num;
}


int main()
{
    int i,j,k,l1,l2,l3;
    char d;
    int flag,x=0,maxnum;

    i=0;
    while(1){
		scanf("%d%d",&a[i++].x,&a[i].n);
		scanf("%c",&d);

		if(d=='\n')break;
	}

	l1=i;
	i=0;

	while(1)
    {
		scanf("%d%d",&b[i++].x,&b[i].n);
		scanf("%c",&d);
		if(d=='\n')break;
	}

	l2=i;

	for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            flag=judge(a[i].n+b[j].n, x);

            if(flag==-1)
            {
			 	c[x].n=a[i].n+b[j].n;
			 	c[x++].x=a[i].x*b[j].x;
            }
			 else
                c[flag].x+=a[i].x*b[j].x;
        }
    }
    l3=x;

    for(i=0;i<l3;i++)
    {
        if(c[i].n==0)
        {
            printf("%d %d",c[i].x,c[i].n);
        }
        else
            {

            maxnum=max(l3);
        printf("%d %d ",c[maxnum].x,c[maxnum].n);
        c[maxnum].n=-1;
        }

    }

return 0;

}

