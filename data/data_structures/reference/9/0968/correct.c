#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define y1 Y
int x1[100],y1[100],x2[100],y2[100];
int max=0,max_locx=10000,max_locy=10000,place;
int search(int loc,int n,int count)
{
	if(place==1) 
	{
	int mid=real_search1(loc,n);
	if(mid==-1)
	return count;
	count++;
	search(mid,n,count);
	}
	else
	{
	int mid=real_search2(loc,n);
	if(mid==-1)
	return count;
	count++;
	search(mid,n,count);
	} 	
}
int real_search1(int loc,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==loc) continue;
		if(x2[i]==x2[loc]&&y2[i]==y2[loc])
		{
			place=2;		return i;
		}
		if(x1[i]==x2[loc]&&y1[i]==y2[loc])
		{
			place=1;		return i;
		}  
	}
	return -1;
}
int real_search2(int loc,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==loc) continue;
		if(x2[i]==x1[loc]&&y2[i]==y1[loc])
		{
			place=2;		return i;
		}
		if(x1[i]==x1[loc]&&y1[i]==y1[loc])
		{
			place=1;		return i;
		}  
	}
	return -1;
}
void compare(int num,int loc,int dir)
{
	if(dir==1)
	{
	if(x1[loc]<max_locx) 
	{
	max_locx=x1[loc]; 
	max_locy=y1[loc]; 	
	}
	}
	else
	{
	if(x2[loc]<max_locx) 
	{
	max_locx=x2[loc]; 
	max_locy=y2[loc]; 	
	}
	}	
} 
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x1[i],&y1[i]);
		scanf("%d%d",&x2[i],&y2[i]);
	}
	for(i=0;i<n;i++)
	{
		int mid;
		place=1;
		mid=search(i,n,0);
		if(mid>=max) 
		{
		max=mid;	compare(mid,i,1);
		}
		place=2;
		mid=search(i,n,0);
		if(mid>=max)
		{
		max=mid;	compare(mid,i,2);
		}
	}
	printf("%d %d %d",max+1,max_locx,max_locy);
	return 0; 
} 

