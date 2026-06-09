#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments, 'gets' is not available, leading to a compilation error.]
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [Comparing s[i-1] != 0 is incorrect; it should compare with '0' (character), not 0 (null byte). This logic is also flawed because sum==1 means one digit before '.', but s[i-1]!=0 doesn't check if it's non-zero digit correctly.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [This prints '.' followed by s[1], but the base should start with first digit, then '.', then rest. Logic here misconstructs scientific notation format.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses s[i] which never changes inside loop; should be s[j]. This causes infinite loop or undefined behavior.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [s[j+2]!=NULL is wrong; should compare with '\0'. Also, logic assumes at least two digits after decimal, which may not hold.]
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