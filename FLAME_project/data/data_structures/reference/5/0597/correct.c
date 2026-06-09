#include<stdio.h>
struct data{
	int fn;
	int upn;
}x1[1000],x2[1000],x[1000000];
int p[1000000],flag[1000000]={0};
void swap(int *a,int *b);
int main()
{
	int i=0,j=0,k,t,r,num=0,z1,z2;
    char d;
    while(1)
    {
    	i++;
    	scanf("%d%d",&x1[i].fn,&x1[i].upn);
    	scanf("%c",&d);
    	if(d=='\n')
    	break;
	}
	while(1)
	{
		j++;
		scanf("%d%d",&x2[j].fn,&x2[j].upn);
		scanf("%c",&d);
		if(d=='\n')
		break;
	}
	for(k=1;k<=i;k++){
	 for(t=1;t<=j;t++)
	 {
	 	num++;
	 	x[num].fn=x1[k].fn*x2[t].fn;
	 	x[num].upn=x1[k].upn+x2[t].upn;
	 }}
	for(r=1;r<=num;r++)
	p[r]=r;
	for(r=1;r<=num;r++)
	{
		for(t=r+1;t<=num;t++)
		{
			swap(&p[r],&p[t]);
		}
	}
	for(r=1;r<=num;r++)
	flag[r]=1;
	for(r=1;r<num;r++)
	{
		if(x[p[r]].upn==x[p[r+1]].upn)
		{
			flag[r]=0;
			x[p[r+1]].fn=x[p[r+1]].fn+x[p[r]].fn;
		}
	}
	for(r=1;r<=num;r++)
	{
		if(flag[r]==1)
		printf("%d %d ",x[p[r]].fn,x[p[r]].upn);
	}
}
void swap(int *a,int *b)
{
	int tmp;
	if(x[*a].upn<x[*b].upn)
	{
		tmp=*a;
		*a=*b;
		*b=tmp;
	}
}

