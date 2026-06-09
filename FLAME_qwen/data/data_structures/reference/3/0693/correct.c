#include <stdio.h>
#include <string.h>
int main () {
	char ch[100];
	int i,l,zhishu=1,j;
	scanf("%s",ch);

	l=strlen(ch);
	if(ch[0]=='0') {
		for(i=2; i<l; i++) {
			if(ch[i]=='0') {
				zhishu=zhishu+1;
			} else {
				if(i!=l-1) {
					printf("%c.",ch[i]);
					for(i=i+1; i<l; i++) {
						printf("%c",ch[i]);
					}
					printf("e-%d",zhishu);

				} else {
					printf("%ce-%d",ch[i],zhishu);

				}


			}
		}

	} 
	else {
		printf("%c.",ch[0]);
		zhishu=0;
		for(i=1; i<l; i++) {
			if(ch[1]=='.'){
				for(i=2;i<l;i++){
					printf("%c",ch[i]);
				}
				printf("e0");
			}
			else{
			  if(ch[i]!='.'){
            	zhishu=zhishu+1;
            	
			}
			
			   else {
			   	j=i;
		        for(i=1; i<j; i++) {
						printf("%c",ch[i]);
					}
				for(i=j+1;i<l;i++){
						printf("%c",ch[i]);
				}
					printf("e%d",zhishu);
			
			}
			}
            
			
		}
	}


	return 0;
}

