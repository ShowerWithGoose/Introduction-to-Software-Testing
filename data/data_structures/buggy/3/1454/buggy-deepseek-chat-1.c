#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow and is not standard C. Use fgets() instead.]
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [s[i-1]!=0 compares character with integer 0, not '0'. Should be s[i-1]!='0']
                printf("%se0",s); // @@ [prints entire string including decimal point, which is incorrect for scientific notation]
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [incorrectly prints '.' before second character, not handling the decimal point properly]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num); // @@ [num is not correctly computed; it counts digits before decimal, not the exponent]
            }else {
                for(j=i;s[i];j++){ // @@ [loop condition uses s[i] instead of s[j], causing infinite loop or incorrect iteration]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [NULL is for pointers, not characters; should be '\0' or check string end]
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag); // @@ [&s[j+2] prints from that address as string, not correct for scientific notation]
                            break;
                    }else if(s[j+1]!='0'){
                            printf("%ce-%d",s[j+1],flag); // @@ [flag is incremented but not reset; exponent calculation is wrong]
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