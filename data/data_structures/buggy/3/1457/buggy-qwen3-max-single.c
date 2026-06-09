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
    gets(a); // @@ [Using gets() is unsafe and deprecated; may cause compilation error if compiler enforces secure functions or if gets is not available in the standard library (e.g., C11+).]
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
    if(a[pos+1]=='\0'){ // @@ [This condition checks if the character after the first non-zero digit is null, but it should check if there are no more digits after the first significant digit. Also, if cnt causes pos+cnt to be beyond string length, this leads to undefined behavior. However, the primary compilation issue stems from gets().]
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1);
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){
        printf("%se0",a); // @@ [This prints the entire original string including the decimal point, which violates the output format (e.g., "5.0e0" instead of "5e0" or "5.0e0" when only one digit is allowed before decimal). But this is a logic error, not compilation. The main compilation error is gets().]
    }
    else{
        printf("%d.",a[0]-'0');
        for(int i=1,j=0;i<pos-1;i++,j++){
            str2[j]=a[i];
        }
        for(int i=pos,j=0;i<len;i++,j++){
            str3[j]=a[i];
        }
        printf("%s",str2);
        printf("%s",str3);
        printf("e%d",s-1);
    }


return 0;
}