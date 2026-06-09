#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. Additionally, the problem states input ends with a newline, but 'gets' discards the newline, which may affect logic.]
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [Comparison 's[i-1]!=0' is incorrect: it compares against numeric zero instead of character '0'; should be 's[i-1]!='0''. Also, 'sum==1' checks digit count before decimal, but logic doesn't handle all cases correctly.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [This prints '.' followed by second character, but skips first digit; scientific notation requires one non-zero digit before decimal.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses 's[i]' which never changes inside loop, causing infinite loop or undefined behavior. Should be 's[j]'.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ ['NULL' is a pointer constant; should compare against '\0' for string termination. Also, 's[j+2]!=NULL' is invalid as s[j+2] is char, not pointer.]
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