#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s);
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){
                printf("%se0",s); // @@ [This prints the original number with 'e0' when there's one digit before '.', but it should normalize to scientific notation. For input "0.9", sum=1 and s[i-1]=='0', so this condition fails, but logic is flawed for cases like "5.3". Also, s[i-1]!=0 compares char to int 0 instead of '0'.]
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [This incorrectly prints a dot before the second character. Scientific notation requires only one non-zero digit before the decimal. Also, this loop doesn't skip the '.' properly and misplaces digits.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num); // @@ [num is incremented per digit before '.', but initial value is -1, so for "12.3", num becomes 1 (correct), but the printed mantissa is malformed due to earlier logic.]
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses s[i] which never changes; should be s[j]. This causes infinite loop or undefined behavior.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [s[j+2]!=NULL compares char to NULL (pointer). Should be s[j+2]!='\0'. Also, logic assumes at least two digits after leading zeros, which may not hold.]
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