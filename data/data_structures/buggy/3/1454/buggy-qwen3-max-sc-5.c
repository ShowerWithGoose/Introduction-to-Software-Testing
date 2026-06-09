#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments (like GCC with security flags), `gets` is not available, leading to a compilation error: "implicit declaration of function ‘gets’" or linker error. This matches the observed error "/bin/sh: 1: gcc: not found" only if the environment lacks standard libraries, but more likely the actual issue is that `gets` is undefined. However, the shell error suggests toolchain issues—but per problem context, the bug is in code. The real compilation error would be due to `gets` being removed in C11 and often disabled earlier.]
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [This condition checks `s[i-1]!=0`, but `0` here is integer zero, not character '0'. Should be `s[i-1]!='0'`. However, this is a logical error, not compilation. But the primary compilation error is from `gets`.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [This logic is flawed: when j==1, it prints ".X", but s[0] was already skipped? Also, this doesn't produce correct scientific notation. But again, not a compilation error.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses `s[i]` which never changes inside loop → infinite loop if entered. Also, `s[j+2]!=NULL` compares char to NULL (pointer), should be `'\0'`. These are runtime/logical errors, not compilation.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [Comparing char to NULL is invalid; NULL is a pointer constant. Should be `s[j+2]!='\0'`. This may cause a warning or error depending on compiler settings, but typically compiles with warning. However, combined with `gets`, the main issue remains `gets`.]
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