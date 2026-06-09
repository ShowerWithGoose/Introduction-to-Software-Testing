#include<stdio.h> 
struct line{
	int x1;
	int x2;
	int y1;
	int y2;
}l[100];
int le[100];
void Length(int m,int p,int n){
	int i;
	for(i=0;i<n;i++){
		if(l[p].x2==l[i].x1&&l[p].y2==l[i].y1){
			le[m]++;
			Length(m,i,n);
			return;
		}
	}
	return;
}
int main(){
	int p=0,n,m,mp;
	scanf("%d",&n);
	while(p!=n){
		scanf("%d %d %d %d",&l[p].x1,&l[p].y1,&l[p].x2,&l[p].y2);
		p++;
	}
	for(p=0;p<n;p++){
		Length(p,p,n);
		if(le[p]>m)
			m=le[p],mp=p;
	}
	printf("%d %d %d",m+1,l[mp].x1,l[mp].y1);
}

