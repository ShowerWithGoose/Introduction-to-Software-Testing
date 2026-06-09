#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct zb{
	int x;
	int y;
};
struct zy{
	struct zb l;
	struct zb r;
}a[100];
int main()
{
	int n,i=0,j,k,con=0,max,r,l,c=0,o=0;
	char d[100]="0";
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i].l.x,&a[i].l.y,&a[i].r.x,&a[i].r.y); 
	}i=0;
	while(i<n-con){
		c=0;
		for(j=i+1;j<n-con;j++){
			if(a[i].l.x==a[j].r.x&&a[i].l.y==a[j].r.y){
				a[i].l=a[j].l;
				for(k=j+1;k<n-con;k++){
					a[k-1]=a[k];
				}con++;c++;o++;
			}else if(a[i].r.x==a[j].l.x||a[i].r.y==a[j].l.y){
				a[i].r=a[j].r;
				for(k=j+1;k<n-con;k++){
					a[k-1]=a[k];
				}con++;c++;o++;
			}
		}
		if(o>max){
		max=o;
		l=a[i].l.x;
		r=a[i].l.y;
	}
		if(c==0){
		i++;
		o=0;}
	}
	printf("%d %d %d",max+1,l,r);
	return 0;
}

