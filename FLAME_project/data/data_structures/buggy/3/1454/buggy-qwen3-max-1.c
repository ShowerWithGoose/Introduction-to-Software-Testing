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
            if(sum==1&&s[i-1]!=0){ // @@ [s[i-1]!=0 compares character to integer 0; should compare to '0'. Also logic fails for "0.9" because sum==1 and s[i-1]=='0', so this branch is skipped incorrectly.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [This prints second digit after decimal point incorrectly; e.g., for "12.34", it would print "1.234e1", but the loop logic is flawed and doesn't skip the decimal properly.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses s[i] (unchanging) instead of s[j], causing infinite loop or undefined behavior. Should be s[j].]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [s[j+2]!=NULL compares char to NULL; should check s[j+2]!='\0'. Also, logic assumes at least two digits after leading zeros, which fails for "0.9".]
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