#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
int main()
{int i,k;

char s[1000];
gets(s);
for(i=0;i<=strlen(s)-1;i++){
	if(s[i]=='-'&&s[i-1]<=s[i+1]&&islower(s[i-1])==islower(s[i+1])&&isupper(s[i-1])==isupper(s[i+1])&&isdigit(s[i-1])==isdigit(s[i+1])){

for(k=s[i+1]-s[i-1]-1;k>=1;k--){printf("%c",s[i+1]-k);
}

	i++;}

	printf("%c",s[i]);
}
 return 0;
}



