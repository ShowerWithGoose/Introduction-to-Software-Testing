#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ gets() is removed in C11 standard and causes compilation error in modern compilers; use fgets() instead.
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ Compares character to integer 0 (null terminator) instead of character '0'; logical error.
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]);
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ Loop condition uses s[i] which is constant, causing an infinite loop; should be s[j].
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ Compares char to pointer NULL; causes compilation error/warning; should be '\0' or 0.
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag);
                            break;
                    }else if(s[j+1]!='0'){
                            printf("%ce-%d",s[j+1],flag);
                            break;
                        }
                    flag++;
                }
                break;
            }
        }
        sum++;
        num++;
    }

    return 0;
}