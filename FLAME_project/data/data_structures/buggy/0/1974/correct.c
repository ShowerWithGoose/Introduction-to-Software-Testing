#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 



int main(){
	int i,j,b,c,d,e,f,n;
	char p;
char s[1000086];
gets(s);
n=strlen(s);
for(i=0;i<n;i++){
	if(s[i]=='-'){
		if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')&&(s[i+1]>s[i-1])){
			s[i]='\0';for(p=s[i-1]+1;p<s[i+1];p++){pf("%c",p);continue;
			}
		}else if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')&&(s[i+1]>s[i-1])){
			s[i]='\0';for(p=s[i-1]+1;p<s[i+1];p++){pf("%c",p);continue;
			}
		}else if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')&&(s[i+1]>s[i-1])){
			s[i]='\0';
		
			for(p=s[i-1]+1;p<s[i+1];p++){
			pf("%c",p);
			}continue;
			
		}else pf("-");
	}else{
		pf("%c",s[i]);
	}
}
	return 0;
}



