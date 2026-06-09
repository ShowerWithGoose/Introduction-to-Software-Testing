#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int item;
		struct lln *pnext;
}llist;
char s[1000000];
int main()
{
	int i,j;
	gets(s);
	printf("%c",s[0]);
	for(i=1;i<strlen(s)-1;i++){
		if(s[i]=='-'){
			if((isupper(s[i-1]) && isupper(s[i+1]) && s[i-1]<s[i+1]) ||(islower(s[i-1]) && islower(s[i+1])&& s[i-1]<s[i+1]) ||(isdigit(s[i-1]) && isdigit(s[i+1])&& s[i-1]<s[i+1])){
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j); 
			}
			else
				printf("-");
		}
		else
			printf("%c",s[i]);
	}
	printf("%c",s[i]);
    return 0;
}

