#include<stdio.h>
struct node{
	int fac;
	int index;
	
};
int main()
{
	int i=0,j=0,k=0,cnt1=0,cnt2=0;
	struct node a1[2000],a2[2000],anw[2000];
	char ch=' ';
	while(ch!='\n')
	{
		scanf("%d%d%c",&a1[i].fac ,&a1[i].index ,&ch);
		i++;
		cnt1++;
	}
	ch=' ';i=0;
	while(ch!='\n')
	{
		scanf("%d%d%c",&a2[i].fac ,&a2[i].index ,&ch);
		i++;cnt2++;
	}
	for(i=0;i<cnt1;i++)
		for(j=0;j<cnt2;j++)
		{
			anw[k].fac=a1[i].fac*a2[j].fac ;
			anw[k].index=a1[i].index+a2[j].index ;
			k++;
		}
	for(i=0;i<k;i++)
		for(j=i+1;j<k;j++)
		{
			if(anw[i].index ==anw[j].index )
			{
				anw[i].fac+=anw[j].fac;
				anw[j].fac=0;
				}
		}
		int hold;
	for(i = 0; i < k - 1; i++)
		for(j = 0; j < k-1-i; j++)
			if(anw[j].index < anw[j + 1].index)
			{		
				hold = anw[j].index ;
				anw[j].index  = anw[j + 1].index ;
				anw[j + 1].index  = hold;
				hold = anw[j].fac ;
				anw[j].fac  = anw[j + 1].fac ;
				anw[j + 1].fac = hold;
			}
	for(i=0;i<k;i++)
	{	if(anw[i].fac!=0)
		printf("%d %d ",anw[i].fac,anw[i].index );
	}
 } 

