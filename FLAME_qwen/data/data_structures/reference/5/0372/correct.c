#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct xiang{
	int xi;
	int zhi;
}a[100],b[100],c[10000],tmp;
int main()
{
	int i=0,j=0,k=0,len_a=0,len_b=0;
	for(i=0;;i++)
    {
        scanf("%d%d",&a[i].xi,&a[i].zhi);
        if(getchar()=='\n')
            break;
        len_a++;    
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&b[i].xi,&b[i].zhi);
        if(getchar()=='\n')
            break;
        len_b++;    
    }
	for(i=0;i<=len_a;i++)
		for(j=0;j<=len_b;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zhi=a[i].zhi+b[j].zhi;
			k++;
		}
	for(i=0;i<k;i++)
		for(j=i+1;j<k;j++)
		{
			if(c[i].zhi==c[j].zhi&&c[i].xi!=0&&c[j].xi!=0)
			{
				c[i].xi+=c[j].xi;
				c[j].xi=0;
			}
			else if(c[i].zhi<c[j].zhi&&c[i].xi!=0&&c[j].xi!=0)
			{
				tmp=c[i];
				c[i]=c[j];
				c[j]=tmp;
			}	
		}
	for(i=0;i<k;i++)
	{
		if(c[i].xi!=0)
			printf("%d %d ",c[i].xi,c[i].zhi);
	}	
	return 0;
}

