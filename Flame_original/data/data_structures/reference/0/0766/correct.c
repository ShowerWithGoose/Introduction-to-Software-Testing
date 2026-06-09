#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *ch,*p;
	ch=(char*)malloc(sizeof(char)*1000);
	scanf("%s",ch);
	for(p=ch;*p!='\0';p++){
		if(*(p+1)=='-'){
			if(((*p>='0'&&*p<='9'&&*(p+2)>='0'&&*(p+2)<='9')
			||(*p>='a'&&*p<='z'&&*(p+2)>='a'&&*(p+2)<='z')
			||(*p>='A'&&*p<='Z'&&*(p+2)>='A'&&*(p+2)<='Z'))&&*p<*(p+2)){
				for(;*p<*(p+2);(*p)++)
				printf("%c",*p);
				p++;				
			}
			else printf("%c",*p);	
		}
		else printf("%c",*p);
	}
	
//	printf("%d",l); 
}

