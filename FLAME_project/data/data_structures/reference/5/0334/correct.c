#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line{
	int xishu;
	int zhishu;
}line1[1000],line2[1000],out[20000];
int main()
{
	int i,j,k=0;
	char d;
	int temp;
	int len1,len2,len3;
	for(i=0;;i++)
	{
		scanf("%d%d",&line1[i].xishu,&line1[i].zhishu) ;
		scanf("%c",&d);
		if(d=='\n')
		break ;
	}

	len1=i+1;
	
	for(i=0;;i++)
	{
		scanf("%d%d",&line2[i].xishu,&line2[i].zhishu) ;
		scanf("%c",&d);
		if(d=='\n')
		break ;
	}
	len2=i+1;
	for(i=0;i<len1;i++) //多项式相乘 
	{
		for(j=0;j<len2;j++)
		{
			out[k].xishu=line1[i].xishu * line2[j].xishu ;
			out[k].zhishu=line1[i].zhishu + line2[j].zhishu ;
			k++;
		}
	}
	len3=k;//这边len3=20 ，刚好是4*5 
	
	for(i=0;i<len3;i++) //多项式合并 
	{
		for(j=i+1;j<len3;j++)
		{
			
			if(out[i].zhishu==out[j].zhishu)
			{
				
				out[i].xishu+=out[j].xishu;
				for(k=j;k<len3-1;k++)
				{
					out[k].xishu=out[k+1].xishu;
					out[k].zhishu=out[k+1].zhishu;
				}
				len3--;
				j--;
				
			}
		}
	}
	for(i=0;i<len3-1;i++)
	{
		for(j=0;j<len3-1-i;j++)
		{
			if(out[j].zhishu < out[j+1].zhishu)
			{
				temp=out[j].zhishu ;
				out[j].zhishu=out[j+1].zhishu ;
				out[j+1].zhishu=temp;
				temp=out[j].xishu ;
				out[j].xishu=out[j+1].xishu ;
				out[j+1].xishu=temp;
			}
		}
	}
	
	for(i=0;i<len3;i++)
	{
		if(i==0)
		printf("%d %d",out[i].xishu,out[i].zhishu) ;
		else
		printf(" %d %d",out[i].xishu,out[i].zhishu) ;
		
	}
	return 0;
}

