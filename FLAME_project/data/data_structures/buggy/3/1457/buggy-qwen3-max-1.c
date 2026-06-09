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
    gets(a); @@ [Using gets() is unsafe and may cause buffer overflow; also, it's deprecated. More critically, if input has no decimal point, s remains uninitialized, leading to undefined behavior.]
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
    if(a[s-1]=='0'){ @@ [If the input has no decimal point (e.g., "123"), s remains 0, so a[s-1] accesses a[-1], which is invalid. Also, this condition assumes there is always a decimal point, but problem says input has digits before and after decimal, so maybe safe per spec—but logic still fragile. However, main bug: when input is like "0.000...", s=1, so a[s-1] = a[0] = '0' — OK. But if input starts with non-zero and has decimal, e.g., "123.45", then s=3, a[s-1]='3' != '0', so goes to else. So this condition is for numbers < 1. However, the real issue is in output formatting and string termination.]
    for(int i=pos;i<len;i++){
        if(a[i]=='0')
            cnt++; 
        else break;
    }
    for(int i=pos+cnt+1,j=0;i<len;i++,j++){
        str1[j]=a[i];
    } @@ [str1 is not null-terminated, leading to garbage output when printed with %s. This causes the "@" garbage in output.]
    int r=a[pos+cnt]-'0';//首位数字
    if(a[pos+1]=='\0'){ @@ [This checks if second digit after decimal is null, but if cnt>0, pos+1 may be beyond first non-zero. Also, if input is "0.1", then pos=2, a[pos+1] is '\0', so prints "1e-1", which is correct. But logic is flawed for general case. However, the critical error is missing null terminator in str1.]
        printf("%d",r);
        printf("e-%d",cnt+1);
    }
    else{
    
        printf("%d.",r);
        printf("%s",str1); @@ [Because str1 lacks '\0', printf reads beyond valid data, causing garbage like "@".]
        printf("e-%d",cnt+1);}
    }
    else if(a[s-1]!='0'&&s==1){ @@ [This handles cases like "5.123", where only one digit before decimal. But if input is "0.123", s=1, a[s-1]=a[0]='0', so doesn't enter here. If input is "1.23", s=1, a[0]='1' != '0', so enters. But what if input is "12.3"? Then s=2, so skips this. So this branch is only for single-digit non-zero before decimal. However, the condition s==1 implies only one digit before decimal, which is correct. But note: if input has no decimal, this whole logic fails because s remains 0. But problem states input has digits before and after decimal, so maybe acceptable. Still, the main bug is elsewhere.]
        printf("%se0",a); @@ [This prints the whole string with "e0", e.g., "5.123e0", but expected is "5.123e0" — however, per problem, base must have one digit before decimal. So "5.123" is valid base. But if input is "5", without decimal, this wouldn't work — but input always has decimal per problem. However, this outputs "5.123e0", which is correct format. But note: if input is "0.1", it doesn't go here. So this branch seems okay, but the real issue is in the first branch's string handling.]
    }
    else{ @@ [This handles numbers >= 10, e.g., "123.45". It prints first digit, then decimal, then rest of digits before and after decimal. But str2 and str3 are not null-terminated, which could cause issues, but in this test case we are in the first branch, so this isn't triggered.]
        printf("%d.",a[0]-'0');
        for(int i=1,j=0;i<pos-1;i++,j++){
            str2[j]=a[i];
        } @@ [str2 not null-terminated]
        for(int i=pos,j=0;i<len;i++,j++){
            str3[j]=a[i];
        } @@ [str3 not null-terminated]
        printf("%s",str2);
        printf("%s",str3);
        printf("e%d",s-1);
    }


return 0;
}