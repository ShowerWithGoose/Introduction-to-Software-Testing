#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct node{
	int x1,x2;
	int y1,y2,flag;
}xd[100];
int n,cnt=1,max=0,maxx,maxy,k,p;
int cmp(const void* l,const void* m)
{
	struct node *ll=(struct node *)l;
	struct node *mm=(struct node *)m;
	if(ll->x1>mm->x1)return 1;
	if(ll->x1<mm->x1)return -1;
	if(ll->y1>mm->y1)return 1;
	if(ll->y1<mm->y1)return -1;
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
  	scanf("%d%d",&xd[i].x1,&xd[i].y1);
  	scanf("%d%d",&xd[i].x2,&xd[i].y2);
  	xd[i].flag=0;
  }
  qsort(xd,n,sizeof(xd[0]),cmp);
  /*for(int i=0;i<n;i++)
  {
  	printf("x1=%d y1=%d x2=%d y2=%d\n",xd[i].x1,xd[i].y1,xd[i].x2,xd[i].y2);
  } */
  for(int i=0;i<n;i++)
  {
  	if(xd[i].flag==0){
  	
  	for(int j=i+1;j<n;j++)
  	{
  		k=i; p=j;
	  	while(xd[k].x2==xd[p].x1&&xd[k].y2==xd[p].y1)
	  	{
	  		//printf("%d %d\n",xd[k].x2,xd[k].y2);
		  	xd[p].flag=1;cnt++;
		  	//printf("cnt=%d\n",cnt);
		  	k=p;
			ans:p++;
			if(p>=n)break; 
			//printf("p=%d\n",p);
			//printf("k=%d\n",k);
		  	if(xd[p].x1<xd[k].x2&&(xd[k].x2!=xd[p].x1||xd[k].y2!=xd[p].y1))
		  	{
			  goto ans;	
			}
			else if(xd[p].x1>xd[k].x2) break;
		  }
	}
	if(cnt>=max){max=cnt;maxx=xd[i].x1;maxy=xd[i].y1;}
	cnt=1;
	xd[i].flag=1;
	}
  }
printf("%d %d %d",max,maxx,maxy);

return 0;
}

