#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct xian{
	int x1;
	int y1;
	int x2;
	int y2;
	struct xian *next;
}duan[10005];
int max=0,min=1000000;
struct ans{
	int x;
	int y;
	int num1;
}ans1[10005];
int main()
{
	int n,i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&duan[i].x1,&duan[i].y1,&duan[i].x2,&duan[i].y2);
	for(j=0;j<n;j++){
	for(t=0;t<n;t++){
		if(duan[j].x2==duan[t].x1&&duan[j].y2==duan[t].y1){
			duan[j].next=&duan[t];
	}
	}
	}
	int num;
	for(i=0;i<n;i++)
	{
		ans1[i].x=duan[i].x1,ans1[i].y=duan[i].y1;
		struct xian *s=duan[i].next;
		ans1[i].num1++;
		while(s!=NULL){
			s=s->next;
			ans1[i].num1++;
		}
	}
	for(i=0;i<2*n;i++){
		if(ans1[i].num1>max)
		max=ans1[i].num1,num=i;
	}
	printf("%d %d %d",ans1[num].num1,ans1[num].x,ans1[num].y);
	return 0;
}

