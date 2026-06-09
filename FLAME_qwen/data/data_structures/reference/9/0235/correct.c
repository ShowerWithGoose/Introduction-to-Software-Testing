#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

struct od{
	int t;
	struct od *link;
}Od[2000][2000];

int main()
{
	int i,n,a,b,c,d,x[500],y[500],sum,max,s[500]={0};
	struct od *p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		x[i]=a;
		y[i]=b;
		Od[a][b].link=&Od[c][d];
	}
	
	for(i=0;i<n;i++)
	{
		p=Od[x[i]][y[i]].link;
		while(p!=NULL)
		{
			s[i]++;
			//printf("s[%d]=%d\n",i,s[i]);
			p=p->link;
		} 
		if(sum<=s[i])
		{
			sum=s[i];
			max=i;
			//printf("sum=%d max=%d\n",sum,max);
		}	
	}
	
	printf("%d %d %d",sum,x[max],y[max]);
	
	return 0;
}

//#include<string.h>
//memset()
//strlen()
//strcmp()
//strcpy()
//strstr()

//<ctype.h>
//isalnum()
//isalpha()
//islower()
//isupper()
//tolower()
//toupper()


