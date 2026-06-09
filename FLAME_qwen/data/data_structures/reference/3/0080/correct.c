#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
	char a;
	scanf("%c",&a);
	if(a=='0'){
		scanf("%c",&a);
		int i=0;
		scanf("%c",&a);
		while(a=='0'){
			i++;
			scanf("%c",&a);
		}
		printf("%c",a);
		scanf("%c",&a);
		if(a!='\n'){
			printf(".%c",a);
			scanf("%c",&a);
		while(a!='\n'){
		 printf("%c",a); 
                scanf("%c",&a);	
		}
		}printf("e-%d",i+1);
	}
	
	else if(a!='0'){
		printf("%c.",a);int i=0;
        scanf("%c",&a);
        while (a!='.')
        {
            i++; 
            printf("%c",a); 
            scanf("%c",&a);
        }
        scanf("%c",&a);
        while (a!='\n')
        {
            
            printf("%c",a); 
            scanf("%c",&a);
        }
        printf("e%d",i);
    }
 
	}


