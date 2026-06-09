#include <stdio.h>
struct line{
	int start[2],finish[2];
	int num;
};
struct line a[101]; 
int main()
{
	int n,flag;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	int i,j=0,k=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		flag=0;
		for(j=0;j<k;j++)
		{
			if(x1==a[j].finish[0]&&y1==a[j].finish[1])
			{
				a[j].finish[0]=x2;
				a[j].finish[1]=y2;
				a[j].num++;
				flag=1;
			}	
		}
		if(flag==0)
			{
				a[k].start[0]=x1;
				a[k].start[1]=y1;
				a[k].finish[0]=x2;
				a[k].finish[1]=y2;
				a[k].num=1;
				k++;
			}
	 } 
	 for(i=0;i<k;i++)
	 {
	 	for(j=0;j<k;j++)
	 	{
	 		if(a[i].start[0]==a[j].finish[0]&&a[i].start[1]==a[j].finish[1])
	 		{
	 			a[j].finish[0]=a[i].finish[0];
	 			a[j].finish[1]=a[i].finish[1];
	 			a[j].num+=a[i].num;
			 }
		 }
	 }
	 int max=0,b;
	 for(i=0;i<k;i++)
	 {
	 	if(a[i].num>max)
	 	{
	 		max=a[i].num;
	 		b=i;
		 }
	 }
	 printf("%d %d %d",a[b].num,a[b].start[0],a[b].start[1]);
	return 0;
}

