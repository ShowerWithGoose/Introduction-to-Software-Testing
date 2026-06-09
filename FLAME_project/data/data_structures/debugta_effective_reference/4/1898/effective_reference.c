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
	int x;
}tj[1001];
char down(char ch){
	if(ch>='a'&&ch<='z')return ch;
	else return ch+32;
}
int cmp(const void*tj,const void*b){
	struct hs a1=*((struct hs*)tj);
	struct hs b1=*((struct hs*)b);
	return strcmp(a1.word,b1.word);
}
char s[100],ch;
int i;
int main(){
	freopen("article.txt","r",stdin);
	while(~scanf("%c",&ch)){
		if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
			int j=0;
			while((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
				s[j++]=down(ch);scanf("%c",&ch);
			}
			bool p=false;
			fep(i,1,i){
				if(strcmp(s,tj[i].word)==0){
					tj[i].x++;p=true;break;
				}
			}
			if(!p){
				i++;
				fep(i,0,j-1)tj[i].word[i]=s[i];
				tj[i].x=1;
			}
			fep(i,0,j-1)s[i]='\0';
		}
	}
	qsort(tj+1,i,sizeof(struct hs),cmp);
	fep(i,1,i){
		printf("%s %d\n",tj[i].word,tj[i].x);
	}
} 

