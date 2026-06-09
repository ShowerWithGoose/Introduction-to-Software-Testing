#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 1e-10
#define NULL ((void *)0)
#include <ctype.h>
#include <stdlib.h>

int main(){
    char a[150];
    char str1[100],str2[100],str3[100];
    gets(a); // @@ 'gets' is removed in the C11 standard, causing a compilation error in modern environments; use 'fgets' or 'scanf' instead.
    int len=strlen(a);
    int cnt=0;
    int pos=0; 
    int s=0; 
    for(int i=0;i<len;i++){
        if(a[i]=='.'){
            s=i;//前面数字个数 
            pos=i+1;//下一数字位置 
            break;}
    }
    
    //前有0 带负号 
    if(a[s-1]=='0'){
    for(int i=pos;i<len;i++){
        if(a[i]=='0')
            cnt++; 
        else break;
    }
    for(int i=pos+cnt+1,j=0;i<len;i++,j++){ // @@ Missing null-terminator assignment for 'str1' after the loop, which causes undefined behavior when printed with '%s'.
        str1[j]=a[i];
    }
    int r=a[pos+cnt]-'0';//首位数字
    if(a[pos+1]=='\0'){ // @@ Incorrect condition to determine if there is only one significant digit; it should check if 'len == pos + cnt + 1'.
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1); // @@ 'str1' lacks a null terminator, leading to garbage output or a crash.
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){
        printf("%se0",a);
    }
    else{
        printf("%d.",a[0]-'0');
        for(int i=1,j=0;i<pos-1;i++,j++){ // @@ Missing null-terminator assignment for 'str2' after the loop.
            str2[j]=a[i];
        }
        for(int i=pos,j=0;i<len;i++,j++){ // @@ Missing null-terminator assignment for 'str3' after the loop.
            str3[j]=a[i];
        }
        printf("%s",str2); // @@ 'str2' is not null-terminated, causing undefined behavior.
        printf("%s",str3); // @@ 'str3' is not null-terminated, causing undefined behavior.
        printf("e%d",s-1);
    }


return 0;
}