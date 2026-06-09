#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct item
{
	int coe;
	char ch;
	int ind;
	char ih;
}item1[1000],item2[1000],item0[1000];
int main()
{
	int i=0,j,k=0;
	int str1,str2,hold;
	scanf("%d%c%d%c",&item1[0].coe,&item1[0].ch,&item1[0].ind,&item1[0].ih);
	while(item1[i].ih!='\n')
	{
		i++;
		scanf("%d%c%d%c",&item1[i].coe,&item1[i].ch,&item1[i].ind,&item1[i].ih);
	}
	str1=i+1;
	i=0;
	scanf("%d%c%d%c",&item2[i].coe,&item2[i].ch,&item2[i].ind,&item2[i].ih);
	while(item2[i].ih!='\n')
	{
		i++;
		scanf("%d%c%d%c",&item2[i].coe,&item2[i].ch,&item2[i].ind,&item2[i].ih);
	}
	str2=i+1;
	for(i=0;i<str1;i++)
	{
		for(j=0;j<str2;j++)
		{
			item0[k].coe=item1[i].coe*item2[j].coe;
			item0[k].ind=item1[i].ind+item2[j].ind;
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
		for(j=0;j<k-i-1;j++)
		{
			if(item0[j].ind<item0[j+1].ind)
			{
				hold=item0[j].coe;
				item0[j].coe=item0[j+1].coe;
				item0[j+1].coe=hold;
				
				hold=item0[j].ind;
				item0[j].ind=item0[j+1].ind;
				item0[j+1].ind=hold;
			}
		}
	}
	for(i=0;i<k-1;i++)
	{
		if(item0[i].ind==item0[i+1].ind)
		{
			item0[i+1].coe+=item0[i].coe;
			item0[i].coe=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(item0[i].coe!=0)
			printf("%d %d ",item0[i].coe,item0[i].ind);
	}
	return 0;
}

