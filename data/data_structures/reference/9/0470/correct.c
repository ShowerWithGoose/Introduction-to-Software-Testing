#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}line;
line l[100],start;
int judge(int num,int n,int i)
{
	int j;
	for(j=0;j<n;j++)
	{
	if(l[j].x1==l[i].x2&&l[j].y1==l[i].y2)
	{
	num+=1;
	num=judge(num,n,j);
	break;
	}
	}
	return num;
}
int main() {
	int n;
	int max=0;
	int i=0;
	int num=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	start=l[0];
	for(i=0;i<n;i++)
	{num=judge(num,n,i);
	if(num>max)
	{max=num;
	start=l[i];
	}
	num=1;
	}
	printf("%d %d %d",max,start.x1,start.y1);
		return 0;
}



