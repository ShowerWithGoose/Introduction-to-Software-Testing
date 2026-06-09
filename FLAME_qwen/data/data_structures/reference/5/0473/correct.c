#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct god
{
	int a,q;
}a1[10010],a2[10010],b[100010];
int cnt1,cnt2,cnt3;
void iint()
{
	char ch;
	for(;;)
	{
		cnt1++;
		scanf("%d%d%c",&a1[cnt1].a,&a1[cnt1].q,&ch);
		if(ch == '\n') break;
	}
	for(;;)
	{
		cnt2++;
		scanf("%d%d%c",&a2[cnt2].a,&a2[cnt2].q,&ch);
		if(ch == '\n') break;
	}
}
int cmp(const void *a,const void *b)
{
	struct god n1 = *(struct god *)a;
	struct god n2 = *(struct god *)b;
	
	if(n1.q < n2.q) return 1;
	return -1;
}
int main()
{
	iint();
	for(int i=1;i<=cnt1;i++)
	 for(int j=1;j<=cnt2;j++)
	 {
	 	int ta=a1[i].a * a2[j].a;
	 	int tq=a1[i].q + a2[j].q;
	 	
	 	int vis=0;
	 	for(int k=1;k<=cnt3;k++)
	 	 if(b[k].q == tq)
	 	 {
	 	 	vis=1;
	 	 	b[k].a+=ta;
	 	 	break;
		 }
		 
		if(vis) continue;
		cnt3++;
		b[cnt3].a=ta,b[cnt3].q=tq;
	 }
	 
	qsort(b+1,cnt3,sizeof(b[0]),cmp);
	for(int i=1;i<=cnt3;i++)
	 printf("%d %d ",b[i].a,b[i].q);
	 
	return 0;
} 

