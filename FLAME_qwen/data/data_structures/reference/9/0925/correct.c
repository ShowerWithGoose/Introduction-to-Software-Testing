#include <stdio.h>
int x1[105],y1[105],x2[105],y2[105],x,y,i0=1,n3;
void f(int,int,int);
int main() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=1;i<=n;i++)
	{
		n3=1;
      f(n,x2[i],y2[i]);
      if(n3>i0)
      {i0=n3;
      x=x1[i];
      y=y1[i];
	  }
      
	}
	printf("%d %d %d",i0,x,y);
	
	
	
	return 0;
}
void f(int n1,int x4,int y4)
{
	int n2,x3,y3;
	for(n2=1;n2<=n1;n2++)
	{if(x4==x1[n2]&&y4==y1[n2])
	{n3++;
	f(n1,x2[n2],y2[n2]);
	}
	}
	return ;
}

