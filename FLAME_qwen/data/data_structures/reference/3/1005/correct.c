#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
int main()
{
    char c[100];
    int w=1,i;
    gets(c);
    if(c[0]=='0'&&c[1]=='.'){
    	for(i=2;i<strlen(c);i++){
    		if(c[i]=='0')
    			w++;
    		if(c[i]!='0')
    			break;
		}
    	if(w==strlen(c)-2){
    		printf("%ce-%d",c[i],w);
		}
		else{
		
		printf("%c.",c[w+1]);
		for(i=w+2;i<strlen(c);i++)
			printf("%c",c[i]);
		printf("e-%d",w);
		}
	}
	
	else{
		w=0;
		
		for(i=1;i<strlen(c);i++){
			if(c[i]!='.')
				w++;
			else
				break;
		}
		printf("%c.",c[0]);
		for(i=1;i<strlen(c);i++){
			if(c[i]!='.')
				printf("%c",c[i]);
		}
		printf("e%d",w);	
	}
	return 0;
}


