#include<stdio.h>
struct node{
	int x,y;
}s1[1005],s2[1005],s3[1005],sp;
int n1,n2,n3=0;
int main(){
	int l=1;
	while(scanf("%d %d",&s1[l].x,&s1[l].y)!=EOF){
		l++;
		char c;
		scanf("%c",&c);
		if(c=='\n') break;
	}
	n1=l;
	l=1;
	while(scanf("%d %d",&s2[l].x,&s2[l].y)!=EOF){
		l++;
	}
	n2=l-1;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			sp.x=s1[i].x*s2[j].x;
			sp.y=s1[i].y+s2[j].y;
			if(n3==0){
				s3[++n3]=sp;
			}
			else{
	
				for(int k=1;k<=n3+1;k++){
					if(s3[k].y==sp.y){
						s3[k].x+=sp.x;
						break;
					}
					if(sp.y>s3[k].y){
						n3++;
						for(int p=n3;p>k;p--){
							s3[p]=s3[p-1];
						}
						s3[k]=sp;
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n3+1;i++){
		if(s3[i].x)
		printf("%d %d ",s3[i].x,s3[i].y);
	}
	return 0;
}
