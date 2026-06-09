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
            if(sum==1&&s[i-1]!=0){@@ // Wrong condition: should check if s[i-1]!='0' (character zero), not compare to zero. This incorrectly treats numbers like 0.9 as having non-zero whole part.
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
                for(j=i;s[i];j++){@@ // Loop condition uses s[i] which is constant (the decimal point), leading to infinite loop if no break condition met; should use s[j] or s[j+1] instead.
                    if(s[j+1]!='0'&&s[j+2]!=NULL){@@ // Use of NULL is incorrect; should compare to '\0' (null character).
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