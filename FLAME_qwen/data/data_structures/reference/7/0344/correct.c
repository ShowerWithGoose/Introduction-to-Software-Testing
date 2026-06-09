#include<stdio.h>

int n;
struct nodde{
	int data,l,r;
	int dep;
}a[400];

void mid(int now){
	if(a[now].l)mid(a[now].l);
	if(a[now].l==0&&a[now].r==0)printf("%d %d\n",a[now].data,a[now].dep);
	if(a[now].r)mid(a[now].r);
}
	

int main()
{
	int i,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i].data);
	a[1].dep=1;
	for(i=2;i<=n;i++){
		now=1;
		while(1){
			if(a[i].data<a[now].data){
				if(!a[now].l){a[now].l=i;a[i].dep=a[now].dep+1;break;}
				now=a[now].l;
			}
			else if(a[i].data>=a[now].data){
				if(!a[now].r){a[now].r=i;a[i].dep=a[now].dep+1;break;}
				now=a[now].r;
			}
		}
	}
	mid(1);
	return 0;
}
				
				
				
				
				
				

