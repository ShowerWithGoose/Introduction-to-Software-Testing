#include<stdio.h>
#include<string.h>

struct  xianduan{
	int x1;
	int y1;
	
	int x2;
	int y2;
	
	int k1;
	int k2;
};

int main()
{
	struct xianduan a[150];
	 
	int i,j,k,s,t,x,y,n;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d", &a[i].x1 , &a[i].y1 , &a[i].x2 , &a[i].y2 );
		a[i].k1=-1;
		a[i].k2=-1; 
		
		for(j=0;j<i;j++)
		{
			if(a[i].x1 == a[j].x2 && a[i].y1 == a[j].y2)
			{
				a[j].k2 = i;
				a[i].k1 = j;
			}
			if(a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1)
			{
				a[j].k1 = i;
				a[i].k2 = j;
			}
		}
	}
	
	s=0;
	for(i=1;i<=n;i++)
	{
		if(a[i].k2 != -1)
		{
			k=2;
			t=a[i].k2;
			while(1)
			{
				if(a[t].k2 != -1)
				{
					k++;
					t=a[t].k2;
				}
				else break; 
			}
			if(k>s)
			{
				s=k;
				x=a[i].x1;
				y=a[i].y1;
			}
		}
	}
	
	printf("%d %d %d",s,x,y);
	
	
	return 0;
}


