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
    gets(a);
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
    for(int i=pos+cnt+1,j=0;i<len;i++,j++){
        str1[j]=a[i];
    }
    int r=a[pos+cnt]-'0';//首位数字
    if(a[pos+1]=='\0'){ // @@ [Error: This condition checks if the character after the decimal point is null, but for input like "0.00000009123456789012", a[pos+1] is '0', not '\0', so this branch is never taken. The logic should check if there are no digits after the first non-zero digit, but the condition is incorrect.]
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1); // @@ [Error: str1 is not null-terminated after copying from a, so printf("%s", str1) may print garbage characters (like '@' and '') until a null byte is found. The copy loop does not add a null terminator, causing undefined behavior.]
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){
        printf("%se0",a);
    }
    else{
        printf("%d.",a[0]-'0');
        for(int i=1,j=0;i<pos-1;i++,j++){
            str2[j]=a[i];
        }
        for(int i=pos,j=0;i<len;i++,j++){
            str3[j]=a[i];
        }
        printf("%s",str2); // @@ [Error: str2 is not null-terminated, causing potential garbage output.]
        printf("%s",str3); // @@ [Error: str3 is not null-terminated, causing potential garbage output.]
        printf("e%d",s-1);
    }


return 0;
}