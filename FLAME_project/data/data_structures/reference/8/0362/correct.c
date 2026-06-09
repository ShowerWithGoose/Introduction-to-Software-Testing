#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,c,d,s[150][150],t[150],tt[150],flag=-1;
void shendu(int p){
	if(flag==-1){
		printf("%d",p);
		flag=3;
	}
	else{
		printf(" %d",p);
	}
	t[p]=1;
	for(int i=0;i<a;i++){
		if(s[p][i]==1&&t[i]==0){
			shendu(i);
		}
	}
}
void guangdu(int p){
	int x;
	tt[1]=p;
	for(int j=1,r=1;j<=r;){
		x=tt[j++];
		if(t[x]==1)continue;
		if(flag==-1){
			printf("%d",x);
			flag=3;
		}
		else{
			printf(" %d",x);
		}
		t[x]=1;
		for(int i=0;i<a;i++){
			if(s[x][i]==1&&t[i]==0)tt[++r]=i;
		}
	}
}
int main(){
	scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		scanf("%d%d",&c,&d);
		s[c][d]=1;
		s[d][c]=1;
	}
	shendu(0);
	printf("\n");
	for(int i=0;i<150;i++){
		t[i]=0;
		flag=-1;
	}
	guangdu(0);
	printf("\n");
	for(int i=0;i<150;i++){
		t[i]=0;
		flag=-1;
	}
	scanf("%d",&c);
	t[c]=1;
	shendu(0);
	printf("\n");
	for(int i=0;i<150;i++){
		t[i]=0;
		flag=-1;
	}
	t[c]=1;
	guangdu(0);
	printf("\n");
	for(int i=0;i<150;i++){
	    t[i]=0;
		flag=-1;
	} 
	return 0;
}

