#include <stdio.h>

struct line{
	int Bx,By;
	int Ex,Ey;
	int head;
	int num;
}l[102];

int n,ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d %d %d %d",&l[i].Bx,&l[i].By,&l[i].Ex,&l[i].Ey),l[i].num=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(l[i].Ex^l[j].Bx||l[i].Ey^l[j].By)continue;
			l[j].head=i;
		}
	}
	int k=1;
	while(k){
		k=0;
		for(int i=1;i<=n;++i){
			if(l[i].head&&(!l[l[i].head].head))
				k=1,l[i]=l[l[i].head],++l[i].num;
		}
	}
	ans=0;
	for(int i=1;i<=n;++i)
		ans=(l[ans].num>l[i].num?ans:i);
	printf("%d %d %d\n",l[ans].num,l[ans].Bx,l[ans].By);
	return 0;
}
