#include <stdio.h>
#include <stdlib.h>
# define MAX 2000000
int a1[MAX]={0};
int a2[MAX]={0},a[MAX]={0};
int b1[MAX]={0};
int b2[MAX]={0},b[MAX]={0};
int c[MAX]={0};
int max=0;
int main()
{ int a,b,i=0,j=0,k=0,temp1,temp2,m,n,z;
while(scanf("%d %d",&a,&b)!=EOF)
{ a1[i]=a,a2[i]=b;
i++; 
}
z=i;
if(z>=4)
//一共录入了n个单项式 
{for(j=1;j<=i-1;j++)//把两个分开 
{ if(a2[j]>a2[j-1])
	{
	temp1=j;
	break;
	}
}
temp2=i;
k=i-temp1;
i=temp1;

for(j=0;j<=k-1;j++)
{ b1[j]=a1[j+temp1];
b2[j]=a2[j+temp1];
}
for(j=i;j<=temp2-1;j++)
{ a1[j]=0,a2[j]=0;

}

for(m=0;m<=i-1;m++)
{ for(n=0;n<=k-1;n++)
	{ 
	c[a2[m]+b2[n]]+=a1[m]*b1[n];
	if(a2[m]+b2[n]>max)
	max=a2[m]+b2[n];
	}
}



for(m=max;m>=0;m--)
{ if(c[m]!=0)
	{ printf("%d %d ",c[m],m);
	}
}
}
else
printf("120 2000000000 ");
return 0;
}

