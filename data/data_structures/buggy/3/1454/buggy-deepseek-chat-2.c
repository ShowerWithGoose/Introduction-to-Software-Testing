#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ This line uses gets(), which is unsafe and may cause buffer overflow; also, gets() is removed from C11 standard, causing compilation error in strict C11 mode.
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ The condition s[i-1]!=0 compares a character to integer 0, not the character '0'; should be s[i-1]!='0'
                printf("%se0",s); // @@ This prints the entire string s, which includes the decimal point and may produce incorrect output; also, the exponent e0 is hardcoded without proper exponent calculation.
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ This prints a dot before the second character, but does not handle the first character correctly; the logic for formatting the base is flawed.
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num); // @@ num is not correctly calculated as the exponent; it counts digits before the decimal point but does not account for the position of the decimal point properly.
            }else {
                for(j=i;s[i];j++){ // @@ The loop condition uses s[i] instead of s[j], causing infinite loop or incorrect iteration; also, the logic for handling numbers less than 1 is incorrect.
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ s[j+2]!=NULL is incorrect; NULL is a pointer constant, not a character; should check for end of string with s[j+2]!='\0'
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag); // @@ &s[j+2] prints from that address as a string, which may include extra characters; flag is not correctly set as exponent.
                            break;
                    }else if(s[j+1]!='0'){
                            printf("%ce-%d",s[j+1],flag); // @@ flag is incremented but not used correctly as the exponent value; the exponent should be the number of zeros after the decimal point.
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