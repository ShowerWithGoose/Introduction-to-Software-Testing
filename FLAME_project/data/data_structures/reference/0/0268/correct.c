#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define pc putchar
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
char s[50000];
void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int same(int i){
	if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9') return 1;
	else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z') return 1;
	else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z') return 1;
	else return 0;
}
int main(){
       int i,j;
       char c;
		sc("%s",s);
		for(i=0;s[i]!='\0';i++){
			if(s[i]=='-'){
				if(s[i+1]>s[i]&&same(i)){
					for(c=s[i-1]+1;c<s[i+1];c++){
						pr("%c",c);
					}
				}else pr("%c",s[i]);
			}else pr("%c",s[i]);
		}
return 0;
}

