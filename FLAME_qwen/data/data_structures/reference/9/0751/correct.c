#include<stdio.h>
#include<string.h>	
int isline[100];
struct segment
{
	int x1;
	int x2;
	int y1;
	int y2;
};
int line(int n,int i,struct segment s[100],int k)
{
	int flag=0;
	  for(int t=0;t<n;t++)
	 {
		if(s[i].x2==s[t].x1&&s[i].y2==s[t].y1)
		{
		  flag=1;
		  k++;
		  return line(n,t,s,k);
		}	 
	 }
	 if(!flag)
	   return k;
}
int main()
{
	struct segment s[100];
	int n,max=0,length=0,k=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d %d %d %d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
	for(int i=0;i<n;i++)
	 isline[i]=line(n,i,s,k);
	for(int i=0;i<n;i++)
	{
	  if(isline[i]>=length)
	  {
	  	length=isline[i];
	  	max=i;
	  }
	} 
	printf("%d %d %d",length+1,s[max].x1,s[max].y1);
	return 0;
} 

