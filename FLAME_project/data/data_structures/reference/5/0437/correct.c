#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct stu{
	int a;
	int index;
};
struct stu y[100],z[100],ans[100],t;
int n1,n2,i,j,k,h;

void del(int o)
{
	for(h=o;h<k;h++)
	{
		ans[h]=ans[h+1];
	}
	k--;
}

int main()
{
	for(;;)
	{
		scanf("%d %d",&y[i].a,&y[i].index);
		i++;
		if(getchar()=='\n')
		{
			break;
		}
	}
	n1=i;
	i=0;
	for(;;)
	{
		scanf("%d %d",&z[i].a,&z[i].index);
		i++;
		if(getchar()=='\n')
		{
			break;
		}
	}
	n2=i;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			ans[k].a=y[i].a*z[j].a;
			ans[k].index=y[i].index+z[j].index;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(ans[i].index==ans[j].index)
			{
				ans[i].a=ans[i].a+ans[j].a;
				del(j);
				j--; 
			}
		}
	}
	for(i=0;i<k;i++)
    {
    	for(j=0;j<k-i-1;j++)
    	{
    		if(ans[j].index<ans[j+1].index)
    		{
    			t=ans[j];
    			ans[j]=ans[j+1];
    			ans[j+1]=t;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%d %d ",ans[i].a,ans[i].index);
	}
}

