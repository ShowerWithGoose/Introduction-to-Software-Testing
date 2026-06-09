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
                printf("%se0",s); // @@ This prints the entire string as the base, but for input like "0.9", sum==1 is false (sum is 0), so this branch is not reached. However, the logic is incorrect for cases where it would be reached.
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ This prints a dot before the second character, but the expected output should have the first digit before the dot. Also, the exponent calculation is missing.
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num); // @@ `num` is not correctly computed for the exponent; it should be the number of digits before the decimal point minus one.
            }else {
                for(j=i;s[i];j++){ // @@ The loop condition uses `s[i]` which never changes, causing an infinite loop. It should be `s[j]`.
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ `NULL` is not a valid comparison for characters; should use `s[j+2]!='\0'`. Also, the logic for finding the first non-zero digit is flawed.
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag); // @@ `&s[j+2]` prints from that address as a string, but the expected output is a single digit after the decimal point. Also, `flag` is not correctly computed.
                            break;
                    }else if(s[j+1]!='0'){
                            printf("%ce-%d",s[j+1],flag); // @@ `flag` is incremented but not correctly representing the exponent magnitude.
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