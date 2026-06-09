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
bool check(char a,char b){
	int l;
	if(a>='a'&&a<='z'&&b>='a'&&b<='z'){
		l=b-a;
		if(l>0){
			fep(i,1,l)printf("%c",a+i);return true;
		}
		printf("%c",'-');return false;
	}
	else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
		l=b-a;
		if(l>0){
			fep(i,1,l)printf("%c",a+i);return true;
		}
		printf("%c",'-');return false;
	}
	else  if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
		l=b-a;
		if(l>0){
			fep(i,1,l)printf("%c",a+i);return true;
		}
		printf("%c",'-');return false;
	}
	else printf("%c",'-');return false;
}
char s[1000];
int len;
bool p;
int main(){
	scanf("%s",s);
	len=strlen(s);
	fep(i,0,len-1){
		if(s[i]=='-'&&i>=1){
			p=check(s[i-1],s[i+1]);if(p)i++;
		}
		else printf("%c",s[i]);
	}
}


