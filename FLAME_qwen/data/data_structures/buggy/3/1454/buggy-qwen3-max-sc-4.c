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
            if(sum==1&&s[i-1]!=0){ // @@ [This condition checks 's[i-1]!=0', but 's[i-1]' is a char; it should compare with '0' character, i.e., 's[i-1] != '0''. Also, logic for detecting single-digit before decimal is flawed.]
                printf("%se0",s);
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [Incorrect formatting: when j==1, it prints '.' followed by s[1], but s[0] was already printed? This loop doesn't print s[0] at all in this branch, leading to missing first digit.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Loop condition uses 's[i]' which never changes inside the loop (should be 's[j]'), causing infinite loop or undefined behavior.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ ['NULL' is a pointer constant; should use '\0' for string termination. Also, 's[j+2]!=NULL' is invalid comparison between char and pointer.]
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