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
            if(sum==1&&s[i-1]!=0){ // @@ The condition `s[i-1]!=0` compares a character to integer 0, not the character '0'. It should be `s[i-1]!='0'`.
                printf("%se0",s); // @@ This prints the entire string s followed by "e0", but for input like "0.9", sum is 1 and s[i-1] is '0', so this branch is not taken. However, the logic is incorrect for cases where it would be taken.
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ This prints a dot before the second character, but the expected format should have the first character before the dot. Also, the loop logic is flawed.
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ The loop condition uses `s[i]` which never changes, causing an infinite loop. It should be `s[j]`.
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ `s[j+2]!=NULL` is incorrect; NULL is for pointers, not characters. Should check `s[j+2]!='\0'` or simply `s[j+2]`.
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag); // @@ `&s[j+2]` prints the entire substring from j+2, but the expected output is just the remaining digits after the decimal point. Also, the exponent calculation is wrong.
                            break;
                    }else if(s[j+1]!='0'){
                            printf("%ce-%d",s[j+1],flag); // @@ For input "0.9", this prints "9e-1" but the exponent flag is 1, which is correct, but the loop condition issue prevents reaching here correctly.
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