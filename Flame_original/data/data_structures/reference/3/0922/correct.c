#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int item;
		struct lln *pnext;
}llist;

int main()
{
	char s[100000];
	gets(s);
	int i,j;
	for(i=0;i<strlen(s);i++)
		if(s[i]=='.')
			break;
	if(i>1 || (i==1&&s[0]!='0')){
		printf("%c.",s[0]);
		for(j=1;j<strlen(s);j++)
			if(s[j]!='.')
				printf("%c",s[j]);
		printf("e%d",i-1);
	}
	else{
		for(i=2;i<strlen(s);i++)
			if(s[i]!='0')
				break;
		for(j=i;j<strlen(s);j++){
			printf("%c",s[j]);
			if(j==i && j!=strlen(s)-1) printf(".");
		}
		printf("e%d",i*-1+1);
	}
    return 0;
}

