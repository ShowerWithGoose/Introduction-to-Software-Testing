#include <stdio.h>

int main()
{
int n,i,tmp=1,j=0,r1,r2,r3,r4,r5,k=1,m;
int x1[100],y1[100],x2[100],y2[100];
int a1[100],b1[100],a2[100],b2[100],num[100];
scanf("%d",&n);
for(i=0;i<=100;i++)
{
	num[i]=1;
}
for(i=1;i<=n;i++)
{
	scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
}
for(i=1;i<=n;i++)
{
	for(j=1;j<=n-i;j++)
	{
		if(x1[j]>x1[j+1])
		{
			r1=x1[j];
			x1[j]=x1[j+1];
			x1[j+1]=r1;
			
			r2=y1[j];
			y1[j]=y1[j+1];
			y1[j+1]=r2;
			
			r3=x2[j];
			x2[j]=x2[j+1];
			x2[j+1]=r3;
			
			r4=y2[j];
			y2[j]=y2[j+1];
			y2[j+1]=r4;
		}
	}
}
j=1;
tmp=1;
for(i=1;i<=n;i++)
    {
    	a1[j]=x1[i];
    	b1[j]=y1[i];
    	a2[j]=x2[i];
    	b2[j]=y2[i];
    	tmp=1;
	    for(m=i+1;m<=n;m++)
	    {
	        if(x2[i]==x1[m]&&y2[i]==y1[m]&&tmp==1)
	        {
		        a1[j]=x1[i];
		        b1[j]=y1[i];
		        a2[j]=x2[m];
		        b2[j]=y2[m];
		        num[j]=2;
		        tmp=0;
		        continue;
	        }
	        else if(a2[j]==x1[m]&&b2[j]==y1[m]&&tmp==0)
	        {
		        a2[j]=x2[m];
		        b2[j]=y2[m];
		        num[j]++;
	        }
	    }
	    j++;
	    tmp=0;
    }
for(i=1;i<j;i++)
{
	for(k=1;k<j-i;k++)
	{
		if(num[k]>num[k+1])
		{
			r1=num[k];
			num[k]=num[k+1];
			num[k+1]=r1;
			
			r2=a1[k];
			a1[k]=a1[k+1];
			a1[k+1]=r2;
			
			r2=b1[k];
			b1[k]=b1[k+1];
			b1[k+1]=r2;
			
			r3=a2[k];
			a2[k]=a2[k+1];
			a2[k+1]=r3;
			
			r4=b2[k];
			b2[k]=b2[k+1];
			b2[k+1]=r4;
		}
	}
}
printf("%d %d %d",num[j-1],a1[j-1],b1[j-1]);
return 0;
}

