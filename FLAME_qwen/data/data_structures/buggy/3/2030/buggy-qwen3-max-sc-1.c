#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1; // @@ [Variable 'j' is used uninitialized in the first loop, leading to undefined behavior when assigning to str2[j]]
    gets(str1); // @@ [Use of unsafe function 'gets' which can cause buffer overflow; also, 'gets' was removed in C11]
    while(str1[i]!='\0'){
        while(str1[i]=='.'){ // @@ [This inner while loop skips all '.' characters but doesn't handle multiple dots correctly; also, it may skip non-dot characters incorrectly due to logic flaw]
            i++;
        }
        str2[j]=str1[i]; // @@ [Using uninitialized 'j'; should initialize j=0 before this loop]
        j++;
        i++;
    }
    i=0;j=0;
    while(str1[i]!='\0'){
        if(str1[i]=='.'){
            m=i; // @@ [Variable 'm' may be used uninitialized if input has no decimal point, leading to undefined behavior]
        }
        i++;
    }
    if(m==1&&str1[0]!='0'){
        printf("%se0",str1);
    }
    if(m==1&&str1[0]=='0'){ // @@ [This should be 'else if' to avoid overlapping conditions with previous 'if']
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
    if(m!=1){ // @@ [This should be 'else' or 'else if' to prevent executing after previous condition; also fails if input has no decimal point because 'm' is uninitialized]
        printf("%c.",str2[0]);
        while(str2[z]!='\0'){
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1);
    }
    return 0;
}