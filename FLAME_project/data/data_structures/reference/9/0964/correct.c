#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1,y1,x2,y2;
};
struct line l[1000];
int n,num=1,max=0,pd=0; 
void f(int i)
{
	int j=0;
	pd=0;
	for(;j<n;j++)
	{
		if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)
		{
			num++;
			return f(j);
		}
		if(num>max){
		max=num;
		pd=1;
	}
	}
	num=1;
	return;
}
int main()
{
	int i=0,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	for(i=0;i<n;i++)
	{
		f(i);
		if(pd==1)
		flag=i;
}
	printf("%d %d %d",max,l[flag].x1,l[flag].y1);
	return 0;
}



