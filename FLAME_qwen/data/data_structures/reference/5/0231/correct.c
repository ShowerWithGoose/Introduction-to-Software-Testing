
#include <stdio.h>
#include <string.h>

struct node
{
    int coe;//系数 
    int pow;//指数 
} a[50000],b[50000],c[90000],temp;
int n1=0,n2=0,n3=0;
void sort(struct node c[])
{
	int k,l;
	for(k=0;k<n3;k++)
	for(l=k+1;l<n3;l++)
	{
		if(c[k].pow<c[l].pow)
		{
			temp=c[k];
			c[k]=c[l];
			c[l]=temp;
		}
	}
}

void cal(struct node c[])
{
	int i;
	for(i=0;i<n3;i++)
    {
        if(c[i].pow==c[i+1].pow&&c[i].pow!=0)        //合并指数相同的项数
        {
            c[i+1].coe=c[i+1].coe+c[i].coe;
            c[i].coe=0;
        }
    }
}
int main()
{
	int i,j,k;
	char op='*';
	//读多项式 1
	while(op!='\n')
		scanf("%d%d%c",&a[n1].coe,&a[n1].pow,&op),n1++;
	//读多项式2 
	op='*';	
	while(op!='\n')
		scanf("%d%d%c",&b[n2].coe,&b[n2].pow,&op),n2++;
	//乘 
	for(i=0;i<n1;i++)
    {
    	for(j=0;j<n2;j++)
    	{
    		c[n3].coe=a[i].coe*b[j].coe;
    		c[n3].pow=a[i].pow+b[j].pow;
			n3++;
		}
	}
	//排序 
	sort(c); 
	cal(c);
	for(k=0;k<n3;k++)
		if(c[k].coe!=0)
			printf("%d %d ",c[k].coe,c[k].pow); 
	return 0;
} 

