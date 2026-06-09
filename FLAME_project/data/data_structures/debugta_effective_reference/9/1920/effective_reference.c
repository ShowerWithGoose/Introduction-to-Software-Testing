#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct node{
	int x1,x2;
	int y1,y2,flag;
}line[100];
int num,ds=1,max=0,maxx,maxy,k,p;
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
  scanf("%d",&num);
  for(int i=0;i<num;i++)
  {
  	scanf("%d%d",&line[i].x1,&line[i].y1);
  	scanf("%d%d",&line[i].x2,&line[i].y2);
  	line[i].flag=0;
  }
  qsort(line,num,sizeof(line[0]),cmp);
  /*for(int i=0;i<n;i++)
  {
  	printf("x1=%d y1=%d x2=%d y2=%d\n",xd[i].x1,xd[i].y1,xd[i].x2,xd[i].y2);
  } */
  for(int i=0;i<num;i++)
  {
  	if(line[i].flag==0){
  	
  	for(int j=i+1;j<num;j++)
  	{
  		k=i; p=j;
	  	while(line[k].x2==line[p].x1&&line[k].y2==line[p].y1)
	  	{
	  		//printf("%d %d\n",xd[k].x2,xd[k].y2);
		  	line[p].flag=1;ds++;
		  	//printf("cnt=%d\n",cnt);
		  	k=p;
			ans:p++;
			if(p>=num)break; 
			//printf("p=%d\n",p);
			//printf("k=%d\n",k);
		  	if(line[p].x1<line[k].x2&&(line[k].x2!=line[p].x1||line[k].y2!=line[p].y1))
		  	{
			  goto ans;	
			}
			else if(line[p].x1>line[k].x2) break;
		  }
	}
	if(ds>=max){max=ds;maxx=line[i].x1;maxy=line[i].y1;}
	ds=1;
	line[i].flag=1;
	}
  }
printf("%d %d %d",max,maxx,maxy);

return 0;
}

