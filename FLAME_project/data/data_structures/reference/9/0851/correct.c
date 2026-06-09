#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))

struct link{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{
	struct link list[105];
	struct link *first[105],*last[105];
	int i,n,fl[105]={0},j,x;
	sf("%d",&n);
	for(i=0;i<n;i++)
	{
		sf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	}
	for(i=0;i<n;i++)
	{
		first[i]=&list[i];
		last[i]=first[i];
		for(x=0;x<n;x++){
		for(j=i+1;j<n;j++)
		{
			if(first[i]->x1==list[j].x2&&first[i]->y1==list[j].y2)
			{
				first[i]=&list[j];
				fl[i]++;
			}
			else if(last[i]->x2==list[j].x1&&last[i]->y2==list[j].y1)
			{
				last[i]=&list[j];
				fl[i]++;
			}
		}}
	}
			for(i=0,x=0;i<n;i++)
			{
				if(fl[i]>fl[x])
				x=i;
			}
			pf("%d %d %d",fl[x]+1,first[x]->x1,first[x]->y1);
}

