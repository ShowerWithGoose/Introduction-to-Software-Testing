#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n,f[110];
struct god
{
	int x1,x2,y1,y2;
}l[110],pos[110];
int cnt[110];
int find(int x)
{
	if(x == f[x]) return x;
	return find(f[x]);
}
int ok(int i,int j)
{
	if(l[i].x1 == l[j].x2 && l[i].y1 == l[j].y2) return 1;
	if(l[i].x2 == l[j].x1 && l[i].y2 == l[j].y1) return 1;
	return 0;
}
int main()
{
 	scanf("%d",&n);
 	for(int i=1;i<=n;i++)
 	  scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
 	  
 	for(int i=1;i<=n;i++) 
	 {
	 	f[i] = i;
		cnt[i] = 1;
		pos[i].x1 = l[i].x1,pos[i].y1 = l[i].y1;
	 }
 	
	for(int i=2;i<=n;i++)
	 for(int j=1;j<i;j++)
	  if(ok(i,j))
	  {
	  	
	  	//printf("******%d %d\n",i,j);
	  	int rx=find(i),ry=find(j);
	  	f[rx] = ry;
	  	cnt[ry]+=cnt[rx];
	  	
	  	if(pos[rx].x1 < pos[ry].x1)
	  	    pos[ry].x1=pos[rx].x1,pos[ry].y1=pos[rx].y1;
	  }
	
	int ans=0;
	int tpos;
	
	for(int i=1;i<=n;i++) 
	{
		if(cnt[i] > ans) 
	  	 ans=cnt[i],tpos=i;
	  	 
	  	//printf("***%d\n",cnt[i]);
	}
	 
	
	printf("%d %d %d",ans,pos[tpos].x1,pos[tpos].y1);
	return 0;
}

