#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct duo{
	int xi;
	int ji;
}a[1005],b[1005],ans[1005],swap;
int i,n,m,p,q,flag;
char c;
int main()
{
	while(1)
	{
		scanf("%d %d",&a[i].xi,&a[i].ji);
		scanf("%c",&c);i++;
		if(c=='\n')
		break;
	}
	int j=0;
	while(1)
	{
		scanf("%d %d",&b[j].xi,&b[j].ji);
		scanf("%c",&c);j++;
		if(c=='\n')
		break;
	}
	for(;n<i;n++)
	for(m=0;m<j;m++){
		int sum=a[n].ji+b[m].ji,mult=a[n].xi*b[m].xi;
		flag=0;
		for(p=0;p<q;p++)
		if(ans[p].ji==sum){
			ans[p].xi+=mult,flag=1;
			break;
		}
		if(flag==0){
			ans[q].ji=sum;
			ans[q].xi=mult;
			q++;
		}
	}
	for(i=0;i<q-1;i++)
	{
		flag=0;
		for(j=0;j<q-i-1;j++){
		if(ans[j].ji<ans[j+1].ji){
			swap=ans[j];
			ans[j]=ans[j+1];
			ans[j+1]=swap;
			flag=1;
		}
	}
		if(flag==0)
		break;
	}
	for(i=0;i<q;i++)
	printf("%d %d ",ans[i].xi,ans[i].ji);
	return 0;
 } 

