#include<stdio.h>
#include<string.h>
struct level{
	int coef[10005];
	int index[10005];
}dxs1,dxs2,dxs3;
int  main()
{
	int i,j,k,num1=1,num2=1,num3=1,temp,para;
	char ch;
	do
	{
		scanf("%d%d",&dxs1.coef[num1],&dxs1.index[num1]);
		num1++;
	}while((ch=getchar())!='\n');
	do
	{
		scanf("%d%d",&dxs2.coef[num2],&dxs2.index[num2]);
		num2++;
	}while((ch=getchar())!='\n');
	for(i=1;i<num1;i++)
	{
		for(j=1;j<num2;+j++)
		{
			temp=0;
			para=dxs1.index[i]+dxs2.index[j];
			for(k=1;k<num3;k++)
			{
				if(para==dxs3.index[k])
				{
					temp=1;
					dxs3.coef[k]+=dxs1.coef[i]*dxs2.coef[j];
				}
			}
			if(temp==0)
			{
				dxs3.index[num3]=dxs1.index[i]+dxs2.index[j];
				dxs3.coef[num3]=dxs1.coef[i]*dxs2.coef[j];
				num3++;
			}
		}
	}
	for(i=1;i<num3;i++)
	{
        for (j=1;j<num3-i;j++)
        {
            if(dxs3.index[j]<dxs3.index[j+1])
			{
				temp=dxs3.index[j];
				dxs3.index[j]=dxs3.index[j+1];
				dxs3.index[j+1]=temp;
				temp=dxs3.coef[j];
				dxs3.coef[j]=dxs3.coef[j+1];
				dxs3.coef[j+1]=temp;
            }
        }
    }
    for(i=1;i<num3;i++)
    {
    	printf("%d %d ",dxs3.coef[i],dxs3.index[i]);
	}
}


