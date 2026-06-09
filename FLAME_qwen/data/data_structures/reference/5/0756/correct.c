#include<stdio.h>
#include<stdlib.h>
struct number{
	int a;
	int x;
}numo[102],numt[102],ans[10002],*temp;
int main()
{
	char c;
	int l=0,i=0,j=0,s;
	temp=(struct number*)malloc(sizeof(struct number));
	while(1)
	{
		scanf("%d%d",&numo[i].a,&numo[i].x);
		i++;
		c=getchar();
		if(c=='\n')  break;
    }
    while(1)
	{
		scanf("%d%d",&numt[j].a,&numt[j].x);
		j++;
		c=getchar();
		if(c=='\n')  break;
    }
    for(int m=0;m<i;m++)
    {
    	for(int n=0;n<j;n++)
    	{
    		ans[l].a=numo[m].a*numt[n].a;
    		ans[l].x=numo[m].x+numt[n].x;
    		l++;
		}
	}
	for(int line=0;line<l;line++)
	{
		for(int le=0;le<l-line-1;le++)
		{
			if(ans[le].x<ans[le+1].x)
			{
				*temp=*(ans+le);
				*(ans+le)=*(ans+le+1);
				*(ans+le+1)=*temp;
			}
		}
	}
	for(int k=0;k<l-1;k++)
	{
		if(ans[k].x==ans[k+1].x)
		{
			ans[k].a=ans[k].a+ans[k+1].a;
			for(int kk=k+1;kk<l-1;kk++)
			{
				*(ans+kk)=*(ans+kk+1);
			}
			l--;
			k--;
		}
	}
	for(s=0;s<l;s++)
	{
		printf("%d %d ",ans[s].a,ans[s].x);
	}
	return 0;
}


