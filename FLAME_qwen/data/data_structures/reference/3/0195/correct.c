#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<3)+(f<<1)+ch-'0';ch=getchar();}
	return f*w;
}
char s[103];
int len,di;
int main(){
	gets(s);len=strlen(s);
	fep(i,0,len-1)if(s[i]=='.')di=i;
	int tot=0,bg;
	fep(i,0,len-1){
		if(s[i]!='0'&&s[i]!='.'){
			bg=i;break;
		}
	}
	printf("%c",s[bg]);if(bg!=len-1)printf(".");
	if(bg<len-1)fep(i,bg+1,len-1)if(s[i]!='.')printf("%c",s[i]);
	printf("e");tot=di-bg;if(tot>0)tot--;
	printf("%d",tot);
}

