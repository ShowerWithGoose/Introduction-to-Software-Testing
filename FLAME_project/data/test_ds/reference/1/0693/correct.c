#include <stdio.h>
#include <string.h>
int main()
{
	char ch[100];
	int i,l,d,j;
	scanf("%s",ch);
	l=strlen(ch);
	for(i=0;i<l;i++){
		if(ch[i]=='-'){
			if(ch[i-1]>=48&&ch[i-1]<57&&ch[i+1]>ch[i-1]&&ch[i+1]<=57){
			    d=ch[i+1]-ch[i-1];
			    for(j=1;j<d;j++){
				printf("%c",ch[i-1]+j);
			    }	
			}
			else if(ch[i-1]>=65&&ch[i-1]<90&&ch[i+1]>ch[i-1]&&ch[i+1]<=90){
				d=ch[i+1]-ch[i-1];
			    for(j=1;j<d;j++){
				printf("%c",ch[i-1]+j);
			    }	
			}
			else if(ch[i-1]>=97&&ch[i-1]<122&&ch[i+1]>ch[i-1]&&ch[i+1]<=122){
				d=ch[i+1]-ch[i-1];
			    for(j=1;j<d;j++){
				printf("%c",ch[i-1]+j);
			    }	
			}
			else 
			printf("%c",ch[i]);
		}
		else
		printf("%c",ch[i]);
	}
	return 0;
}



