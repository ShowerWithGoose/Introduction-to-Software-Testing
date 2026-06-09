#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
char c[1000],d[1000]; 
int main()
{
    int i,j,sum,t;
	gets(c);
    for(i=0;i<strlen(c);i++){
    	if(c[i]!='-')
    		printf("%c",c[i]);
    	else{
    		if((c[i-1]<c[i+1]&&(c[i-1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i+1]<='Z')||(c[i-1]>='0'&&c[i+1]<='9'))){
    			t=c[i+1]-c[i-1];
				for(j=1;j<t;j++){
					printf("%c",c[i-1]+j);
				}
			}
			else
				printf("%c",c[i]);
		}
	}
	return 0;
}


