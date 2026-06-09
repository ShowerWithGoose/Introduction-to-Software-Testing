#include<stdio.h>
#include<malloc.h>
struct input{
	int x1;
	int y1;
	int x2;
	int y2;
	int count; 
} a[105],b,*p;
int main(){
	int n,t=0,i,j,k=0,l,panduan;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&b.x1,&b.y1,&b.x2,&b.y2);
		for(j=0,panduan=1;j<t;j++)
		{
			if(b.x1==a[j].x2&&b.y1==a[j].y2){
				a[j].x2=b.x2;
				a[j].y2=b.y2;
				a[j].count++;
				//printf("%d %d %d\n",a[j].count,a[j].x2,a[j].y2);
				panduan=0;
				break;
			}
			else if(b.x2==a[j].x1&&b.y2==a[j].y1){
				a[j].x1=b.x1;
				a[j].y1=b.y1;
				a[j].count++;
				//printf("%d %d %d\n",a[j].count,a[j].x1,a[j].y1);
				panduan=0;
				break;
			}
		}
		if(panduan)
		{
			a[t].x1=b.x1;
			a[t].y1=b.y1;
			a[t].x2=b.x2;
			a[t].y2=b.y2;
			a[t].count=1;
			t++;
		}
	}
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<t;j++)
		{
			if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2){
				a[j].x2=a[i].x2;
				a[j].y2=a[i].y2;//printf("%d %d\n",a[i].count,a[j].count);
				a[j].count+=a[i].count;
				a[i].x1=0;
				a[i].x2=0;
				a[i].y1=0;
				a[i].y2=0;
				a[i].count=0;
				break;
			}
			else if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1){
				a[j].x1=a[i].x1;
				a[j].y1=a[i].y1;//printf("%d %d\n",a[i].count,a[j].count);
				a[j].count+=a[i].count;
				a[i].x1=0;
				a[i].x2=0;
				a[i].y1=0;
				a[i].y2=0;
				a[i].count=0;
				break;
			}
	 	} 
	}
	for(i=0;i<t;i++)
	{
		if(a[i].count>k)
		{
			l=i;
			k=a[i].count;
		}
	}
	printf("%d %d %d",a[l].count,a[l].x1,a[l].y1);
	return 0;
}

