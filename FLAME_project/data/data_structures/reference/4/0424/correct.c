#include <stdio.h>
#include <string.h>

char st[10001][101];

int n=1;

int Cmp(const char a[],const char b[]){
	int i;
	for(i=0;a[i]&&a[i]==b[i];++i);
	return(a[i]>b[i]);
}

void sort(int l,int r){
	if(l==r)return;
	else if(r==l+1){
		if(Cmp(st[l],st[r])){
			memcpy(st[0],st[l],sizeof(st[0]));
			memcpy(st[l],st[r],sizeof(st[0]));
			memcpy(st[r],st[0],sizeof(st[0]));
		}
		return;
	}
	sort(l,(l+r)/2),sort((l+r)/2+1,r);
	char tmp[r-l+2][101];
	int x=l,y=(l+r)/2+1;
	for(int i=l;i<=r;++i){
		if(x^((l+r)/2+1)&&y^(r+1)){
			memcpy(tmp[i-l+1],Cmp(st[x],st[y])?st[y]:st[x],sizeof(st[y]));
			if(Cmp(st[x],st[y]))++y;
			else ++x;
		}
		else if(x^((l+r)/2+1))memcpy(tmp[i-l+1],st[x],sizeof(st[y])),++x;
		else memcpy(tmp[i-l+1],st[y],sizeof(st[y])),++y;
	}
	for(int i=l;i<=r;++i)
		memcpy(st[i],tmp[i-l+1],sizeof(st[i]));
	return;
}

FILE *in;

int main(){
	in=fopen("article.txt","r");
	while(!feof(in)){
		fscanf(in,"%s",st[++n]);
	}
	for(int i=1;i<=n;++i){
		for(int o=0;st[i][o];++o)
			if(st[i][o]<='z'&&st[i][o]>='a')continue;
				else if(st[i][o]<='Z'&&st[i][o]>='A')st[i][o]=st[i][o]-'A'+'a';
					else{
						for(int j=o;st[i][j];++j)
							st[n+1][j-o]=st[i][j+1];
						st[i][o]=0;
						--o;
						++n;
					}
	}
	for(int i=1;i<=n;++i){
		if(!st[i][0])memcpy(st[i],st[n],sizeof(st[0])),--n,--i;
	}
	sort(1,n);
	int num=1;
	for(int i=1;i<=n;++i){
		if(!Cmp(st[i+1],st[i]))++num;
		else printf("%s %d\n",st[i],num),num=1;
	}
	printf("%s %d\n",st[n],num-1);
	return 0;
}
