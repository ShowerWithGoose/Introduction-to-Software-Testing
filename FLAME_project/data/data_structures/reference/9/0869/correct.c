#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct po{
	int a[2];
	int b[2];
}
po[100],re;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&po[i].a[0],&po[i].a[1],&po[i].b[0],&po[i].b[1]);
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(po[j].a[0]>po[j+1].a[0]){
				re=po[j+1];
				po[j+1]=po[j];
				po[j]=re;
			}
		}
	}
	int max=0,p,q;
	for(int i=0;i<n;i++){
		int l=1,r=i;
		for(int j=i+1;j<n;j++){
			if(po[r].b[0]==po[j].a[0]&&po[r].b[1]==po[j].a[1]){
				l++;
				r=j;
			}
			if(l>max){
				max=l;
				p=po[i].a[0];
				q=po[i].a[1];
			}
		}
	}
	printf("%d %d %d",max,p,q);
	return 0;
} 


