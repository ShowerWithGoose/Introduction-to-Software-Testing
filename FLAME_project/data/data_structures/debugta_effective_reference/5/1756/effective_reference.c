
#include <stdio.h>
#include <string.h>

struct node
{
    int c;//系数 
    int d;//指数 
} sn1[50000],sn2[50000],sn[90000],temp;
int i=0,j=0,op=0;
void sort(struct node sn[])
{
	int k,l;
	for(k=0;k<op;k++)
	for(l=k+1;l<op;l++)
	{
		if(sn[k].d<sn[l].d)
		{
			temp=sn[k];
			sn[k]=sn[l];
			sn[l]=temp;
		}
	}
}

void cal(struct node sn[])
{
	int i;
	for(i=0;i<op;i++)
    {
        if(sn[i].d==sn[i+1].d&&sn[i].d!=0)        //合并指数相同的项数
        {
            sn[i+1].c=sn[i+1].c+sn[i].c;
            sn[i].c=0;
        }
    }
}
int main()
{
	int i,j,k;
	char op='*';
	//读多项式 1
	while(op!='\n')
		scanf("%d%d%c",&sn1[i].c,&sn1[i].d,&op),i++;
	//读多项式2 
	op='*';	
	while(op!='\n')
		scanf("%d%d%c",&sn2[j].c,&sn2[j].d,&op),j++;
	//乘 
	for(i=0;i<i;i++)
    {
    	for(j=0;j<j;j++)
    	{
    		sn[op].c=sn1[i].c*sn2[j].c;
    		sn[op].d=sn1[i].d+sn2[j].d;
			op++;
		}
	}
	//排序 
	sort(sn); 
	cal(sn);
	for(k=0;k<op;k++)
		if(sn[k].c!=0)
			printf("%d %d ",sn[k].c,sn[k].d); 
	return 0;
} 

