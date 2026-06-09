#include<stdio.h>
void qpl(int *,int ,int );
int main(){
	int n,a[10],i=0,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	qpl(a,0,n-1);
	return 0;
}
void qpl(int *b,int now,int latter){
	int c=0,d,e;
	int a1[10];
	if(now==latter){
		for(d=0;d<=latter;d++){
			printf("%d ",b[d]);
		}printf("\n");
	}else{
		for(d=now;d<=latter;d++){
			c=b[d];
			b[d]=b[now];
			b[now]=c;
			for(e=0;e<=latter;e++){
				a1[e]=b[e];
			}
			qpl(b,now+1,latter);
			for(e=0;e<=latter;e++){
				b[e]=a1[e];
			}
		}
	}
}

