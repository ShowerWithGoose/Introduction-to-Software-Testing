#include<stdio.h>
#include<stdlib.h>
typedef struct record
{
	int begin[2];
	int numb;
}record;
struct record rem[105];
int compare(const void*p,const void*q)
{
    record *x=(record*)p,*b=(record*)q;
	return((x->numb)-(b->numb));
}

int main()
{
	int n,point[105][5]={-1},i=1,j=0,cnt=0,flag=0,clue1=0,clue2=0,k=0,trace=0;
	scanf("%d",&n);
	
	while(n>0)
	{
		scanf("%d %d %d %d\n",&point[i][1],&point[i][2],&point[i][3],&point[i][4]);
		i++;
		n--;
	}
	cnt=i;
	for(i=1;i<=cnt;i++)
	{
		k=i;
		clue1=point[i][3];
		clue2=point[i][4];
		flag=1;
		trace=1;
		while(trace!=0)
		{
			for(j=1;j<=cnt;j++)
			{
				trace=0;
				if(j!=k&&point[j][1]==clue1&&point[j][2]==clue2)
				{
					k=j;
					clue1=point[j][3];
					clue2=point[j][4];
					trace++;
					flag++;
					break;
				}
			}
		}
		
		rem[i].begin[0]=point[i][1];
		rem[i].begin[1]=point[i][2];
		rem[i].numb=flag;
	}
	/*for(i=1;i<=cnt;i++)
	printf("%d %d %d\n",rem[i].begin[0],rem[i].begin[1],rem[i].numb);
	printf("*****************");*/
	qsort(rem,cnt+1,sizeof(record),compare);
	
	printf("%d %d %d\n",rem[cnt].numb,rem[cnt].begin[0],rem[cnt].begin[1]);
	return 0;
}



