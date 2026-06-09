#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<malloc.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
struct hs{
	char word[100];
	int nm;
}a[1001];
char down(char ch){
	if(ch>='a'&&ch<='z')return ch;
	else return ch+32;
}
int cmp(const void*a,const void*b){
	struct hs a1=*((struct hs*)a);
	struct hs b1=*((struct hs*)b);
	return strcmp(a1.word,b1.word);
}
char s[100],ch;
int tot;
int main(){
	freopen("article.txt","r",stdin);
	while(~scanf("%c",&ch)){
		if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
			int len=0;
			while((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
				s[len++]=down(ch);scanf("%c",&ch);
			}
			bool p=false;
			fep(i,1,tot){
				if(strcmp(s,a[i].word)==0){
					a[i].nm++;p=true;break;
				}
			}
			if(!p){
				tot++;
				fep(i,0,len-1)a[tot].word[i]=s[i];
				a[tot].nm=1;
			}
			fep(i,0,len-1)s[i]='\0';
		}
	}
	qsort(a+1,tot,sizeof(struct hs),cmp);
	fep(i,1,tot){
		printf("%s %d\n",a[i].word,a[i].nm);
	}
} 

