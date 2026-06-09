#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define ULL unsigned long long 
#define LL long long
#define fep(q,l,r) for(int q=(l);q<=r;q++)
#define ffep(q,r,l) for(int q=(r);q>=l;q--)
int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<3)+(f<<1)+ch-'0';ch=getchar();}
	return f*w;
}
char s[103];
int len,y;
int main(){
	gets(s);len=strlen(s);
	fep(q,0,len-1)if(s[q]=='.')y=q;
	int x=0,w;
	fep(q,0,len-1){
		if(s[q]!='0'&&s[q]!='.'){
			w=q;break;
		}
	}
	printf("%c",s[w]);if(w!=len-1)printf(".");
	if(w<len-1)fep(q,w+1,len-1)if(s[q]!='.')printf("%c",s[q]);
	printf("e");x=y-w;if(x>0)x--;
	printf("%d",x);
}

