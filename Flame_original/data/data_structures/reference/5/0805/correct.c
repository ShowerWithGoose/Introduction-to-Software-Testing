#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe;//系数 
	int pow;//指数 
	struct Node *next;
};
struct Node a[100],b[100],ans[100];
int compare(const void *p1,const void *p2)
{
	struct Node*a=(struct Node*)p1;
	struct Node*b=(struct Node*)p2;
	return b->pow-a->pow;
}
int main()
{
	int n1=0,n2=0,n3=0;
    char c;
    do {
        scanf("%d%d%c",&a[n1].coe,&a[n1].pow,&c);
        n1++;
    }while(c!='\n');
    qsort(a,n1,sizeof(struct Node),compare);
    do {
        scanf("%d%d%c",&b[n2].coe,&b[n2].pow,&c);
        n2++;
    }while(c!='\n');
    qsort(b,n2,sizeof(struct Node),compare);
    int i,j;
    for(i=0;i<n1;i++)//进行相乘操作 
    {
    	for(j=0;j<n2;j++)
    	{
    		ans[n3].coe=a[i].coe*b[j].coe;
    		ans[n3].pow=a[i].pow+b[j].pow;
    		n3++;
		}
	}
	qsort(ans,n3,sizeof(struct Node),compare);
	for(i=0;i<n3;i++)
	{
		if(ans[i].pow!=0&&ans[i].pow==ans[i+1].pow)
		{
			ans[i+1].coe=ans[i+1].coe+ans[i].coe;
			ans[i].coe=-1;
		}
	}
	for(i=0;i<n3;i++)
	{
		if(ans[i].coe==0||ans[i].coe==-1) continue;
		else printf("%d %d ",ans[i].coe,ans[i].pow);
	}
	return 0;
}

