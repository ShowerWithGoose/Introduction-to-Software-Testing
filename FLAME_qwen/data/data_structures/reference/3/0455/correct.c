#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    char s[105];char a[105];
    gets(s);
    int i,j,l,k;

    char *p=NULL;
    p=strchr(s,'.');
    if(p!=(s+1)){
        j=p-s;
        printf("%c",s[0]);
        printf(".");
		for(i=1;i<strlen(s);i++){
            if(s[i]!='.'){
			printf("%c",s[i]);
            }
		}


		printf("e%d",j-1);

    }
    else{
        if(s[0]=='0'){
            for(i=2;i<strlen(s);i++){
                if(s[i]!='0')
				{
					l=i;
					break;
				}
			}
            if(s[l+1]!='\0'){
                printf("%c",s[l]);
				printf(".");
				for(i=l+1;s[i]!='\0';i++){
					printf("%c",s[i]);
				}
				printf("e-%d",l-1);
            }
            else{
                printf("%c",s[l]);
				for(i=l+1;s[i]!='\0';i++){
					printf("%c",s[i]);
				}
				printf("e-%d",l-1);
            }

            }
        else{
            for(j=0;j<strlen(s);j++)
			{
				printf("%c",s[j]);
			}
			printf("e0");
        }

        }

    return 0;
}

