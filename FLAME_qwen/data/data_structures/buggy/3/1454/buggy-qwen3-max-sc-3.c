#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to a compilation error.]
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [Comparing `s[i-1] != 0` checks against null byte, not character '0'. Should be `s[i-1] != '0'`. Also, logic for detecting single-digit before decimal is flawed.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [This prints ".X" at j=1, but j=1 may not be the correct position after removing the original decimal point. Logic misrepresents scientific notation format.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses `s[i]` (fixed value) instead of `s[j]`, causing infinite loop or undefined behavior.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [`NULL` is a pointer; should use `'\0'` for string termination. Also, `s[j+2]!=NULL` is invalid comparison.]
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