#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1; // @@ [Initializing sum to 1 is incorrect; should be 0 because it is meant to count the number of zeros after the decimal point before the first non-zero digit.]
int main(){
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1; // @@ [This sets flag to 1 even when s[i] is the dot ('.'), causing premature termination of zero counting. Should exclude the dot: if(s[i]!='0' && s[i]!='.')]
            if(!flag&&s[i]=='0')sum++;
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){ // @@ [Start index should be dot+sum+1 to skip all leading zeros after the decimal. Here it starts at dot+sum, which is the last zero, not the first non-zero digit.]
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf("."); // @@ [This prints a decimal point after the last leading zero, which is incorrect. It should be placed after the first non-zero digit if there are more digits.]
            }
            printf("e-%d",sum); // @@ [Exponent should be -(sum+1) to reflect the correct power of ten. Here it prints -sum, which is off by one.]
        }
        else{
            for(int i=0;i<len;i++){
                if(s[i]!='.'){
                    printf("%c",s[i]); 
                }
                if(i==0)printf(".");
            }
            printf("e%d",dot-1);
        }
    }
    return 0;
}