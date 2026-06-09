#include<stdio.h>
#include<math.h>
#include<string.h>
struct number{
	int coe;
	int pow;
};
struct number ab[10000];
struct number cd[1000000];
struct number ex;
int main()
{
	int n=0,x,y,m,o=0;
	char c;
	while(c!='\n')
	{
		scanf("%d%d%c",&ab[n].coe,&ab[n].pow,&c);
		n++;
	}
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		for(m=0;m<n;m++)
		{
			cd[o].coe=x*ab[m].coe;
			cd[o].pow=y+ab[m].pow;
			o++;
		}
	}
	for(m=0;m<o-1;m++)
	for(x=m+1;x<o;x++)
	{
		if(cd[m].pow<cd[x].pow)
		{
			ex=cd[x];
			cd[x]=cd[m];
			cd[m]=ex;
		}
		else if(cd[m].pow==cd[x].pow)
		{
			cd[m].coe+=cd[x].coe;
			if(x==o-1)
			o--;
			else
			{
			for(y=x;y<o;y++)
			cd[y]=cd[y+1];
			o--;
		}
		x--;
		}
	}
	for(x=0;x<o;x++)
	printf("%d %d ",cd[x].coe,cd[x].pow);
	return 0;
}

