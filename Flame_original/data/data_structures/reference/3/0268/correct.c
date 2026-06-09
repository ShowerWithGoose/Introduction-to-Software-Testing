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
char s[10000]; 
void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int main(){
       int i,j,cnt;
		sc("%s",s);
		for(i=0;i<strlen(s);i++){
			if(s[i]=='.'){
				cnt=i;
				break;
			}
		}
		if(s[0]!='0'){
			pr("%c.",s[0]);
			for(i=1;i<strlen(s);i++){
				if(s[i]!='.')	pr("%c",s[i]);
			}
			pr("e%d",cnt-1);
		}else{
			for(i=0;s[i]=='0'||s[i]=='.';i++);
			j=i;
			if(s[j+1]=='\0') pr("%c",s[j]);
			else{
				pr("%c.",s[j]);
				for(i++;i<strlen(s);i++){
					pr("%c",s[i]);
				}	
			}
			pr("e%d",cnt-j);
		}
		
return 0;
}

