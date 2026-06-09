#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    int m,n,i=0,j,z=1;
    gets(str1);
    while(str1[i]!='\0'){
        while(str1[i]=='.'){
            i++;
        }
        str2[j]=str1[i]; // @@ [Error: Variable j is uninitialized, leading to undefined behavior when used as an array index]
        j++;
        i++;
    }
    i=0;j=0;
    while(str1[i]!='\0'){
        if(str1[i]=='.'){
            m=i;
        }
        i++;
    }
    if(m==1&&str1[0]!='0'){
        printf("%se0",str1);
    }
    if(m==1&&str1[0]=='0'){
        for(j=0;str2[j]!='\0';j++){ // @@ [Error: str2 is not null-terminated, so the loop condition may cause out-of-bounds access]
            if(str2[j]<='9'&&str2[j]>'0'){
                n=j;
                break;
            }
        }
        printf("%c",str2[n]);
        if(str2[n+1]!='\0'){ // @@ [Error: str2 is not null-terminated, so this condition may be unreliable]
            printf(".");
        }
        j=n;
        n=n+1;
        while(str2[n]!='\0'){ // @@ [Error: str2 is not null-terminated, so this loop may access out-of-bounds memory]
            printf("%c",str2[n]);
            n++;
        }
        printf("e-%d",j);
    }
    if(m!=1){
        printf("%c.",str2[0]);
        while(str2[z]!='\0'){ // @@ [Error: str2 is not null-terminated, so this loop may access out-of-bounds memory]
            printf("%c",str2[z]);
            z++;
        }
        printf("e%d",m-1);
    }
    return 0;
}