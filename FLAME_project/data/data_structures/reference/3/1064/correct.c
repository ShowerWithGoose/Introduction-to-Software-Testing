#include <stdio.h>
#include <string.h>
int main()
{
	char s[108];
	int i,j,l,count=0,s1=0,k,s2=0,m,n;
	gets(s);
	l=strlen(s);
	if(s[0]=='0'){
		for(n=2;n<l;n++){
			if(s[n]=='0'){
				s1++;
			}
			else break;
		}
		k=n;
		if(l-2-s1==1){
			printf("%c",s[l-1]);
		}
		else{
			printf("%c.",s[k]);
			for(j=k+1;j<l;j++)printf("%c",s[j]);
		}
		printf("e-%d",s1+1);
	}
	else{
		if(s[1]=='.'){
			for(i=0;i<l;i++){
				printf("%c",s[i]);
			}
			printf("e0");
		}
		else{
			for(i=0;i<l,s[i]!='.';i++){
				s2++;
				m=i+1;
			}
			printf("%c.",s[0]);
			for(i=1;i<l;i++){
				if(i==m)continue;
				else printf("%c",s[i]);
			}
			printf("e%d",s2-1);
		}
	}
	return 0;
}

