#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1;
    gets(str1); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, 'j' is used uninitialized in the next loop.]
    while(str1[i]!='\0'){
        while(str1[i]=='.'){ // @@ [This inner while loop skips all '.' characters but doesn't handle multiple decimals correctly; also logic flaw: should copy non-'.' chars, but condition is inverted.]
            i++;
        }
        str2[j]=str1[i]; // @@ ['j' is used without initialization (undefined behavior).]
        j++;
        i++;
    }
    i=0;j=0;
    while(str1[i]!='\0'){
        if(str1[i]=='.'){
            m=i; // @@ ['m' may remain uninitialized if input has no decimal point, leading to undefined behavior later.]
        }
        i++;
    }
    if(m==1&&str1[0]!='0'){
        printf("%se0",str1);
    }
    if(m==1&&str1[0]=='0'){ // @@ [This should be 'else if' to avoid overlapping conditions with previous 'if'.]
        for(j=0;str2[j]!='\0';j++){
            if(str2[j]<='9'&&str2[j]>'0'){
                n=j;
                break;
            }
        }
        printf("%c",str2[n]);
        if(str2[n+1]!='\0'){
            printf(".");
        }
        j=n;
        n=n+1;
        while(str2[n]!='\0'){
            printf("%c",str2[n]);
            n++;
        }
        printf("e-%d",j);
    }
    if(m!=1){ // @@ [This should be 'else' or 'else if' to avoid executing after the zero-leading case; also fails when input has no decimal (m uninitialized).]
        printf("%c.",str2[0]);
        while(str2[z]!='\0'){
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1);
    }
    return 0;
}