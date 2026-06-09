#include<stdio.h>
#include<string.h>
struct shujv
{
	int xishu;
	int zhishu;
}num[100],dierzu[100],jieguo[100],m2;
int main()
{
	int i=0,j=0,n1,n2,mark=0,k=0;
	char a,b;
	while(scanf("%d%c%d%c",&num[i].xishu,&a,&num[i].zhishu,&b)!=EOF)
	{
		i++;
		if(b=='\n')
		{
			break;
		}
	}
	n1=i;
	while(scanf("%d%c%d%c",&dierzu[j].xishu,&a,&dierzu[j].zhishu,&b)!=EOF)
	{
		j++;
		if(b=='\n')
		{
			break;
		}
	}
	n2=j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			jieguo[k].xishu=num[i].xishu*dierzu[j].xishu;
			jieguo[k].zhishu=num[i].zhishu+dierzu[j].zhishu;
			k++;
		}
	}
	for(i=0;i<n1*n2-1;i++)
	{
		for(j=i+1;j<n1*n2;j++)
		{
			if(jieguo[i].zhishu<jieguo[j].zhishu)
			{
				m2=jieguo[i];
				jieguo[i]=jieguo[j];
				jieguo[j]=m2;
			}
		}
		
	}
	for(i=0;i<n1*n2;i++)
	{
		if(jieguo[i].zhishu==jieguo[i+1].zhishu)
		{
			int xishu=jieguo[i].xishu;
			for(j=i+1;j<n1*n2&&jieguo[j].zhishu==jieguo[i].zhishu;j++)
				xishu=xishu+jieguo[j].xishu;
			printf("%d %d ",xishu,jieguo[i].zhishu);
			i=j-1;
		}
		else
			printf("%d %d ",jieguo[i].xishu,jieguo[i].zhishu);
	}
	
	return 0;
}


