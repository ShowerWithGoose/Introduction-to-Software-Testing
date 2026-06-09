#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in many modern environments, 'gets' is not available, leading to compilation error]
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [Comparing character s[i-1] with integer 0 instead of character '0'; this logic is flawed and will not work as intended]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [Incorrect formatting: when j==1, it prints ".X" but the first digit (at j=0) was never printed, breaking scientific notation format]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses s[i] which never changes inside the loop, causing infinite loop or undefined behavior; should be s[j]]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [Comparing s[j+2] with NULL (pointer) instead of '\0' (character); also, potential out-of-bounds access]
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