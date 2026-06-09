#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char s[200];
int dot=0,flag=0,wa=0,sum=1;
int main(){
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Should use 'fgets' instead.]
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.')dot=i;
        if(dot>0){
            if(s[i]!='0')flag=1;
            if(!flag&&s[i]=='0')sum++;
        }
    }
    if(dot==1&&s[0]!='0'){
        printf("%se0",s);
    }
    else{
        if(s[0]=='0'){
            for(int i=dot+sum;i<len;i++){
                if(s[i]!='.')
                printf("%c",s[i]);
                if(i==dot+sum&&i!=len-1)printf(".");
            }
            printf("e-%d",sum);
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