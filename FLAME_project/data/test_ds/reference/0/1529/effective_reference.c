#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
char s[1000];
gets(s);
int i,j,k,y;
int a;
a=strlen(s);
for(i=0;i<a;i++){
	if(s[i]=='-'){
		if(((s[i-1]>=48&&s[i-1]<=57)&&(s[i+1]>=48&&s[i+1]<=57))||((s[i-1]>=65&&s[i-1]<=90)&&(s[i+1]>=65&&s[i+1]<=90))||((s[i-1]>=97&&s[i-1]<=122)&&(s[i+1]>=97&&s[i+1]<=122)))
		{
		y=0;
		j=s[i+1]-s[i-1];
		for(y=s[i-1]+1;y<=s[i-1]+j;y++){
			printf("%c",y);
		}
		i++;
	}
		else{
			printf("-");
		}
	}

	else{
		printf("%c",s[i]);
	}
} 
 
 return 0;
}






